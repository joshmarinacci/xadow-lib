#include <Arduino.h>
#include <Wire.h>
#include "ledmodule.h"

int error;
int n;

#define LEDAddress 0x04
#define DISP_CHAR_5X7	0x80
#define DISP_STRING		0x81
#define SET_DISP_ORIENTATION 0x82
/*Marco definitions for the display orientation of the LED matrix*/
#define RIGHT_TO_LEFT 0
#define LEFT_TO_RIGHT 1
#define POWER_DOWN  0x83
uint8_t buffer[24];

void ledmodule::TESTIO(void)
{
 
  DDRB|=0x0e;
  PORTB&=~0x0e;
  DDRF|=0x01;
  PORTF&=~0x01;
  DDRD&=~0x0f;

  PORTB|=0x04;
  PORTF|=0x01;
  delay(30);
if(!(PIND&0x01))
{
  error=1;
}
if(PIND&0x02)
{
  error=1;
}
if(!(PIND&0x04))
{
  error=1;
}
if(PIND&0x08)
{
  error=1;
}
 PORTB&=~0x04;
 PORTB|=0x0a;
 PORTF&=~0x01;
 delay(30);
if(PIND&0x01)
{
  error=1;
}
if(!(PIND&0x02))
{
  error=1;
}
if(PIND&0x04)
{
 error=1;
}
if(!(PIND&0x08))
{
 error=1;
}
Serial.println(error);
}

/**********************************************************************/
/*Function: Send command to Xadow LED to display a string by the I2C. */
/*Parameter:-char* data_,Store a string to display on the xadow LED.  */
/*          -uint8_t len,The length of the data_.                     */
/*			-uint16_t time,The time of the character moving one	step. */
/*Return:	void                      			                      */

void dispString(char* data_,uint8_t len,uint16_t time)
{  
	Wire.beginTransmission(LEDAddress);
	Wire.write(DISP_STRING);
	Wire.write(len);
	Wire.write((uint8_t*)data_,len);
	Wire.write(time>>8); //high byte of time
	Wire.write(time);//low byte of time
	Wire.endTransmission();
}
void dispChar(uint8_t data_,uint16_t time)
{
	Wire.beginTransmission(LEDAddress);
	Wire.write(DISP_CHAR_5X7);
	Wire.write(data_);
	Wire.write(time>>8); //high byte of time
	Wire.write(time);//low byte of time
	Wire.endTransmission();
}
void setDispOrientation(uint8_t orientation)
{
	Wire.beginTransmission(LEDAddress);
	Wire.write(SET_DISP_ORIENTATION);
	Wire.write(orientation);
	Wire.endTransmission();
}
void powerDown()
{
	Wire.beginTransmission(LEDAddress);
	Wire.write(POWER_DOWN);
	Wire.endTransmission();
	digitalWrite(3,HIGH);
}
void wakeUp()
{
	Wire.beginTransmission(LEDAddress);
	Wire.endTransmission();	
}


void ledmodule::init() {
	Wire.begin();
    delay(100);
    TESTIO();
    if(error==0) {
        DDRB|=0x80;
        PORTB&=~0x80;
    }
}


void ledmodule::lprint(String s) {
    char str[s.length()+1];
    s.toCharArray(str,s.length()+1);
    for(n=0;n<s.length()*6;n++) {
        dispString(str,s.length(),200);
        delay(200);
    }
    delay(1000);
//    dispChar('0'+s.length(),4000);
}




ledmodule LedModule;
