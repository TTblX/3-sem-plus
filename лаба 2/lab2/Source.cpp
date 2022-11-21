#include "Two_arrays.h"
#include "CString.h"

int main() {
	setlocale(LC_ALL, "RU");


	int size1, size2;
	/*std::cout << "Two_arrays : " << std::endl;

	std::cout << "Enter size of first array\n";
	std::cin >> size1;

	std::cout << "Enter size of second array\n";
	std::cin >> size2;

	Two_arrays obj = Two_arrays(size1, size2);

	obj.show();
	std::cout << std::endl;
	std::cout << obj.maxNum() << '\n';
	std::cout << obj.minNum() << '\n';
	obj.swap();
	obj.show();
	std::cout << std::endl;

	Two_arrays  obj2 = obj + obj;
	obj2.show();
	std::cout << std::endl;

	obj2.swap(1, 1);
	obj2.show();
	std::cout << std::endl;

	(obj2 & obj2).show();
	std::cout << std::endl;*/



	std::cout << "CString : " << std::endl;

	CString * obj1 = new CString(), * obj2 = new CString(), * obj3 = new CString("");

	std::cout << obj1 << std::endl << obj2 << std::endl;

	(*obj3) = (*obj2);
	*obj3 += *obj1;

	std::cout << obj3 << std::endl;
	(*obj3) = (*obj2) + (*obj2);
	std::cout << obj3 << std::endl;

	if (*obj3 == *obj2)
	{
		std::cout << "obj3 == obj2\n";
	}

	if (*obj3 != *obj2)
	{
		std::cout << "obj3 != obj2\n";
	}
	char tmp = (*obj1)[0];
	std::cout << "1st character of obj1 is " << (*obj1)[0] << std::endl;

	std::cout << "substring(0, 2) of 2nd string is " << (*obj2)(0, 1) << std::endl;

	return 0;
}