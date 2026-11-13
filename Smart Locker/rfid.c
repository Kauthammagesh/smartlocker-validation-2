#include "header.h"

unsigned char rfid_buf[13];

void rfid_read()
{
	unsigned int i;
	unsigned char ch;
	
	uart0_config();
	uart0_txstr("RFID EM-18 Reader Ready");
	
	
		for(i = 0; i < 12; )
		{
			ch = uart0_rx();
		
		
		if((ch>='0' && ch<='9') || ch>='A' && ch<='z')
		{
			rfid_buf[i] = ch;
			i++;
		}
		}
	 
	 rfid_buf[12] = '\0';
	 
	 uart0_txstr("Card Detected");
	 uart0_txstr((unsigned char*)rfid_buf);
	 uart0_txstr("\r\n");
  }

