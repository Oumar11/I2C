 #ifndef __LCD4_H_
 #define __LCD4_H_
 
 #define LCD_PRT PORTA
 #define LCD_DDR DDRA
 #define LCD_PIN PINA
 #define LCD_RS 0
 #define LCD_RW 1
 #define LCD_EN 2

 #include <avr/io.h>
 #include <util/delay.h>

 void lcd_cmnd (unsigned char );
 void lcd_data (unsigned char );
 void lcd_intit ();
 void lcd_goto(unsigned char  , unsigned char );
 void lcd_prnt (char * );

#endif