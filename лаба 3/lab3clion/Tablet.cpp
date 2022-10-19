//
// Created by vanish on 14.10.2022.
//

#include "Tablet.h"

char *Tablet::getModem() const {
    return modem;
}

void Tablet::setModem(char *modem) {
    Tablet::modem = modem;
}

Tablet::Tablet(char *brand, char *model, int batteryCharge, double diag, char *modem) : Poratble(brand, model,
                                                                                                 batteryCharge, diag),
                                                                                        modem(modem) {}

Tablet::~Tablet() {
    delete[] modem;
}
