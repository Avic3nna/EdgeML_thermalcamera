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

// Lab 8: add prediction data structure
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

/* Resolution of MNINST Input Image */
#define NN_INPUT_IMAGE_WIDTH				28
#define NN_INPUT_IMAGE_HEIGHT				28

/* Resolution of character on screen */
#define LCD_INPUT_IMAGE_WIDTH				240
#define LCD_INPUT_IMAGE_HEIGHT				240

/* Using 2 layers from datasheet */
#define LCD_FRAME_BUFFER_LAYER0             (LCD_FRAME_BUFFER +0x130000)
#define LCD_FRAME_BUFFER_LAYER1 			LCD_FRAME_BUFFER
#define CONVERTED_FRAME_BUFFER              (LCD_FRAME_BUFFER +0x260000)

/* Defining positions of screen elements */
#define DRAW_IMG_X1							10
#define	DRAW_IMG_X2							230

#define DRAW_IMG_Y1							10
#define	DRAW_IMG_Y2							230

#define ERASE_BUTTON_X1						5
#define ERASE_BUTTON_Y1						285
#define ERASE_BUTTON_X2						ERASE_BUTTON_X1 +230
#define ERASE_BUTTON_Y2						ERASE_BUTTON_Y1 + 30

#define IMG_SCALED_X_SHIFT					200
#define IMG_SCALED_Y_SHIFT					250

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
void mnist_game_reset(ai_float*, ai_float*, pred_probType*, pred_probType*);
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
	printf("[MAIN] Application running \r\n");

	// LAB7: Initialise BUTTON_KEY. Use BSP_PB_Init() function.
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	/* Initialise all peripherals related to LCD and Touch sensor */

	// LAB7: Initialise touch sensor
	touch_sensor_init();

	// LAB7: Initialise LCD and reset it
	user_interface_init();
	user_interface_reset();

	// LAB8: Define NN variables
	/*	Replaced by in_data and out_data
	 ai_float nn_input_data[NN_INPUT_IMAGE_HEIGHT][NN_INPUT_IMAGE_WIDTH];
	 ai_float nn_output_data[NUM_CLASSES];*/

	pred_probType _1st_pred, _2nd_pred;
	_1st_pred.prob = _2nd_pred.prob = 0.0f;

	char _1st_pred_str[10], _1st_pred_prob_str[10];

	// Lab8: Reset NN data preliminary
	mnist_game_reset(in_data, out_data, &_1st_pred, &_2nd_pred);

	// Lab8: Init NN
	aiInit();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
		// LAB7: Get touch screen detection state. Use function from stm32f429i_discovery_ts.c. use ui_state type definition to store the result. (Defined on line 46).
		BSP_TS_GetState(&ui_state);

		if (ui_state.TouchDetected) {

			if ((ui_state.X > DRAW_IMG_X1 && ui_state.X < DRAW_IMG_X2)
					&& (ui_state.Y > DRAW_IMG_Y1 && ui_state.Y < DRAW_IMG_Y2)) {

				// LAB7: Draw pixels to the points on the screen where screen is touched
				int delta = 4;
				int size = 4;
				BSP_LCD_FillCircle(ui_state.X, ui_state.Y, size);
				BSP_LCD_FillCircle((ui_state.X) + delta, ui_state.Y, size);
				BSP_LCD_FillCircle(ui_state.X, (ui_state.Y) + delta, size);
				BSP_LCD_FillCircle((ui_state.X) - delta, ui_state.Y, size);
				BSP_LCD_FillCircle(ui_state.X, (ui_state.Y) - delta, size);
				//printf("X: %d, Y: %d\n", ui_state.X, ui_state.Y);

				// Scale down to 22x22 and add margin (22+3+3=28)
				int x = ui_state.Y * ((float) 20 / 240) + 4;
				int y = ui_state.X * ((float) 20 / 240) + 4;
//				int x = ui_state.Y * ((float) 28 / 240);
//				int y = ui_state.X * ((float) 28 / 240);

				// Add  the input to in_data for inference
//				in_data[28 * (x - 2) + (y + 2)] = 0.8;
				in_data[28 * (x - 2) + (y + 1)] = PXL_SET;
				in_data[28 * (x - 2) + (y)] = PXL_SET;
				in_data[28 * (x - 2) + (y - 1)] = PXL_SET;
//				in_data[28 * (x - 2) + (y - 2)] = 0.8;

//				in_data[28 * (x - 1) + (y + 2)] = 0.8;
				in_data[28 * (x - 1) + (y + 1)] = PXL_SET;
				in_data[28 * (x - 1) + (y)] = PXL_SET;
				in_data[28 * (x - 1) + (y - 1)] = PXL_SET;
//				in_data[28 * (x - 1) + (y - 2)] = 0.8;

//				in_data[28 * (x) + (y + 2)] = 0.8;
				in_data[28 * (x) + (y + 1)] = PXL_SET;
				in_data[28 * (x) + (y)] = PXL_SET;
				in_data[28 * (x) + (y - 1)] = PXL_SET;
//				in_data[28 * (x) + (y - 2)] = 0.8;

//				in_data[28 * (x + 1) + (y + 2)] = 0.8;
				in_data[28 * (x + 1) + (y + 1)] = PXL_SET;
				in_data[28 * (x + 1) + (y)] = PXL_SET;
				in_data[28 * (x + 1) + (y - 1)] = PXL_SET;
//				in_data[28 * (x + 1) + (y - 2)] = 0.8;

//				in_data[28 * (x + 2) + (y + 2)] = 0.8;
//				in_data[28 * (x + 2) + (y + 1)] = PXL_SET;
//				in_data[28 * (x + 2) + (y)] = PXL_SET;
//				in_data[28 * (x + 2) + (y - 1)] = PXL_SET;
//				in_data[28 * (x + 2) + (y - 2)] = 0.8;

				// Draw 28x28 in the small screen
//				x = ui_state.Y * ((float) 28 / 240);
//				y = ui_state.X * ((float) 28 / 240);

				BSP_LCD_DrawPixel(y + 1 + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x + 1, 255);
				BSP_LCD_DrawPixel(y - 1 + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x - 1, 255);
				BSP_LCD_DrawPixel(y + 1 + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x, 255);
				BSP_LCD_DrawPixel(y - 1 + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x, 255);
				BSP_LCD_DrawPixel(y + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x, 255);
				BSP_LCD_DrawPixel(y + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x + 1, 255);
				BSP_LCD_DrawPixel(y + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x - 1, 255);
				BSP_LCD_DrawPixel(y + 1 + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x - 1, 255);
				BSP_LCD_DrawPixel(y - 1 + IMG_SCALED_X_SHIFT,
				IMG_SCALED_Y_SHIFT + x + 1, 255);

				printf("X =%d Y=%d\r\n", ui_state.X, ui_state.Y);

			} else if ((ui_state.X > ERASE_BUTTON_X1
					&& ui_state.X < ERASE_BUTTON_X2)
					&& (ui_state.Y > ERASE_BUTTON_Y1
							&& ui_state.Y < ERASE_BUTTON_Y2)) {
				// LAB7: When erase button is pressed reset user interface.
				user_interface_reset();
				// LAB8: Reset MNIST to that fills input data with zeros. Use mnist_game_reset() function.
				mnist_game_reset(in_data, out_data, &_1st_pred, &_2nd_pred);
			}

		}
		HAL_Delay(1);

		if (BSP_PB_GetState(BUTTON_KEY)) {
			printf("NN processing...");
			// LAB8: Execute inference. We will use here our own made function MX_X_CUBE_AI_Process_2() that feeds model with input data and outputs results.
			// You could use MX_X_Cube_AI_Process() function if you prefer to use function generated by CubeMX software.
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

			// Display first predicted number
			sprintf(_1st_pred_str, "%d", _1st_pred.label);
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_SetFont(&Font20);
			BSP_LCD_SetBackColor(LCD_COLOR_LIGHTCYAN);
			BSP_LCD_DisplayStringAt(130, 255, (uint8_t*) _1st_pred_str,
					LEFT_MODE);
			// Display probability of 1st guess
			sprintf(_1st_pred_prob_str, "%.1f", (float) _1st_pred.prob * 100);
			BSP_LCD_DisplayStringAt(10, 220, (uint8_t*) _1st_pred_prob_str,
					LEFT_MODE);
			BSP_LCD_DisplayStringAt(80, 220, (uint8_t*) "%", LEFT_MODE);
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
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

// Lab8: Reset function
void mnist_game_reset(ai_float *in_data, ai_float *out_data,
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

	// Set text color to black
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	// set font size 16
	BSP_LCD_SetFont(&Font16);

	// Set background color (lightcyan)
	BSP_LCD_SetBackColor(LCD_COLOR_LIGHTCYAN);

	// Write prediction output string "NN OUTPUT" to position x,y = (5, 255)
	BSP_LCD_DisplayStringAt(5, 255, (uint8_t*) "NN OUTPUT: ", LEFT_MODE);

	// Draw rectangle to mark prediction output area. Marked with "B" on image.
	// Position x,y = (200, 250) and dimensions = (28, 28)
	BSP_LCD_DrawRect(200, 250, 28, 28);

	// Set text color to blue
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);

	// Write clear button area, marked with "C". Draw filled rectangle to position x,y = (5, 285) with dimensions = (230, 30)
	BSP_LCD_FillRect(5, 285, 230, 30);

	// Set text color to white
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set font size to 16
	BSP_LCD_SetFont(&Font16);

	// Set background color as blue
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);

	// Display string "CLEAR" to position x,y = (330, 291)
	BSP_LCD_DisplayStringAt(330, 291, (uint8_t*) "SELGE", LEFT_MODE);

	// Draw minimized user drawing area, marked with "D" on figure. Draw rectangle to position x,y = (2,2) and dimensions (237,237)
	BSP_LCD_DrawRect(2, 2, 237, 237);

	// Set text color as black
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

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
