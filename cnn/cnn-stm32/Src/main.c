/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "dma2d.h"
#include "i2c.h"
#include "ltdc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/unistd.h>

#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ts.h"

#include "network.h"
#include "network_data.h"

#include "X_test.c"
#include "y_test.c"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
TS_StateTypeDef ui_state;

/* Global handle to reference an instantiated C-model */
static ai_handle network = AI_HANDLE_NULL;

/* Global c-array to handle the activations buffer */
AI_ALIGNED(32)
static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];

/* Data payload for input tensor */
AI_ALIGNED(32)
static ai_float in_data[AI_NETWORK_IN_1_SIZE];
/* or static ai_u8 in_data[AI_NETWORK_IN_1_SIZE_BYTES]; */

/* Data payload for the output tensor */
AI_ALIGNED(32)
static ai_float out_data[AI_NETWORK_OUT_1_SIZE];
/* static ai_u8 out_data[AI_NETWORK_OUT_1_SIZE_BYTES]; */

// add prediction data structure
struct prediction_probability {
	ai_float prob;
	ai_u8 label;
};

typedef struct prediction_probability pred_probType;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SET    1
#define RESET  0
#define LCD_LAYER_1 SET
#define LCD_LAYER_0 RESET
#define TRUE SET

/* Using 2 layers from datasheet */
#define LCD_FRAME_BUFFER_LAYER0             (LCD_FRAME_BUFFER +0x130000)
#define LCD_FRAME_BUFFER_LAYER1 			LCD_FRAME_BUFFER
#define CONVERTED_FRAME_BUFFER              (LCD_FRAME_BUFFER +0x260000)

#define  PXL_SET							0.99
// LAB8: Change number of output classes accordingly based on the MNIST model
#define  NUM_CLASSES						10

// LAB7: Add USART prototype for printf (described in lecture 9 materials)
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
PUTCHAR_PROTOTYPE {
	while (HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, 10) != HAL_OK) {
	};
	return ch;
}

#ifdef __GNUC__
#define GETCHAR_PROTOTYPE int __io_getchar (void)
#else
#define GETCHAR_PROTOTYPE int fgetc(FILE * f)
#endif /* __GNUC__ */

GETCHAR_PROTOTYPE {
	uint8_t ch = 0;
	// Clear the Overrun flag just before receiving the first character
	__HAL_UART_CLEAR_OREFLAG(&huart1);
	HAL_UART_Receive(&huart1, (uint8_t*) &ch, 1, 0xFFFF);
	while (HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, 10) != HAL_OK) {
	};
	return ch;
}

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void user_interface_init(void);
void user_interface_reset(void);
void touch_sensor_init(void);
// Lab 8: add prototype
void reset_nn(ai_float*, ai_float*, pred_probType*, pred_probType*);
int aiInit(void);
int aiRun(const void*, void*);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	setvbuf(stdin, NULL, _IONBF, 0);
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_I2C3_Init();
  MX_LTDC_Init();
  MX_SPI5_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	printf("ias0360-final-project running \r\n");

	// Initialise BUTTON_KEY. Use BSP_PB_Init() function.
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	// Initialise LCD and reset it
	user_interface_init();
	user_interface_reset();

	pred_probType _1st_pred, _2nd_pred;
	_1st_pred.prob = _2nd_pred.prob = 0.0f;

	char _1st_pred_str[50], _1st_pred_prob_str[50];

	// Reset NN data preliminary
	reset_nn(in_data, out_data, &_1st_pred, &_2nd_pred);

	// Init NN
	aiInit();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {

		if (BSP_PB_GetState(BUTTON_KEY)) {
			printf("NN processing...");
			// Execute inference

			// Show image
			for(int x=0; x<32, x++){
				for(int y=0; y<32, y++){
				BSP_LCD_SetTextColor(0xFFFFFF00+x);
				BSP_LCD_FillRect(64+(x*4), 64+(y*4), 4, 4);
				}
			}


			aiRun(in_data, out_data);

			for (int i = 0; i < NUM_CLASSES; i++) {
				if (_1st_pred.prob < out_data[i]) {
					_2nd_pred.label = _1st_pred.label;
					_2nd_pred.prob = _1st_pred.prob;
					_1st_pred.prob = out_data[i];
					_1st_pred.label = i;

				} else if (_2nd_pred.prob < out_data[i]) {
					_2nd_pred.label = i;
					_2nd_pred.prob = out_data[i];
				}
			}

			printf("NN First Guess: %d  %f \n\r", _1st_pred.label,
					_1st_pred.prob);
			printf("NN Second Guess: %d  %f \n\r", _2nd_pred.label,
					_2nd_pred.prob);

			// Set display for NN output
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_SetFont(&Font20);
			BSP_LCD_SetBackColor(LCD_COLOR_LIGHTCYAN);

			// Display predicted class
			sprintf(_1st_pred_str, "Pred.: %d", _1st_pred.label);
			BSP_LCD_DisplayStringAt(10, 240, (uint8_t*) _1st_pred_str, CENTER_MODE);

			// Display real class
			sprintf(_1st_pred_str, "Truth: %d", _1st_pred.label);
			BSP_LCD_DisplayStringAt(10, 260, (uint8_t*) _1st_pred_str, CENTER_MODE);
		}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

// Reset function
void reset_nn(ai_float *in_data, ai_float *out_data,
		pred_probType *_1st_pred, pred_probType *_2nd_pred) {
	memset(in_data, 0.0, sizeof(in_data[0]) * AI_NETWORK_IN_1_SIZE);
	memset(out_data, 0.0, sizeof(out_data[0]) * AI_NETWORK_OUT_1_SIZE);
	_2nd_pred->label = _2nd_pred->prob = _1st_pred->label = _1st_pred->prob =
			0.0;
}

/*
 * Bootstrap code
 */
int aiInit(void) {
	ai_error err;

	/* 1 - Create an instance of the model */
	err = ai_network_create(&network, AI_NETWORK_DATA_CONFIG /* or NULL */);
	if (err.type != AI_ERROR_NONE) {
		printf("E: AI ai_network_create error - type=%d code=%d\r\n", err.type,
				err.code);
		return -1;
	};

	/* 2 - Initialise the instance */
	const ai_network_params params = AI_NETWORK_PARAMS_INIT(
			AI_NETWORK_DATA_WEIGHTS(ai_network_data_weights_get()),
			AI_NETWORK_DATA_ACTIVATIONS(activations)
	);

	if (!ai_network_init(network, &params)) {
		err = ai_network_get_error(network);
		printf("E: AI ai_network_init error - type=%d code=%d\r\n", err.type,
				err.code);
		return -1;
	}

	return 0;
}

/*
 * Run inference code
 */
int aiRun(const void *in_data, void *out_data) {
	ai_i32 n_batch;
	ai_error err;

	/* 1 - Create the AI buffer IO handlers with the default definition */
	ai_buffer ai_input[AI_NETWORK_IN_NUM] = AI_NETWORK_IN;
	ai_buffer ai_output[AI_NETWORK_OUT_NUM] = AI_NETWORK_OUT;

	/* 2 - Update IO handlers with the data payload */
	ai_input[0].n_batches = 1;
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].n_batches = 1;
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	/* 3 - Perform the inference */
	n_batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
	if (n_batch != 1) {
		err = ai_network_get_error(network);
		printf("E: AI ai_network_run error - type=%d code=%d\r\n", err.type,
				err.code);
		return -1;
	};

	return 0;
}

/**
 *
 * @brief: TLCD INIT Implementation
 * @Param: Board Support Package
 *
 */
void user_interface_init(void) {
	// Initialise LCD. Use functions from stm32f429i_discovery_lcd.h
	BSP_LCD_Init();

	// Initialise LCD Layer 1 (background layer) with FB address that points to layer 1
	BSP_LCD_LayerDefaultInit(LCD_LAYER_1, LCD_FRAME_BUFFER_LAYER1);

	// Select layer 1
	BSP_LCD_SelectLayer(LCD_LAYER_1);

	// Clear LCD (color red)
	BSP_LCD_Clear(LCD_COLOR_RED);

	// Set colour keyring for layer 1 (colour dark cyan)
	BSP_LCD_SetColorKeying(LCD_LAYER_1, LCD_COLOR_DARKCYAN);

	// Set layer 1 visibility to disabled
	BSP_LCD_SetLayerVisible(LCD_LAYER_1, DISABLE);

	// Initialise Layer 0 (foreground or visible layer) with FB address that points to layer 0
	BSP_LCD_LayerDefaultInit(LCD_LAYER_0, LCD_FRAME_BUFFER_LAYER0);

	// Select Layer 0
	BSP_LCD_SelectLayer(LCD_LAYER_0);

	// Switch LCD display on
	BSP_LCD_DisplayOn();

	HAL_Delay(200);

	// Clear the whole LCD with color lightcyan
	BSP_LCD_Clear(LCD_COLOR_LIGHTCYAN);

	HAL_Delay(100);

	printf("LCD initialisation completed \r\n");
}

/**
 *
 * @brief: User Interface Control Function Implementation
 * @Param: Board Support Package
 *
 */
void user_interface_reset(void) {
	// Clear LCD with light cyan color. Possible color definitions in stm32f429i_discovery_lcd.h
	BSP_LCD_Clear(LCD_COLOR_LIGHTCYAN);

	// Set background color (lightcyan)
	BSP_LCD_SetBackColor(LCD_COLOR_LIGHTCYAN);

	// set font size 16
	BSP_LCD_SetFont(&Font20);
	// Set text color to blue
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	// Write prediction output string "NN OUTPUT" to position x,y = (5, 255)
	BSP_LCD_DisplayStringAt(15, 5, (uint8_t*) "Thermal Picture ", CENTER_MODE);
	BSP_LCD_DisplayStringAt(15, 25, (uint8_t*) "Prediction ", CENTER_MODE);

	// Set text color to black
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	// Picture box
	BSP_LCD_FillRect(64, 64, 128, 128);

	// set font size 16
	BSP_LCD_SetFont(&Font16);
	// Write prediction output string "NN OUTPUT" to position x,y = (5, 255)
	BSP_LCD_DisplayStringAt(5, 220, (uint8_t*) "NN OUTPUT: ", LEFT_MODE);

	// Set text color to blue
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);

	// Write clear button area, marked with "C". Draw filled rectangle to position x,y = (5, 285) with dimensions = (230, 30)
	// BSP_LCD_FillRect(5, 285, 230, 30);

	// Set text color to white
	// BSP_LCD_SetTextColor(LCD_COLOR_WHITE);


	// Set background color as blue
	// BSP_LCD_SetBackColor(LCD_COLOR_BLUE);

	// Set text color as black
	// BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	printf("LCD Interface INIT successful \r\n");
}

/**
 *
 * @brief: Touch Sensor INIT Implementation
 * @Param: Board Support Package
 *
 */
void touch_sensor_init(void) {
	// Initialise touch sensor to use a whole LCD area (240x320) and print to UART whether the initialization was successful or not
	if (BSP_TS_Init(240, 320) == TS_ERROR) {
		printf("Touch sensor initialization failed \r\n");
	} else {
		printf("Touch sensor initialization successful \r\n");
	}
	HAL_Delay(50);
}

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
