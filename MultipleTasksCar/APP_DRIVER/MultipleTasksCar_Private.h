/*
 * MultipleTasksCar_Private.h
 *
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

/*     Libraries    */
#include "../Serivecs_driver/STD_TYPES.h"

/* Lower Layer Interface Files*/
    /* no lower layers */

/* Own Driver Files*/
    /* no needed */

#ifndef APP_DRIVER_MULTIPLETASKSCAR_PRIVATE_H_
#define APP_DRIVER_MULTIPLETASKSCAR_PRIVATE_H_

#define UP       'a'
#define DOWN     'b'
#define RIGHT    'c'
#define LEFT     'd'
#define NO_THING 'e'

#define HIGH 1
#define LOW 0

//define wanted states
#define STOP 0
#define CLK_WISE 1
#define ANTI_CLK_WISE 2

//define PORT
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


#define HALF_PERCENTAGE          50
#define FULL_PERCENTAGE          100
#define QUARTER_PERCENTAGE       25
#define THREE_QUARTER_PERCENTAGE 75


#define ANGLE_ZERO       1500
#define ANGLE_NEGTIVE90  400
#define ANGLE_POSITIVE90 2400

#define MIN_DISTANCE      25


/* private functions  */
void MultipleTasksCar_DCMotorVelocity(u8 CopyVelocityPercentage);
void MultipleTasksCar_UltrasonicTriger();
void MultipleTasksCar_State1Car(void);
void MultipleTasksCar_State2Car(void);
void MultipleTasksCar_State3Car(void);
void MultipleTasksCar_State4Car(void);

#endif /* APP_DRIVER_MULTIPLETASKSCAR_PRIVATE_H_ */
