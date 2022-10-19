//
// Created by vanish on 14.10.2022.
//

#ifndef LAB3CLION_COMPUTER_H
#define LAB3CLION_COMPUTER_H


class Computer {
private:
    char * brand;
    char * model;
public:
    virtual ~Computer();

    Computer(char *brand, char *model);

    char *getBrand() const;

    void setBrand(char *brand);

    char *getModel() const;

    void setModel(char *model);
};


#endif //LAB3CLION_COMPUTER_H
