/*
 * CURT2_cfg.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed Yassin
 */

#ifndef CURT2_CFG_H_
#define CURT2_CFG_H_

#include "CURT2_private.h"

/* Led & LDR cfg */
#define PORT_LED    2
#define GREEN_LED_PIN      3
#define YELLOW_LED_PIN      4
#define RED_LED_PIN     	 5

/*buzzer cfg*/
#define BUZZER_PORT 1
#define BUZZER_PIN   6

/* servo cfg */
#define SERVO_PORT   3
#define SERVO_PIN   5
#define GET_IN   1
#define GET_OUT  2
#define GET_OUT_FIRE  3

#define HIGH 1
#define LOW 0

#endif /* CURT2_CFG_H_ */
