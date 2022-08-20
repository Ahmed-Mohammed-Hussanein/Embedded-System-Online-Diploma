/* Ahmed Mohammed Hussanein Ali
	lab 1 assignment on UART0
	ARM Versatilepb Physical board
	core: arm926ej-s processor
	*/
	
.globl reset

reset:
	ldr sp, =stack_top
	bl main

stop: b stop
