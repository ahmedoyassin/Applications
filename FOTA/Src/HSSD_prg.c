/*
 * HSSD_prg.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Ahmed Yassin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"


#include "HSSD_interface.h"
#include "HSSD_private.h"
#include "HSSD_cfg.h"

/******************************************************************************/
/* Syntax           : u8 HSSD_u8DisplayNumber(u8 Copy_u8Type , u8 Copy_u8Number , u8 Copy_u8Port , u8 Copy_u8HalfPort)
 * Description      : Display Number on Seven sesgment which connected to full half port
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Type , Copy_u8Number , Copy_u8Port , Copy_u8HalfPort
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 HSSD_u8DisplayNumber(u8 Copy_u8Number)
{

	u8 SSD_ZERO[7] = {0,0,1,1,1,1,1,1};
	u8 SSD_ONE[7] = {0,1,1,0,0,0,0,0};
	u8 SSD_TWO[7] = {1,1,0,1,1,0,1,1};
	u8 SSD_THREE[7] = {1,1,1,1,0,0,1,0};
	u8 SSD_FOUR[7] = {0,1,1,0,0,1,1,0};
	u8 SSD_FIVE[7] = {1,0,1,1,0,1,1,1};
	u8 SSD_SIX[7]	={1,0,1,1,1,1,1,1};
	u8 Pins[7] = {A0,A1,A8,A9,A10,A11,A12};
	Port_SetPinDirection(A0,OUTPUT_2);
	Port_SetPinDirection(A1,OUTPUT_2);
	Port_SetPinDirection(A8,OUTPUT_2);
	Port_SetPinDirection(A9,OUTPUT_2);
	Port_SetPinDirection(A10,OUTPUT_2);
	Port_SetPinDirection(A11,OUTPUT_2);
	Port_SetPinDirection(A12,OUTPUT_2);

	switch(Copy_u8Number)
	{
	case SSD_NUMBER0:
		for(int i=0; i<7; i++)
			Dio_WriteChannel(Pins[i],SSD_ZERO[i]);
     break;

	case SSD_NUMBER1:
		for(int i=0; i<7; i++)
			Dio_WriteChannel(Pins[i],SSD_ONE[i]);
		break;

	case SSD_NUMBER2:
		for(int i=0; i<7; i++)
			Dio_WriteChannel(Pins[i],SSD_TWO[i]);
		break;

	case SSD_NUMBER3:
		for(int i=0; i<7; i++)
			Dio_WriteChannel(Pins[i],SSD_THREE[i]);
		break;

	case SSD_NUMBER4:
		for(int i=0; i<7; i++)
			Dio_WriteChannel(Pins[i],SSD_FOUR[i]);
		break;

	case SSD_NUMBER5:
		for(int i=0; i<7; i++)
			Dio_WriteChannel(Pins[i],SSD_FIVE[i]);
		break;

	case SSD_NUMBER6:
		for(int i=0; i<7; i++)
			Dio_WriteChannel(Pins[i],SSD_SIX[i]);
		break;
	}
}

/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/

