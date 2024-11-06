/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED1_Pin GPIO_PIN_2
#define RED1_GPIO_Port GPIOA
#define YELLOW1_Pin GPIO_PIN_3
#define YELLOW1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_4
#define GREEN1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_5
#define RED2_GPIO_Port GPIOA
#define YELLOW2_Pin GPIO_PIN_6
#define YELLOW2_GPIO_Port GPIOA
#define GREEN2_Pin GPIO_PIN_7
#define GREEN2_GPIO_Port GPIOA
#define SEGA1_Pin GPIO_PIN_0
#define SEGA1_GPIO_Port GPIOB
#define SEGB1_Pin GPIO_PIN_1
#define SEGB1_GPIO_Port GPIOB
#define SEGC1_Pin GPIO_PIN_2
#define SEGC1_GPIO_Port GPIOB
#define SEGD2_Pin GPIO_PIN_10
#define SEGD2_GPIO_Port GPIOB
#define SEGE2_Pin GPIO_PIN_11
#define SEGE2_GPIO_Port GPIOB
#define SEGF2_Pin GPIO_PIN_12
#define SEGF2_GPIO_Port GPIOB
#define SEGG2_Pin GPIO_PIN_13
#define SEGG2_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_9
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_10
#define EN1_GPIO_Port GPIOA
#define BUT0_Pin GPIO_PIN_13
#define BUT0_GPIO_Port GPIOA
#define BUT1_Pin GPIO_PIN_14
#define BUT1_GPIO_Port GPIOA
#define BUT2_Pin GPIO_PIN_15
#define BUT2_GPIO_Port GPIOA
#define SEGD1_Pin GPIO_PIN_3
#define SEGD1_GPIO_Port GPIOB
#define SEGE1_Pin GPIO_PIN_4
#define SEGE1_GPIO_Port GPIOB
#define SEGF1_Pin GPIO_PIN_5
#define SEGF1_GPIO_Port GPIOB
#define SEGG1_Pin GPIO_PIN_6
#define SEGG1_GPIO_Port GPIOB
#define SEGA2_Pin GPIO_PIN_7
#define SEGA2_GPIO_Port GPIOB
#define SEGB2_Pin GPIO_PIN_8
#define SEGB2_GPIO_Port GPIOB
#define SEGC2_Pin GPIO_PIN_9
#define SEGC2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
