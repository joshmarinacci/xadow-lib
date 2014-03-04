#ifndef __OLED_MODULE_H__
#define __OLED_MODULE_H__

#include <SeeedOLED.h>

class oledmodule {
private:
public:
    void init();
    void clear();
    void drawString(int x, int y, String string);
    void drawBitmapNumber(int x, int y, int sx, int sy, int sw, int sh);
};

extern oledmodule OledModule;

#endif
