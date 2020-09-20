#pragma once
#include <iostream>
namespace algos{
int Partition(int * arr, int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j <= r - 1; j++) {

		if (arr[j] < pivot) {

			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[r]);

	return i + 1;
}
void QuicksortUtil(int * arr, int l, int r)
{
	if (l >= r)
		return;

	int p = Partition(arr, l, r);
	QuicksortUtil(arr, l, p - 1);
	QuicksortUtil(arr, p + 1, r);

}
void Quicksort(int * arr, int sz)
{
	QuicksortUtil(arr, 0, sz - 1);
}
}  