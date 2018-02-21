#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

void delay_ms(int milliseconds);

int main(void)
{
	DDRD = 0b11111111;
	
	while(1)
	{
		int d = PINA;
		
		if (d==0)
		{
			PORTD = 0;
			_delay_ms(1000);
			continue;
		}
		
		d *= 4;
		
		PORTD = 1;
		delay_ms(d);
		PORTD = 0;
		delay_ms(d);
	}	
	
	return 0;
}

void delay_ms(int milliseconds)
{
	while(milliseconds > 0)
	{
		 _delay_ms(1);
		milliseconds--;
	}
}