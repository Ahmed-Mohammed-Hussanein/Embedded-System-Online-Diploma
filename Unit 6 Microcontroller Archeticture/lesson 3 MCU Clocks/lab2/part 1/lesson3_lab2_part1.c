/* 
	Ahmed Mohammed Hussanein Ali
	Unit 6 lesson 3 lab 2
	STM32F103C6 ARM CortexM3
	Clock Configuration
	*/

#include "Platform_Types.h"

#define SET(port, pin) 		port |= (1<<pin)
#define TOGGLE(port, pin) 	port ^= (1<<pin)

#define RCC_BASEADDRESS      0x40021000
#define GPIO_PA_BASEADDRESS  0x40010800

#define RCC_CR				 *(volatile uint32*)(RCC_BASEADDRESS + 0x00)
#define RCC_CFGR			 *(volatile uint32*)(RCC_BASEADDRESS + 0x04)
#define RCC_APB2ENR			 *(volatile uint32*)(RCC_BASEADDRESS + 0x18)

#define GPIO_CRH			 *(volatile uint32*)(GPIO_PA_BASEADDRESS + 0x04)
#define GPIO_ORD			 *(volatile uint32*)(GPIO_PA_BASEADDRESS + 0x0c)

void clock_init(void)
{
	SET(RCC_CR, 1);
	RCC_CFGR &= ~(0b00);
	RCC_CFGR |= (0b100 << 8);
	RCC_CFGR |= (0b101 << 11);
	SET(RCC_APB2ENR, 2);
}

int main(void)
{
	uint32 i;
	clock_init();
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;
	SET(GPIO_ORD, 13);
	/* Loop forever */
	for(;;)
	{
		TOGGLE(GPIO_ORD, 13);
		for(i = 0; i<100000; ++i);
		TOGGLE(GPIO_ORD, 13);
		for(i = 0; i<100000; ++i);
	}
}