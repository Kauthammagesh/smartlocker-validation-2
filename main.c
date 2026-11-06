#include "header.h"

int main()
{
	unsigned char res;
	unsigned char i;
	unsigned char password[5];
	unsigned char attempts=0;
	lcd_init();
	lcd_command(0x80);
	lcd_string("Smart Locker");
	
	delay_milliseconds(2000);
	
	lcd_command(0x01);
	lcd_string("Scan your Card");
	
	
	//uart0_config();
	scan:
	rfid_read(); 
	//uart0_txstr((unsigned char*)rfid_buf);
//	lcd_string((unsigned char*)rfid_buf);
	
	if(strcmp((char*)rfid_buf,"0600680EE989")==0)
	{
		lcd_command(0x01);
		delay_milliseconds(2);
		lcd_command(0x80);
		lcd_string("Access Granted");
		delay_milliseconds(500);
		lcd_command(0x01);
		lcd_string("Enter Password");
		
	}
	else
	{
		lcd_command(0x01);
		delay_milliseconds(2);
		lcd_command(0x80);
		lcd_string("Access Denied");
		delay_milliseconds(500);
		lcd_command(0x01);
		lcd_string("Scan again");
		delay_milliseconds(500);
		goto scan;
	}


	lcd_command(0x80);
	lcd_string("Enter Password");

	lcd_command(0xC0);

	for(i=0; i<4; i++)
	{
	 res = keypad_scan();
	 password[i] = res + '0';
	 lcd_data('*');
	}
	password[4]='\0';

	while(attempts<=3)
	{
	if(strcmp((char*)password, "4321")==0)
	{
     	lcd_command(0x01);
		delay_milliseconds(2);
		lcd_string("Correct Password");
	//	dc_motor();
	 }
	 else
	 {
	    attempts++;
	    lcd_command(0x01);
		delay_milliseconds(2);
		lcd_string("Wrong Password");
	//	led_buzzer();
	 }
	 }
	while(1);
	
}
