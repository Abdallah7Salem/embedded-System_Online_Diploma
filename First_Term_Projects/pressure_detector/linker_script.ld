/* linker script CortexM3 
Eng. Abdallah Salem
*/

MEMORY
{
	flash(RX) : ORIGIN = 0X0000000 , LENGTH = 512M
	sram(RW)  : ORIGIN = 0x20000000 , LENGTH = 512M
}

SECTIONS
{
	.text : {
		   *(.vectors*)
		   *(.text*)
		   *(.rodata)
		   _E_text = . ;
	}> flash

	.data : {
	_S_DATA = . ;
	*(.data)
	. = ALIGN(4) ;
	_E_DATA = . ;
	}> sram AT> flash

	.bss : {
	_S_bss = . ;
		   *(.bss*)
		   *(COMMON)
	_E_bss = . ;

	}> sram
}