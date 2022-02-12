#include "Platform_Types.h"

#define SET(port, pin) 		port |= (1<<pin)
#define TOGGLE(port, pin)	port ^= (1<<pin)
#define CLEAR(port, value) 	port &= value
#define WRITE(port, value) 	port |= value

#define RCA_BASEADDRESS		0x40021000
#define GPIOA_BASEADDRESS	0x40010800

#define RCA_APB2ENR			*(volatile uint32*) (RCA_BASEADDRESS + 0x18)
#define GPIOA_CRH			*(volatile uint32*) (GPIOA_BASEADDRESS + 0x04)
#define GPIOA_ORD			*(volatile uint32*)	(GPIOA_BASEADDRESS + 0x0C)


int main()
{
	int i;
	SET(GPIOA_CRH, 2);
	CLEAR(GPIOA_CRH, 0xFF0FFFFF);
	WRITE(GPIOA_CRH, 0x00200000);
	for (;;)
	{
		TOGGLE(GPIOA_ORD, 13);
		for (i = 0; i < 1000000; ++i);
		TOGGLE(GPIOA_ORD, 13);
		for (i = 0; i < 1000000; ++i);
	}
}