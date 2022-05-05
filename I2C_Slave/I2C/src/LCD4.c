#include "LCD4.h"



 void lcd_cmnd (unsigned char cmnd)
 {
	 LCD_PRT = (LCD_PRT & 0X0F) | (cmnd & 0XF0); // clearing 4 bits from port.. clearing first 4 bits of cmnd
	 LCD_PRT &= ~(1<<LCD_RS);
	 LCD_PRT &= ~(1<<LCD_RW);

	 LCD_PRT |= (1<<LCD_EN);
	 _delay_us(1);
	 LCD_PRT &= ~(1<<LCD_EN);

	 _delay_us(20);

	 LCD_PRT = (LCD_PRT & 0X0F) | (cmnd<<4);
	 LCD_PRT |= (1<<LCD_EN);
	 _delay_us(1);
	 LCD_PRT &= ~(1<<LCD_EN);
 }
 void lcd_data (unsigned char data)
 {
	 LCD_PRT = (LCD_PRT & 0X0F) | (data & 0XF0); // clearing 4 bits from port.. clearing first 4 bits of cmnd
	 LCD_PRT |= (1<<LCD_RS);
	 LCD_PRT &= ~(1<<LCD_RW);

	 LCD_PRT |= (1<<LCD_EN);
	 _delay_us(1);
	 LCD_PRT &= ~(1<<LCD_EN);

	 _delay_us(20);

	 LCD_PRT = (LCD_PRT & 0X0F) | (data<<4);
	 LCD_PRT |= (1<<LCD_EN);
	 _delay_us(1);
	 LCD_PRT &= ~(1<<LCD_EN);
 }
 void lcd_intit ()
 {
	 LCD_DDR  = 0xff;

	 LCD_PRT &= ~(1<<LCD_EN );   //LCD_en = 0
	 _delay_us(2000);			//waiting for stable power
	 lcd_cmnd(0x33);				// 4 bit mode
	 _delay_us(100);				//waiting

	 lcd_cmnd(0x32);				// 4 bit mode
	 _delay_us(100);				// waiting

	 lcd_cmnd(0x28);				// 4 bit mode
	 _delay_us(100);				//waiting

	 lcd_cmnd(0x0E);				// display on / cursor on
	 _delay_us(100);				// waiting

	 lcd_cmnd(0x01);				//Clear LCD
	 _delay_us(100);				//waiting
	 lcd_cmnd(0x06);				//shift cursor right......
	 _delay_us(100);
 }
 void lcd_goto(unsigned char x , unsigned char y)
 {
	 unsigned char address[] = {0x80,0xC0,0x94,0xD4};
	 lcd_cmnd(address[y-1] + x - 1);
	 _delay_us(100);

 }
 void lcd_prnt (char * str)
 {
	 unsigned char i = 0 ;
	 while (str[i]!=0)
	 {
		 lcd_data(str[i]);
		 i++;
	 }
 }