#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include "FILE.h"
#include "TreeCreation.h"
#include "Exceptions.h"

int main()
{
	int com, type = 0;
	setlocale(LC_ALL, "rus");
	Tree<int> _int_tree;
	Tree<string> _string_tree;
	while (1)
	{
		try
		{
			cout << "Choose node's type:" << endl;
			int n;
			cout << "1 - int   2 - string" << endl;
			cin >> n;

			if (n < 0 || n > 3)
			{
				throw ArgumentException("parameter 'type' is out of range(1 to 3).");
			}

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				rewind(stdin);
				throw ArgumentException("parameter 'type' is not integer.");
			}

			if (n == 1)
			{				
				type = 0;
			}

			if (n == 2)
			{				
				type = 1;
			}
		}
		catch (ArgumentException ex)
		{
			rewind(stdin);
			_EXCEPTION_OUTPUT(ex);
			continue;
		}

		break;
	}

	while (true)
	{
		//system("CLS");

		cout << "1. Вывести дерево" << endl
			<< "2. Удалить элемент дерева" << endl
			<< "3. Добавить элемент в дерево" << endl
			<< "4. Вывести дерево в текстовый файл" << endl
			<< "5. Прочитать дерево из текстового файла" << endl
			<< "0. Закрыть программу" << endl;
		cin >> com;
		system("CLS");
		
		switch (com)
		{
		case 1:
		{
			try
			{
				if (type) // type == 0 -> int, type == 1 -> string
				{
					_string_tree.Show("", _string_tree.GetTop(), false);
				}
				else
				{
					_int_tree.Show("", _int_tree.GetTop(), false);
				}
			}
			catch (ArgumentIsEmptyException ex)
			{				
				rewind(stdin);
				_EXCEPTION_OUTPUT(ex);
			}
			
			break;
		}
		case 2:
		{
			if (type) // type == 0 -> int, type == 1 -> string
			{
				string element;
				while (1)
				{
					try
					{
						cout << "What element do you want to delete?" << endl;
						element = InputStringElement();
					}
					catch (ArgumentNullException ex)
					{
						rewind(stdin);
						_EXCEPTION_OUTPUT(ex);
						continue;
					}
					catch (ArgumentIsEmptyException ex)
					{
						rewind(stdin);
						_EXCEPTION_OUTPUT(ex);
						continue;
					}

					break;
				}

				_string_tree.Pop(element, _string_tree.GetTop());
			}
			else
			{
				int element;
				while (1)
				{
					try
					{
						cout << "What element do you want to delete?" << endl;
						element = InputIntElement();
					}
					catch (ArgumentException ex)
					{
						rewind(stdin);
						_EXCEPTION_OUTPUT(ex);
						continue;
					}

					break;
				}

				_int_tree.Pop(element, _int_tree.GetTop());
			}
			break;
		}
		case 3:
		{
			if (type) // type == 0 -> int, type == 1 -> string
			{
				string element;
				while (1)
				{
					try
					{
						cout << "Input element: " << endl;

						element = InputStringElement();
					}
					catch (ArgumentNullException ex)
					{
						rewind(stdin);
						_EXCEPTION_OUTPUT(ex);
						continue;
					}
					catch (ArgumentIsEmptyException ex)
					{
						rewind(stdin);
						_EXCEPTION_OUTPUT(ex);
						continue;
					}

					break;
				}

				_string_tree.Push(element, _string_tree.GetTop(), nullptr);
				if (_string_tree.GetTop() == nullptr)
				{
					_string_tree.SetTop(_string_tree.Push(element, _string_tree.GetTop(), nullptr));
				}
			}
			else
			{
				int element;
				while (1)
				{
					try
					{
						cout << "Input element: " << endl;

						element = InputIntElement();
					}
					catch (ArgumentNullException ex)
					{
						rewind(stdin);
						_EXCEPTION_OUTPUT(ex);
						continue;
					}
					catch (ArgumentIsEmptyException ex)
					{
						rewind(stdin);
						_EXCEPTION_OUTPUT(ex);
						continue;
					}

					break;
				}

				_int_tree.Push(element, _int_tree.GetTop(), nullptr);
				if (_int_tree.GetTop() == nullptr)
				{
					_int_tree.SetTop(_int_tree.Push(element, _int_tree.GetTop(), nullptr));
				}
			}
			break;
		}
		case 4:
		{
			if (type) // type == 0 -> int, type == 1 -> string
			{
				SendToFile(_string_tree);
			}
			else
			{
				SendToFile(_int_tree);
			}
			break;
		}
		case 5:
		{
			std::string fileName;
			std::cout << "Input name of file:" << std::endl;
			std::cin >> fileName;
			std::cout << "Choose tree type:\n1 - int\n2 - string" << std::endl;
			std::cin >> type;

			if (type == 1) // type == 0 -> int, type == 1 -> string
			{
				TextFile<int> txtFile = fileName;								

				try
				{
					txtFile.OpenFile();
				}
				catch (FileOpenErrorException ex)
				{
					rewind(stdin);
					_EXCEPTION_OUTPUT(ex);
				}				

				txtFile.ReadFile(_int_tree);
				type = 0;
			}
			else if (type == 2) // type == 0 -> int, type == 1 -> string
			{
				TextFile<string> txtFile = fileName;				

				try
				{
					txtFile.OpenFile();
				}				
				catch (FileOpenErrorException ex)
				{
					rewind(stdin);
					_EXCEPTION_OUTPUT(ex);
				}

				txtFile.ReadFile(_string_tree);
				type = 1;
			}

			break;
		}
		default:
			return 0;
		}

	}

	return 0;
}