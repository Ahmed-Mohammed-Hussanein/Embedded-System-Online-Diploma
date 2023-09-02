/*
 * keypad.h
 *
 * Created: 8/31/2023 2:48:34 PM
 *  Author: Ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"
#include "stm32f103c6_GPIO_Driver.h"


// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

#define COL_PORT		KEYPAD_PORT_B		// This specifies port for columns for keypad.
											//  This parameter must be a value of @ref KEYPAD_PORT_define.

#define COL_0			KEYPAD_PIN_5		// This specifies pin for left column for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.
				
#define COL_1			KEYPAD_PIN_6		// This specifies pin for the second left column for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.
											
#define COL_2			KEYPAD_PIN_7		// This specifies pin for the third left column for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.
											
#define COL_3			KEYPAD_PIN_8		// This specifies pin for the fourth left column for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.
											
#define ROW_PORT		KEYPAD_PORT_B		// This specifies port for rows for keypad.
											//  This parameter must be a value of @ref KEYPAD_PORT_define.
											
#define ROW_0			KEYPAD_PIN_0		// This specifies pin for upper row for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.

#define ROW_1			KEYPAD_PIN_1		// This specifies pin for the second upper row for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.

#define ROW_2			KEYPAD_PIN_3		// This specifies pin for the third upper row for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.

#define ROW_3			KEYPAD_PIN_4		// This specifies pin for the fourth upper row for keypad.
											//  This parameter must be a value of @ref KEYPAD_PIN_define.


// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

// @ref KEYPAD_PORT_define.
#define KEYPAD_PORT_A					GPIOA
#define KEYPAD_PORT_B					GPIOB
#define KEYPAD_PORT_C					GPIOC


// @ref KEYPAD_PIN_define.
#define KEYPAD_PIN_0					GPIO_PIN_0
#define KEYPAD_PIN_1					GPIO_PIN_1
#define KEYPAD_PIN_2					GPIO_PIN_2
#define KEYPAD_PIN_3					GPIO_PIN_3
#define KEYPAD_PIN_4					GPIO_PIN_4
#define KEYPAD_PIN_5					GPIO_PIN_5
#define KEYPAD_PIN_6					GPIO_PIN_6
#define KEYPAD_PIN_7					GPIO_PIN_7
#define KEYPAD_PIN_8					GPIO_PIN_8
#define KEYPAD_PIN_9					GPIO_PIN_9
#define KEYPAD_PIN_10					GPIO_PIN_10
#define KEYPAD_PIN_11					GPIO_PIN_11
#define KEYPAD_PIN_12					GPIO_PIN_12
#define KEYPAD_PIN_13					GPIO_PIN_13
#define KEYPAD_PIN_14					GPIO_PIN_14
#define KEYPAD_PIN_15					GPIO_PIN_15


// ===================================================
// ================== APIs Functions =================
// ===================================================
void HAL_Keypad_Init();

uint8_t HAL_Keypad_getKey(uint8_t (*keys) []);


#endif /* KEYPAD_H_ */
