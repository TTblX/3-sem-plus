//
// Created by vanish on 14.10.2022.
//
#include <cstring>
#include "Computer.h"

}

char *Computer::getBrand() const {
    return brand;
}

void Computer::setBrand(char *brand) {
    Computer::brand = brand;
}

char *Computer::getModel() const {
    return model;
}

void Computer::setModel(char *model) {
    Computer::model = model;
}

Computer::Computer(char *brand, char *model) : brand(brand), model(model) {}

Computer::~Computer() {
    delete[] brand;
    delete[] model;
}
