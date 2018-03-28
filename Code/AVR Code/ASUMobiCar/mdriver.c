#include "macros.h"
#include "mdriver.h"

int8_t in1, in2, in3, in4;

void Motor_Init(int8_t IN1, int8_t IN2, int8_t IN3, int8_t IN4){		//initialize motor pins
	in1 = IN1;
	in2 = IN2;
	in3 = IN3;
	in4 = IN4;

	BIT_SET(DDR_MOTOR,in1);		//make AVR's pins output
	BIT_SET(DDR_MOTOR,in2);
	BIT_SET(DDR_MOTOR,in3);
	BIT_SET(DDR_MOTOR,in4);
}

void moveForward(){
	BIT_SET(PORT_MOTOR,in1);
	BIT_CLEAR(PORT_MOTOR,in2);
	BIT_SET(PORT_MOTOR,in3);
	BIT_CLEAR(PORT_MOTOR,in4);
}

void moveBackward(){
	BIT_CLEAR(PORT_MOTOR,in1);
	BIT_SET(PORT_MOTOR,in2);
	BIT_CLEAR(PORT_MOTOR,in3);
	BIT_SET(PORT_MOTOR,in4);
}

void moveRight(){
	BIT_CLEAR(PORT_MOTOR,in1);
	BIT_SET(PORT_MOTOR,in2);
	BIT_CLEAR(PORT_MOTOR,in3);
	BIT_CLEAR(PORT_MOTOR,in4);
}

void moveLeft(){
	BIT_CLEAR(PORT_MOTOR,in1);
	BIT_CLEAR(PORT_MOTOR,in2);
	BIT_SET(PORT_MOTOR,in3);
	BIT_CLEAR(PORT_MOTOR,in4);
}

void stop(){
	BIT_CLEAR(PORT_MOTOR,in1);
	BIT_CLEAR(PORT_MOTOR,in2);
	BIT_CLEAR(PORT_MOTOR,in3);
	BIT_CLEAR(PORT_MOTOR,in4);
}
