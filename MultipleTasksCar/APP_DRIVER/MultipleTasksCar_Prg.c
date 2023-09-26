/*
 * MultipleTasksCar_Prg.c
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"
#include "avr/delay.h"

/* Lower Layer Interface Files*/
#include "../HAL_DRIVERS/DCMOTOR_Interface.h"
#include "../HAL_DRIVERS/Servo_Inteface.h"
#include "../HAL_DRIVERS/ULTRASONIC_Interface.h"
#include "MultipleTasksCar_Private.h"
#include "MultipleTasksCar_Cfg.h"

/* Own Driver Files*/
#include "../MCAL_DRIVERS/UART_Interface.h"
#include "../MCAL_DRIVERS/DIO_interface.h"
#include "../MCAL_DRIVERS/TIMER_Interface.h"
#include "../MCAL_DRIVERS/INTERRUPT_Interface.h"

/* Global signals */
extern distance;

/**************** Will be deleted soon each variable after that***********************/
u8 flag_state1 = HIGH ;
u8 flag_state2 = LOW ;
u8 flag_state3 = LOW ;
/************************************************************************************/

/*
 Name        : MultipleTasksCar_VidInit
 Input       : void
 Output      : void
 Description : to initialize the states of the car
*/
void MultipleTasksCar_VidInit(){
	/*****************************************/
	/* mode 1 */
	UART_VidInit();
	DcMotor_VidInit();
	TIMER2_VidInitialize();

	/* to set the velocity of car */
	MultipleTasksCar_DCMotorVelocity(THREE_QUARTER_PERCENTAGE);

	/****************************************/
	/* mode 2 */
	/* IR PIN*/
	DIO_VidSetPinDirection(IR_PORT,IR_PIN_LEFT,LOW);
	DIO_VidSetPinDirection(IR_PORT,IR_PIN_RIGHT,LOW);

	/* mode 3*/
	GIE_VidEnable();
	Servo_Init();
	ultrasonic_init();
}

/*
 Name        : MultipleTasksCar_GetDirections
 Input       : void
 Output      : void
 Description : to set the directions of the car
*/
void MultipleTasksCar_GetDirections(){
     u8 direction = UART_VidRecieveData() ;

	if ( direction == UP  ){
			DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
			DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	}
	else if ( direction == DOWN  ){
			DcMotor_VidRotate_Wheels1(CLK_WISE);
			DcMotor_VidRotate_Wheels2(CLK_WISE);
	}
	else if ( direction == RIGHT ){
			DcMotor_VidRotate_Wheels1(STOP);
			DcMotor_VidRotate_Wheels2(CLK_WISE);
	}
	else if ( direction == LEFT ){
			DcMotor_VidRotate_Wheels1(CLK_WISE);
			DcMotor_VidRotate_Wheels2(STOP);
	}
	else if (direction == NO_THING){
			DcMotor_VidRotate_Wheels1(STOP);
			DcMotor_VidRotate_Wheels2(STOP);
	}
}

/*
 Name        : MultipleTasksCar_DCMotorVelocity
 Input       : void
 Output      : void
 Description : to set the percentage of the velocity of car
*/
void MultipleTasksCar_DCMotorVelocity(u8 CopyVelocityPercentage){
	Timer2_VidSETDUTY(CopyVelocityPercentage);
}

/*
 Name        : MultipleTasksCar_GetMode
 Input       : void
 Output      : u8
 Description : to return the type of mode
*/
u8   MultipleTasksCar_GetMode(){
	return UART_VidRecieveData() ;
}

/*
 Name        : MultipleTasksCar_LineFollower
 Input       : void
 Output      : void
 Description : to return the type of mode
*/
void MultipleTasksCar_LineFollower(){
    u8 IRRight   = DIO_U8GetPinValue(IR_PORT,IR_PIN_RIGHT);
    u8 IRLeft    = DIO_U8GetPinValue(IR_PORT,IR_PIN_LEFT);

	 if (! IRRight && ! IRLeft){
		DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
		DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	 }
	 else if ( IRRight && ! IRLeft ){
		DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
		DcMotor_VidRotate_Wheels2(CLK_WISE);
	 }
	 else if (! IRRight && IRLeft) {
		DcMotor_VidRotate_Wheels1(CLK_WISE);
		DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
	 }
	 else {
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(STOP);
	 }
}


/*
 Name        : MultipleTasksCar_UltraSonic
 Input       : void
 Output      : void
 Description : to detect obtacles and move accroding to the states
 state 1 : up   - check on obtacle ------no obtacle----> up
                                   ------an obtacle---->state 2
 state 2 : stop - check on obtacle ------no obtacle---->left , delay , up
                                   ------an obtacle---->state 3
 state 3 : stop - check on obtacle ------no obtacle---->right , delay , up
                                   ------an obtacle---->stop for 10 seconds then state 1
 state 4 : all directions are blocked ----> stop for 4 seconds
*/
void MultipleTasksCar_UltraSonic(){
	/* variable for directions */
	static u8 right_flag ;
	static u8 left_flag ;
	static u8 stop_flag ;

	/* to trig ultrasonic pin and get new distance*/
	MultipleTasksCar_UltrasonicTriger();

	/* to make servo forward */
	Sero_SetAngle(ANGLE_ZERO);

	/* to go forward */
	if (distance > MIN_DISTANCE){
		DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
		DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);
		right_flag = LOW ;
		left_flag  = LOW ;
		stop_flag  = LOW ;
	}//if (distance > MIN_DISTANCE)
	else {
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(STOP);

		/* 0 : -90 */
		SetAngleOfServo(ANGLE_ZERO,ANGLE_NEGTIVE90);

		/* update on distance */
		MultipleTasksCar_UltrasonicTriger();

		/*no obtacle */
		if (distance > MIN_DISTANCE){
			right_flag = HIGH ;
		}//if (distance > MIN_DISTANCE)
		else {
			/* -90 : +90 */
			SetAngleOfServo(ANGLE_NEGTIVE90,ANGLE_POSITIVE90);

			/* update on distance */
			MultipleTasksCar_UltrasonicTriger();

			/*no obtacle */
			if  (distance > MIN_DISTANCE){
				left_flag = HIGH ;
			}//if  (distance > MIN_DISTANCE)
			else {
				stop_flag = HIGH ;
			}//else ----> (distance > MIN_DISTANCE)
		}//else ----> (distance > MIN_DISTANCE)
	}//else ----> (distance > MIN_DISTANCE)

	if (right_flag){
		SetAngleOfServo(ANGLE_NEGTIVE90,ANGLE_ZERO);
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(CLK_WISE);
		_delay_ms(800);
	}//if (right_flag)

	if (left_flag){
		SetAngleOfServo(ANGLE_POSITIVE90,ANGLE_ZERO);
		DcMotor_VidRotate_Wheels1(CLK_WISE);
		DcMotor_VidRotate_Wheels2(STOP);
		_delay_ms(800);
	}//if (left_flag)


	if (stop_flag){
		SetAngleOfServo(ANGLE_POSITIVE90,ANGLE_ZERO);
		_delay_ms(4000);
	}//if (stop_flag)


	/*if (flag_state1){
	      MultipleTasksCar_State1Car() ;
	}//end if
	else {
		MultipleTasksCar_State2Car();
		if (flag_state2){
			MultipleTasksCar_State1Car() ;
		}//end if
		else {
			MultipleTasksCar_State3Car() ;
			if (flag_state3){
				MultipleTasksCar_State1Car() ;
			}//end if
			else {
				MultipleTasksCar_State4Car() ;
				flag_state1 = HIGH ;
			}//end else
		}//end else
	}//end else*/
}

/*
 Name        : MultipleTasksCar_UltrasonicTriger
 Input       : void
 Output      : void
 Description : up   - check on obtacle ------no obtacle----> up
                                       ------an obtacle----> state 2
*/
void MultipleTasksCar_UltrasonicTriger(){
	ultrasonic_triger();
	_delay_ms(15);
}

/************************* Will be deleted soon each function after that *********************/
/*
 Name        : MultipleTasksCar_State1Car
 Input       : void
 Output      : u8
 Description : to achieve state 1
*/
void MultipleTasksCar_State1Car(void ){
	/* to update shaft servo */
	SetAngleOfServo(400,1500);

	if (distance >= 25 ){
		/* up */
		DcMotor_VidRotate_Wheels1(ANTI_CLK_WISE);
		DcMotor_VidRotate_Wheels2(ANTI_CLK_WISE);

		flag_state1 = HIGH ;
	}
	else {
		/* an abtacle */
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(STOP);
	}
	flag_state1 = LOW ;
}//end MultipleTasksCar_State1Car

/*
 Name        : MultipleTasksCar_State2Car
 Input       : void
 Output      : u8
 Description : stop - check on obtacle ------no obtacle---->right , delay , up
                                       ------an obtacle---->state 3
*/
void MultipleTasksCar_State2Car(){
	/* to update shaft servo */
	SetAngleOfServo(1500,2400);

	if (distance >= 25 ){    //no obtacle
		/* right */
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(CLK_WISE);
		_delay_ms(800);

		flag_state2 = HIGH ;
	}
	else {
		/* an abtacle */
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(STOP);
	}
	flag_state2 = LOW ;
}//end MultipleTasksCar_State2Car

/*
 Name        : MultipleTasksCar_State3Car
 Input       : void
 Output      : u8
 Description :  stop - check on obtacle ------no obtacle---->left , delay , up
                                        ------an obtacle---->stop for 10 seconds then state 1
*/
void MultipleTasksCar_State3Car(){
	/* to update shaft servo */
	SetAngleOfServo(2400,400);

	if (distance >= 25 ){    //no obtacle
		/* left */
		DcMotor_VidRotate_Wheels1(CLK_WISE);
		DcMotor_VidRotate_Wheels2(STOP);
		_delay_ms(800);

		flag_state3 = HIGH ;
	}
	else {
		/* an abtacle */
		DcMotor_VidRotate_Wheels1(STOP);
		DcMotor_VidRotate_Wheels2(STOP);
	}
	flag_state3 = LOW ;
}//end MultipleTasksCar_State3Car

/*
 Name        : MultipleTasksCar_State4Car
 Input       : void
 Output      : u8
 Description :  if all ways are blocked
*/
void MultipleTasksCar_State4Car(){
	/* an abtacle */
	DcMotor_VidRotate_Wheels1(STOP);
	DcMotor_VidRotate_Wheels2(STOP);

	_delay_ms(3000);
}
/**************************************************************************************/
