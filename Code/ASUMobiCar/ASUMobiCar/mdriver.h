#ifndef DRIVER_H_
#define DRIVER_H_

#include <avr/io.h>

#define DDR_MOTOR DDRB
#define PORT_MOTOR PORTB

void Motor_Init(int8_t IN1, int8_t IN2, int8_t IN3, int8_t IN4);
void moveForward();
void moveBackward();
void moveRight();
void moveLeft();
void stop();

#endif /* DRIVER_H_ */