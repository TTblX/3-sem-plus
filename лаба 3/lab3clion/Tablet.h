//
// Created by vanish on 14.10.2022.
//
#pragma once
#include "Poratble.h"

class Tablet : public Portable{
private:
    char* modem;
public:
    char* getModem() const {
        return modem;
    }

    virtual ~Tablet() {
        delete[] modem;
    }

    Tablet(char* brand, char* model, int batteryCharge, double diag, char* modem) : Portable(brand, model,
        batteryCharge, diag),
        modem(modem) {}

    Tablet() : Portable() {
        modem = (char*)"TP-Link";
    }

    void setModem(char* modem) {
        Tablet::modem = modem;
    }

    void show() {
        cout << "Бренд : " << getBrand() << endl
            << "Модель : " << getModel() << endl
            << "Диагональ : " << getDiag() << endl
            << "Заряд батареи: " << getBatteryCharge() << endl
            << "Модем : " << getModem() << endl;
    }
};