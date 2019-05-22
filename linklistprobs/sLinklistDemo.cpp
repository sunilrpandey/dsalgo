#include "slinklist.h"
#include <iostream>
using namespace std;
int main(int argc, char *arg[])
{
	LySinglyLinklist list;
	int arr[] = { 2,1,5,4,3 };
	int numElem = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < numElem; i++)
		list.push_front(arr[i]);
	
	list.show();
	cout << endl << list.size(true);

	list.clear();
	cout << endl << list.size();

	getchar();
	return 0;
}