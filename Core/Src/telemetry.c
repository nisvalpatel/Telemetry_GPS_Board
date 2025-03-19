/*
 * telemetry.c
 *
 *  Created on: Oct 1, 2023
 *      Author: vasil
 */
#include "telemetry.h"
#include <stdlib.h>

#include "sx126x.h"
#include "sx126x_regs.h"
#include "sx126x_hal.h"

int setupTelemetry() //RX_SWITCH_LORA_Pin gets passed in to check whether it transmits or receives
{
	return 0;
}

int sendData(char* data)
{
	HAL_GPIO_WritePin(TX_SWITCH_LORA_GPIO_Port, TX_SWITCH_LORA_Pin, 1);
	HAL_GPIO_WritePin(RX_SWITCH_LORA_GPIO_Port, RX_SWITCH_LORA_Pin, 0);
	sx126x_set_tx(0,0);
	void* buffer = &(*data);
	uint8_t size = sizeof(*(data))/sizeof(char);
	uint8_t offset = 0;
	sx126x_write_buffer(0,offset,(uint8_t*)buffer,size);
	return 0;
}

int receiveData(char* data)
{
	HAL_GPIO_WritePin(TX_SWITCH_LORA_GPIO_Port, TX_SWITCH_LORA_Pin, 0);
	HAL_GPIO_WritePin(RX_SWITCH_LORA_GPIO_Port, RX_SWITCH_LORA_Pin, 1);
	sx126x_set_rx(0,0);
	void* buffer = &(*data);
	uint8_t size = sizeof(*(data)/sizeof(char));
	uint8_t offset = 0;
	sx126x_read_buffer(0,offset,(uint8_t*)buffer,size);
	return 0;
}

sx126x_hal_status_t sx126x_hal_write(const void* context, const uint8_t* command, const uint16_t command_length,
                                      const uint8_t* data, const uint16_t data_length)
{
	//uint8_t BUFFER_SIZE = command_length + data_length;
	uint8_t* txData = (uint8_t*)malloc(sizeof(uint8_t) * (command_length + data_length));
	HAL_StatusTypeDef status;

	for (int i = 0; i < command_length; i++)
	{
		txData[i] = command[i];
	}

	for (int i = 0; i < data_length; i++)
	{
		txData[i+command_length] = data[i];
	}

	while(HAL_GPIO_ReadPin(LORA_BUSY_GPIO_Port, LORA_BUSY_Pin));	//wait for BUSY pin to become 0, while BUSY is 1 we cannot use SPI

	/**
	* data_length might also be BUFFER_SIZE
	*/
	HAL_GPIO_WritePin(SPI_NSS_LORA_GPIO_Port, SPI_NSS_LORA_Pin, 0);
	status = HAL_SPI_Transmit(&hspi1, txData, command_length + data_length, (uint32_t)0);
	HAL_GPIO_WritePin(SPI_NSS_LORA_GPIO_Port, SPI_NSS_LORA_Pin, 1);
	free(txData);

	if(status == HAL_OK)
			return SX126X_HAL_STATUS_OK;
		return SX126X_HAL_STATUS_ERROR;
}

sx126x_hal_status_t sx126x_hal_read(const void* context, const uint8_t* command, const uint16_t command_length,
                                     uint8_t* data, const uint16_t data_length)
{
	uint8_t* MISOData = (uint8_t*)malloc(sizeof(uint8_t) * (command_length+data_length));
	uint8_t* cmd = (uint8_t*)malloc(sizeof(uint8_t) * (command_length+data_length));
	HAL_StatusTypeDef status;

	for(int i = 0;i < command_length;i++)
	{
		cmd[i] = command[i];
	}

	while(HAL_GPIO_ReadPin(LORA_BUSY_GPIO_Port, LORA_BUSY_Pin));	//wait for BUSY pin to become 0, while BUSY is 1 we cannot use SPI

	HAL_GPIO_WritePin(SPI_NSS_LORA_GPIO_Port, SPI_NSS_LORA_Pin, 0);
	status = HAL_SPI_TransmitReceive(&hspi1, cmd, MISOData, command_length + data_length, (uint32_t)0x0);	//could be 0xFFFFFF
	HAL_GPIO_WritePin(SPI_NSS_LORA_GPIO_Port, SPI_NSS_LORA_Pin, 1);
	for(int i = 0; i < data_length; i++)
	{
		data[i] = MISOData[i+command_length];
	}

	free(MISOData);

	if(status == HAL_OK)
		return SX126X_HAL_STATUS_OK;
	return SX126X_HAL_STATUS_ERROR;
}

sx126x_hal_status_t sx126x_hal_reset(const void* context)
{
	HAL_GPIO_WritePin(LORA_RESET_GPIO_Port, LORA_RESET_Pin, GPIO_PIN_RESET);
	//TODO: check how long to send reset signal for
	HAL_Delay(1);	//needs 100 microseconds
	HAL_GPIO_WritePin(LORA_RESET_GPIO_Port, LORA_RESET_Pin, GPIO_PIN_SET);

	return SX126X_HAL_STATUS_OK;
}

sx126x_hal_status_t sx126x_hal_wakeup(const void* context)
{
	return SX126X_HAL_STATUS_OK;
}
