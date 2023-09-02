/*
 * assignment.c
 *
 * Created: 9/7/2022 8:15:42 PM
 *  Author: Ahmed
 */ 

#include "Platform_Types.h"

/*	4 ports in atmega32 (A, B, C, D)
 *	port x has 8 pins 
 *	each pin has 3 bit for configuration in 3 different registers
 *	DDRx register to configure the pin if it is INPUT or OUTPUT by writing 0 or 1 respectively to the corresponding bit.
 *	if pin is configured as OUTPUT then register PORTx is used to write logic 1 or 0 to the corresponding bit.
 *	if pin is configured as INPUT then register PINx is used to read only the status of the pin from the corresponding bit.
 *	if the pin is configured as INPUT and the corresponding bit in PORTx register is set then internal Pull Up Resistor is activated.
 *	if this bit is reset then internal Pull Up Resistor is deactivated.
 */


/**************** Port A Registers Addresses ***************/
#define PORTA	*(vuint8_t *) (0x3B)
#define DDRA	*(vuint8_t *) (0x3A)
#define PINA	*(vuint8_t *) (0x39)

/*************** Useful Macros ******************/
#define SET(reg, bit) (reg |= (1<<(bit)))
#define CLEAR(reg, bit) (reg &= ~(1<<(bit)))

/*************** HW pins *******************/
#define RED_PIN				0
#define GREEN_PIN			1
#define YELLOW_PIN			2
#define BUZZER_PIN			3

void DIO_Init(void)
{
	SET(DDRA, RED_PIN);
	SET(DDRA, GREEN_PIN);
	SET(DDRA, YELLOW_PIN);
	SET(DDRA, BUZZER_PIN);
}

void wait(uint8_t time)
{
	vuint16_t i, j;
	for (i = 0; i<time; ++i)
		for(j = 0; j<1000; ++j);
}

// custom delay 
#define delay 50

int main(void)
{
	DIO_Init();
	
    while(1)
    {
        //TODO:: Please write your application code 
		SET(PORTA, RED_PIN);
		wait(delay);
		
		CLEAR(PORTA, RED_PIN);
		SET(PORTA, GREEN_PIN);
		wait(delay);
		
		CLEAR(PORTA, GREEN_PIN);
		SET(PORTA, YELLOW_PIN);
		wait(delay);
		
		CLEAR(PORTA, YELLOW_PIN);
		SET(PORTA, BUZZER_PIN);
		wait(delay);
		
		CLEAR(PORTA, BUZZER_PIN);
    }
}