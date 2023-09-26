/*
 * Servo_Prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"
#include "../MCAL_DRIVERS/DIO_interface.h"
#include "../MCAL_DRIVERS/TIMER_Interface.h"
#include "avr/delay.h"

#define STEP_ANGLE  5

void Servo_Init(){
	TIMER1_VidInitialize();
	Timer1_VidSETFreqency();
}

void SetAngleOfServo(u16 InitialAngle , u16 LastAngle ) {

	/* min duty : 400
	   max duty : 2400
	 */

	if (InitialAngle <= LastAngle){

		for (u16 i = InitialAngle ; i < LastAngle ; i+=STEP_ANGLE ){
			Timer1_VidSETDUTY(i,0);
			_delay_ms(1);
		}//end for loop

	}//end if InitialAngle <= LastAngle

	else {

		for (u16 i = InitialAngle ; i > LastAngle ; i-=STEP_ANGLE ){
			Timer1_VidSETDUTY(i,0);
			_delay_ms(1);
		}//end for loop

	}//end else
}

void Sero_SetAngle(u16 Copy_Angle){
	Timer1_VidSETDUTY(Copy_Angle,0);
}
