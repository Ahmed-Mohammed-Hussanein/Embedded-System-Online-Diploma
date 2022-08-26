#include "Platform_Types.h"

#define SET(port, pin) 		port |= (1<<pin)
#define TOGGLE(port, pin) 	port ^= (1<<pin)

#define RCC_BASEADDRESS      0x40021000
#define GPIO_PA_BASEADDRESS  0x40010800

#define RCC_APB2ENR			 *(volatile uint32*)(RCC_BASEADDRESS + 0x18)
#define GPIO_CRH			 *(volatile uint32*)(GPIO_PA_BASEADDRESS + 0x04)
#define GPIO_ORD			 *(volatile uint32*)(GPIO_PA_BASEADDRESS + 0x0c)

typedef union
{
	volatile uint32 all_pins;
	struct
	{
		volatile uint32 reserved:13;
		volatile uint32 pin13:1;
	} pins;

} ORD_Register_t;

extern void NMI_handler(void)
{

}

extern void HardFault_handler(void)
{

}

volatile ORD_Register_t *ORD_Reg = (volatile ORD_Register_t *) (GPIO_PA_BASEADDRESS + 0x0c);
uint8 MyName[] = "Ahmed Mohammed Hussanein Ali";
uint32 g;
const uint8 MyHeight = 170;

int main(void)
{
	uint32 i;
	SET(RCC_APB2ENR, 2);
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;

	/* Loop forever */
	for(;;)
	{
		ORD_Reg->pins.pin13 = 0;
		for(i = 0; i<100000; ++i);
		ORD_Reg->pins.pin13 = 1;
		for(i = 0; i<100000; ++i);
	}
}