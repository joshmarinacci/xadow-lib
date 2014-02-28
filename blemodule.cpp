#include <Arduino.h>
#include <Wire.h>
#include "blemodule.h"


void blemodule::TESTIO(void)
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

void blemodule::init() {
    int n;
  PORTB|=0x04;
  TESTIO();
  if(error==0)
  {
    DDRB|=0x81;
    for(n=0;n<40;n++)
    {
      PORTB&=~0x81;
      delay(50);
      PORTB|=0x81;
    }
  }
  Serial1.begin(38400);
}

blemodule BleModule;
