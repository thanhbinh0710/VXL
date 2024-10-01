/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define GPIO_PORT GPIOB
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1,2,3,4};

int timer0_counter = 0;
int timer0_flag = 1;
int timer1_counter = 0;
int timer1_flag = 1;
int timer2_counter = 0;
int timer2_flag = 1;
int TIMER_CYCLE = 10;

const uint8_t MatrixCol[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
GPIO_TypeDef * RowPort[8] = {Row0_GPIO_Port,Row1_GPIO_Port,Row2_GPIO_Port,Row3_GPIO_Port,Row4_GPIO_Port,Row5_GPIO_Port,Row6_GPIO_Port,Row7_GPIO_Port};
const uint16_t RowPin[8] = {Row0_Pin,Row1_Pin,Row2_Pin,Row3_Pin,Row4_Pin,Row5_Pin,Row6_Pin,Row7_Pin};
GPIO_TypeDef * ColPort[8] = {Enm0_GPIO_Port,Enm1_GPIO_Port,Enm2_GPIO_Port,Enm3_GPIO_Port,Enm4_GPIO_Port,Enm5_GPIO_Port,Enm6_GPIO_Port,Enm7_GPIO_Port};
const uint16_t ColPin[8] = {Enm0_Pin,Enm1_Pin,Enm2_Pin,Enm3_Pin,Enm4_Pin,Enm5_Pin,Enm6_Pin,Enm7_Pin};
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0xff, 0x80, 0x77, 0x77, 0x77, 0x77, 0x80, 0xff};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int hour, int minute);
void setTimer0 (int duration);
void setTimer1 (int duration);
void setTimer2 (int duration);
void timer_run();
void displayLEDMatrix (int num);
void MatrixColLed (int num);
void updateLEDMatrix(int index);
void updateMatrixBuffer();
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  HAL_GPIO_WritePin(Dot_GPIO_Port,Dot_Pin, RESET);
  int hour = 15, minute =  59, second = 57;
//  setTimer0(100);
//  int duration = 1000;
//  updateClockBuffer(hour, minute);
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
	if (timer0_flag == 1){
		updateMatrixBuffer();
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		HAL_GPIO_TogglePin(Dot_GPIO_Port, Dot_Pin);
		second++;
	  	 if (second >= 60) {
	  		 second = 0;
	  		 minute ++;
	  	 }
	  	 if(minute >= 60) {
	  		 minute = 0;
	  		 hour ++;
	  	 }
	  	 if(hour >=24){
	  		 hour = 0;
	  	 }
	  	  updateClockBuffer(hour, minute);
	  	  updateMatrixBuffer();
	  	  setTimer0(1000);
	}
	if (timer1_flag == 1){
		update7SEG(index_led++);
		updateMatrixBuffer();
		index_led = (index_led < MAX_LED) ? index_led : 0;
		setTimer1(500);
	}
	if (timer2_flag == 1){
		setTimer2(10);
		if(index_led_matrix >= 8) index_led_matrix = 0;
		updateLEDMatrix(index_led_matrix++);
	}
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Enm0_Pin|Enm1_Pin|Dot_Pin|LED_Pin
                          |En0_Pin|En1_Pin|En2_Pin|En3_Pin
                          |Enm2_Pin|Enm3_Pin|Enm4_Pin|Enm5_Pin
                          |Enm6_Pin|Enm7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|Row2_Pin
                          |Row3_Pin|Row4_Pin|Row5_Pin|Row6_Pin
                          |Row7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|Row0_Pin|Row1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Enm0_Pin Enm1_Pin Dot_Pin LED_Pin
                           En0_Pin En1_Pin En2_Pin En3_Pin
                           Enm2_Pin Enm3_Pin Enm4_Pin Enm5_Pin
                           Enm6_Pin Enm7_Pin */
  GPIO_InitStruct.Pin = Enm0_Pin|Enm1_Pin|Dot_Pin|LED_Pin
                          |En0_Pin|En1_Pin|En2_Pin|En3_Pin
                          |Enm2_Pin|Enm3_Pin|Enm4_Pin|Enm5_Pin
                          |Enm6_Pin|Enm7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin Row2_Pin
                           Row3_Pin Row4_Pin Row5_Pin Row6_Pin
                           Row7_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin Row0_Pin Row1_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|Row2_Pin
                          |Row3_Pin|Row4_Pin|Row5_Pin|Row6_Pin
                          |Row7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|Row0_Pin|Row1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//const unsigned int Default = 100;
//int counter = Default;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	timer_run();
}

void display7SEG(int num){
	switch (num){
	case 0:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
	case 1:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
	case 2:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
	case 3:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
	case 4:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
	case 5:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
	case 6:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
	case 7:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
	case 8:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
	case 9:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
	default:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
	}
}

void update7SEG(int index){
	switch (index){
	case 0:
		display7SEG(led_buffer[0]);
		HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, RESET);
		HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, SET);
		HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, SET);
		HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, SET);
		break;
	case 1:
		display7SEG(led_buffer[1]);
		HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, SET);
		HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, RESET);
		HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, SET);
		HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, SET);
		break;
	case 2:
		display7SEG(led_buffer[2]);
		HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, SET);
		HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, SET);
		HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, RESET);
		HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, SET);
		break;
	case 3:
		display7SEG(led_buffer[3]);
		HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, SET);
		HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, SET);
		HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, SET);
		HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, SET);
		HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, SET);
		HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, SET);
		HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, SET);
		break;
	}
}

void updateClockBuffer(int hour, int minute){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}



void setTimer0 (int duration){
	timer0_counter = duration /TIMER_CYCLE;
	timer0_flag = 0;
}

void setTimer1 (int duration){
	timer1_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2 (int duration)
{
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}

void timer_run(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter == 0) timer0_flag = 1;
	}
	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter == 0) timer1_flag = 1;
	}
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter == 0) timer2_flag = 1;
	}
}



void displayLEDMatrix (int num){
	for (int i = 0; i < MAX_LED_MATRIX; i++){
		HAL_GPIO_WritePin(RowPort[i], RowPin[i], (matrix_buffer[num] >> i) & 0x01);
	}
}

void MatrixColLed (int num){
	for (int i = 0; i < MAX_LED_MATRIX; i++){
		HAL_GPIO_WritePin(ColPort[i], ColPin[i], (MatrixCol[num] >> i) & 0x01);
	}
}

void updateLEDMatrix(int index){
	switch (index){
	 case 0:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 case 1:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 case 2:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 case 3:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 case 4:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 case 5:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 case 6:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 case 7:
		 MatrixColLed(index);
		 displayLEDMatrix(index);
		 break;
	 default:
		 break;
	}
}

void updateMatrixBuffer(){
		matrix_buffer[7] = matrix_buffer[0];
		for (int i = 0; i < 7; i++){
			matrix_buffer[i] = matrix_buffer[i+1];
		}
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
