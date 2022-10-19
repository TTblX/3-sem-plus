//
// Created by vanish on 14.10.2022.
//

#include "Poratble.h"

int Poratble::getBatteryCharge() const {
    return batteryCharge;
}

void Poratble::setBatteryCharge(int batteryCharge) {
    Poratble::batteryCharge = batteryCharge;
}

double Poratble::getDiag() const {
    return diag;
}

void Poratble::setDiag(double diag) {
    Poratble::diag = diag;
}

Poratble::Poratble(char *brand, char *model, int batteryCharge, double diag) : Computer(brand, model),
                                                                               batteryCharge(batteryCharge),
                                                                               diag(diag) {}
