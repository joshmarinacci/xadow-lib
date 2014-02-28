#include <Arduino.h>
#include "vibratemodule.h"

void vibratemodule::init() {
    DDRF |= 0x01;	
    DDRB |= 0x04;	 	
}

void vibratemodule::vibrate(int time) {
    vibrateOn();
    delay(time);
    vibrateOff();
}
void vibratemodule::vibrateOn() {
    PORTF |= 0x01;		
    PORTB |= 0x04;	
}
void vibratemodule::vibrateOff() { 
    PORTF &= ~(0x01);	
    PORTB |= 0x04;	
}

vibratemodule VibrateModule;

