#include <iostream>
#include "countingsort.h"

void ShowArray(const std::string& msg, int * arr, int sz)
{
	std::cout << msg.c_str();
	for (int i = 0; i < sz; i++) {
		std::cout << arr[i] << "   ";
	}
	std::cout << std::endl;
}

int main()
{
	//int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
	int arr[] = { 10, 15, 10, 13, 13, 13 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	ShowArray("Given Array : ", arr, sz);
	algos::Countingsort(arr, sz);
	ShowArray("Sorted Array : ", arr, sz);

	std::cout << std::endl;

	std::cin.get();
	return 0;
}