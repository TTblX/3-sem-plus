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

    friend ostream& operator<<(ostream& out, Tablet obj);
};

ostream& operator<<(ostream& out, Tablet obj) {
    cout << "Бренд : " << obj.getBrand() << endl
        << "Модель : " << obj.getModel() << endl
        << "Диагональ : " << obj.getDiag()  << endl
        << "Заряд батареи: " << obj.getBatteryCharge() << endl
        << "Модем : " << obj.getModem() << endl;
    return out;
}
