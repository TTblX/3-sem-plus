//
// Created by vanish on 14.10.2022.
//
#pragma once
#include "Computer.h"

class Desktop : public Computer{
private:
    char* frame;
public:
    char* getFrame() const {
        return frame;
    }

    virtual ~Desktop() {
        delete[] frame;
    }

    Desktop(char* frame) {
        this->frame = new char[30];
        setFrame(frame);
    }

    Desktop(Desktop* obj) {
        setBrand(new char[30]);
        setModel(new char[30]);
        frame = new char[30];

        memcpy_s(getBrand(), 30 * sizeof(char), obj->getBrand(), 30 * sizeof(char));
        memcpy_s(getModel(), 30 * sizeof(char), obj->getModel(), 30 * sizeof(char));
        setFrame(obj->frame);
    }

    Desktop() : Computer() {
        this->frame = new char[30];
        setFrame((char*)"frame");
    }

    void setFrame(char* frame) {
        memcpy_s(this->frame, 30 * sizeof(char), frame, 30 * sizeof(char));
        //Desktop::frame = frame;
    }

    friend ostream& operator<<(ostream& out, Desktop obj);
};

ostream& operator<<(ostream& out, Desktop obj) {
    cout << "Бренд : " << obj.getBrand() << endl
        << "Модель : " << obj.getModel() << endl
        << "Корпус : " << obj.getFrame() << endl;;
    return out;
}