#ifndef __VIBRATE_MODULE_H__
#define __VIBRATE_MODULE_H__

class vibratemodule {
private:
public:
    void init();
    void vibrate(int time);
    void vibrateOn();
    void vibrateOff();
};

extern vibratemodule VibrateModule;

#endif
