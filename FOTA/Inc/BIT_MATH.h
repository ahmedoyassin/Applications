/*
 * APP.h
 *
 *  Created on: July 28, 2022
 *      Author: Ahmed Yassin
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define TOGGLE_BIT(REG,BIT) REG^=1<<BIT
#define CLR_BIT(REG,BIT) REG&=(~(1 << BIT))
#define SET_BIT(REG,BIT) REG|=1<<BIT
#define SHIFT_ROTATE(REG,BIT) REG^=1<<BIT
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)

#endif
