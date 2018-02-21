#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0b00001111 ;
	PORTA = 0 ;
	
	while(1)
	{
		for( int i = 0; i < 4 ; i++)
		{
			PORTA |= ( 1 << i );
			_delay_ms(1000);
			PORTA = 0 ;
		}
		
		for( int i = 2; i>0 ;i--)
		{
			PORTA |= ( 1 << i );
			_delay_ms(1000);
			PORTA = 0;
		}
	}	
	
	return 0;
}