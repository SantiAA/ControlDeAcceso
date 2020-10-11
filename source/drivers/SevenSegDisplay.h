/***************************************************************************//**
  @file     7SegDisplay.c
  @brief    7 Segment Display Header
  @author   Grupo 2 - Lab de Micros
 ******************************************************************************/

#ifndef SEVENSEGDISPLAY_H_
#define SEVENSEGDISPLAY_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define NONE	(uint8_t)0x00
#define ZERO	(uint8_t)0x3F
#define ONE		(uint8_t)0x06
#define TWO		(uint8_t)0x5B
#define THREE	(uint8_t)0x4F
#define FOUR	(uint8_t)0x66
#define FIVE	(uint8_t)0x6D
#define SIX		(uint8_t)0x7D
#define SEVEN	(uint8_t)0x07
#define EIGHT	(uint8_t)0x7F
#define NINE	(uint8_t)0x6F
#define LINE	(uint8_t)0x80

#define MASK	(uint8_t)0x01

#define CHARS 	{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, LINE, NONE}

#define SEG_LEN	8
#define SEL_LEN	2

#define RESET_BLINK -1

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef enum {
	MAX = 6,
	MID = 3,
	MIN = 1
}bright_t;


typedef  struct
{
	uint8_t character;
	bool blink;
}sevenSeg_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

bool SevenSegDisplay_Init(void);

bool SevenSegDisplay_ChangeCharacter(uint8_t screen_char, uint8_t new_char);

void SevenSegDisplay_EraseScreen(void);

bool SevenSegDisplay_ToggleBlinkScreen(void);

void SevenSegDisplay_SetBright(bright_t new_bright);

/**
 * @brief select a digit to blink or reset blinks
 * @param digit, the number that corresponds to the 7segments display
 * @return blink succeed, false if there was an error with the digit
 */
bool SevenSegDisplay_BlinkCharacter(uint8_t digit);

//bool SevenSegDisplay_ShiftLeft(void);

//bool SevenSegDisplay_ShiftRight(void);


#endif /* SEVENSEGDISPLAY_H_ */
