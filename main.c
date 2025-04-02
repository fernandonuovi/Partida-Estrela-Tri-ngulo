#define F_CPU   16000000
#include <util/delay.h>
#include <avr/io.h>

#define S1 (1<<2) // botão de partida
#define S0 (1<<1) // Botão de parada
#define K1 (1<<5) // Contator K1
#define K2 (1<<4) // Contator K2
#define K3 (1<<3) // Contator K3

int main(void)
{
	// Configuração botões como entrada
	DDRB &= ~(S1 | S0);
	
	// Ativando Pull Up
	PORTB |= (S1 | S0);
	
	// Configurando Contatores como saída
	DDRB |= (K1 | K2 | K3);
	
	// Zerando as saídas
	PORTB &= ~(K1 | K2 | K3);
	
	estado = 0
	
	switch( estado )
	{
		case 0:
		PORTB &= ~(K1 | K2 | K3);
		
			if( !(PINB & S1) )
			{
				estado = 1
			}
		break;
		
		case 1:
		PORTB |= (K1 | K2);
		delay = 5000
		
		estado = 2
		break;
		
		case 2: delay--;
		_delay_ms(1);
		
			if( !(PINB & S0) )
			{
				estado = 0
			}
			else if( delay ==0)
			{
			estado = 3
			}
		break;
		
		case 3:
		PORTB &= ~(K2);
		PORTB |= (K3);
		
			if( !(PINB & S0) )
			{
				estado = 0
			}
		break;
	}
}
