/*
 * lcd_driver.c
 *
 * Created: 8/30/2023 6:20:37 PM
 *  Author: Ahmed
 */ 

#define F_CPU	8000000UL

#include <avr/io.h>

#include "atmega32_GPIO_Driver.h"
#include "LCD.h"

int main(void)
{
	LCD_controlConfig_t lcd;
	lcd.LCD_controlPort			=	LCD_CTRL_PORT_B;
	lcd.LCD_RS_pin				=	LCD_CTRL_PIN_1;
	lcd.LCD_RW_pin				=	LCD_CTRL_PIN_2;
	lcd.LCD_EN_pin				=	LCD_CTRL_PIN_3;
	
	HAL_LCD_Init(&lcd);
	
	uint8_t str[] = "Learn-In-Dep\xCBh.";
	
	uint8_t delay = 100;
	
	uint8_t i;
    while(1)
    {
		for(i = 0; i < 15; i++)
		{
			HAL_LCD_writeChar(&lcd, str[i]);
			_delay_ms(delay);
		}
		
		HAL_LCD_autoShiftLeft(&lcd);
		HAL_LCD_GoXY(&lcd, 15, 1);
		
		for(i = 0; i < 15; i++)
		{
			HAL_LCD_writeChar(&lcd, str[i]);
			_delay_ms(delay);
		}
		
		HAL_LCD_noAutoShiftLeft(&lcd);
		
		for(i = 0; i < 7; i++)
		{
			HAL_LCD_displayOff(&lcd);
			_delay_ms(delay);
			HAL_LCD_displayOn(&lcd);
			_delay_ms(delay);
		}
		
		HAL_LCD_Clear(&lcd);
		HAL_LCD_GoXY(&lcd, 0, 0);
		
    }
}