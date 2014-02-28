#include "Arduino.h"
#include "xadow.h"
#include "userled.h"

void userled::blinkGreen(int count, int gap) {
    for(int i=0; i<count; i++) {
        Xadow.greenLed(LEDON);   
        delay(gap);
        Xadow.greenLed(LEDOFF);    
        delay(gap);
    }
}

userled UserLed;

