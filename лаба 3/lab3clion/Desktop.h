//
// Created by vanish on 14.10.2022.
//

#ifndef LAB3CLION_DESKTOP_H
#define LAB3CLION_DESKTOP_H
#include "Computer.h"

class Desktop : public Computer{
private:
    char* frame;
public:
    char *getFrame() const;

    virtual ~Desktop();

    Desktop(char *frame);

    void setFrame(char *frame);
};


#endif //LAB3CLION_DESKTOP_H
