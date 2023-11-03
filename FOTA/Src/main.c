/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "APP.h"
	TaskHandle_t taskHandle_t1;
	TaskHandle_t taskHandle_t2;
	TaskHandle_t taskHandle_t3;
	TaskHandle_t taskHandle_t4;
	TaskHandle_t taskHandle_t5;



int main(void)
{

	 u8 ret;
	 xQueue1 = xQueueCreate( 1, sizeof( u8 ) );
	 if( xQueue1 == NULL )
	     {
	     while(1);
	     }
	  ret= xTaskCreate(Task_Init,("Task1"), (configSTACK_DEPTH_TYPE)50, "Hello world", (UBaseType_t)9, &taskHandle_t1 );
	  configASSERT(ret == pdPASS);
	  ret= xTaskCreate(Task_manager,("Task2"), (configSTACK_DEPTH_TYPE)50, "Hello world 2", (UBaseType_t)4, &taskHandle_t2 );
	  configASSERT(ret == pdPASS);
	  ret= xTaskCreate(Task_Action,("Task3"), (configSTACK_DEPTH_TYPE)50, "Hello world 3", (UBaseType_t)3, &taskHandle_t3 );
	  configASSERT(ret == pdPASS);
	  ret= xTaskCreate(Task_led,("Task4"), (configSTACK_DEPTH_TYPE)50, "Hello world 4", (UBaseType_t)2, &taskHandle_t4 );
	  configASSERT(ret == pdPASS);
	  ret= xTaskCreate(Task_LCD,("Task5"), (configSTACK_DEPTH_TYPE)50, "Hello world 5", (UBaseType_t)2, &taskHandle_t5 );
	  configASSERT(ret == pdPASS);


	  vTaskStartScheduler();

    /* Loop forever */
	for(;;);

}
