/***********************************************************************
 * [FILE NAME]    : <keypad.h>              						   *
 * [AUTHOR]       : <Abdelrahman>									   *
 * [DATE CREATED] : <2/2/2020>										   *
 * [DESCRIPTION]  : <Header File Of The Keypad module>                 *                                          *
 ***********************************************************************/
/*Guard Header*/
#ifndef KEYPAD_H_
#define KEYPAD_H_
/***************************************************
 *             (Common)Header Files                *
 ***************************************************/
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
/***************************************************
 *             PreProssecor Macros                 *
 ***************************************************/
#define N_COL 4
#define N_ROW 4

#define KEYPAD_PORT_OUTPUT PORTA
#define KEYPAD_PORT_INPUT  PINA
#define KEYPAD_PORT_DIRC   DDRA

/***************************************************
 *        (Public)Function Prototype               *
 ***************************************************/

/*
 *	Function To get the key pressed by the keypad
 * */
uint8 Keypad_getPressedKey(void);
#endif /* KEYPAD_H_ */
