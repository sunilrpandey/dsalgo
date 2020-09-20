#include <iostream>
#include "search_utils.h"

int main()
{
    int arr[] = {3,5,7,7,7,7,9,11,34,56,120};

	int item_to_search = 7;
    
    //int pos = SearchUtil::Get()->BinarySearchRecursive(arr, sizeof arr / sizeof arr[0], item_to_search);
	int pos = SearchUtil::Get()->BinarySearchIterative(arr, sizeof arr / sizeof arr[0], item_to_search);

	if (pos != -1)
		std::cout << "Found : " << arr[pos] << " at index :  " << pos << std::endl;
	else
		std::cout << "Not Found" << std::endl;

	std::cout << "Demo : Find floor value if not found!" << std::endl;
	item_to_search = 9;
	pos = SearchUtil::Get()->BinarySearchIterativeFloorValue(arr, sizeof arr / sizeof arr[0], item_to_search);

	if (pos != -1)
		std::cout << "Floor Value : " << arr[pos] << " at index :  " << pos;
	else
		std::cout << "Query number should be greater than first number at least!";


	SearchUtil::Cleanup();
	std::cin.get();
    return 0;
}