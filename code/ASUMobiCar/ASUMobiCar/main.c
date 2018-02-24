#define F_CPU 16000000UL //16 MHz
#include <avr/io.h>
#include <util/delay.h>

void UART_init(int baud);
void UARD_send_char(char data);
char UARD_receive_char();
void moveForward();
void moveBackward();
void turnRight();
void turnLeft();

int main(void)
{
	UART_init(9600);
	char R;
	
	while(1)
	{
		R = UARD_receive_char();
		
		if (R == 'F') //Forward
		moveForward();
		
		if (R == 'B') //Backward
		moveBackward();
		
		if (R == 'R') //Right
		turnRight();
		
		if (R == 'L') //Left
		turnLeft();
	}
	
	return 0;
}

void UART_init(int baud)
{
	uint16_t UBRR_Value = (F_CPU / (16L * baud)) -1;
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value >> 8);
	UCSRB = (1 << RXEN) | (1 << TXEN); //enable transmitting and receiving
	UCSRC = (3 << UCSZ0); //8-bits
}
void UARD_send_char(char data)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = data;
}
char UARD_receive_char()
{
	while (!(UCSRA & (1 << RXC)));
	return UDR;
}
void moveForward()
{
	
}
void moveBackward()
{
	
}
void turnRight()
{
	
}
void turnLeft()
{
	
}