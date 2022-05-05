#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include "LCD4.h"
#include "I2C.h"

int main(void)

{
	
	i2c_S_init(0x10);
	lcd_intit();
	_delay_ms(1);
	
	char str [16];
	while (1)
	{
		i2c_listen();
		unsigned char i = 0;
		
		while (i!=16)
		{
			str[i] = i2c_read(1);
			i++;
		}
		lcd_goto(1,1);
		lcd_prnt(str);
		

	}
}
