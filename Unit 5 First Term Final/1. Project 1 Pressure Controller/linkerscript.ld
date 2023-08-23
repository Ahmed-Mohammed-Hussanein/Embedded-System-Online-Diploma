ENTRY(_reset)

MEMORY
{
	FLASH (xrw): o = 0x08000000, l = 32K
	SRAM (rw): o = 0x20000000, l = 10K
}

_stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
_sSRAM = ORIGIN(SRAM);

SECTIONS
{
	. = 0x08000000;
	.text . :
	{
		*(.vectors)
		*(.text)
		*(.rodata)
		_eText = . ;
	}> FLASH

	.data :
	{
		_sData = . ;
		*(.data)
		. = ALIGN(4);
		_eData = . ;
	}> SRAM AT> FLASH

	.bss :
	{
		_sBSS = . ;
		*(.bss)
		. = ALIGN(4);
		_eBSS = . ;
	}> SRAM
}