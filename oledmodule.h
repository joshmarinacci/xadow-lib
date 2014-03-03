#ifndef __OLED_MODULE_H__
#define __OLED_MODULE_H__

#include <SeeedOLED.h>

class oledmodule {
private:
public:
    void init();
    void drawString(int x, int y, String string);
};

extern oledmodule OledModule;

#endif
