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
#define red 0
#define yellow 1
#define green 2
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
	void display7SEG(int counter)
	{
		switch (counter){
		case 0:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, RESET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, RESET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, RESET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, SET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, SET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, SET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, SET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, SET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, RESET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, RESET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, SET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, RESET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, SET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, SET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, SET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, SET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, SET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, RESET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, SET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, RESET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, SET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, RESET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, SET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, RESET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, RESET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, RESET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, SET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, SET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, SET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, RESET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, RESET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, RESET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOA_GPIO_Port,GPIOA_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB_GPIO_Port,GPIOB_Pin, RESET);
			HAL_GPIO_WritePin(GPIOC_GPIO_Port,GPIOC_Pin, RESET);
			HAL_GPIO_WritePin(GPIOD_GPIO_Port,GPIOD_Pin, RESET);
			HAL_GPIO_WritePin(GPIOE_GPIO_Port,GPIOE_Pin, SET);
			HAL_GPIO_WritePin(GPIOF_GPIO_Port,GPIOF_Pin, RESET);
			HAL_GPIO_WritePin(GPIOG_GPIO_Port,GPIOG_Pin, RESET);

			break;
		}
	}

	void display7SEG2(int counter2)
		{
			switch (counter2){
			case 0:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, SET);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, SET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, SET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, SET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, SET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, SET);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, SET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, SET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, RESET);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, SET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, SET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, RESET);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, SET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, SET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, SET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, RESET);
				break;
			case 5:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, SET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, SET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, RESET);
				break;
			case 6:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, SET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, RESET);
				break;
			case 7:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, SET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, SET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, SET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, SET);
				break;
			case 8:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, RESET);
				break;
			case 9:
				HAL_GPIO_WritePin(GPIOA2_GPIO_Port,GPIOA2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB2_GPIO_Port,GPIOB2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOC2_GPIO_Port,GPIOC2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOD2_GPIO_Port,GPIOD2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOE2_GPIO_Port,GPIOE2_Pin, SET);
				HAL_GPIO_WritePin(GPIOF2_GPIO_Port,GPIOF2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOG2_GPIO_Port,GPIOG2_Pin, RESET);

				break;
			}
		}
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
int counter = 5;
int counter2 = 3;
int status = 0;
  while (1)
  {
	 switch (status){
		 case red:
			 if (counter == 5){
				 HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
				 HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
				 HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			 }
			 display7SEG(counter--);
			 display7SEG2(counter2--);

			 HAL_Delay(1000);

			 break;

		 case yellow:
			 if (counter < 2){
				 HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
				 HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			 }
			 break;

		 case green:
			 if (counter <3){}
			 break;
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
  HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIOA_Pin|GPIOB_Pin|GPIOC_Pin|GPIOD2_Pin
                          |GPIOE2_Pin|GPIOF2_Pin|GPIOG2_Pin|GPIOD_Pin
                          |GPIOE_Pin|GPIOF_Pin|GPIOG_Pin|GPIOA2_Pin
                          |GPIOB2_Pin|GPIOC2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED1_Pin YELLOW1_Pin GREEN1_Pin RED2_Pin
                           YELLOW2_Pin GREEN2_Pin */
  GPIO_InitStruct.Pin = RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
                          |YELLOW2_Pin|GREEN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : GPIOA_Pin GPIOB_Pin GPIOC_Pin GPIOD2_Pin
                           GPIOE2_Pin GPIOF2_Pin GPIOG2_Pin GPIOD_Pin
                           GPIOE_Pin GPIOF_Pin GPIOG_Pin GPIOA2_Pin
                           GPIOB2_Pin GPIOC2_Pin */
  GPIO_InitStruct.Pin = GPIOA_Pin|GPIOB_Pin|GPIOC_Pin|GPIOD2_Pin
                          |GPIOE2_Pin|GPIOF2_Pin|GPIOG2_Pin|GPIOD_Pin
                          |GPIOE_Pin|GPIOF_Pin|GPIOG_Pin|GPIOA2_Pin
                          |GPIOB2_Pin|GPIOC2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
