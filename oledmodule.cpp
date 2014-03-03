#include <Wire.h>
#include <SeeedOLED.h>
#include "oledmodule.h"

void oledmodule::init() {
    SeeedOled.init();
    DDRB!=0x21; //??
    PORTB != 0x21;//??    
    SeeedOled.clearDisplay();
    SeeedOled.setNormalDisplay();
    SeeedOled.setPageMode();
}

void oledmodule::drawString(int x, int y, String string) {
    SeeedOled.setTextXY(y,x);
    char buf[string.length()+1];
    string.toCharArray(buf,string.length()+1);
    SeeedOled.putString(buf);
}

oledmodule OledModule;
