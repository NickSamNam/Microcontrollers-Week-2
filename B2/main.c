/*
* B4.c
*
* Created: 2-2-2018 13:52:07
* Author : snick
*/

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void wait(int ms) {
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

ISR(INT1_vect)
{
	wait(500);
	PORTD = 0x04;
}

ISR(INT2_vect)
{
	wait(500);
	PORTD = 0x02;
}

int main(void)
{
	// Init IO
	DDRD = 0xFF;
	
	// Init interrupt
	EICRA |= 0x3C;	// ISC INT1, INT2: Rising edge
	EIMSK |= 0x06;	// Enable INT1, INT2
	
	// Enable global interrupt system
	sei();
	
	// Board the trigger train
	PORTD |= 0x02;
	
	// Main loop
	while (1)
	{
	}
}
