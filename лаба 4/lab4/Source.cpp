#include"Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int command, int_tmp;
	bool isChar;
	char char_tmp;
	Node<int>  int_root;
	Node<char> char_root;
	cout << "����� ��� ������ �� ������ ������������?" << endl
		<< "1. int" << endl
		<< "2. char" << endl;
	cin >> command;

	if (command == 1) {
		isChar = false;
		cout << "������� �������� �����" << endl;
		cin >> int_tmp;
		int_root.CreateNode(int_tmp);
		int_root = int_root;
	}
	else {
		isChar = true;
		cout << "������� �������� �����" << endl;
		cin >> char_tmp;
		char_root.CreateNode(char_tmp);
		char_root = char_root;
	}

	
	

	while (true)
	{
		cout << "1. �������� ����� ������� � ������" << endl
			<< "2. ������� ������� �� ������" << endl
			<< "3. ������� ������" << endl
			<< "4. ������� � ������ ������� (�������� --), �������� � ����, �� ��� �� ������� ��������� � ��������" << endl
			<< "5. ������� � ������� �������(�������� ++), �������� � ����, �� ��� �� ������� ��������� � ��������" << endl
			<< "0. ����� �� ���������" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
		{
			cout << "������� �������� ������ ��������" << endl;
			if (isChar)
			{
				cin >> char_tmp;
				char_root.InsertNode(char_tmp);
			}
			else
			{
				cin >> int_tmp;
				int_root.InsertNode(int_tmp);
			}
			break;
		}
		case 2:
		{
			cout << "������� ��������, ������� � ������� ���� �������" << endl;
			if (isChar)
			{
				cin >> char_tmp;
				char_root.deleteNode(char_tmp);
			}
			else
			{
				cin >> int_tmp;
				int_root.deleteNode(int_tmp);
			}
			break;
		}
		case 3:
		{
			if (isChar) char_root.printBT(&char_root);
			else int_root.printBT(&int_root);
			break;
		}
		case 4:
		{
			if (isChar)
			{
				--char_root;
			}
			else
			{
				--int_root;
			}
			break;
		}
		case 5:
		{
			if (isChar)
			{
				char_root.operator++();
			}
			else
			{
				int_root.operator++();
			}
			break;
		}
		default:
			return 0;
		}
	}

	return 0;
}
