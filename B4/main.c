/*
* B4.c
*
* Created: 16-2-2018 23:33:28
* Author : snick
*/

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

typedef struct _Anim
{
	int data;
	int delay;
} Anim;

Anim anim[] =
{
	{0x01, 50}, {0x03, 50}, {0x07, 50}, {0x0F, 50}, {0x1F, 50}, {0x3F, 100},
	{0x3D, 50}, {0x39, 50}, {0x31, 50}, {0x21, 50}, {0x01, 100},
	{0x23, 50}, {0x63, 50}, {0x77, 50}, {0x7F, 100},
	{0x77, 50}, {0x37, 50}, {0x36, 50}, {0x09, 50}, {0x40, 100},
	{0x08, 50}, {0x1C, 50}, {0x3E, 75}, {0x3F, 100},
	{0x36, 100}, {0x40, 300},
	{0x20, 50}, {0x01, 50}, {0x02, 50}, {0x40, 50}, {0x10, 50}, {0x08, 50}, {0x04, 50}, {0x40, 100},
	{0x24, 50}, {0x09, 50}, {0x12, 50}, {0x40, 50}, {0x24, 50}, {0x09, 50}, {0x12, 50}, {0x40, 100},
	{0x08, 50}, {0x48, 50}, {0x49, 50}, {0x41, 50}, {0x01, 50},
	{0x00, 0x00}
};

void wait(int ms) {
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

int main(void)
{
	// Init IO
	DDRA = 0xFF;
	
	// Main loop
	while (1)
	{
		int m;
		for (m = 3; m > 0; m--)
		{
			// Anim loop
			int i;
			for (i = 0; anim[i].delay != 0; i++)
			{
				PORTA = anim[i].data;
				wait(anim[i].delay*m);
			}
		}
	}
}

