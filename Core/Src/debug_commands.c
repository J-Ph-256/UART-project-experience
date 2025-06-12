#include "stm32f4xx_hal_uart.h"
#include <string.h>

static const char LED_RED[]="LED RED";

static const char LED_BLUE[]="LED BLUE";

static const char LED_GREEN[]="LED GREEN";

void LED_RED(UART):
		HAL_GPIO_TogglePin(LD1_GPIO_Port,LD1_Pin);
		HAL_UART_Transmit(UART,"UNDERSTOOD");
void LED_BLUE(UART)
		HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
		HAL_UART_Transmit(UART,"UNDERSTOOD");
void LED_GREEN(UART):
		HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin);
		HAL_UART_Transmit(UART,"UNDERSTOOD");



void execute_command(char command[],UART_HandleTypeDef UARTHANDLE):
		if (strcmp(LED_RED,command)==0) LED_RED(UARTHANDLE);
		else if (strcmp(LED_BLUE,command)==0) LED_BLUE(UART_HandleTypeDef);
		else if (strcmp(LED_GREEN,command)==0) LED_GREEN(UART_HandleTypeDef);
