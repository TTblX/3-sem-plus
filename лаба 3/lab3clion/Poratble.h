//
// Created by vanish on 14.10.2022.
//
#pragma once
#include "Computer.h"
#include <iostream>

class Portable : public Computer{
private:
    int batteryCharge;
    double diag;
public:
    Portable(char* brand, char* model, int batteryCharge, double diag) : Computer(brand, model),
        batteryCharge(batteryCharge),
        diag(diag) 
    {
        checkBatteryCharge();        
        checkDiag();
    }
    Portable() : Computer(), batteryCharge(100), diag(15.6) {}

    int getBatteryCharge() const {
        return batteryCharge;
    }

    void setBatteryCharge(int batteryCharge) {
        Portable::batteryCharge = batteryCharge;
        checkBatteryCharge();
    }

    double getDiag() const {
        return diag;
    }

    void setDiag(double diag) {
        Portable::diag = diag;
        checkDiag();
    }

    void checkBatteryCharge() {
        if (batteryCharge < 0 || batteryCharge > 100)
        {
            cout << "Error : incorrect battery charge. Used default battey charge (100%)\n";
            batteryCharge = 100;
        }
    }

    void checkDiag() {
        if (diag <= 0)
        {
            cout << "Error : incorrect diagonal. Diagonal must be above 0. Used default diagonal (15.6)\n";
            diag = 15.6;
        }
    }

    friend ostream& operator<<(ostream& out, Portable obj);
};

ostream& operator<<(ostream& out, Portable obj) {
    cout << "Бренд : " << obj.getBrand() << endl
        << "Модем : " << obj.getModel() << endl
        << "Диагональ: " << obj.diag << endl
        << "Заряд батареи " << obj.batteryCharge << endl;
    return out;
}