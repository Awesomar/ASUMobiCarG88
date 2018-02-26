#include "UART.h"
#include <util/delay.h>

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