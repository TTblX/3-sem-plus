#pragma once
#include <iostream>
#include <string>
#include "Tree.h"
#include "Clock.h"
#include "FILE.h"

using namespace std;
template<int N>
struct select_type;

template<>
struct select_type<1>
{
	typedef int Type;
};

template<>
struct select_type<2>
{
	typedef std::string Type;
};

template<>
struct select_type<3>
{
	typedef Clock Type;
};

int InputIntElement()
{
	int element;
	cin >> element;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		rewind(stdin);
		throw ArgumentException("parameter 'element' is not integer.");
	}

	return element;
}

string InputStringElement()
{
	rewind(stdin);
	string str;
	getline(cin, str);

	if (str.c_str() == nullptr)
	{
		throw ArgumentNullException(nameof(str));
	}

	if (str.empty())
	{
		throw ArgumentIsEmptyException(nameof(str));
	}

	return str;
}

Clock InputClockElement(Clock& clock)
{
	string brand;
	time_t time;

	cout << "Brand: " << endl;
	brand = InputStringElement();
	clock.SetBrand(brand);

	cout << "Time: " << endl;
	cin >> time;

	if (time < 0 || time >= INT_MAX)
	{
		throw ArgumentException("parameter 'time' is out of range.");
	}

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		rewind(stdin);
		throw ArgumentException("parameter 'time' is not integer.");
	}


	clock.SetTime(time);


	return clock;
}

Tree<int> InputIntElemsInTree(int count, Tree<int>& tree)
{
	int element = 0, flg = 0;
	while (count != 0)
	{
		while (1)
		{
			try
			{
				cout << "Input element: " << endl;

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

		tree.Push(element, tree.GetTop(), nullptr);
		if (flg == 0)
		{
			tree.SetTop(tree.Push(element, tree.GetTop(), nullptr));
			flg = 1;
		}
		count--;
	}

	return tree;
}

Tree<string> InputStringElemsInTree(int count, Tree<string>& tree)
{
	string element;
	int flg = 0;
	while (count != 0)
	{
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

		tree.Push(element, tree.GetTop(), nullptr);
		if (flg == 0)
		{
			tree.SetTop(tree.Push(element, tree.GetTop(), nullptr));
			flg = 1;
		}
		count--;
	}

	return tree;
}

template<typename T>
int SendToFile(Tree<T>& tree)
{
	std::string fileName;

	std::cout << "Please, input file name." << std::endl;	
	std::cin >> fileName;

	TextFile<T> txtFile = fileName;

	try
	{
		txtFile.OpenFile();
	}
	catch (FileOpenErrorException ex)
	{
		rewind(stdin);
		_EXCEPTION_OUTPUT(ex);
		return -1;
	}

	txtFile.WriteFile(tree);

	return 0;
}