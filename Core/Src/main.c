/*
 * main.c
 *
 *  Created on: Sep 8, 2025
 *      Author: lenovo
 */
#include "stm32f4xx_hal.h"
#include "main.h"

void SystemClockConfig(void);
void UART_Init(void);
void Error_handler(void);

UART_HandleTypeDef huart2;


int main(void){

	HAL_Init();
	SystemClockConfig();
	UART_Init();


	return 0;
}

void SystemClockConfig(void){

}

void UART_Init(void){
	huart2.Instance = USART2;
	huart2.Init.BaudRate =115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
		//there is a problem
		Error_handler();
	}
}

void Error_handler(void){
	while(1);
}

