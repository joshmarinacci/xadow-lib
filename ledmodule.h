#ifndef __LED_MODULE_H__
#define __LED_MODULE_H__

class ledmodule {
private:
    void TESTIO(void);
public: 
    void init();
    void lprint(String s);
};

extern ledmodule LedModule;

#endif
