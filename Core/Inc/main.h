/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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
#define CAN_TERM_Pin GPIO_PIN_14
#define CAN_TERM_GPIO_Port GPIOC
#define VBUS_Pin GPIO_PIN_0
#define VBUS_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOC
#define CAN_SHDN_Pin GPIO_PIN_11
#define CAN_SHDN_GPIO_Port GPIOC
#define ENC_A_Pin GPIO_PIN_6
#define ENC_A_GPIO_Port GPIOB
#define ENC_A_EXTI_IRQn EXTI9_5_IRQn
#define ENC_B_Pin GPIO_PIN_7
#define ENC_B_GPIO_Port GPIOB
#define ENC_B_EXTI_IRQn EXTI9_5_IRQn
#define ENC_Z_Pin GPIO_PIN_8
#define ENC_Z_GPIO_Port GPIOB
#define ENC_Z_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
