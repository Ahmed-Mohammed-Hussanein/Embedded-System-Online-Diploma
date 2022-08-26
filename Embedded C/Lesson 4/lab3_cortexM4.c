/* Ahmed Mohammed Hussanein Ali
	Lab 2 lesson 3
	application: toggling led connected to port F pin 3 for ARM cortexM4
	TM4C123GH6PZ physical board
	*/

#include "Platform_Types.h"

#define SET(Reg, bit) 	Reg |= (1<<bit)
#define CLEAR(Reg, bit) Reg &= ~(1<<bit)

#define SYSCTL_RCGC2_R 			*(volatile uint32*) (0x400FE000 + 0x108)
#define GPIO_PORTF_DIR_R 		*(volatile uint32*) (0x40025000 + 0x400)
#define GPIO_PORTF_DEN_R 		*(volatile uint32*) (0x40025000 + 0x51C)
#define GPIO_PORTF_DATA_R 		*(volatile uint32*) (0x40025000 + 0x3FC)


int main()
{
	volatile uint32 delayCount;

	SYSCTL_RCGC2_R &= 0xFFFFFF0F;
	for(delayCount = 0; delayCount < 200; ++delayCount);

	SYSCTL_RCGC2_R |= 0x00000020;
	for(delayCount = 0; delayCount < 200; ++delayCount);

	SET(GPIO_PORTF_DIR_R, 3);
	SET(GPIO_PORTF_DEN_R, 3);

	while(1)
	{
		SET(GPIO_PORTF_DATA_R, 3);
		for(delayCount = 0; delayCount < 200000; ++delayCount);

		CLEAR(GPIO_PORTF_DATA_R, 3);
		for(delayCount = 0; delayCount < 200000; ++delayCount);
	}


	return 0;
}