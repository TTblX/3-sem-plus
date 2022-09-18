#include "Two_arrays.h"

int main() {
	int size1, size2;
	std::cout << "Enter size of first array\n";
	std::cin >> size1;

	std::cout << "Enter size of second array\n";
	std::cin >> size2;

	Two_arrays* obj = new Two_arrays(size1, size2);

	obj->show();
	std::cout << obj->maxNum() << '\n';
	std::cout << obj->minNum() << '\n';
	obj->swap();
	obj->show();

	return 0;
}