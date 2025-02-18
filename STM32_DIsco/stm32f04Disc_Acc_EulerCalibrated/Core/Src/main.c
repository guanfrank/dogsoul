/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LIS3DSH.h"
#include <stdio.h>
#include <math.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t LEDS[3][3] = {
	{GPIO_PIN_SET,  GPIO_PIN_RESET,GPIO_PIN_RESET},
	{GPIO_PIN_RESET,GPIO_PIN_SET,  GPIO_PIN_RESET},
	{GPIO_PIN_RESET,GPIO_PIN_RESET,GPIO_PIN_SET}};
int balance(int ind);

float accX = 0.0;
float accY = 0.0;
float accZ = 0.0;

float accRoll = 0.0;
float accPitch = 0.0;

float rollCal = 0;
float pitchCal = 0;

LIS3DSH_DataScaled acc;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void EulerAngleCalibration(int N);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */

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
	const uint8_t UART_BUF_MAX = 30;
	uint8_t buf[UART_BUF_MAX];
	HAL_StatusTypeDef ret;
	LIS3DSH_InitTypeDef accConfigDef;
	GPIO_PinState state; // Define a enum struct which contain boolean states
	enum DIRS {FRONT = 0, BACK, STOP};

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
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  accConfigDef.dataRate = LIS3DSH_DATARATE_3_125; /* 3.125 Hz Normal Mode */
  accConfigDef.fullScale = LIS3DSH_FULLSCALE_16;   /* 16 g  */
  accConfigDef.enableAxes = LIS3DSH_XYZ_ENABLE;
  accConfigDef.antiAliasingBW = LIS3DSH_FILTER_BW_50;  /* 50 Hz  */
  accConfigDef.interruptEnable = false;
  LIS3DSH_Init(&hspi1, &accConfigDef);

  EulerAngleCalibration(100);

  /* USER CODE END 2 */
//  LIS3DSH_X_calibrate(-1000.0, 980.0);
//  LIS3DSH_Y_calibrate(-1020.0, 1040.0);
//  LIS3DSH_Z_calibrate(-920.0, 1040.0);
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //PD_14 -Red, PD_15 Blue  PD_12 green
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    if(LIS3DSH_PollDRDY(1000)){
    	acc = LIS3DSH_GetDataScaled();
    	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);

    	accX = acc.x;
    	accY = acc.y;
    	accZ = acc.z;

    	// Acceleration vector angle
    	accRoll = atan2(accZ, accY) * 180.0 / M_PI - rollCal;
    	accPitch = -atan2(accZ, accX) * 180.0 / M_PI - pitchCal;

    	if(acc.x > 0.1f) {//move up/back - red
    		balance(0);
    	}else if(acc.x < -0.1f) {//move down/front - green
    		balance(1);
		}else {//no move - blue
			balance(2);
		}
    	// ret = HAL_UART_Transmit(&huart3, buf, strlen((char*)buf), HAL_MAX_DELAY);
    	// if(ret != HAL_OK) {
    	// 	strcpy((char*)buf, "Error Tx:%d\r\n");}
    }
    state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0); // read state of push button and save it in "state" variable
	// if state is high, run another Euler angle calibration
	if(state) {
		EulerAngleCalibration(100);
	}
  }
  /* USER CODE END 3 */
}

void EulerAngleCalibration(int N)
{
	// Display message
	printf("Calibrating accelerator with %d points. Do not move!\r\n", N);

	int counter = 0;
	// Take N readings for each coordinate and add to itself
	for(int i=0;i<N;i++) {
	    if(LIS3DSH_PollDRDY(1000)){
	    	// collect accelerator data
	    	acc = LIS3DSH_GetDataScaled();
	    	accX = acc.x;
	    	accY = acc.y;
	    	accZ = acc.z;
	    	// Acceleration vector angle
	    	rollCal += atan2(accZ, accY) * 180.0 / M_PI;
	    	pitchCal += -atan2(accZ, accX) * 180.0 / M_PI;
	    }
	    // Flash LEDs to reflect euler angles calibration
	    counter = i % 3;
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, LEDS[counter][0]);//red
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, LEDS[counter][1]);//green
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, LEDS[counter][2]);//blue
	}

	// Find average offset value
	rollCal /= N;
	pitchCal /= N;

	// Display message
	printf("Calibration complete\r\n");
	printf("\tRoll Cal offset: %.2f\r\n", rollCal);
	printf("\tPitch Cal offset: %.2f\r\n", pitchCal);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
 hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(MEMS_CS_GPIO_Output_GPIO_Port, MEMS_CS_GPIO_Output_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LED_Green_Pin|LED_Orange_Pin|LED_Red_Pin|LED_Blue_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : MEMS_CS_GPIO_Output_Pin */
  GPIO_InitStruct.Pin = MEMS_CS_GPIO_Output_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(MEMS_CS_GPIO_Output_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_Green_Pin LED_Orange_Pin LED_Red_Pin LED_Blue_Pin */
  GPIO_InitStruct.Pin = LED_Green_Pin|LED_Orange_Pin|LED_Red_Pin|LED_Blue_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PE0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

int balance(int ind) {
	//sprintf((char*)buf, "#AccXYZ:%5.2f,%5.2f,%5.2f\r\n", acc.x, acc.y, acc.z);
	HAL_StatusTypeDef ret;
	if(ind < 0 || ind >3) return -1;
	if(ind == 0) {//move front
		printf("F\n");
		ret = HAL_UART_Transmit(&huart3, "F", 1, HAL_MAX_DELAY);
		if(ret != HAL_OK) 	printf("Error Tx:%d\r\n", ret);
	}else if(ind == 1) {//move back
		printf("B\n");
		ret = HAL_UART_Transmit(&huart3, "B", 1, HAL_MAX_DELAY);
		if(ret != HAL_OK) {
		   printf("Error Tx:%d\r\n", ret);}
	}else if(ind == 2) {//stop
		printf("A\n");
		ret = HAL_UART_Transmit(&huart3, "A", 1, HAL_MAX_DELAY);
		if(ret != HAL_OK) {
		   printf("Error Tx:%d\r\n", ret);}
	}
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, LEDS[ind][0]);//red
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, LEDS[ind][1]);//green
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, LEDS[ind][2]);//blue
	return 0;
}

int _write(int file, char *ptr, int len){
	int DataIdx;
	for(DataIdx=0;DataIdx<len;DataIdx++) {
		ITM_SendChar(*ptr++);
	}
	return len;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
