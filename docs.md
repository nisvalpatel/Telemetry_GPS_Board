# Documentation
hello world aaaaaaaaaa
This page is created  to give you a brief overview, as well as document the current progress of the Telemetry project, written specifically for the STM32 microcontroller.
lllll
The purpose of this firmware is to effectively manage the telemetry aspect of the car. This involves facilitating the transmission and reception of messages. These capabilities are essential for ensuring seamless communication, which is critical for the functioning of various systems within the car. The firmware is a vital component in the telemetry system and has been meticulously designed to handle a wide range of tasks related to telemetry efficiently and reliably.

*This firmware consists of 2 main code files we only make changes to :*
  - ```main.c``` : Handles the key functions, and calls the functions that are written in the telemetry.c file
    ```telemetry.c``` : Includes the helper functions to do specific main  HAL functions like read write, send, and receive. [Most of the functions written are based on the ```sx126x.c``` functions


The main components of the two main code files are included for clarity. Key functions are described in detail below.

NOTE:
Most of the code written for this was referred from the code that was specifically written for the older telemetry hardware, which was also known to have some bugs when sending and receiving data.
## ```main.c```:

The section below is a key component of this program. It operates in an infinite loop, meaning it continues to function as long as the code is running.

```c
/* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  uint16_t address = 0x0385;
	  uint8_t size = 1;
	  uint8_t in[size];
	  uint8_t out[size];
	  in[0] = 'a';
	  sx126x_write_register(0 ,address ,in ,size );
	  sx126x_read_register(0 ,address ,out ,size );
	  for(int i = 0; i < size; i++){
		  if(in[i] == out[i]) {
			  HAL_GPIO_WritePin(LED1_LORA_GPIO_Port,LED1_LORA_Pin, GPIO_PIN_SET);
			  HAL_Delay(100);
			  HAL_GPIO_WritePin(LED1_LORA_GPIO_Port,LED1_LORA_Pin, GPIO_PIN_RESET);
			  HAL_Delay(100);
		  }
		  else{
			  HAL_GPIO_WritePin(LED2_GPS_GPIO_Port,LED2_GPS_Pin, GPIO_PIN_SET);
			  HAL_Delay(1000);
			  HAL_GPIO_WritePin(LED2_GPS_GPIO_Port,LED2_GPS_Pin, GPIO_PIN_RESET);
			  HAL_Delay(1000);
		  }
	  }
  }
  /* USER CODE END 3 */
}
```

### Current Progress:

We are currently testing and debugging the send and receive features of the telemetry program, by attempting to send and receive the letter  `‘a’`

### Current problems:

```LORA_BUSY``` pin is always high when the code is ran, inhibiting us from being able to actually write and send data (use SPI)

Possible solutions [Not tried yet]:
Adjust some of the parameters to match the clock's frequency in the ```.ioc``` file

## ```telemetry.c```:

```
/*
 * setupTelemetry:
 * This function sets up the SX1262 registers and other settings necessary on startup
 * May need to add parameters
 * Returns error code (0 for no error)
 */
int setupTelemetry()
{
	return 0;
}

/*
 * sendData:
 * This function sets the TX pin, resets the RX pin, writes data to the buffer and sends it
 * Returns error code
 */
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

/*
 * receiveData:
 * This function sets the RX pin, resets the TX pin, and receives data into the buffer
 * Changes the data string and returns an error code
 */
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
```
