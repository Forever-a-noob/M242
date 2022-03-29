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
	
	BUTTONS_DDR = 0x00;
	LEDS_DDR	= 0xFF;
	/* Replace with your application code */
	while (1)
	{
		buttons = ~BUTTONS;
		leds = ~LEDS;
		
		switch (buttons){
			
			case 0x01:
					for (int i = 0x01; i < 0x80; i *= 2){
						leds = i;
						LEDS = ~leds;
						_delay_ms(80);
					}
					
					for (int i = 0x80; i > 0x01; i /= 2){
						leds = i;
						LEDS = ~leds;
						_delay_ms(80);
					}
				delay = 80;
				break;
			case 0x02:
				delay = 70;
				break;
			case 0x04:
				delay = 60;
				break;
			case 0x08:
				delay = 50;
				break;
			case 0x10:
				delay = 40;
				break;
			case 0x20:
				delay = 30;
				break;
			case 0x40:
				delay = 20;
				break;
			case 0x80:
				delay = 10;
				break;
		}
		

		
		
		

		

		LEDS = ~leds;

	}
}

