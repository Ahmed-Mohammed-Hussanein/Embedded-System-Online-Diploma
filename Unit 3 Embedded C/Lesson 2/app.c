/* Ahmed Mohammed Hussanein Ali
	lab 1 assignment on UART0
	ARM Versatilepb Physical board
	core: arm926ej-s processor
	*/

#include "Platform_Types.h"
#include "UART0.h"

uint8 buffer1[100] = "learn-in-depth:<Ahmed Mohammed Hussanein Ali>";
 
void main(void)
{
	UART0_Tx(buffer1);
}