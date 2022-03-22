/*
 * M242.c
 *
 * Created: 15.03.2022 08:48:41
 * Author : fluri
 */ 

#include <avr/io.h>

#define BUTTONS		PINA
#define BUTTONS_DDR DDRA

#define LEDS		PORTB
#define LEDS_DDR	DDRB


int main(void)
{	
	BUTTONS_DDR = 0x00;
	LEDS_DDR	= 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		LEDS = BUTTONS;
    }
}

