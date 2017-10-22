/*
 * interrupt.c
 *
 * Created: 16-10-2017 14:56:48
 * Author : hp
 */ 

#include <avr/io.h>
#include "avr/interrupt.h"
#include <avr/delay.h>

//ISR(INT0_vect)
//{
	//PORTB = ~PORTB;
//
//}
//
//int main()
//{
	//DDRB = 0xff;  //Port b output configure
	//PORTB = 0b01010101;
	//MCUCR = 0b00000000; //Toggle when it is in pressed or low level
	//GICR = (1<<INT0);
	//sei();
	//while(1);  // Alive loop 
//
//}

int main(void)
{
	DDRA = 0xff;
	PORTA = 0x04;
	DDRB = 0xfe;
	while(1)
	{
		//if(PORTC != 0x01){
			//PORTC = 0x01;
		//}
		//else PORTC = 0x00;
		//_delay_ms(2000);

		if(PINB & (1<<PB0))
		{
			if(PORTA == 0x0f){
				PORTA = 0x00;
			}
			else PORTA += 1;
		}
		_delay_ms(1000);


	}
}

