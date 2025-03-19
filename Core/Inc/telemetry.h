/*
 * telemetry.h
 *
 *  Created on: Oct 1, 2023
 *      Author: vasil
 */

#ifndef INC_TELEMETRY_H_
#define INC_TELEMETRY_H_

#include "stm32f1xx_hal.h"

//#include "sx126x_conf.h"


//#include "main.h"	//for SPI config struct

extern SPI_HandleTypeDef hspi1;

#define LORA_RESET_Pin GPIO_PIN_13
#define LORA_RESET_GPIO_Port GPIOC
#define LORA_BUSY_Pin GPIO_PIN_14
#define LORA_BUSY_GPIO_Port GPIOC
#define RX_SWITCH_LORA_Pin GPIO_PIN_15
#define RX_SWITCH_LORA_GPIO_Port GPIOC
#define TX_SWITCH_LORA_Pin GPIO_PIN_0
#define TX_SWITCH_LORA_GPIO_Port GPIOB
#define SPI_NSS_LORA_Pin GPIO_PIN_4
#define SPI_NSS_LORA_GPIO_Port GPIOA
#define SPI_SCK_LORA_Pin GPIO_PIN_5
#define SPI_SCK_LORA_GPIO_Port GPIOA
#define SPI_MISO_LORA_Pin GPIO_PIN_6
#define SPI_MISO_LORA_GPIO_Port GPIOA
#define SPI_MOSI_LORA_Pin GPIO_PIN_7
#define SPI_MOSI_LORA_GPIO_Port GPIOA
#define LED1_LORA_Pin GPIO_PIN_1
#define LED1_LORA_GPIO_Port GPIOB
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

/*
 * setupTelemetry:
 * This function sets up the SX1262 registers and other settings necessary on startup
 * May need to add parameters
 * Returns error code (0 for no error)
 */
int setupTelemetry();

/*
 * sendData:
 * This function sets the TX pin, resets the RX pin, writes data to the buffer and sends it
 * Returns error code
 */
int sendData(char* data);

/*
 * receiveData:
 * This function sets the RX pin, resets the TX pin, and receives data into the buffer
 * Changes the data string and returns an error code
 */
int receiveData(char* data);

#endif /* INC_TELEMETRY_H_ */
