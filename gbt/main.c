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

#include "X_test.h"
#include "y_test.h"

extern float X_train[20][1024];
extern float y_train[];
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

struct prediction_probability{
 ai_float prob;
 ai_u8  label;
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

/* Using 2 layers from data sheet */
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
#define  NUM_CLASSES						2

// USART prototype for printf (described in lecture 9 materials)
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
PUTCHAR_PROTOTYPE {
        while (HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 10) != HAL_OK) {};
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
  HAL_UART_Receive(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  while (HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 10) != HAL_OK) {};
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
void user_interface_reset();
void touch_sensor_init();
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
  MX_X_CUBE_AI_Init();
  /* USER CODE BEGIN 2 */
  printf("[MAIN] Application running - Final Project \r\n");

  // Initialize BUTTON_KEY
  BSP_PB_Init(BUTTON_KEY,  BUTTON_MODE_GPIO);

  // Initialize touch sensor
  touch_sensor_init();

  // Initialize LCD and reset it
  /* Initialize all peripherals related to LCD and Touch sensor */
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
  int image_idx = 0;
  while (1) {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			user_interface_reset();

			// Show image
			int color = 0xFFFFFFFF;
			for(int x=0; x<32; x++){
				for(int y=0; y<32; y++){
					int repr_data = (int)( X_test[image_idx][(int)(x*32+y)]*10);
					if (repr_data == 150) {
						color = LCD_COLOR_GRAY;
					}
					else if (repr_data >= 255) {
						color = LCD_COLOR_RED;
					}
					else {
						// shift to the RR Position of BBRRGGBB
						color = 0xFF000000 | (repr_data << 16);
					}
					BSP_LCD_SetTextColor(color);
					BSP_LCD_FillRect(64+(x*4), 64+(y*4), 4, 4);
				}
			}

			// Execute inference
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

			// TODO: Display predicted class
			sprintf(_1st_pred_str, "Pred.: %d", _1st_pred.label);
			BSP_LCD_DisplayStringAt(10, 240, (uint8_t*) _1st_pred_str, CENTER_MODE);

			// Display real class
			sprintf(_1st_pred_str, "Truth: %d", y_test[image_idx]);
			BSP_LCD_DisplayStringAt(10, 260, (uint8_t*) _1st_pred_str, CENTER_MODE);

			// TODO: Display inference time
			sprintf(_1st_pred_str, "Time: %.1f", _1st_pred.prob);
			BSP_LCD_DisplayStringAt(10, 280, (uint8_t*) _1st_pred_str, CENTER_MODE);

			// count to next image and start from 0 when at the end
			image_idx += 1;
			image_idx %= 20;

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
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

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
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 50;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 2;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
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
/**
 *
 * @brief: TLCD INIT Implementation
 * @Param: Board Support Package
 *
 */
void user_interface_init(void)
{
	// Initialize LCD. Use functions from stm32f429i_discovery_lcd.h
	BSP_LCD_Init();

	// Initialize LCD Layer 1 (background layer) with FB address that points to layer 1
	BSP_LCD_LayerDefaultInit(LCD_LAYER_1, LCD_FRAME_BUFFER_LAYER1);

	// Select layer 1
	BSP_LCD_SelectLayer(LCD_LAYER_1);

	// Clear LCD (color red)
	BSP_LCD_Clear(LCD_COLOR_RED);

	// Set color keyring for layer 1 (color dark cyan)
	BSP_LCD_SetColorKeying(LCD_LAYER_1, LCD_COLOR_DARKCYAN);

	// Set layer 1 visibility to disabled
	BSP_LCD_SetLayerVisible(LCD_LAYER_1, DISABLE);

	// Initialize Layer 0 (foreground or visible layer) with FB address that points to layer 0
	BSP_LCD_LayerDefaultInit(LCD_LAYER_0, LCD_FRAME_BUFFER_LAYER0);

	// Select Layer 0
	BSP_LCD_SelectLayer(LCD_LAYER_0);

	// Switch LCD display on
	BSP_LCD_DisplayOn();

	HAL_Delay(200);

	// Clear the whole LCD with color lightcyan
	BSP_LCD_Clear(LCD_COLOR_LIGHTCYAN);

	HAL_Delay(100);

	printf("LCD initialization completed \r\n");
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
	BSP_LCD_DisplayStringAt(5,  255,  (uint8_t*) "NN OUTPUT: ", LEFT_MODE);

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
	BSP_LCD_DisplayStringAt(330, 291, (uint8_t*) "CLEAR", LEFT_MODE);

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
	// Initialize touch sensor to use a whole LCD area (240x320) and print to UART whether the initialization was successful or not
	if(BSP_TS_Init(240, 320) == TS_ERROR) {
		printf("Touch sensor initialization failed \r\n");
	} else{
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
