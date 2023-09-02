/*
 * Task1.c
 *
 * Created: 9/7/2022 9:59:23 PM
 *  Author: Ahmed
 */ 

#include "Platform_Types.h"
#include "Utils.h"
#include "MemMap.h"

void DIO_Init(void)
{
	DDRA = 0xff;
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
	uint8_t i;
	
	DIO_Init();
    while(1)
    {
        //TODO:: Please write your application code
		for (i = 0; i<8; ++i)
		{
			SETBIT(PORTA, i);
			wait(delay);
		}
		
		for (i = 8; i>0; --i)
		{
			CLEARBIT(PORTA, i-1);
			wait(delay);
		}
		 
    }
}