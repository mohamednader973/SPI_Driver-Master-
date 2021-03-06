/*
 * SPI_Driver.c
 *
 * Created: 10/4/2020 12:54:45 AM
 * Author : monad
 */ 

#include <avr/io.h>
#include "SPI.h"
#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	DDRC |=(1<<7);
	SPI_Init('M');
	PORTB &=~(1<<SS);  //slave enable
    /* Replace with your application code */
    while (1) 
    {
		if (SPI_TxRx(0x01)==0x55)
		{
			PORTC ^=(1<<7);
			_delay_ms(500);
		}
    }
}

