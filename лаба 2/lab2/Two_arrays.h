#pragma once
#include <iostream>

class Two_arrays
{
public:
	
	int maxNum() {
		int max = this->array1[0];

		for (int i = 0; i < this->size1; i++)
		{
			if (this->array1[i] > max)
			{
				max = this->array1[i];
				this->id1 = i;
			}
		}

		return max;
	}

	int minNum() {
		int min = this->array2[0];

		for (int i = 0; i < this->size2; i++)
		{
			if (this->array2[i] < min)
			{
				min = this->array2[i];
				this->id2 = i;
			}
		}

		return min;
	}

	void swap() {
		int tmp = this->array1[this->id1];
		this->array1[this->id1] = this->array2[this->id2];
		this->array2[this->id2] = tmp;
	}

	void swap(int id1, int id2) {
		int tmp = this->array1[id1];
		this->array1[id1] = this->array2[id2];
		this->array2[id2] = tmp;
	}

	void show() {
		for (int i = 0; i < this->size1; i++)
		{
			std::cout << this->array1[i] << ' ';
		}
		std::cout << '\n';

		for (int i = 0; i < this->size2; i++)
		{
			std::cout << this->array2[i] << ' ';
		}
		std::cout << '\n';
	}

	Two_arrays(int size1, int size2) {
		this->array1 = new int[size1];
		this->array2 = new int[size2];

		std::cout << "Enter all components of first array\n";
		for (int i = 0; i < size1; i++)
		{
			std::cin >> this->array1[i];
		}

		std::cout << "Enter all components of second array\n";
		for (int i = 0; i < size2; i++)
		{
			std::cin >> this->array2[i];
		}

		this->size1 = size1;
		this->size2 = size2;
	}

	Two_arrays(int* array1, int* array2, int size1, int size2) : size1(size1), size2(size2) {
		this->array1 = new int[size1];
		this->array2 = new int[size2];

		memcpy(this->array1, array1, size1 * sizeof(int));
		memcpy(this->array2, array2, size2 * sizeof(int));
	}

	~Two_arrays() {
		delete[] this->array1;
		delete[] this->array2;
	}

	Two_arrays& operator+(const Two_arrays& obj) {
		int* array1 = new int[this->size1 + obj.size1];
		int* array2 = new int[this->size2 + obj.size2];
		for (int i = 0; i < this->size1 + obj.size1; i++)
		{
			if (i < this->size1)
			{
				array1[i] = this->array1[i];
			}
			else
			{
				array1[i] = obj.array1[i - this->size1];
			}
		}

		for (int i = 0; i < this->size2 + obj.size2; i++)
		{
			if (i < this->size2)
			{
				array2[i] = this->array2[i];
			}
			else
			{
				array2[i] = obj.array2[i - this->size2];
			}
		}
		Two_arrays* result = new Two_arrays(array1, array2, this->size1 + obj.size1, this->size2 + obj.size2);

		return * result;
	}

	Two_arrays& operator&(const Two_arrays& obj) {
		if (obj.size1 != size1 || size2 != obj.size2)
		{
			std::cout << "size of the arrays must be equal\n";
			return *this;
		}
		for (int i = 0; i < size1; i++)
		{
			array1[i] = array1[i] & obj.array1[i];
		}
		for (int i = 0; i < size2; i++)
		{
			array2[i] = array2[i] & obj.array2[i];
		}

		return *this;
	}


private:
	int *array1;
	int *array2;

	int size1;
	int size2;

	int id1;
	int id2;
};

