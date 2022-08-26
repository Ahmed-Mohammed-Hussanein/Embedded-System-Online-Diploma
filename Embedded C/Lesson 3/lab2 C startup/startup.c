/* Ahmed Mohammed Hussanein Ali
	Lab 2 lesson 3
	startup.c for ARM cortexM3
	*/

#include "Platform_Types.h"

extern uint32 _stackTop_;

extern int main(void);
void default_handler(void);
void reset_handler(void);
void NMI_handler(void)__attribute__((weak, alias("default_handler")));
void HardFault_handler(void)__attribute__((weak, alias("default_handler")));
void MMFault_handler(void)__attribute__((weak, alias("default_handler")));
void BusFault_handler(void)__attribute__((weak, alias("default_handler")));
void UsageFault_handler(void)__attribute__((weak, alias("default_handler")));

uint32 vectors[] __attribute__((section(".vectors")))= 
{
	//(uint32)0x20001000,
	(uint32)&_stackTop_,
	(uint32)&reset_handler,
	(uint32)&NMI_handler,
	(uint32)&HardFault_handler,
	(uint32)&MMFault_handler,
	(uint32)&BusFault_handler,
	(uint32)&UsageFault_handler
};

void default_handler(void)
{
	reset_handler();
}

extern uint32 _E_TEXT;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;

void reset_handler(void)
{
	uint32 dataSize = (uint8*)&_E_DATA - (uint8*)&_S_DATA;
	uint8* ptr_src = (uint8*)&_E_TEXT;
	uint8* ptr_dst = (uint8*)&_S_DATA;

	uint32 j;
	for(j = 0; j < dataSize; ++j)
	{
		*((uint8*)ptr_dst++) = *((uint8*)ptr_src++);
	}

	/* intializing bss section in sram */
	uint32 bssSize = (uint8*)&_E_BSS - (uint8*)&_S_BSS;
	ptr_dst = (uint8*)&_S_BSS;
	for(j = 0; j < bssSize; ++j)
	{
		*((uint8*)ptr_dst++) = 0;
	}
	main();
}