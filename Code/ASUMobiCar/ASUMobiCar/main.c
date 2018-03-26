#include "UART.h"
#include "mdriver.h"
#include <util/delay.h>

int main(void)
{
	UART_init(9600); //initializing the receiver
	char R;
	
	while(1)
	{
		R = UARD_receive_char(); //receiving a character
		
		if (R == 'F') //Forward
			moveForward();
		
		if (R == 'B') //Backward
			moveBackward();
		
		if (R == 'R') //Right
			moveRight();
		
		if (R == 'L') //Left
			moveLeft();
		
		else
			stop();
	}
	
	return 0;
}