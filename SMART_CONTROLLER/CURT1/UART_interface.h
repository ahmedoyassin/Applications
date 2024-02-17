/*
 * UART_interface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: Ahmed Yassin
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Vidinit();

u8 UART_U8GetChar();
void UART_U8SendChar(u8 data);
void UART_U8StringWriter(u8 *str);


#endif
