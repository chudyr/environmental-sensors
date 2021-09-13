/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f0xx_hal.h"

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
#define PWR_ON_BUZZER_Pin GPIO_PIN_1
#define PWR_ON_BUZZER_GPIO_Port GPIOF
#define OLED_DC_Pin GPIO_PIN_2
#define OLED_DC_GPIO_Port GPIOA
#define OLED_RST_Pin GPIO_PIN_3
#define OLED_RST_GPIO_Port GPIOA
#define OLED_CS_Pin GPIO_PIN_4
#define OLED_CS_GPIO_Port GPIOA
#define OLED_CLK_Pin GPIO_PIN_5
#define OLED_CLK_GPIO_Port GPIOA
#define OLED_DATA_Pin GPIO_PIN_7
#define OLED_DATA_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_2
#define LED_1_GPIO_Port GPIOB
#define PWR_ON_OLED_Pin GPIO_PIN_12
#define PWR_ON_OLED_GPIO_Port GPIOB
#define CO2_RDY_Pin GPIO_PIN_15
#define CO2_RDY_GPIO_Port GPIOB
#define CO2_RDY_EXTI_IRQn EXTI4_15_IRQn
#define PWR_ON_SPS30_Pin GPIO_PIN_11
#define PWR_ON_SPS30_GPIO_Port GPIOA
#define PWR_ON_CO2_Pin GPIO_PIN_12
#define PWR_ON_CO2_GPIO_Port GPIOA
#define ENCODER_SW_Pin GPIO_PIN_3
#define ENCODER_SW_GPIO_Port GPIOB
#define ENCODER_SW_EXTI_IRQn EXTI2_3_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
