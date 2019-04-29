#include <iostream>

using namespace std;

int partition(int arr[], int start, int end)
{
	int pivot = end;
	int i = -1;
	for(int j = 0; j < end; j++) {
		if(arr[j] < arr[pivot]){
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	i++;
	std::swap(arr[i], arr[pivot]);
	return i;
}
void quicksort(int arr[], int start, int end)
{
	if(start >= end)
		return;

	int pivot = partition(arr, start, end);

	quicksort(arr, start, pivot - 1);
	quicksort(arr, pivot + 1, end);
}

int main()
{
	int arr[] = {5, 9, 3, 7, 15};
	quicksort(arr, 0, 4);

	for(int i = 0; i < 5; i++) {
		cout << "\t" << arr[i];
	}
	return 0;
}
