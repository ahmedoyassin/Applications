/*
 * CURT2_interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed Yassin
 */

#ifndef CURT2_INTERFACE_H_
#define CURT2_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CURT2_cfg.h"

/* to check on flags */
#define HIGH 1
#define LOW 0

/* to control on DC motor*/
#define STOP 0
#define CLK_WISE 1
#define ANTI_CLK_WISE 2


/* duty*/
#define ZERO_DUTY       0
#define PercentageOf20  20
#define PercentageOf40  40
#define PercentageOf60  60
#define PercentageOf80  80
#define FULL_DUTY       100

#define FALLING    1

typedef enum
{
	MACHINE_OFF,
	MACHINE_ON

}Machine_state;


typedef enum
{
	STOP_MACHINE='0',
	Normal_State_Lower_than_20 ='1',
	Normal_State_Between_20_40 = '2',
	Normal_State_Between_40_50 = '3',
	Emergency_State = '4',
	Abnormal_State= '5',
	SHUTTING_DOWN = '6'
}StatesForMCU2;

void FUN();
void CURT2_VidInit();
void Check_States();


#endif /* CURT2_INTERFACE_H_ */
