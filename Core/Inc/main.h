/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#include "gps.h"
#include "telemetry.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
//SPI_HandleTypeDef hspi1;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LORA_RESET_Pin GPIO_PIN_13
#define LORA_RESET_GPIO_Port GPIOC
#define LORA_BUSY_Pin GPIO_PIN_14
#define LORA_BUSY_GPIO_Port GPIOC
#define RX_SWITCH_LORA_Pin GPIO_PIN_15
#define RX_SWITCH_LORA_GPIO_Port GPIOC
#define UART_TX_USB_Pin GPIO_PIN_2
#define UART_TX_USB_GPIO_Port GPIOA
#define UART_RX_USB_Pin GPIO_PIN_3
#define UART_RX_USB_GPIO_Port GPIOA
#define SPI_NSS_LORA_Pin GPIO_PIN_4
#define SPI_NSS_LORA_GPIO_Port GPIOA
#define SPI_SCK_LORA_Pin GPIO_PIN_5
#define SPI_SCK_LORA_GPIO_Port GPIOA
#define SPI_MISO_LORA_Pin GPIO_PIN_6
#define SPI_MISO_LORA_GPIO_Port GPIOA
#define SPI_MOSI_LORA_Pin GPIO_PIN_7
#define SPI_MOSI_LORA_GPIO_Port GPIOA
#define TX_SWITCH_LORA_Pin GPIO_PIN_0
#define TX_SWITCH_LORA_GPIO_Port GPIOB
#define LED1_LORA_Pin GPIO_PIN_1
#define LED1_LORA_GPIO_Port GPIOB
#define LED3_GPS_Pin GPIO_PIN_10
#define LED3_GPS_GPIO_Port GPIOB
#define LED2_GPS_Pin GPIO_PIN_11
#define LED2_GPS_GPIO_Port GPIOB
#define LED1_GPS_Pin GPIO_PIN_12
#define LED1_GPS_GPIO_Port GPIOB
#define LNA_EN_GPS_Pin GPIO_PIN_13
#define LNA_EN_GPS_GPIO_Port GPIOB
#define RESET_N_GPS_Pin GPIO_PIN_14
#define RESET_N_GPS_GPIO_Port GPIOB
#define EXTINT_GPS_Pin GPIO_PIN_15
#define EXTINT_GPS_GPIO_Port GPIOB
#define D_SEL_GPS_Pin GPIO_PIN_8
#define D_SEL_GPS_GPIO_Port GPIOA
#define UART_TX_GPS_Pin GPIO_PIN_9
#define UART_TX_GPS_GPIO_Port GPIOA
#define UART_RX_GPS_Pin GPIO_PIN_10
#define UART_RX_GPS_GPIO_Port GPIOA
#define CANRX_Pin GPIO_PIN_11
#define CANRX_GPIO_Port GPIOA
#define CANTX_Pin GPIO_PIN_12
#define CANTX_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define LED_CAN_Pin GPIO_PIN_15
#define LED_CAN_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define USB_RST_Pin GPIO_PIN_4
#define USB_RST_GPIO_Port GPIOB
#define LED3_LORA_Pin GPIO_PIN_5
#define LED3_LORA_GPIO_Port GPIOB
#define LED2_LORA_Pin GPIO_PIN_6
#define LED2_LORA_GPIO_Port GPIOB
#define DIO3_LORA_Pin GPIO_PIN_7
#define DIO3_LORA_GPIO_Port GPIOB
#define DIO2_LORA_Pin GPIO_PIN_8
#define DIO2_LORA_GPIO_Port GPIOB
#define DIO1_LORA_Pin GPIO_PIN_9
#define DIO1_LORA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
