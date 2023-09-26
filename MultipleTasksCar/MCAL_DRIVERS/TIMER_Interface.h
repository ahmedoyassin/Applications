/*
 * TIMER_Interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: HP
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "../Serivecs_driver/STD_TYPES.h"
#include "TIMER_Private.h"
#include "TIMER_CFG.h"




/************************* TIMER0 FUNC *******************************/

void TIMER0_VidInitialize (void) ;                                    //use to initialize TIMER0



/************************* TIMER1 FUNC *******************************/

void TIMER1_VidInitialize (void) ;                                           //use to initialize TIMER0
void Timer1_VidSETDUTY (u16 Copy_U8DutyA , u16 Copy_U8DutyB ) ;              //to select specific duty in timer0
void Timer1_VidSetFrequency () ;


/************************* TIMER2 FUNC *******************************/

void TIMER2_VidInitialize (void) ;                                    //use to initialize TIMER0

#if TIMER2_MODE == FAST_PWM

void Timer2_VidSETDUTY (u8 duty ) ;                                   //to select specific duty in timer0

#elif TIMER2_MODE != FAST_PWM

void TIMER2_Set_Time_S (u8 Copy_U8Time);                                     //to set wanted time
void TIMER2_Set_Time_mS (u16 Copy_U8Time);                                   //to set wanted time
void TIMER_VidSetCallBack (u8 Copy_NumOfINT , void (*ptr)(void));     //use to point on excuted function in ISR

#endif

#endif /* TIMER_INTERFACE_H_ */
