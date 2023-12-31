/*
 * GPIO_private.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed Yassin
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_


#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"


#define GPIO_PORTA_BASE_ADDRESS 0x40010800
#define GPIO_PORTB_BASE_ADDRESS 0x40010C00
#define GPIO_PORTC_BASE_ADDRESS 0x40011000
#define GPIO_PORTD_BASE_ADDRESS 0x40011400
typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIO_TYPE;



#define GPIOA              ((GPIO_TYPE*)GPIO_PORTA_BASE_ADDRESS)
#define GPIOB              ((GPIO_TYPE*)GPIO_PORTB_BASE_ADDRESS)
#define GPIOC              ((GPIO_TYPE*)GPIO_PORTC_BASE_ADDRESS)

//#define GPIOD              ((GPIO_TYPE*)GPIO_PORTD_BASE_ADDRESS)

#define NOT_USED  255

typedef enum
{
	LOW,
	HIGH

}Dio_LevelType,Dio_PortLevelType, PIN_STATE_E ;


typedef enum
{
	A0=0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	A8,
	A9,
	A10,
	A11,
	A12,
	A13,
	A14,
	A15,
	B0,
	B1,
	B2,
	B3,
	B4,
	B5,
	B6,
	B7,
	B8,
	B9,
	B10,
	B11,
	B12,
	B13,
	B14,
	B15,
	C0,
	C1,
	C2,
	C3,
	C4,
	C5,
	C6,
	C7,
	C8,
	C9,
	C10,
	C11,
	C12,
	C13,
	C14,
	C15

}Dio_ChannelType;

typedef enum
{
	PORTA,
	PORTB,
	PORTC

}Dio_PortType, PORT_IDs_E;

/*Function id*/
typedef enum
{
	GPIO_VidInitId,
	GPIO_SET_PIN_VALUEId,
	GPIO_voidSetPinValueBSRRId,
	GPIO_GET_PIN_VALUEId
}GPIO_FunctionsIDs_E;

/*Errors id*/
typedef enum{
	GPIO_invalidPortId,
	GPIO_invalidPinId,
	GPIO_invalidModeId,
	GPIO_invalidValueHighLowId
}GPIO_ErrorsIDs_E;


typedef enum
{
	PIN0  ,
	PIN1  ,
	PIN2  ,
	PIN3  ,
	PIN4  ,
	PIN5  ,
	PIN6  ,
	PIN7  ,
	PIN8  ,
	PIN9  ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
	PIN15
}PIN_IDs_E;


#define SW_RELEASE_VERSION  1
#define SW_MAJOR_VERSION    0
#define SW_MINOR_VERSION    0

typedef struct {
u8 Major;
u8 Minor;

}Std_VersionInfoType;
typedef enum {
	INPUT			 = 	   0x0 , /*00 : Input mode	*/
	OUTPUT_10        =     0x1 , /*01 : Output mode, max speed 10 MHz. */
	OUTPUT_2         =     0x2 , /*10 : Output mode, max speed 2 MHz. */
	OUTPUT_50        =     0x3 , /*11 : Output mode, max speed 50 MHz. */

	/* In output mode (MODE[1:0] > 00) : */
	G_PUSH_PULL      =     0x0 , /*00: General purpose output push-pull */
	G_OPEN_DRAIN     =     0x4 , /*01: General purpose output Open-drain*/
	A_PUSH_PULL      =     0x8 , /*10: Alternative purpose output push-pull */
	A_OPEN_DRAIN     =     0xC , /*11: Alternative purpose output Open-drain*/
	NONE_OUTPUT      =     0x0 ,

	/*  In input mode (MODE[1:0]=00): */
	ANA_MODE         =     0x0  ,
	FLOATING_INPUT   =     0x4  ,
	INPUT_PULL_DOWN  =     0x8  ,
	NONE_INPUT       =     0x0
}Port_PinModeType;

#endif /* MGPIO_PRIVATE_H_ */
