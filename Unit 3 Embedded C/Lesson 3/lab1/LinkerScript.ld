/* Ahmed Mohammed Hussanein Ali
	lab 1 assignment on UART0
	ARM Versatilepb board
	arm926ej-s processor
	*/

ENTRY(reset)

/* Defining memories */
MEMORY
{
	mem (rwx): ORIGIN = 0x0, LENGTH = 64M
}

/* Mapping memory into sections */
SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}> mem
	.text :
	{
		*(.text)
	}> mem
	.rodata :
	{
		*(.rodata)
	}> mem
	.data :
	{
		*(.data)
	}> mem
	.bss :
	{
		*(.bss)
	}> mem
	.debug :
	{
		*(.debug*)
	}
	. = . + 0x1000;
	stack_top = .;
}