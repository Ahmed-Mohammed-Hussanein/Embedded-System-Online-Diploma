/*
 * lesson4_lab3.c
 *
 * Created: 9/4/2022 12:01:19 AM
 *  Author: Ahmed
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

void DIO_init(void)
{
	/* PD5, PD6 and PD7 are output and PD2, PD3 and PB2 are input */
	DDRD = 0b11100000;
	PORTD = 0b00000000;
	
	DDRB = 0b00000000;
}

void EXTI_init(void)
{
	/* configure INT0 any logical change 
	and INT1 rising edge */
	MCUCR = 0b00001101;
	
	/* configure INT2 falling edge */
	MCUCSR &= ~(1<<6);
	
	/* enable general interrupt */
	__asm__("SEI");
	
	/* enable INT0, INT1 and INT2 */
	GICR = 0b11100000;
}

int main(void)
{
	DIO_init();
	EXTI_init();
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

ISR(INT0_vect)
{
	PORTD |= (1<<5);
	_delay_ms(1000);
	PORTD &= ~(1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(1000);
	PORTD &= ~(1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
	PORTD &= ~(1<<7);
	_delay_ms(1000);
}