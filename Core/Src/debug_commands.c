#include "stm32f4xx_hal_uart.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>

static const char LED_RED[]="LED RED";
static const char LED_BLUE[]="LED BLUE";
static const char LED_GREEN[]="LED GREEN";
static const char RNG_CALL[]="RNG:";

void LED_RED_RESP(UART_HandleTypeDef* UART){
		HAL_GPIO_TogglePin(LD1_GPIO_Port,LD1_Pin);
		HAL_UART_Transmit(UART,&LED_RED,len(LED_RED),5);
}
void LED_BLUE_RESP(UART_HandleTypeDef* UART)
{
		HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
		HAL_UART_Transmit(UART,&LED_RED,len(LED_RED),5);
}
void LED_GREEN_RESP(UART_HandleTypeDef* UART)
{
		HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin);
		HAL_UART_Transmit(UART,&LED_RED,len(LED_RED),5);
}
void RNG_CALL_RESP(UART_HandleTypeDef* UART,number)
{
	return;
}


void execute_command(char* command[],UART_HandleTypeDef * UARTHANDLE)
{
		if (strcmp(LED_RED,command)==0) LED_RED_RESP(UARTHANDLE);
		else if (strcmp(LED_BLUE,command)==0) LED_BLUE_RESP(UARTHANDLE);
		else if (strcmp(LED_GREEN,command)==0) LED_GREEN_RESP(UARTHANDLE);
		else if (strncmp(RNG_CALL,command,sizeof(RNG_CALL)/sizeof(char))==0)RNG_CALL_ESP(UARTHANDLE,atoi(command[strlen(RNG_CALL)]));
		else HAL_UART_Transmit(UARTHANDLE,command,strlen(command),5);
}
