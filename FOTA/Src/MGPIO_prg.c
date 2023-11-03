/*
 * GPIO_prg.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed Yassin
 */

#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"
#include "MGPIO_interface.h"

void Port_SetPinDirection(Dio_ChannelType Copy_U8Pin,u8 Copy_U8Direction)
{
	if ( Copy_U8Pin >= A0  && Copy_U8Pin <= A15 ){
		if (Copy_U8Pin <= A7){
			GPIOA->CRL &= ~((0xF) << ( Copy_U8Pin * 4));
			GPIOA->CRL |= ( Copy_U8Direction <<(Copy_U8Pin  * 4) ) ;
		}
		else {
			GPIOA->CRH &= ~((0xF) << ( (Copy_U8Pin -8) * 4));
			GPIOA->CRH |= ( Copy_U8Direction <<( (Copy_U8Pin -8)*4) ) ;
		}
	}
	else if (Copy_U8Pin >= B0  && Copy_U8Pin <= B15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(Copy_U8Pin,4);

		if (Copy_U8Pin  <= A7 ){
			GPIOB->CRL &= ~((0xF) << ( Copy_U8Pin * 4));
			GPIOB->CRL |= ( Copy_U8Direction << (Copy_U8Pin *4) ) ;
		}
		else {
			GPIOB->CRH &= ~((0xF) << ( (Copy_U8Pin -8) * 4));
			GPIOB->CRH |= ( Copy_U8Direction <<( (Copy_U8Pin -8)*4) ) ;
		}
	}
	else if (Copy_U8Pin >= C13  && Copy_U8Pin <= C15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(Copy_U8Pin,5);

		GPIOC->CRH &= ~((0xF) << ( (Copy_U8Pin -8) * 4));
		GPIOC->CRH |= ( Copy_U8Direction <<( ((Copy_U8Pin -8)*4))) ;
	}
}


void Port_SetPinMode(Dio_ChannelType Copy_U8Pin,Port_PinModeType Copy_U8Mode)
{
	if ( Copy_U8Pin >= A0  && Copy_U8Pin <= A15 ){
		if (Copy_U8Pin <= A7){
			GPIOA->CRL |= ( Copy_U8Mode <<(Copy_U8Pin  * 4) ) ;
		}
		else {
			GPIOA->CRH |= ( Copy_U8Mode <<( (Copy_U8Pin -8)*4) ) ;
		}
	}
	else if (Copy_U8Pin >= B0  && Copy_U8Pin <= B15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(Copy_U8Pin,4);

		if (Copy_U8Pin  <= A7 ){
			GPIOB->CRL |= ( Copy_U8Mode << (Copy_U8Pin *4) ) ;
		}
		else {
			GPIOB->CRH |= ( Copy_U8Mode <<( (Copy_U8Pin -8)*4) ) ;
		}
	}
	else if (Copy_U8Pin >= C13  && Copy_U8Pin <= C15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(Copy_U8Pin,5);
		GPIOB->CRH |= ( Copy_U8Mode <<( (Copy_U8Pin -8)*4) ) ;
	}
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	u8 U8copy_Get;
	if ( ChannelId >= A0 && ChannelId <= A15 )
{

	U8copy_Get =GET_BIT(GPIOA -> IDR,ChannelId);
		if(U8copy_Get == 1)
		{
			return HIGH;
		}
		else
		{
			return LOW;
		}
}
	else if ( ChannelId >= B0  && ChannelId <= B15 )
{
		U8copy_Get =GET_BIT(GPIOB -> IDR,(ChannelId-16));
		if(U8copy_Get == 1)
		{
			return HIGH;
		}
		else
		{
			return LOW;
		}
}
	else if ( ChannelId >= C0  && ChannelId <= C15 )
		{
			 U8copy_Get =GET_BIT(GPIOC -> IDR,(ChannelId-32));
			if(U8copy_Get == 1)
			{
return HIGH;
			}
			else
			{
return LOW;
			}
		}
}

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	if ( ChannelId >= A0 && ChannelId <= A15 )
	{	if(Level ==HIGH){
	SET_BIT(GPIOA ->BSRR, ChannelId);
}
else
{
	SET_BIT(GPIOA->BRR,ChannelId);
}
}
	if ( ChannelId >= B0 && ChannelId <= B15 )
	{			CLR_BIT(ChannelId,4);

		if(Level ==HIGH){
	SET_BIT(GPIOB ->BSRR, ChannelId);
}
else
{
	SET_BIT(GPIOB->BRR,ChannelId);
}
}
	else if ( ChannelId >= C0 && ChannelId <= C15 )
	{			CLR_BIT(ChannelId,5);
		if(Level ==HIGH){
	SET_BIT(GPIOC ->BSRR, ChannelId);
}
else
{
	SET_BIT(GPIOC->BRR,ChannelId);
}
}
}


void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{
if (Level == HIGH)
	{
 	if (PortId == PORTA){
 		GPIOA ->ODR=0x0000FFFF;
 }
 else if (PortId == PORTB){
	 GPIOB ->ODR=0x0000FFFF;
 }
 else{
	 GPIOC ->ODR=0x0000FFFF;
 	 }
 }

else if (Level == LOW)

 	if (PortId == PORTA){
 		GPIOA ->ODR=0x00000000;
 }
 else if (PortId == PORTB){
	 GPIOB ->ODR=0x00000000;
 }
 else{
	 GPIOC ->ODR=0x00000000;
 	 }
}

void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo )
{
	VersionInfo->Major = SW_MAJOR_VERSION;
	VersionInfo->Minor = SW_MINOR_VERSION;
}

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	u8 U8copy_Get;
	if(ChannelId < 16)
	{
	U8copy_Get =GET_BIT(GPIOA -> IDR,ChannelId);
		if(U8copy_Get == 1)
		{
			return LOW;
		}
		else
		{
			return HIGH;
		}

	}
	else if((ChannelId >= 16) && (ChannelId < 32))
	{
		 U8copy_Get =GET_BIT(GPIOB -> IDR,(ChannelId - 16));
		if(U8copy_Get == 1)
		{
			return LOW;
		}
		else
		{
			return HIGH;
		}
	}
	else
		{
		if(U8copy_Get == 1)
		{
			return LOW;
		}
		else
		{
			return HIGH;
		}
	}
}
