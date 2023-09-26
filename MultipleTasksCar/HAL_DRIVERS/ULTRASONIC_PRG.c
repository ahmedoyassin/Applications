/*
 * MultipleTasksCar_Cfg.h
 *
 *  Created on: 23/12/2022
 *  Author: ENG/Ahmed Yassin
 */

#include "../Serivecs_driver/STD_TYPES.h"
#include "ULTRASONIC_Private.h"

u8 sensor_working=0;
u8 rising_edge=0;
u32 timer_counter=0;
u32 distance;
u8 distance_str[10];

void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  TIMER0_VidInitialize ();
  return;
}
void enable_ex_interrupt(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}

void ultrasonic_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT0)/466;

    timer_counter=0;
    rising_edge=0;
  }
}}

ISR(TIMER0_OVF_vect){
    timer_counter++;
    if(timer_counter >730){
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}
