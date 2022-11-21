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
    cout << "����� : " << obj.getBrand() << endl
        << "������ : " << obj.getModel() << endl
        << "��������� : " << obj.getDiag()  << endl
        << "����� �������: " << obj.getBatteryCharge() << endl
        << "����� : " << obj.getModem() << endl;
    return out;
}
