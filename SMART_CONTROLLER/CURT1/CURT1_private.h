/*
 * CURT1_private.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed Yassin
 */

#ifndef CURT1_PRIVATE_H_
#define CURT1_PRIVATE_H_


/* temperature*/
#define MAX_TEMP 50
#define MIN_TEMP 20
#define MID_TEMP 30
#define MAX_NORMAL_TEMP 40

/* to check on flags */
#define HIGH 1
#define LOW 0

/* to control on DC motor*/
#define STOP 0
#define CLK_WISE 1
#define ANTI_CLK_WISE 2


/* duty*/
#define ZERO_DUTY       0
#define PercentageOf20  20
#define PercentageOf40  40
#define PercentageOf60  60
#define PercentageOf80  80
#define FULL_DUTY       100

#define FALLING    1


#endif /* CURT1_PRIVATE_H_ */
