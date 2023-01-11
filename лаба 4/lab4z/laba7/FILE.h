#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Tree.h"

template<class T>
class AbstractFile
{
public:
	virtual void ReadFile(Tree<T>&) = 0;
	virtual void WriteFile(Tree<T>&) = 0;
};

template<class T>
class TextFile : public AbstractFile<T>
{
private:
	std::string _fileName;
public:
	TextFile() = default;
	TextFile(std::string& name) : _fileName(name) {};
	void OpenFile();
	void ReadFile(Tree<T>&) override;
	void WriteFile(Tree<T>&) override;
};

template<class T>
class BinaryFile : public AbstractFile<T>
{
private:
	std::string _fileName;
public:
	BinaryFile() = default;
	BinaryFile(std::string& name) : _fileName(name) {};
	void OpenFile();
	void ReadFile(Tree<T>&) override;
	void WriteFile(Tree<T>&) override;
};

template<typename T>
void TextFile<T>::OpenFile() 
{
	std::fstream file;

	try
	{
		file.open(_fileName, std::ios::app);

		if (!file.is_open())
		{
			throw FileOpenErrorException(nameof(_fileName));
		}
	}
	catch (FileOpenErrorException ex)
	{
		rewind(stdin);
		std::cout << "Error message: " << ex.what() << std::endl;
		std::cout << "Error code: " << ex.GetErrorCode() << std::endl;
	}

	file.close();
}

template<typename T>
void TextFile<T>::ReadFile(Tree<T>& tree)
{
	bool flg = 0;

	std::fstream file;
	file.open(_fileName + ".txt", std::ios::in);

	while (file)
	{
		//std::getline(file, str);
		T data;
		file >> data;
		tree.Push(data, tree.GetTop(), nullptr);
		if (flg == 0)
		{
			tree.SetTop(tree.Push(data, tree.GetTop(), nullptr));
			flg = 1;
		}
	}


	file.close();
}

template<typename T>
void TextFile<T>::WriteFile(Tree<T>& tree)
{
	std::fstream file;
	file.open(_fileName + ".txt", std::ios::out);

	tree.GetTop()->WriteNodeToTextFile(file);
}

template<class T>
inline void BinaryFile<T>::OpenFile()
{
	std::fstream file;

	try
	{
		file.open(_fileName, std::ios::binary);
	}
	catch (FileOpenErrorException ex)
	{
		rewind(stdin);
		std::cout << "Error message: " << ex.what() << std::endl;
		std::cout << "Error code: " << ex.GetErrorCode() << std::endl;
	}

	file.close();
}

template<class T>
inline void BinaryFile<T>::ReadFile(Tree<T>& tree)
{
	bool flg = 0;
	setlocale(LC_ALL, "rus");

	std::fstream file;
	file.open(_fileName, std::ios::in | std::ios::binary);

	while (true)
	{
		//std::getline(file, str);
		T data;
		file.read(reinterpret_cast<char*>(&data), sizeof(T));
		if (file.eof()) break;
		tree.Push(data, tree.GetTop(), nullptr);
		if (flg == 0)
		{			
			tree.SetTop(tree.Push(data, tree.GetTop(), nullptr));
			flg = 1;
		}

	}


	file.close();
}

template<class T>
inline void BinaryFile<T>::WriteFile(Tree<T>& tree)
{
	std::fstream file;
	file.open(_fileName, std::ios::out | std::ios::binary);
	

	tree.GetTop()->WriteNodeToBinaryFile(file);
}
