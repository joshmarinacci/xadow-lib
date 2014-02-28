#ifndef __BLE_MODULE_H__
#define __BLE_MODULE_H__

class blemodule {
private:
    int error;
    void TESTIO(void);
public:
    void init();
};

extern blemodule BleModule;
#endif

