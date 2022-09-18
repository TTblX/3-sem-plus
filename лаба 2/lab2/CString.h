#pragma once
#include <iostream>
class CString
{
public:
	CString() {
		std::cout << "—колько символов с строке?";
		std::cin >> this->str_size;
		this->str = new char[str_size];
		std::cout << "¬ведите строку";
		std::cin >> str;
	}

	CString(char* str) {
		this->str = str;
		this->str_size = strlen(str);
	}

	CString operator+ (CString obj) {
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
		return str;
	}

	CString& operator= (CString obj) {
		return *new CString(obj.str);
	}

	CString& operator+= (CString obj) {
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
		return *this;
	}

	friend bool operator==(CString obj1, CString obj2);
	friend bool operator!=(CString obj1, CString obj2);

	char operator[](int i) {
		return this->str[i];
	}
private:
	char* str;
	int str_size;
};

bool operator==(CString obj1, CString obj2) {
	return strcmp(obj1.str, obj2.str);
}

bool operator!=(CString obj1, CString obj2) {
	return !strcmp(obj1.str, obj2.str);
}

