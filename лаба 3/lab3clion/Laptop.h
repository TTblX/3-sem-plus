//
// Created by vanish on 14.10.2022.
//
#pragma once
#include "Poratble.h"

class Laptop : public Portable{
private:
    int numOfButtons;
public:
    int getNumOfButtons() const {
        return numOfButtons;
    }

    Laptop(char* brand, char* model, int batteryCharge, double diag, int numOfButtons) : Portable(brand, model,
        batteryCharge,
        diag),
        numOfButtons(
            numOfButtons) {
        checkNumOfButtons();
    }

    Laptop() : Portable(), numOfButtons(102) {}

    void setNumOfButtons(int numOfButtons) {
        Laptop::numOfButtons = numOfButtons;
        checkNumOfButtons();
    }

    void checkNumOfButtons() {
        if (numOfButtons <= 0)
        {
            cout << "Error : incorrect number of buttons. Used default number of buttons\n";
            numOfButtons = 102;
        }
    }

    friend ostream& operator<<(ostream& out, Laptop obj);
};

ostream& operator<<(ostream& out, Laptop obj) {
    cout << "Бренд : " << obj.getBrand() << endl
        << "Модель : " << obj.getModel() << endl
        << "Диагональ : " << obj.getDiag() << endl
        << "Заряд батареи: " << obj.getBatteryCharge() << endl
        << "Количество клавиш : " << obj.getNumOfButtons() << endl;
    return out;
}