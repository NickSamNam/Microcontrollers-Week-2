/*
* B3.c
*
* Created: 16-2-2018 22:30:27
* Author : snick
*/

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void wait(int ms) {
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

void display(int digit)
{
	switch(digit)
	{
		case 0x0:
			PORTA = 0x3F;
			break;
		case 0x1:
			PORTA = 0x06;
			break;
		case 0x2:
			PORTA = 0x5B;
			break;
		case 0x3:
			PORTA = 0x4F;
			break;
		case 0x4:
			PORTA = 0x66;
			break;
		case 0x5:
			PORTA = 0x6D;
			break;
		case 0x6:
			PORTA = 0x7D;
			break;
		case 0x7:
			PORTA = 0x07;
			break;
		case 0x8:
			PORTA = 0x7F;
			break;
		case 0x9:
			PORTA = 0x67;
			break;
		case 0xA:
			PORTA = 0x77;
			break;
		case 0xB:
			PORTA = 0x7C;
			break;
		case 0xC:
			PORTA = 0x39;
			break;
		case 0xD:
			PORTA = 0x5E;
			break;
		case 0xE:
			PORTA = 0x79;
			break;
		case 0xF:
			PORTA = 0x71;
			break;
		default:
			PORTA = 0xF9;
			break;
	}
}

int main(void)
{
	/* Replace with your application code */
	DDRA = 0xFF;
	while (1)
	{
		for (int i = 0x0; i <= 0xF+1; i++)
		{
			display(i);
			wait(500);
		}
	}
}