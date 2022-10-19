//
// Created by vanish on 14.10.2022.
//

#include "Monoblock.h"

double Monoblock::getDiag() const {
    return diag;
}

void Monoblock::setDiag(double diag) {
    Monoblock::diag = diag;
}

Monoblock::Monoblock(char *frame, double diag) : Desktop(frame), diag(diag) {}
