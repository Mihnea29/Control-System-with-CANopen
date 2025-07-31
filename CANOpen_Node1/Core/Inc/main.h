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
#include "stm32f7xx_hal.h"

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
void MX_I2C4_Init(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_RESET_Pin GPIO_PIN_15
#define LCD_RESET_GPIO_Port GPIOJ
#define TP_IRQ_Pin GPIO_PIN_13
#define TP_IRQ_GPIO_Port GPIOI
#define TP_IRQ_EXTI_IRQn EXTI15_10_IRQn
#define RENDER_TIME_Pin GPIO_PIN_7
#define RENDER_TIME_GPIO_Port GPIOC
#define VSYNC_FREQ_Pin GPIO_PIN_6
#define VSYNC_FREQ_GPIO_Port GPIOC
#define MCU_ACTIVE_Pin GPIO_PIN_6
#define MCU_ACTIVE_GPIO_Port GPIOF
#define FRAME_RATE_Pin GPIO_PIN_1
#define FRAME_RATE_GPIO_Port GPIOJ

/* USER CODE BEGIN Private defines */
// Pozitii
#define LED_LEFT_SIGNAL_BIT     0  // Bit 0: Semnalizare stanga
#define LED_RIGHT_SIGNAL_BIT    1  // Bit 1: Semnalizare dreapta
#define LED_HIGH_BEAM_BIT       2  // Bit 2: Faza Lunga
#define LED_FLASH_BIT           3  // Bit 3: Flash
#define LED_HEADLIGHT_BIT       4  // Bit 4: Faruri

// Masca
#define LED_LEFT_SIGNAL_MASK    (1 << LED_LEFT_SIGNAL_BIT)     // 0b00001
#define LED_RIGHT_SIGNAL_MASK   (1 << LED_RIGHT_SIGNAL_BIT)    // 0b00010
#define LED_HIGH_BEAM_MASK      (1 << LED_HIGH_BEAM_BIT)       // 0b00100
#define LED_FLASH_MASK          (1 << LED_FLASH_BIT)           // 0b01000
#define LED_HEADLIGHT_MASK      (1 << LED_HEADLIGHT_BIT)       // 0b10000
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
