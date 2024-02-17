/*
 * main.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed Yassin
 */



#define F_CPU 8000000UL

#include "CURT1_interface.h"


int main()
{
	CURT1_VidInit();
	while(1)
	{
		StateOfFunAndBuzzer();
	}

}//end main

