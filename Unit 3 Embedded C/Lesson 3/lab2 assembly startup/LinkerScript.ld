/* Ahmed Mohammed Hussanein Ali
	Lab 2 lesson 3
	linker script for ARM cortexM3
	*/

MEMORY
{
	flash (rx): ORIGIN = 0x08000000, LENGTH = 128K
	sram (rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text)
		*(.rodata)
	}> flash

	.data :
	{
		*(.data)
	}> flash

	.bss :
	{
		*(.bss)
	}> sram
}