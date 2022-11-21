#include <iostream>
#include "Monoblock.h"
#include "Tablet.h"
#include "Laptop.h"

int main() {
    setlocale(LC_ALL, "rus");
	Monoblock monoblock;
	Laptop laptop;
	Tablet tablet;
	int com;

	while (true)
	{
		system("CLS");

		cout << "1. Изменить объект класса Monoblock" << endl
			<< "2. Изменить объект класса Laptop" << endl
			<< "3. Изменить объект класса Tablet" << endl
			<< "4. Вывести данные в объекте класса Monoblock" << endl
			<< "5. Вывести данные в объекте класса Laptop" << endl
			<< "6. Вывести данные в объекте класса Tablet" << endl;
		cin >> com;
		system("CLS");
		char* brand, * model, * frame, * modem;
		switch (com)
		{
		case 1:
		{
			cout << "1. Изменить бренд" << endl
				<< "2. Изменить модель" << endl
				<< "3. Изменить корпус" << endl
				<< "4. Изменить диагональ" << endl;
			cin >> com;
			switch (com)
			{
			case 1:
				cout << "Введите название бренда" << endl;
				brand = new char[30];
				cin >> brand;
				monoblock.setBrand(brand);
				break;
			case 2:
				cout << "Введите название модели" << endl;
				model = new char[30];
				cin >> model;
				monoblock.setModel(model);
				break;
			case 3:
				cout << "Введите название корпуса" << endl;
				frame = new char[30];
				cin >> frame;
				monoblock.setFrame(frame);
				break;
			case 4:cout << "Введите диагональ" << endl;
				double diag;
				cin >> diag;
				monoblock.setDiag(diag);
				break;
			default:
				break;
			}
			break;
		}
		case 2:
		{
			cout << "1. Изменить бренд" << endl
				<< "2. Изменить модель" << endl
				<< "3. Изменить заряд батареи" << endl
				<< "4. Изменить диагональ" << endl
				<< "5. Изменить количество кнопок" << endl;
			cin >> com;
			switch (com)
			{
			case 1:
				cout << "Введите название бренда" << endl;
				brand = new char[30];
				cin >> brand;
				laptop.setBrand(brand);
				break;
			case 2:
				cout << "Введите название модели" << endl;
				model = new char[30];
				cin >> model;
				laptop.setModel(model);
				break;
			case 3:
				cout << "Введите заряд батареи" << endl;
				int batteryCharge;
				cin >> batteryCharge;
				laptop.setBatteryCharge(batteryCharge);
				break;
			case 4:cout << "Введите диагональ" << endl;
				double diag;
				cin >> diag;
				laptop.setDiag(diag);
				break;
			case 5:
				int numOfButtons;
				cin >> numOfButtons;
				laptop.setNumOfButtons(numOfButtons);
			default:
				break;
			}
			break;
		}
		case 3:
		{
			cout << "1. Изменить бренд" << endl
				<< "2. Изменить модель" << endl
				<< "3. Изменить заряд батареи" << endl
				<< "4. Изменить диагональ" << endl
				<< "5. Изменить модем" << endl;
			cin >> com;
			switch (com)
			{
			case 1:
				cout << "Введите название бренда" << endl;
				brand = new char[30];
				cin >> brand;
				tablet.setBrand(brand);
				break;
			case 2:
				cout << "Введите название модели" << endl;
				model = new char[30];
				cin >> model;
				tablet.setModel(model);
				break;
			case 3:
				cout << "Введите заряд батареи" << endl;
				int batteryCharge;
				cin >> batteryCharge;
				tablet.setBatteryCharge(batteryCharge);
				break;
			case 4:cout << "Введите диагональ" << endl;
				double diag;
				cin >> diag;
				tablet.setDiag(diag);
				break;
			case 5:
				cout << "Введите модем" << endl;
				modem = new char[30];
				cin >> modem;
				tablet.setModem(modem);
			default:
				break;
			}
			break;
		}
		case 4:
		{
			Monoblock tmp = monoblock;
			cout << tmp << endl;
			break;
		}
		case 5:
		{
			cout << laptop << endl;
			break;
		}
		case 6:
		{
			cout << tablet << endl;
			break;
		}
		default:
			return 0;
		}

	}
    
    return 0;
}
