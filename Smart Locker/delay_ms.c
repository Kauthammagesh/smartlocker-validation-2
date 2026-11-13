#include "header.h"

void delay_milliseconds(unsigned int ms)
{
	T0PR = 15000-1;
	T0TCR = 0X01;
	while(T0TC < ms);
	T0TCR |= 0X03;
	T0TCR = 0x00;
}

							 