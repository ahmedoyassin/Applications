/*
 * MultipleTasksCar_Cfg.h
 *
 *  Created on: 23/12/2022
 *  Author: ENG/Ahmed Yassin
 */

#ifndef _ULTRASONIC_PRIVATE_H_
#define _ULTRASONIC_PRIVATE_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../MCAL_DRIVERS/TIMER_Interface.h"

#define   TRIGER_DDR    DDRA
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTA
#define   ECHO_PULLUP   PORTD
#define   TRIGER        7
#define   ECHO          3

#endif
