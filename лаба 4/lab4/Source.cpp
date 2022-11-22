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
	cout << "Какой тип данных вы хотите использовать?" << endl
		<< "1. int" << endl
		<< "2. char" << endl;
	cin >> command;

	if (command == 1) {
		isChar = false;
		cout << "Введите значение корня" << endl;
		cin >> int_tmp;
		int_root.CreateNode(int_tmp);
		int_root = int_root;
	}
	else {
		isChar = true;
		cout << "Введите значение корня" << endl;
		cin >> char_tmp;
		char_root.CreateNode(char_tmp);
		char_root = char_root;
	}

	
	

	while (true)
	{
		cout << "1. Добавить новый элемент в дерево" << endl
			<< "2. Удалить элемент из дерева" << endl
			<< "3. Вывести дерево" << endl
			<< "4. Перейти к левому потомку (оператор --), переходя к нему, вы уже не сможете вернуться к родителю" << endl
			<< "5. Перейти к правому потомку(оператор ++), переходя к нему, вы уже не сможете вернуться к родителю" << endl
			<< "0. Выйти из программы" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
		{
			cout << "Введите значение нового элемента" << endl;
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
			cout << "Введите значение, элемент с которым надо удалить" << endl;
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
