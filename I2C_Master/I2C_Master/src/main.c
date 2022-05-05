#include <avr/io.h>
#include <util/delay.h>
#include "LCD4.h"
#include "I2C.h"




int main(void)
{
	i2c_M_init();
	_delay_ms(100);
	
	
	unsigned char str [16] ={"I2C Initialized"};
	while (1)
	{
		i2c_strt();
		i2c_send(0x10);
		unsigned char i;
		for ( i = 0 ; i<16 ; i++ )
		{
			
			i2c_send(str[i]);
			_delay_ms(100);
		}
		
		
		i2c_stop();
	}
	
}