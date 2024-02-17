/*
 * CURT1_interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed Yassin
 */

#ifndef CURT1_INTERFACE_H_
#define CURT1_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CURT1_cfg.h"

void CURT1_VidInit();
u16 LM35_U16_ReadTemp();
void StateOfFunAndBuzzer();
void emergency_state_check(void);


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


typedef enum
{
	Normal,
	Emergency,
	Abnormal
}StatesMCU1;

#endif /* CURT1_INTERFACE_H_ */
