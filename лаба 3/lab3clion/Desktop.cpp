//
// Created by vanish on 14.10.2022.
//

#include "Desktop.h"

char *Desktop::getFrame() const {
    return frame;
}

void Desktop::setFrame(char *frame) {
    Desktop::frame = frame;
}

Desktop::Desktop(char *frame) : frame(frame) {}

Desktop::~Desktop() {
    delete[] frame;
}
