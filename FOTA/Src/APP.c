/*
 * APP.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Ahmed Yassin
 */


#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "UART_interface.h"
#include "HSSD_interface.h"


u8 x;

extern TaskHandle_t taskHandle_t1;
extern TaskHandle_t taskHandle_t2;
extern TaskHandle_t taskHandle_t3;
extern TaskHandle_t taskHandle_t4;
extern TaskHandle_t taskHandle_t5;

QueueHandle_t xQueue1;
void Task_Init (void * PV)
{

	 RCC_voidInitializeSystemClock();

	 USART_VidInit(arrOfUART);

	 Port_SetPinDirection(A4,OUTPUT_2);
	 Port_SetPinMode(A4, G_PUSH_PULL);
	 Dio_WriteChannel(A4, LOW);
	 Port_SetPinDirection(A5,OUTPUT_2);
	 Port_SetPinMode(A5, G_PUSH_PULL);
	 Dio_WriteChannel(A5, LOW);
	 Port_SetPinDirection(A6,OUTPUT_2);
	 Port_SetPinMode(A6, G_PUSH_PULL);
	 Dio_WriteChannel(A6, LOW);
	 Port_SetPinDirection(A7,OUTPUT_2);
	 Port_SetPinMode(A7, G_PUSH_PULL);
	 Dio_WriteChannel(A7, LOW);



	 vTaskDelete(NULL);

}


void Task_manager (void * PV)
{

	u8 Messege_Recieved;
	while(1){

		USART_TransmitString(UART2,"Press 'a' To access LED updates\n");
		USART_TransmitString(UART2,"Press 'b' To access LCD updates\n");
		do{
			Messege_Recieved=USART_ReceiveByte(UART2);
		}while(Messege_Recieved !='a' && Messege_Recieved !='b' );

		xQueueSend(xQueue1, &Messege_Recieved, (TickType_t) 100);

		xTaskNotify(taskHandle_t3,3, eSetValueWithoutOverwrite);


		vTaskSuspend(NULL);


	}
	vTaskDelete(NULL);
}


void Task_Action(void * PV)
{
	u8 Message_for_Action;
	u8 Task_Action_permissionINDEX;

	while(1)
	{
		Task_Action_permissionINDEX = ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
		if(3 == Task_Action_permissionINDEX){
			xQueueReceive(xQueue1, &Message_for_Action, portMAX_DELAY);

			if('a' == Message_for_Action)
						{
						USART_TransmitString(UART2,"INPUT 1\n");
						xTaskNotify(taskHandle_t4, 2,eSetValueWithoutOverwrite);
						}
						else if('b' == Message_for_Action)
						{
						USART_TransmitString(UART2,"INPUT 2\n");
						xTaskNotify(taskHandle_t5, 4,eSetValueWithoutOverwrite);
						}
						else
						{
							USART_TransmitString(UART2,"WRONG INPUT\n");
						}

			vTaskSuspend(NULL);

		}
}
	vTaskDelete(NULL);
}

void Task_led	(void * PV)
{
	u8 LEDpermissionINDEX;
	while(1){
		LEDpermissionINDEX = ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
		if(2 == LEDpermissionINDEX){
		USART_TransmitString(UART2,"Press 1 To Toggle LED (1)\nPress 2 To Toggle LED (2)\nPress 3 To Toggle LED (3)\nPress 4 To Toggle LED (4)\n");



		vTaskResume(taskHandle_t2);
		vTaskResume(taskHandle_t3);
		}


			}
			vTaskDelete(NULL);
}

void Task_LCD	(void * PV)
{
	u8 LCDpermissionINDEX;


	while(1){
		LCDpermissionINDEX =ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
		if(4 == LCDpermissionINDEX){
        USART_TransmitString(UART2,"Write whatever you want to be written on LCD\n");


		vTaskResume(taskHandle_t2);
		vTaskResume(taskHandle_t3);
		}

	}
			vTaskDelete(NULL);

}



