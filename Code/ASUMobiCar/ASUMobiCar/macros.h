/*
 * macros.h
 *
 * The avr/macros.h file provides a set of macros
 * necessary for compiling AVR. These are provided
 * to offer analogous functionality on Windows.
 *
 * Created: 26/03/18 
 *  Author: Ammar
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#include  <avr/io.h>

#define BIT_SET(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define BIT_CLEAR(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define BIT_CHECK(ADDRESS,BIT) (ADDRESS & (1<<BIT))
#define BIT_FLIP(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))


#endif /* MACROS_H_ */