/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/

#include "ssd1306_i2c.h"
#include "time.h"
#include <unistd.h>



void main(void) 
{
  unsigned char symbol=0;
  ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);      //LCD Screen initialization
  usleep(150*1000);                                                  //Short delay Ensure the normal response of the lower function
  FirstGetIpAddress();                        //Get IP address
  GetHostName();
	while(1)
	{
    LCD_Display(symbol);
    sleep(5);
    sleep(1);
    sleep(1);
    symbol++;
    if(symbol==4)
    {
      symbol=0;
    }
	}
}
