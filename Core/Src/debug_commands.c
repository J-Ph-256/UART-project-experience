#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char LED_RED[]="LED RED";

static const char LED_BLUE[]="LED BLUE";

static const char LED_GREEN[]="LED GREEN";

static const char RNG_CALL[]="RNG:";

static const char PARTY_TIME[]="PARTY";

static const char COUNTING[]="COUNT UP";

static const char COUNTING_DOWN[]="COUNT DOWN";

static const char WAVE[]="WAVE";

static const char RETURN[]="RETURN";

static const char GET_MODE[]="GET MODE";

static const char INVERT[]="INVERT";

static const char RESP[]="UNDERSTOOD\n";


void LED_GREEN_RESP(UART_HandleTypeDef* UART){
		HAL_GPIO_TogglePin(LD1_GPIO_Port,LD1_Pin);
		HAL_UART_Transmit(UART,&RESP,strlen(RESP),5);
}

void LED_BLUE_RESP(UART_HandleTypeDef* UART)
{
		HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
		HAL_UART_Transmit(UART,&RESP,strlen(RESP),5);
}

void LED_RED_RESP(UART_HandleTypeDef* UART)
{
		HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin);
		HAL_UART_Transmit(UART,&RESP,strlen(RESP),5);
}
void RNG_CALL_RESP(UART_HandleTypeDef* UART,int number,RNG_HandleTypeDef* hrng)
{
	uint32_t result;
	char response[64];
	HAL_RNG_GenerateRandomNumber(hrng,&result);
	result=result%number;
	result++;
	sprintf(&response,"RNG is %lu\n",result);
	if (result==number) sprintf(&response,"RNG is %lu, Wow lucky!!\n",result);
	if (result==1) sprintf(&response,"RNG is %lu. That's rough.\n",result);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}

void PARTY_MODE_CHANGE(UART_HandleTypeDef* UART,int *MODE)
{
	*MODE=PARTY_MODE;
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}

void COUNTING_MODE_CHANGE(UART_HandleTypeDef* UART,int *MODE)
{
	*MODE=COUNTING_MODE;
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}

void COUNTING_DOWN_MODE_CHANGE(UART_HandleTypeDef* UART,int *MODE)
{
	*MODE=COUNTING_DOWN_MODE;
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}

void NORMAL_MODE_CHANGE(UART_HandleTypeDef* UART,int *MODE)
{
	*MODE=MAIN_MODE;
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}
void WAVE_MODE_CHANGE(UART_HandleTypeDef* UART,int *MODE)
{
	*MODE=WAVE_MODE;
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}
void INVERT_MODE_CHANGE(UART_HandleTypeDef* UART,int *MODE)
{
	*MODE=INVERT_MODE;
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}

void SINE_MODE(UART_HandleTypeDef* UART,int *MODE)
{
	*MODE=SINE_WAVE_MODE;
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}


void SEND_CURRENT_MODE(UART_HandleTypeDef* UART,int *MODE)
{
	char response[64];
	sprintf(&response,"MODE is %i\n",*MODE);
	HAL_UART_Transmit(UART,&response,strlen(response),5);
}

void execute_command(char* command[],UART_HandleTypeDef * UARTHANDLE, RNG_HandleTypeDef* hrng,int *mode)
{
		if (strcmp(LED_RED,command)==0) LED_RED_RESP(UARTHANDLE);

		else if (strcmp(LED_BLUE,command)==0) LED_BLUE_RESP(UARTHANDLE);

		else if (strcmp(LED_GREEN,command)==0) LED_GREEN_RESP(UARTHANDLE);

		else if (strncmp(RNG_CALL,command,strlen(RNG_CALL))==0)
		{
			char* ptr;
			ptr=strchr(command,':');
			ptr++;
			uint32_t number=atoi(ptr);
			RNG_CALL_RESP(UARTHANDLE,number,hrng);
		}
		else if (strcmp(PARTY_TIME,command)==0) PARTY_MODE_CHANGE(UARTHANDLE,mode);
		else if (strcmp(COUNTING,command)==0) COUNTING_MODE_CHANGE(UARTHANDLE,mode);
		else if (strcmp(RETURN,command)==0) NORMAL_MODE_CHANGE(UARTHANDLE,mode);
		else if (strcmp(COUNTING_DOWN,command)==0) COUNTING_DOWN_MODE_CHANGE(UARTHANDLE,mode);
		else if (strcmp(WAVE,command)==0) WAVE_MODE_CHANGE(UARTHANDLE,mode);
		else if(strcmp(INVERT,command)==0) INVERT_MODE_CHANGE(UARTHANDLE,mode);
		else if(strcmp(GET_MODE,command)==0) SEND_CURRENT_MODE(UARTHANDLE,mode);
		else HAL_UART_Transmit(UARTHANDLE,command,strlen(command),5);

}
