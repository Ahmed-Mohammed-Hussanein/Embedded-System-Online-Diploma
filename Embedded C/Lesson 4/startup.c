/* Ahmed Mohammed Hussanein Ali
	Lab 2 lesson 3
	startup.c 
	application: toggling led connected to port F pin 3 for ARM cortexM4
	TM4C123GH6PZ physical board
	*/

#include "Platform_Types.h"

extern int main(void);
void Default_Handler();
void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler() __attribute__((weak, alias("Default_Handler")));
void MM_fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_fault() __attribute__((weak, alias("Default_Handler")));
void Usage_fault_Handler() __attribute__((weak, alias("Default_Handler")));

static uint32 stackTop[256];

void (* const gPtr_fn_Vectors[])() __attribute__((section(".vectors"))) =
{
	(void (*)()) ((uint32)stackTop + sizeof(stackTop)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&MM_fault_Handler,
	&Bus_fault,
	&Usage_fault_Handler
};

void Default_Handler()
{
	Reset_Handler();
}

extern uint32 _E_TEXT;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;

void Reset_Handler()
{
	/* Copying data section from flash to sram */
	uint32 j;
	uint32 DATA_SiZE = (uint8*)&_E_DATA - (uint8*)&_S_DATA;
	uint8* ptr_src = (uint8*)&_E_TEXT;
	uint8* ptr_dst = (uint8*)&_S_DATA;
	for(j = 0; j < DATA_SiZE; ++j)
	{
		*((uint8*)ptr_dst++) = *((uint8*)ptr_src++);
	}

	/* intializing bss section in sram */
	uint32 BSS_SiZE = (uint8*)&_E_BSS - (uint8*)&_S_BSS;
	ptr_dst = (uint8*)&_S_BSS;
	for(j = 0; j < DATA_SiZE; ++j)
	{
		*((uint8*)ptr_dst++) = 0;
	}

	main();
}

