//
// Created by vanish on 14.10.2022.
//

#ifndef LAB3CLION_TABLET_H
#define LAB3CLION_TABLET_H
#include "Poratble.h"

class Tablet : Poratble{
private:
    char* modem;
public:
    char *getModem() const;

    virtual ~Tablet();

    Tablet(char *brand, char *model, int batteryCharge, double diag, char *modem);

    void setModem(char *modem);
};


#endif //LAB3CLION_TABLET_H
