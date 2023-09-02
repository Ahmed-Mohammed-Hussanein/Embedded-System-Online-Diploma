/*
 * lcd_driver.c
 *
 * Created: 8/30/2023 6:20:37 PM
 *  Author: Ahmed
 */ 

#define F_CPU	1000000UL

#include <avr/io.h>

#include "atmega32_GPIO_Driver.h"
#include "LCD.h"
#include "keypad.h"

int main(void)
{
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
	lcd.LCD_controlPort			=	LCD_CTRL_PORT_B;
	lcd.LCD_RS_pin				=	LCD_CTRL_PIN_2;
	lcd.LCD_RW_pin				=	LCD_CTRL_PIN_1;
	lcd.LCD_EN_pin				=	LCD_CTRL_PIN_0;
	
	HAL_LCD_Init(&lcd);
	HAL_Keypad_Init();
	
    while(1)
    {	
		uint8_t key = HAL_Keypad_getKey(keys);
		if (key != '\0')
		{
			HAL_LCD_writeChar(&lcd, key);
		}
    }
}