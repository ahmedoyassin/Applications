/*
 * CURT1_prg.c
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
#include "ADC_interface.h"
#include "EX_INT_Interface.h"
#include "INTERRUPT_Interface.h"
#include "TIMER_Interface.h"
#include "UART_interface.h"
#include "CURT1_interface.h"
#include "WDT_interface.h"

/*   GLOBAL Variables  */
	u8 Duty_Fan ;                                         //define duty direct "FUN in PWM_Volt_fan "
	StatesForMCU2 MCU2;
	u8 counter=0;
	u8 temp=0;
	StatesMCU1 MCU1;
/*
 Name        : FUNC
 Input       : void
 Output      : void
 Description : pointer to function which excuted interrupt
*/
void FUNC (void){
	if(MCU2 == Normal_State_Between_40_50)
	{
	UART_U8SendChar(STOP_MACHINE);
	}
	else
	{
		//do nothing
	}
}


/*
 Name        : CURT1_VidInit
 Input       : void
 Output      : void
 Description : to initialize every function in project
*/

void CURT1_VidInit(){
	/* For Fun */
	TIMER0_VidInitialize();
	TIMER2_VidInitialize();

	 /* Check Temp Every 0.05 Sec */
	TIMER_VidSetCallBack(2,&emergency_state_check);
	TIMER2_Set_Time_mS(50);



		ADC_VidInit();
		DcMotor_VidInit();
		UART_Vidinit();


		/* decleration of external interrupt to exist room */
	    GIE_VidEnable();
	    EX_INT_VidINIT();
		EX_PIE_VidEnable(INT_NUM);
		EX_INT_VidSetCallBack(INT_NUM,FUNC);
		EX_INT_VidSetEdge(INT_NUM,FALLING);

		DIO_VidSetPinDirection(SWITCH_PORT,SWITCH_PIN,LOW);   //define Switch as an input pin direction
		DIO_VidSetPinValue(SWITCH_PORT,SWITCH_PIN,HIGH);      //Pull up switch


		DIO_VidSetPinDirection(2,5,HIGH);   //define Switch as an input pin direction

}


/*
 Name        : LM35_U16_ReadTemp
 Input       : void
 Output      : u16
 Description : to read temperature by LM35
*/
u16 LM35_U16_ReadTemp()
{
	return ADC_VidReadChannel(3)/10 ;
}

/*
 Name        : StateOfFunAndBuzzer
 Input       : void
 Output      : void
 Description : to check the given temp sensor then set the duty of fan and state of buzzer
*/
void StateOfFunAndBuzzer(){
	if (temp < MIN_TEMP ){
		counter =0;
		MCU2 = Normal_State_Lower_than_20;
		MCU1 = Normal;
		eeprom_update_byte (( u8 *) 69, MCU1 );
		Duty_Fan = ZERO_DUTY ;
	}
	else if (temp >= MIN_TEMP && temp < MAX_TEMP ){
		counter =0;
		MCU1 = Normal;
		eeprom_update_byte (( u8 *) 69, MCU1 );

		//to make discrete duty of fan
		if (temp >= MIN_TEMP && temp < MIN_TEMP+5 ){
			MCU2 = Normal_State_Between_20_40;
			Duty_Fan = PercentageOf20 ;
		}
		else if (temp >= MIN_TEMP+5 && temp < MID_TEMP ){
			MCU2 = Normal_State_Between_20_40;
			Duty_Fan = PercentageOf40 ;
		}
		else if (temp >= MID_TEMP && temp < MID_TEMP+5 ){
			MCU2 = Normal_State_Between_20_40;
			Duty_Fan = PercentageOf60 ;
		}
		else if (temp >= MID_TEMP+5 && temp < MAX_NORMAL_TEMP ){
			MCU2 = Normal_State_Between_20_40;
			Duty_Fan = PercentageOf80 ;
		}
		else
		{
			MCU2 = Normal_State_Between_40_50;
			Duty_Fan = FULL_DUTY ;
		}
		}
		else
		{
			MCU2 = Emergency_State;
			MCU1 = Emergency;
			eeprom_update_byte (( u8 *) 69, MCU1 );

			Duty_Fan = FULL_DUTY ;
		}
	DcMotor_VidRotate(CLK_WISE);
	Timer0_VidSETDUTY(Duty_Fan);
}

/*
 Name        : emergency_state_check
 Input       : void
 Output      : void
 Description : to read Temp in project then sends it to the other MCU and checks for emergency state every 0.5s and go for abnormal if it's been in emergency state.
*/
void emergency_state_check(void){
	WDT_VidDisable();
	temp = LM35_U16_ReadTemp();
	UART_U8SendChar(MCU2);


	static u8 CounterTimer=0;
	CounterTimer++;
	if(CounterTimer>10)
	{
		CounterTimer =0;
	if(eeprom_read_byte((const u8*)69) == Emergency)
	{
		MCU2 = Emergency_State;
		temp = LM35_U16_ReadTemp();

		counter++;

		if(counter >=14 && counter <24)
		{
			MCU2 = Abnormal_State;
			MCU1 = Abnormal;
			eeprom_update_byte (( u8 *) 69, MCU1 );

			UART_U8SendChar(MCU2);

			counter=0;
			WDT_VidEnable();
		}
		else if(counter >=24)
		{
			MCU2 = Emergency_State;
			UART_U8SendChar(MCU2);
		}
	}
	}
}
