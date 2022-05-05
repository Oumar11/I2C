#include "I2C.h"

void i2c_send (uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (((TWCR) & (1<<TWINT)) == 0 );
}
void i2c_strt ()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while (((TWCR) & (1<<TWINT)) == 0 );

}
void i2c_stop ()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
}
void i2c_M_init ()
{
	TWSR = 0x00;  //set the scalar bits to 0
	TWBR = 0x47;
	TWCR = 0x04; // enables the module via TWEN .
}
uint8_t i2c_read (uint8_t x)
{
	if (x == 0 )							// if x = 1 .. we're reading only 1 byte
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);	// if x = 0 .. we 're reading more than one byte
	else
	TWCR = (1<<TWINT)|(1<<TWEN);  // no ack is sent here.
	while (((TWCR) & (1<<TWINT)) == 0);
	return TWDR;

}
void i2c_listen ()
{
	while (((TWCR) & (1<<TWINT)) == 0 );
}
void i2c_S_init (uint8_t slaveaddress)
{
	TWCR = 0x04;
	TWAR = slaveaddress;
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
}