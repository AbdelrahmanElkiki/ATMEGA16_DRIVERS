/***********************************************************************
 * [FILE NAME]    : <keypad.c>              						   *
 * [AUTHOR]       : <Abdelrahman>									   *
 * [DATE CREATED] : <2/2/2020>										   *
 * [DESCRIPTION]  : <This File Contain The Source Code Of The Keypad   *
 *                   Module.>                                          *
 ***********************************************************************/

/*----------Header Files----------------------------*/

#include "keypad.h"

/*----------(Private)Function Prototype------------*/
#if(N_COL == 3)
static uint8 Keypad_4x3_adjustSwitchNumber(uint8 a_button);
#elif(N_COL == 4)
static uint8 Keypad_4x4_adjustSwitchNumber(uint8 a_button);
#endif

/*-----------Function Definitions-----------*/

/*-----------------------------------------------------------------------------------------
 * [Function Name] : Keypad_getPressedKey
 * [Args]          : the function dont take any arguments
 * [Return]        : its return uint8 data of the key
 * 					 pressed for the keypad
 * [Description]   : This function return the key pressed
 * 					 by the keypad
 *-----------------------------------------------------------------------------------------*/
uint8 Keypad_getPressedKey(void)
{
	uint8 row,col;
	/*
	 * Using The polling Because of the Microcontroller High Speed so
	 * We cant Sense The Key pressed so We used polling to w8 untill
	 * key pressed
	 * */
	while(1)
	{
	for(col=0;col<N_COL;col++)
	{
		/*
		 * Every Iteration Only One column will be output and other will input
		 **/
		KEYPAD_PORT_DIRC   =  (0b00010000<<col);
		/*
		 * The output column will out 0
		 * but other column will out 1
		 **/
		KEYPAD_PORT_OUTPUT =  (~(0b00010000<<col));
		/*
		 * We Start To check the Rows
		 * and At the Same Time We Active the
		 * pull-up resistors for the RowS
		 * */
		for(row=0;row<N_ROW;row++)
		{
			if(BIT_IS_CLEAR(KEYPAD_PORT_INPUT,row))
			{
				#if(N_COL == 4)
					return Keypad_4x4_adjustSwitchNumber((row*N_COL)+col+1);
				#elif (N_COL == 3)
					return Keypad_4x3_adjustSwitchNumber((row*N_COL)+col+1);
				#endif

			}
		}
	}
	}
}

/*-----------------------------------------------------------------------------------------
 * [Function Name] : Keypad_4x3_adjustSwitchNumber
 * [Description]   : This function return the key pressed
 * 					 by the keypad,
 * 					 This Function Is private to Module ,other Modules Cant extern it
 * [Args]          :
 * [IN]            :
 * 				     uint8 a_button
 * 				     		this argument contain The number of the key pressed
 *
 * [Return]        : its return the actual pressed key
 *-----------------------------------------------------------------------------------------*/
#if(N_COL == 3)
static uint8 Keypad_4x3_adjustSwitchNumber(uint8 a_button)
{
	switch(a_button)
	{
	case 10: return '*';
		break;
	case 11: return 0;
		break;
	case 12: return '#';
		break;
	default: 	return a_button;
	}
}
#elif(N_COL == 4)
/*-----------------------------------------------------------------------------------------
 * [Function Name] : Keypad_4x4_adjustSwitchNumber
 * [Description]   : This function return the key pressed
 * 					 by the keypad,
 * 					 This Function Is private to Module ,other Modules Cant extern it
 * [Args]          :
 * [IN]            :
 * 				     uint8 a_button
 * 				     		this argument contain The number of the key pressed
 *
 * [Return]        : its return the actual pressed key
 *-----------------------------------------------------------------------------------------*/
static uint8 Keypad_4x4_adjustSwitchNumber(uint8 a_button)
{
	switch(a_button)
	{
	case 1: return   7;
		break;
	case 2: return   8;
			break;
	case 3: return   9;
			break;
	case 4: return   '%'; /* return Asci*/
			break;
	case 5: return   6;
			break;
	case 6: return   5;
			break;
	case 7: return   4;
			break;
	case 8: return   '*';
			break;
	case 9: return   1;
			break;
	case 10: return   2;
			break;
	case 11: return   3;
			break;
	case 12: return   '-';
			break;
	case 13: return   13;
			break;
	case 14: return   0;
			break;
	case 15: return   '=';
			break;
	case 16: return   '+';
			break;
	default: 	return a_button;
	}
}
#endif
