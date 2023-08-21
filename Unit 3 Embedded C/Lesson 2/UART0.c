/* Ahmed Mohammed Hussanein Ali
	lab 1 assignment on UART0
	ARM Versatilepb Physical board
	core: arm926ej-s processor
	*/

#include "UART0.h"

#define UART0DR *(volatile uint32 * const) ((uint32*)0x101f1000)

void UART0_Tx(const uint8* ptr_Tx)
{
	while(*ptr_Tx != '\0')
	{
		UART0DR = (uint32)(*ptr_Tx);
		ptr_Tx++; 
	}
}