#ifndef __DEBUG_COMMANDS_H
#define __DEBUG_COMMANDS_H

void execute_command(char* command[],UART_HandleTypeDef * UARTHANDLE,RNG_HandleTypeDef* hrng, int *MODE);


#endif
