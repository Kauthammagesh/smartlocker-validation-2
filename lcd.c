#include "header.h"

void lcd_init()
{
	IODIR0 = lcd_d|rs|e;
	lcd_command(0x01);
	lcd_command(0x02);
	lcd_command(0x0C);
	lcd_command(0x38);
}

void lcd_command(unsigned char cmd)
{
	IOCLR0 = lcd_d;
	IOSET0 = cmd<<6;
	IOCLR0 = rs;
	IOSET0 = e;
	delay_milliseconds(2);
	IOCLR0 = e;
}

void lcd_data(unsigned char d)
{
	IOCLR0 = lcd_d;
	IOSET0 = d<<6;
	IOSET0 = rs;
	IOSET0 = e;
	delay_milliseconds(2);
	IOCLR0 = e;
}

void lcd_string(unsigned char *s)
{
	unsigned char pos = 0;
	
	while(*s)
	{
		//lcd_command(0x80);
		lcd_data(*s++);
		delay_milliseconds(100);
		pos++;
		if(pos == 16)
		{
			lcd_command(0xC0);
		}
	}
}
