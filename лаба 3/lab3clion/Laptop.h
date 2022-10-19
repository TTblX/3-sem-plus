//
// Created by vanish on 14.10.2022.
//

#ifndef LAB3CLION_LAPTOP_H
#define LAB3CLION_LAPTOP_H
#include "Poratble.h"

class Laptop : public Poratble{
private:
    int numOfButtons;
public:
    int getNumOfButtons() const;

    Laptop(char *brand, char *model, int batteryCharge, double diag, int numOfButtons);

    void setNumOfButtons(int numOfButtons);
};


#endif //LAB3CLION_LAPTOP_H
