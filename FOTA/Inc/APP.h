/*
 * APP.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Ahmed Yassin
 */

#ifndef APP_H_
#define APP_H_
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "UART_interface.h"
#include "HSSD_interface.h"

extern QueueHandle_t xQueue1;

void Task_Init (void * PV);
void Task_manager (void * PV);
void Task_Action (void * PV);
void Task_led (void *PV);
void Task_LCD (void *PV);


#endif /* APP_H_ */
