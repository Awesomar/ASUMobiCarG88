/*
 * mdriver.h
 *
 * Created: 25/03/18 
 *  Author: Ammar 
 */ 


#ifndef DRIVER_H_
#define DRIVER_H_

#define F_CPU 1000000UL
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