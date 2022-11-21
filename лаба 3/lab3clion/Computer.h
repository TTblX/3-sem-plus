#pragma once
using namespace std;

class Computer {
private:
    char * brand;
    char * model;
public:
    virtual ~Computer() {
        delete brand;
        delete model;
    }

    Computer() {
        brand = (char*) "Asus";
        model = (char*)"TUF Gaming";
    }

    Computer(Computer* obj) {
        brand = new char[30];
        model = new char[30];
        memcpy_s(brand, 30 * sizeof(char), obj->brand, 30 * sizeof(char));
        memcpy_s(model, 30 * sizeof(char), obj->model, 30 * sizeof(char));
    }

    Computer(char* brand, char* model) : brand(brand), model(model) {}

    char* getBrand() const {
        return brand;
    }

    void setBrand(char* brand) {
        Computer::brand = brand;
    }

    char* getModel() const {
        return model;
    }

    void setModel(char* model) {
        Computer::model = model;
    }

    friend ostream& operator<<(ostream& out, Computer obj);
};

ostream& operator<<(ostream& out, Computer obj) {
    cout << "Бренд : " << obj.brand << endl
        << "Модель : " << obj.model << endl;
    return out;
}