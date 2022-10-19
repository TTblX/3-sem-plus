//
// Created by vanish on 14.10.2022.
//

#ifndef LAB3CLION_MONOBLOCK_H
#define LAB3CLION_MONOBLOCK_H
#include "Desktop.h"

class Monoblock : public Desktop{
private:
    double diag;
public:
    double getDiag() const;

    Monoblock(char *frame, double diag);

    void setDiag(double diag);
};


#endif //LAB3CLION_MONOBLOCK_H
