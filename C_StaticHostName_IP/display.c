/******
Demo for ssd1306 i2c driver for  Raspberry Pi
******/

#include "ssd1306_i2c.h"
#include "time.h"
#include <unistd.h>



void main(void)
{
  unsigned char symbol=3;
  ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);      //LCD Screen initialization
  usleep(150*1000);                                                  //Short delay Ensure the normal response of the lower function
  OLED_Clear();
  GetHostName();
	while(1)
	{
    LCD_Display(symbol);
    sleep(1000); //sleep for 1000 seconds
    symbol++;
    if(symbol==4)
    {
      symbol=0;
    }
	}
}
