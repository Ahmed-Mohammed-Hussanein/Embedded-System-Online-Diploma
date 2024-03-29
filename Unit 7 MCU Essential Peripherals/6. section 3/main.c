/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103c6_GPIO_Driver.h"
#include "LCD.h"
#include "keypad.h"

int main(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

	uint8_t keys[4][4]=
	{
		{
			'7', '8', '9', '/'
		},

		{
			'4', '5', '6', '*'
		},

		{
			'1', '2', '3', '-'
		},

		{
			'?', '0', '=', '+'
		}
	};

	LCD_controlConfig_t lcd;
	lcd.LCD_controlPort			=	LCD_CTRL_PORT_A;
	lcd.LCD_RS_pin				=	LCD_CTRL_PIN_8;
	lcd.LCD_RW_pin				=	LCD_CTRL_PIN_9;
	lcd.LCD_EN_pin				=	LCD_CTRL_PIN_10;

	HAL_Keypad_Init();
	HAL_LCD_Init(&lcd);

//	HAL_LCD_writeString(&lcd, (uint8_t*)"Ahmed Mohammed");


    while(1)
    {
		uint8_t key = HAL_Keypad_getKey(keys);
		if (key != '\0')
		{
			HAL_LCD_writeChar(&lcd, key);
		}
    }
}
