#pragma once
#include <iostream>
#include <string>

class CString
{
public:
	CString() {
		std::cout << "—колько символов с строке?\n";
		std::cin >> this->str_size;
		this->str = new char[str_size];
		std::cout << "¬ведите строку\n";
		std::cin >> str;
		str_size = strlen(str);
	}

	CString(const char* str) {
		str_size = strlen(str);
		this->str = new char[str_size + 1];
		strcpy_s(this->str, str_size * sizeof(char) + 1, str);
	}

	CString operator+ (CString const & obj) {
		char* str = new char[this->str_size + obj.str_size];
		for (int i = 0; i < this->str_size + obj.str_size; i++)
		{
			if (i < this->str_size)
			{
				str[i] = this->str[i];
			}
			else
			{
				str[i] = obj.str[i - this->str_size];
			}
		}
		str[this->str_size + obj.str_size] = '\0';
		return CString(str);
	}

	CString operator+ (CString * obj) {
		char* str = new char[this->str_size + obj->getSize()];
		for (int i = 0; i < this->str_size + obj->getSize(); i++)
		{
			if (i < this->str_size)
			{
				str[i] = this->str[i];
			}
			else
			{
				str[i] = obj->getChar(i - this->str_size);
			}
		}
		return CString(str);
	}

	CString operator= (CString obj) {
		str_size = obj.str_size;
		str = new char[str_size + 1];
		strcpy_s(str, str_size * sizeof(char) + 1, obj.str);
		return *this;
	}

	CString operator+= (CString obj) {
		char* str = new char[this->str_size + obj.str_size];
		int i;
		for (i = 0; i < this->str_size + obj.str_size; i++)
		{
			if (i < this->str_size)
			{
				str[i] = this->str[i];
			}
			else
			{
				str[i] = obj.str[i - this->str_size];
			}
		}
		str[i] = '\0';
		this->str_size = strlen(str);
		this->str = new char[this->str_size + 1];
		strcpy_s(this->str, str_size * sizeof(char) + 1, str);
		return *this;
	}

	friend bool operator==(const CString obj1, const CString obj2);
	friend bool operator!=(const CString obj1, const CString obj2);
	friend std::ostream& operator<<(std::ostream& os, const CString& str);

	char operator[](int i) const {
		try
		{
			return str[i];
		}
		catch (const std::exception&)
		{
			std::cout << "Error : index out of bound exception\n";
		}
	}

	CString* operator()(int left_id, int right_id) {
		if (right_id >= str_size || left_id >= str_size)
		{
			std::cout << "Error : index out of bound exception\n";
			return NULL;
		}

		char* str = new char[right_id - left_id + 2];

		for (int i = 0; i < right_id - left_id + 1; i++)
		{
			str[i] = this->str[left_id + i];
		}
		str[right_id - left_id + 1] = '\0';

		CString* result = new CString(str);
		delete[] str;
		return result;
	}

	const char* getStr() {
		return str;
	}

	const char getChar(int i) {
		return str[i];
	}

	const int getSize() {
		return str_size;
	}


private:
	char* str;
	int str_size;
};

bool operator==(CString obj1, CString obj2) {
	return !strcmp(obj1.str, obj2.str);
}

bool operator!=(CString obj1, CString obj2) {
	return strcmp(obj1.str, obj2.str);
}

std::ostream& operator<<(std::ostream& os,   CString* str)
{	
	for (int i = 0; i < str->getSize(); i++)
	{
		os << str->getChar(i);
	}

	return os;
}

