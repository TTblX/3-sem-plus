//
// Created by vanish on 14.10.2022.
//

#ifndef LAB3CLION_PORATBLE_H
#define LAB3CLION_PORATBLE_H
#include "Computer.h"

class Poratble : public Computer{
private:
    int batteryCharge;
    double diag;
public:
    Poratble(char *brand, char *model, int batteryCharge, double diag);

    int getBatteryCharge() const;

    void setBatteryCharge(int batteryCharge);

    double getDiag() const;

    void setDiag(double diag);
};


#endif //LAB3CLION_PORATBLE_H
