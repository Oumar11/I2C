#ifndef __I2C_H_
#define __I2C_H_
 #include <avr/io.h>

void i2c_send (uint8_t );
void i2c_strt ();
void i2c_stop ();
void i2c_M_init ();
uint8_t i2c_read (uint8_t );
void i2c_listen ();
void i2c_S_init (uint8_t );
#endif