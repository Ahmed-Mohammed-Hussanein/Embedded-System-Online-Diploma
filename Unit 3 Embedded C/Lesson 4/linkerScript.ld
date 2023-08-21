/* Ahmed Mohammed Hussanein Ali
	Lab 2 lesson 3
	linker script.ld 
	application: toggling led connected to port F pin 3 for ARM cortexM4
	TM4C123GH6PZ physical board
	*/

MEMORY
{
	flash (RX): ORIGIN = 0x00000000, LENGTH = 512M
	sram (RWX): ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_TEXT = .;
	}> flash

	.data :
	{
		_S_DATA = .;
		*(.data)
		_E_DATA = .;
	}> sram AT> flash

	.bss :
	{
		_S_BSS = .;
		*(.bss)
		_E_BSS = .;
	}> sram
}