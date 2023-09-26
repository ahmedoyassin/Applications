/*
 * main.c
 *
 *  Created on: 18/12/2022
 *  Author: ENG/Shehab aldeen
 */

#include "APP_DRIVER/MultipleTasksCar_Interface.h"

void main (){
	/* initializiation function of car  */
	MultipleTasksCar_VidInit();

	/* to set the mode of the car */
	u8 mode ;
	u8 FlagInitialMode = LOW ;

	while (1){

		if (FlagInitialMode ==  LOW){
			mode = MultipleTasksCar_GetMode() ;
		}//end if

		if (mode == '1'){
			/* to get the directions of car */
			MultipleTasksCar_GetDirections();

			/* no to enter mode again */
			FlagInitialMode = HIGH ;
		}//end if mode

		if (mode == '2'){
			/* to set LineFollower mode */
			MultipleTasksCar_LineFollower();

			/* no to enter mode again */
			FlagInitialMode = HIGH ;
		}//end if mode

		if (mode == '3'){
			/* to set LineFollower mode */
			MultipleTasksCar_UltraSonic();

			/* no to enter mode again */
			FlagInitialMode = HIGH ;
		}//end if mode

	}//end while(1)
}
