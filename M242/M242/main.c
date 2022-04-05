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

#define F_CPU       3686000UL
#include <util/delay.h>

int main(void)
{
	uint8_t buttons;
	uint8_t leds = 0x01;
	uint8_t delay = 10;
	uint8_t valueFromGod = 0x3A;
	uint8_t value;
	uint8_t value1;
	uint8_t value2;
	uint8_t prevButton = 0x00;
	uint8_t ledState = 1;
	
	BUTTONS_DDR = 0x00;
	LEDS_DDR	= 0xFF;
	/* Replace with your application code */
	while (1)
	{
		buttons = ~BUTTONS;
		leds = ~LEDS;
		
		if (buttons > 0x00 && buttons != prevButton) {
			if (ledState == 1){
				leds = 0x00;
				ledState = 0;
				prevButton = buttons;
			} else {
				leds = 0xFF;
				ledState = 1;
				prevButton = buttons;
			}
		}


		LEDS = ~leds;

	}
}

