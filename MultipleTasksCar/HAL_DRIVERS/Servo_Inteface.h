/*
 * Servo_Inteface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include "../Serivecs_driver/STD_TYPES.h"

#ifndef SERVO_INTEFACE_H_
#define SERVO_INTEFACE_H_

void Servo_Init();
void SetAngleOfServo(u16 InitialAngle , u16 LastAngle );         /* to set the angle of servo */
void Sero_SetAngle(u16 Copy_Angle);

#endif /* SERVO_INTEFACE_H_ */
