/*
 * main.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed
 */



#define F_CPU 8000000UL

#include "CURT2_interface.h"
#include "SERVOMOTOR_interface.h"
#include <util/delay.h>

int main()
{
	CURT2_VidInit();
	while(1)
	{

		Check_States();
	}

}//end main

