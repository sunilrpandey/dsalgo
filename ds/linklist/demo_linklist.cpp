#include "linklist.h"
int main()
{
	ds::LinkList list = { 3,4,5,6,7 };
	list.Show();
	std::cout << "Size : " << list.Size();

    list.reset();

	std::cin.get();
	return 0;
}