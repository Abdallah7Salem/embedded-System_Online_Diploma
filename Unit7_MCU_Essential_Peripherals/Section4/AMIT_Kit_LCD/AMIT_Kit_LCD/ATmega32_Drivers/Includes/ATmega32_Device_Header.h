/*
 * ATmega32_Device_Header.h
 *
 * Created: 12/11/2021 1:53:59 AM
 *  Author: Abdallah
 */ 


#ifndef ATMEGA32_DEVICE_HEADER_H_
#define ATMEGA32_DEVICE_HEADER_H_

//--------------------------------------------------------------------
//							Includes
//--------------------------------------------------------------------
#include <stdint.h>
//#include "Platform_Types.h"

//--------------------------------------------------------------------
//				  Base Addresses For Memories
//--------------------------------------------------------------------
#define FLASH_MEMORY		0x00
#define SRAM				0x60

//--------------------------------------------------------------------
//			  	  Base Addresses For Peripherals
//--------------------------------------------------------------------
#define GPIOA_Base			0x39
#define GPIOB_Base			0x36
#define GPIOC_Base			0x33
#define GPIOD_Base			0x30

#define USART_Base			0x29

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{

	// PIN Register
	volatile union {
		volatile uint8_t PIN;
		struct{
			volatile uint8_t PIN0 :1;
			volatile uint8_t PIN1 :1;
			volatile uint8_t PIN2 :1;
			volatile uint8_t PIN3 :1;
			volatile uint8_t PIN4 :1;
			volatile uint8_t PIN5 :1;
			volatile uint8_t PIN6 :1;
			volatile uint8_t PIN7 :1;
		}bits;
	}PIN;
	//####################################

	// DDR Register
	volatile union {
		volatile uint8_t DDR;
		struct{
			volatile uint8_t DD0 :1;
			volatile uint8_t DD1 :1;
			volatile uint8_t DD2 :1;
			volatile uint8_t DD3 :1;
			volatile uint8_t DD4 :1;
			volatile uint8_t DD5 :1;
			volatile uint8_t DD6 :1;
			volatile uint8_t DD7 :1;
		}bits;
	}DDR;
	//###################################

	// PORT Register
	volatile union{
		volatile uint8_t PORT;
		struct{
			volatile uint8_t PORT0 :1;
			volatile uint8_t PORT1 :1;
			volatile uint8_t PORT2 :1;
			volatile uint8_t PORT3 :1;
			volatile uint8_t PORT4 :1;
			volatile uint8_t PORT5 :1;
			volatile uint8_t PORT6 :1;
			volatile uint8_t PORT7 :1;
		}bits;
	}PORT;
}GPIO_typedef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:USART
//-*-*-*-*-*-*-*-*-*-*-*
/*
// UCSRB Register
typedef struct{

	volatile uint8_t UBRRL;

	volatile union{
		volatile uint8_t UCSRB;
		struct{
			volatile uint8_t TXB8 	:1;
			volatile uint8_t RXB8 	:1;
			volatile uint8_t UCSZ2	:1;
			volatile uint8_t TXEN	:1;
			volatile uint8_t RXEN	:1;
			volatile uint8_t UDRIE	:1;
			volatile uint8_t TXCIE	:1;
			volatile uint8_t RXCIE	:1;
		}bits;
	}UCSRB;
	//#########################################

	// UCSRA Register
typedef struct{
	volatile uint8_t UCSRA;
	struct{
		volatile uint8_t MPCM :1;
		volatile uint8_t U2X  :1;
		volatile uint8_t PE	 :1;
		volatile uint8_t DDR  :1;
		volatile uint8_t FE   :1;
		volatile uint8_t UDRE :1;
		volatile uint8_t TXC  :1;
		volatile uint8_t RXC  :1;
	}bits;
	}UCSRA;
	//#######################################

	volatile uint8_t UDR;

}USART_typedef;
*/
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA 				((GPIO_typedef *)(GPIOA_Base))
#define GPIOB  				((GPIO_typedef *)(GPIOB_Base))
#define GPIOC 				((GPIO_typedef *)(GPIOC_Base))
#define GPIOD 				((GPIO_typedef *)(GPIOD_Base))

#define USART 				((USART_typedef *)(USART_Base))

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//USART Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define UBRRH 				*((uint8_t *)(0x40))

#define UCSRC				*((uint8_t *)(0x40))
#define UCPOL							0
#define UCSZ0							1
#define UCSZ1							2
#define USBS							3
#define UPM0							4
#define UPM1							5
#define UMSEL							6
#define URSEL							7

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*




#endif /* ATMEGA32_DEVICE_HEADER_H_ */