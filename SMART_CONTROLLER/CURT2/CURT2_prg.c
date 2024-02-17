/*
 * CURT2_prg.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed Yassin
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DCMOTOR_Interface.h"
#include "SERVOMOTOR_interface.h"
#include "ADC_interface.h"
#include "EX_INT_Interface.h"
#include "INTERRUPT_Interface.h"
#include "TIMER_Interface.h"
#include "UART_interface.h"
#include "CURT2_interface.h"


/*   GLOBAL Variables  */
	u8 ReceivedData ;                                         //define duty direct "FUN in PWM_Volt_fan "
	u8 x;
	u8 count=0;
	Machine_state MACHINE_STATE = MACHINE_ON;
	u8 Speed;

/*
 Name        : CURT1_VidInit
 Input       : void
 Output      : void
 Description : to initialize every function in project
*/

void CURT2_VidInit(){
	/* For DcMotor */
	TIMER0_VidInitialize();
	TIMER1_VidInit();
	TIMER2_VidInitialize();

	   /* For LCD & LM35 & DCMOTOR & USART*/
		ADC_VidInit();
		//DcMotor_VidInit();

		UART_Vidinit();


		/* decleration of external interrupt to exist room */
	    GIE_VidEnable();

	    DIO_VidSetPinDirection(BUZZER_PORT,BUZZER_PIN,HIGH);

	    DIO_VidSetPinDirection(0,3,1);
	    DIO_VidSetPinValue(0,3,1);


		DIO_VidSetPinDirection(SERVO_PORT,SERVO_PIN,HIGH);			  //define Servo pin direction


		DIO_VidSetPinDirection(PORT_LED,GREEN_LED_PIN,HIGH);
		DIO_VidSetPinValue(PORT_LED,GREEN_LED_PIN,LOW);

		DIO_VidSetPinDirection(PORT_LED,YELLOW_LED_PIN,HIGH);
		DIO_VidSetPinValue(PORT_LED,YELLOW_LED_PIN,LOW);

		DIO_VidSetPinDirection(PORT_LED,RED_LED_PIN,HIGH);
		DIO_VidSetPinValue(PORT_LED,RED_LED_PIN,LOW);

		_delay_ms(150);
}

/*
 Name        : Check_States
 Input       : void
 Output      : void
 Description : to recieve the uart from the other MCU then check for the state of the LEDs, Servo Motor, Machine State.
*/
void Check_States(){
	x= UART_U8GetChar();
	static Flag = 0;
	if(!Flag)
	{
	switch(x)
	{
	case STOP_MACHINE:
		MACHINE_STATE = MACHINE_OFF;
		SERVOMOTOR_VidSetDirection(92,OC1A_PIN);
	    DIO_VidSetPinValue(0,3,0);
			break;
	case Normal_State_Lower_than_20:
		DIO_VidSetPinValue(PORT_LED,RED_LED_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,YELLOW_LED_PIN,LOW);
		DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,GREEN_LED_PIN,HIGH);
		SERVOMOTOR_VidSetDirection(92,OC1A_PIN);
	    DIO_VidSetPinValue(0,3,1);
		break;
	case Normal_State_Between_20_40:
		DIO_VidSetPinValue(PORT_LED,GREEN_LED_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,RED_LED_PIN,LOW);
		DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,YELLOW_LED_PIN,HIGH);
		SERVOMOTOR_VidSetDirection(92,OC1A_PIN);
	    DIO_VidSetPinValue(0,3,1);
		break;
	case Normal_State_Between_40_50:
		DIO_VidSetPinValue(PORT_LED,GREEN_LED_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,YELLOW_LED_PIN,LOW);
		DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,RED_LED_PIN,HIGH);
		SERVOMOTOR_VidSetDirection(92,OC1A_PIN);
		break;

	case Emergency_State:
		DIO_VidSetPinValue(PORT_LED,GREEN_LED_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,YELLOW_LED_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,RED_LED_PIN,HIGH);
		DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,HIGH);
		SERVOMOTOR_VidSetDirection(92,OC1A_PIN);
	    DIO_VidSetPinValue(0,3,1);
		break;
	case Abnormal_State:
		DIO_VidSetPinValue(PORT_LED,GREEN_LED_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,YELLOW_LED_PIN,LOW);
		DIO_VidSetPinValue(PORT_LED,RED_LED_PIN,HIGH);
		DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,HIGH);
		SERVOMOTOR_VidSetDirection(180,OC1A_PIN);
	    DIO_VidSetPinValue(0,3,0);

		break;
	}}
	if (x == '5')
	{
		Flag = 1;
	}
	else if(count >= 50)
	{
		Flag = 0;
		count =0;
	}
	else if(Flag == 1)
	{
		count++;
}}
