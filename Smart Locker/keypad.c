#include "header.h"

unsigned int keypad_lut[4][4]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}}; 


 unsigned int keypad_scan()
 {
  unsigned char row_val, col_val;
  IODIR1 = r0|r1|r2|r3;
  while(1)
  {
  IOCLR1 = r0|r1|r2|r3;
  IOSET1 = c0|c1|c2|c3;
  while((c0&&c1&&c2&&c3)==1);
  IOCLR1=r0;
  IOSET1=r1|r2|r3;
  if((c0 && c1 && c2 && c3)==0)
  {
  row_val=0;
  break;
  }
  IOCLR1=r1;
  IOSET1=r0|r2|r3;
  if((c0 && c1 && c2 && c3)==0)
  {
  row_val=1;
  break;
  }
  IOCLR1=r2;
  IOSET1=r0|r1|r3;
  if((c0 && c1 && c2 && c3)==0)
  {
  row_val=2;
  break;
  }
  IOCLR1=r3;
  IOSET1=r0|r1|r2;
  if((c0 && c1 && c2 && c3)==0)
  {
  row_val=3;
  break;
  }
  }
  if(c0==0)
  col_val=0;
  else if(c1==0)
  col_val=1;
  else if(c2==0)
  col_val=2;
  else
  col_val=3;

  delay_milliseconds(250);
  while((c0 && c1 && c2 && c3) == 0);
  return keypad_lut[row_val][col_val];
  }

 

