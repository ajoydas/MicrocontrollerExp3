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

/*
int main(void)
{
	DDRA = 0xff;
	PORTA = 0x00;
	DDRB = 0xfc;
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
		if(PINB & (1<<PB1))
		{
			if(PORTA == 0x00){
				PORTA = 0x0f;
			}
			else PORTA -= 1;
		}
		_delay_ms(2000);


	}
}

*/

volatile char c;

ISR(INT0_vect)
{
	c++;
	if(c>15) c=0;
	c = c & 0x0f;
	PORTA = c;
	_delay_ms(500);
	GIFR = 0xFF;
}

ISR(INT1_vect)
{
	c--;
	if(c<0) c=15;
	c = c & 0x0f;
	PORTA = c;
	_delay_ms(500);
	GIFR = 0xFF;
}

int main(void)
{
	c = 0x0f;
	DDRA = 0xff;
	PORTA = c;
	GICR = (1 << INT0) | (1 << INT1);
	MCUCR = MCUCR | 0x0a;
	sei();
	
	while(1)
	{
		//TODO:: Please write your application code
		
	}
}