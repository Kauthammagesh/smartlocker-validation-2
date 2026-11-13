#include "header.h"

void uart0_config(void)
{
	PINSEL0 = 0X05;
	U0LCR = 0X83;
	U0DLL = 97;
	U0DLM = 0;
	U0LCR = 0X03;
}

void uart0_tx(unsigned char ch)
{
	while(((U0LSR>>5)&1) == 0);
  U0THR = ch;
}

unsigned char uart0_rx(void)
{
	while((U0LSR & 0X01) == 0);
	return U0RBR;
}

void uart0_txstr(unsigned char *s)
{
	while(*s)
	{
		uart0_tx(*s++);
	}
}
