/*
 * SPI Master.c
 *
 * Created: 3/12/2022 7:38:16 PM
 * Author : Abdallah
 */
#define F_CPU 1000000UL 

#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_MasterInit()
{
	DDRB = (1<<SS) | (1<<MOSI) | (1<<SCK);
	
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
}

unsigned char SPI_MasterTransmit(unsigned char cdata)
{
	SPDR = cdata;
	while(! (SPSR & (1<<SPIF)));
	return SPDR;
}

int main(void)
{
    /* Replace with your application code */
	SPI_MasterInit();
	DDRA = 0xFF;
	unsigned char data;
	
    for (data = 0; data <= 255; data++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterTransmit(data);
	}
}

