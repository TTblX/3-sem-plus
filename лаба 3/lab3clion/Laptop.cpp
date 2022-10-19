//
// Created by vanish on 14.10.2022.
//

#include "Laptop.h"

int Laptop::getNumOfButtons() const {
    return numOfButtons;
}

void Laptop::setNumOfButtons(int numOfButtons) {
    Laptop::numOfButtons = numOfButtons;
}

Laptop::Laptop(char *brand, char *model, int batteryCharge, double diag, int numOfButtons) : Poratble(brand, model,
                                                                                                      batteryCharge,
                                                                                                      diag),
                                                                                             numOfButtons(
                                                                                                     numOfButtons) {}
