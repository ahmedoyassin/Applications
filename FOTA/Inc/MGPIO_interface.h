/*
 * GPIO_interface.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed Yassin
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_private.h"

void Port_SetPinDirection(Dio_ChannelType Copy_U8Pin,u8 Copy_U8Direction);
void Port_SetPinMode(Dio_ChannelType Copy_U8Pin,Port_PinModeType Copy_U8Mode);

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level);
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);

#endif /* MGPIO_INTERFACE_H_ */
