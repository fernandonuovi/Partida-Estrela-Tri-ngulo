#define F_CPU   16000000
#include <util/delay.h>
#include <avr/io.h>

int main(void) 
{
	// ENTRADAS
	DDRB  &=  ~(1<<2);
	DDRB  &=  ~(1<<1);
	
	// SAÍDA
	DDRB  &= ~(1<<5); // K1
	DDRB  &= ~(1<<4); // K2
	DDRB  &= ~(1<<3); // K3
	
	// ATIVAR PULL UP
	PORTB  |=  (1<<2);
	PORTB  |=  (1<<1);
	
	// ZERANDO
	PORTB &= ~(1<<5); 
	PORTB &= ~(1<<4); 
	PORTB &= ~(1<<3); 
	
	
	
    while ( 1 )
    {
		if( !(PINB  &= ~(1<<2))); // S1
		{
			PORTB |=  (1<<5); // K1
			PORTB |=  (1<<4); // K2
			_delay_ms(5000);
			
			PORTB  &=  ~(1<<4);
			PORTB |=  (1<<3);
		}
		else if( !(PINB  &= ~(1<<2))); // S1

    }
}
