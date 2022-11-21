//
// Created by vanish on 14.10.2022.
//
#pragma once
#include "Desktop.h"
#include <iostream>

class Monoblock : public Desktop{
private:
    double diag;
public:
    double getDiag() const {
        return diag;
    }

    Monoblock(char* frame =(char*) "", double diag = 15.6) : Desktop(frame), diag(diag) {
        checkDiag();
    }

    Monoblock(Monoblock* obj) : diag(obj->diag) {
        setBrand(new char[30]);
        setModel(new char[30]);
        setFrame(new char[30]);

        memcpy_s(getBrand(), 30 * sizeof(char), obj->getBrand(), 30 * sizeof(char));
        memcpy_s(getModel(), 30 * sizeof(char), obj->getModel(), 30 * sizeof(char));
        memcpy_s(getFrame(), 30 * sizeof(char), obj->getFrame(), 30 * sizeof(char));
    }

    void setDiag(double diag) {
        Monoblock::diag = diag;
        checkDiag();
    }

    void checkDiag() {
        if (diag <= 0)
        {
            cout << "Error : incorrect diagonal. Diagonal must be above 0. Used default diagonal (15.6)\n";
            diag = 15.6;
        }
    }

    friend ostream& operator<<(ostream& out, Monoblock obj);
};

ostream& operator<<(ostream& out, Monoblock obj) {
    cout << "Бренд : " << obj.getBrand() << endl
        << "Модель : " << obj.getModel() << endl
        << "Корпус : " << obj.getFrame() << endl
        << "Диагональ : " << obj.getDiag() << endl;
    return out;
}