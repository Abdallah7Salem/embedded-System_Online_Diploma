/*
 * SPI Slave.c
 *
 * Created: 3/12/2022 7:44:27 PM
 * Author : Abdallah
 */ 
#define F_CPU 1000000UL


#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_SlaveInit()
{
	DDRB = (1<<MISO);
	
	SPCR = (1<<SPE);
}

unsigned char SPI_SlaveReceive(unsigned char cdata)
{
	SPDR = cdata;
	while(! (SPSR & (1<<SPIF)));
	return SPDR;	
}

int main(void)
{
    /* Replace with your application code */
	SPI_SlaveInit();
	DDRA = 0xFF;
	unsigned char data;
	
    for (data = 0; data <= 255; data++)
	{
		_delay_ms(1000);
		PORTA = SPI_SlaveReceive(data);
	}
}

