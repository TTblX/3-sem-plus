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

		cout << "1. �������� ������ ������ Monoblock" << endl
			<< "2. �������� ������ ������ Laptop" << endl
			<< "3. �������� ������ ������ Tablet" << endl
			<< "4. ������� ������ � ������� ������ Monoblock" << endl
			<< "5. ������� ������ � ������� ������ Laptop" << endl
			<< "6. ������� ������ � ������� ������ Tablet" << endl;
		cin >> com;
		system("CLS");
		char* brand, * model, * frame, * modem;
		switch (com)
		{
		case 1:
		{
			cout << "1. �������� �����" << endl
				<< "2. �������� ������" << endl
				<< "3. �������� ������" << endl
				<< "4. �������� ���������" << endl;
			cin >> com;
			switch (com)
			{
			case 1:
				cout << "������� �������� ������" << endl;
				brand = new char[30];
				cin >> brand;
				monoblock.setBrand(brand);
				break;
			case 2:
				cout << "������� �������� ������" << endl;
				model = new char[30];
				cin >> model;
				monoblock.setModel(model);
				break;
			case 3:
				cout << "������� �������� �������" << endl;
				frame = new char[30];
				cin >> frame;
				monoblock.setFrame(frame);
				break;
			case 4:cout << "������� ���������" << endl;
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
			cout << "1. �������� �����" << endl
				<< "2. �������� ������" << endl
				<< "3. �������� ����� �������" << endl
				<< "4. �������� ���������" << endl
				<< "5. �������� ���������� ������" << endl;
			cin >> com;
			switch (com)
			{
			case 1:
				cout << "������� �������� ������" << endl;
				brand = new char[30];
				cin >> brand;
				laptop.setBrand(brand);
				break;
			case 2:
				cout << "������� �������� ������" << endl;
				model = new char[30];
				cin >> model;
				laptop.setModel(model);
				break;
			case 3:
				cout << "������� ����� �������" << endl;
				int batteryCharge;
				cin >> batteryCharge;
				laptop.setBatteryCharge(batteryCharge);
				break;
			case 4:cout << "������� ���������" << endl;
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
			cout << "1. �������� �����" << endl
				<< "2. �������� ������" << endl
				<< "3. �������� ����� �������" << endl
				<< "4. �������� ���������" << endl
				<< "5. �������� �����" << endl;
			cin >> com;
			switch (com)
			{
			case 1:
				cout << "������� �������� ������" << endl;
				brand = new char[30];
				cin >> brand;
				tablet.setBrand(brand);
				break;
			case 2:
				cout << "������� �������� ������" << endl;
				model = new char[30];
				cin >> model;
				tablet.setModel(model);
				break;
			case 3:
				cout << "������� ����� �������" << endl;
				int batteryCharge;
				cin >> batteryCharge;
				tablet.setBatteryCharge(batteryCharge);
				break;
			case 4:cout << "������� ���������" << endl;
				double diag;
				cin >> diag;
				tablet.setDiag(diag);
				break;
			case 5:
				cout << "������� �����" << endl;
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
