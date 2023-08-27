/* 
	Ahmed Mohammed Hussanein Ali
	Unit 6 lesson 3 lab 2
	STM32F103C6 ARM CortexM3
	Clock Configuration
	*/

#include "Platform_Types.h"

#define SET(reg, bit) 				reg |= (1<<bit)
#define TOGGLE(reg, bit) 			reg ^= (1<<bit)

#define RCC_BASEADDRESS      0x40021000
#define GPIO_PA_BASEADDRESS  0x40010800

#define RCC_CR				 *(volatile uint32*)(RCC_BASEADDRESS + 0x00)
#define RCC_APB2ENR			 *(volatile uint32*)(RCC_BASEADDRESS + 0x18)

#define GPIO_CRH			 *(volatile uint32*)(GPIO_PA_BASEADDRESS + 0x04)
#define GPIO_ORD			 *(volatile uint32*)(GPIO_PA_BASEADDRESS + 0x0c)

#pragma pack(1)
typedef union
{
	uint32 RCC_CFGR;
	struct
	{
		uint32 SW:2;
		uint32 SWS:2;
		uint32 HPRE:4;
		uint32 PPRE1:3;
		uint32 PPRE2:3;
		uint32 ADCPRE:2;
		uint32 PLLSRC:1;
		uint32 PLLXTPRE:1;
		uint32 PLLMUL:4;
		uint32 USBPRE:1;
		uint32 reserved1:1;
		uint32 MCO:3;
		uint32 reserved2:5;
	} S_RCC_CFGR;
} U_RCC_CFGR;

volatile U_RCC_CFGR* CFGR = (volatile U_RCC_CFGR*) (RCC_BASEADDRESS + 0x04);

void clock_init(void)
{
	SET(RCC_CR, 1);  					// Enable HSI_RC
	CFGR->S_RCC_CFGR.PLLSRC = 0b0;
	CFGR->S_RCC_CFGR.PLLMUL = 0b0110;	// x8
	CFGR->S_RCC_CFGR.SW = 0b10;			// PLL selected
	CFGR->S_RCC_CFGR.PPRE1 = 0b100;		// APB1 prescaler /2
	CFGR->S_RCC_CFGR.PPRE2 = 0b101;		// APB2 prescaler /4
	SET(RCC_CR, 24);
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