/*
 * TIMER_PRG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include "../Serivecs_driver/STD_TYPES.h"
#include "../Serivecs_driver/BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER_Interface.h"
#include "TIMER_Private.h"
#include "TIMER_CFG.h"

/*  Don't forget to use
	GIE_VidEnable()       to clear flag of timer by hardware
	define the used pin OCR in PWM mode
*/
static void (*TIMER1_PFUNC)(void) = 0 ;
static void (*TIMER2_PFUNC)(void) = 0 ;

static u16 PRE_SCALAR_TIMER1 ;

static u64 DESIRED_TIME_TIMER2 ;
static u16 PRE_SCALAR_TIMER2 ;
static f32 T_OV_TIMER2  ;
static f32 NUM_OV_TIMER2 ;
static f32 PRE_LOAD_TIMER2 ;

void TIMER_VidSetCallBack (u8 Copy_NumOfINT , void (*ptr)(void)){
	switch (Copy_NumOfINT){
	case 1 :TIMER1_PFUNC = ptr ;             break ;
	case 2 :TIMER2_PFUNC = ptr ;             break ;
	}
}




/*******************To initialize OV or COMPARE or FAST_PWM mode***************************************/
void TIMER0_VidInitialize (void) {
	/* Disable Timer 0 */
	TCCR0 = DISABLE_MODULE_VALUE;

	/* Setting pre scaler */
    TCCR0 = (PRESCLR1_VALUE);

    /* Initializing the timer with zero */
	TCNT0 = ZER0_INITIALIZER;

	/* Timer overflow interrupt enable*/
	TIMSK |=(1<<TOIE0);

}//end FUNC TIMER_VidInitialize


/********************************************************************************/




/*******************To initialize OV or COMPARE or FAST_PWM mode***************************************/
//to check that you don't use OV or COMPARE or FAST_PWM mode
void TIMER1_VidInitialize (void) {

	//COM1A1/COM1B1 COM1A0/COM1B0  1 0 Clear OC1A/OC1B on compare match, set  OC1A/OC1B at TOP
	TCCR1A = 0b10100000 ;

	//in next update we will make Timer not fixed modes
	/*WGM13 WGM12	WGM11	WGM10	Timer/Counter Mode of Operation TOP Update of OCR1x	TOV1 Flag Set 	on
      1      1       1        0        Fast PWM                      ICR1 TOP TOP*/
	SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);

	//define pin of timer1
	DIO_VidSetPinDirection(3,5,1);
	DIO_VidSetPinDirection(3,4,1);
	DIO_VidSetPinValue(3,5,0);
	DIO_VidSetPinValue(3,4,0);

	/*   CS12 CS11 CS10
	       0    0    1         clkI/O/1 (No prescaling)
           0    1    0         clkI/O/8 (From prescaler)
           0    1    1         clkI/O/64 (From prescaler)
           1    0    0         clkI/O/256 (From prescaler)
           1    0    1          clkI/O/1024 (From prescaler)
	*/

    /*   to initialize timer pre_scalar      */
#if PRE_TYPE_TIMER1 == NO_PRE
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	PRE_SCALAR_TIMER1 = 1 ;
#elif PRE_TYPE_TIMER1 == PRE_8
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
	PRE_SCALAR_TIMER1 = 8 ;
#elif PRE_TYPE_TIMER1 == PRE_64
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	PRE_SCALAR_TIMER1 = 64 ;
#elif PRE_TYPE_TIMER1 == PRE_256
	SET_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
	PRE_SCALAR_TIMER1 = 256 ;
#elif PRE_TYPE_TIMER1 == PRE_1024
	SET_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	PRE_SCALAR_TIMER1 = 1024 ;
#endif

}//end FUNC TIMER_VidInitialize

//to set the top of counting in PWM
void Timer1_VidSETFreqency (){

	/*
	ICR1H = (u8)(top_count>>8) ;
	ICR1L = (u8)(top_count) ;
	*/

	/* set duty accroding to the wanted frequency */
	ICR1H = 0b10011000 ;
	ICR1L = 0b00100000 ;
}

//in next update we want to make duty by _precentage %
void Timer1_VidSETDUTY (u16 Copy_U8DutyA , u16 Copy_U8DutyB ) {
	OCR1AH = (u8)(Copy_U8DutyA>>8) ;
	OCR1AL = (u8)Copy_U8DutyA ;

	OCR1BH = (u8)(Copy_U8DutyB>>8) ;
	OCR1BL = (u8)Copy_U8DutyB ;
}

/******************************************************************************************************/




/*******************To initialize OV or COMPARE or FAST_PWM mode***************************************/
//to check that you don't use OV or COMPARE or FAST_PWM mode
void TIMER2_VidInitialize (void) {
	//define pin of timer 2
	DIO_VidSetPinDirection(3,7,1);
	DIO_VidSetPinValue(3,7,0);

#if TIMER2_MODE == OV
	/*   overflow mode , to clear FOC0 and register
	     to enable interrupt , when rising flag jump to ISR     */
	TCCR2 = 0 ;
	SET_BIT(TIMSK,TOIE2);
#endif

#if TIMER2_MODE == COMPARE
	/*  CTC MODE , SET(WGM01)   CLEAR(WGM00)
	    to enable interrupt , when rising flag jump to ISR
	*/
	SET_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);

	SET_BIT(TIMSK,OCIE2);
#endif

#if TIMER2_MODE == FAST_PWM
	// to initialize timer0 on 0 , FOCO = 0
	TCCR2 = 0 ;

	// 1 1 Fast PWM
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);

	//1 0 Clear OC0 on compare match, set OC0 at TOP ,  NON_INVERED MODE PWM
	SET_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);
#endif

	/*   CS22 CS21 CS20
	     0     0    1   no_prescalar   "NO_PRE"
	     0     1    0   clkI/O/8       "PRE_8"
	     0     1    1   clkI/O/64      "PRE_64"
	     1     0    0   clkI/O/256     "PRE_256"
	     1     0    1   clkI/O/1024    "PRE_1024"
	*/

    /*   to initialize timer pre_scalar      */
#if PRE_TYPE_TIMER2 == NO_PRE
	CLR_BIT(TCCR2,CS22);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS20);
#elif PRE_TYPE_TIMER2 == PRE_8
	CLR_BIT(TCCR2,CS22);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS20);
	PRE_SCALAR_TIMER2 = 8 ;
#elif PRE_TYPE_TIMER2 == PRE_64
	CLR_BIT(TCCR2,CS22);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS20);
	PRE_SCALAR_TIMER2 = 64 ;
#elif PRE_TYPE_TIMER2 == PRE_256
	SET_BIT(TCCR2,CS22);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS20);
	PRE_SCALAR_TIMER2 = 256 ;
#elif PRE_TYPE_TIMER2 == PRE_1024
	SET_BIT(TCCR2,CS22);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS20);
	PRE_SCALAR_TIMER2 = 1024 ;
#endif

}//end FUNC TIMER_VidInitialize

/******************** The part that use to count time  *************************/
//to check that you don't use OV or COMPARE mode
#if TIMER2_MODE == OV

void TIMER2_Set_Time_S (u8 Copy_U8Time){
	DESIRED_TIME_TIMER2 = (u64)Copy_U8Time*1000 ;                                    //time in ms
    T_OV_TIMER2 = (256*(f32)PRE_SCALAR_TIMER2)/8000 ;                                //time in ms
	NUM_OV_TIMER2 = DESIRED_TIME_TIMER2 / T_OV_TIMER2 ;                              //number of overflow wanted in entered if
	PRE_LOAD_TIMER2  = NUM_OV_TIMER2 -( (u32)(DESIRED_TIME_TIMER2 /T_OV_TIMER2) );   //the value which should be in TCNT to make time more accurate
	if ( NUM_OV_TIMER2 > (u32)NUM_OV_TIMER2 ){
		NUM_OV_TIMER2++;
	}//end if

	//to begin from specific value
	TCNT2 = 256-(256*PRE_LOAD_TIMER2 );
}

void TIMER2_Set_Time_mS (u16 Copy_U8Time){
	DESIRED_TIME_TIMER2 = Copy_U8Time ;                         //time in ms
    T_OV_TIMER2 = (256*(f32)PRE_SCALAR_TIMER2)/8000 ;                  //time in us
	NUM_OV_TIMER2 = DESIRED_TIME_TIMER2 / T_OV_TIMER2 ;                       //number of overflow wanted in entered if
	PRE_LOAD_TIMER2  = NUM_OV_TIMER2 -( (u32)(DESIRED_TIME_TIMER2 /T_OV_TIMER2) );   //the value which should be in TCNT to make time more accurate
	if ( NUM_OV_TIMER2 > (u32)NUM_OV_TIMER2 ){
		NUM_OV_TIMER2++;
	}//end if
#if PRE_TYPE_TIMER2 != PRE_8
#error "YOU SELECTED PRE_SCALAR MAKE MORE THAN 1 ms"
#endif

	//to begin from specific value
	TCNT2 = 256-(256*PRE_LOAD_TIMER2 );
}

#endif


//to check that you use FAST_PWM mode
#if TIMER2_MODE == FAST_PWM

void Timer2_VidSETDUTY (u8 duty ) {
	duty = (u8)( (u16)duty*255/100 ) ;
	OCR2 = duty ;
}

#endif

/****************************************************************************/







/****************************** ISR FUNC ****************************/

/*
    "NOT_PREFEREED because time is not accurate with high F every 1ms take in real 3ms"
    1) NO_PRE   every 1msec need t_ov = 32us , num_ov = 31.250 , pre_load = 0.25
    *****************************************************
    "USED in scale 1 mS"
    2) PRE_8   every 1msec need t_ov = 256us , num_ov = 3.90625 , pre_load = 0.90625
     *****************************************************
    "USED in scale 1S "
    3) PRE_64   every 1sec need t_ov = 2.048ms  , num_ov = 488.28125   , pre_load = 0.28125
    4) PRE_256  every 1sec need t_ov = 8.192ms  , num_ov = 122.0703125 , pre_load = 0.0703125
    5) PRE_1024 every 1sec need t_ov = 32.768ms , num_ov = 30.51757813 , pre_load = 0.51757813
*/



/****************************************************************************/

void __vector_5(void){
	static u32 tick = 0 ;
	tick++ ;

	if (tick == (u32)NUM_OV_TIMER2 ){
		TIMER2_PFUNC();                                     //to toggle led
		TCNT2 = 256-(256*PRE_LOAD_TIMER2);                         //to begin from specific value
		tick = 0 ;                                          //to start count from beginning again
	}//end if
}//end ISR FUNC

/********************************************************************************/

void __vector_9(void){
/*****************************************/
}//end ISR FUNC

/********************************************************************************/
void __vector_6(void){
/*****************************************/
}

