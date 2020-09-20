#include "sorting_util.h"

void swap(int& i, int& j) {

	if (i == j)
		return;
	int temp = i;
	i = j;
	j = temp;
}

int Partition(int * arr, int l, int r)
{
	int pivot = arr[r];
	int i = l-1;
	for (int j = l; j <= r - 1; j++) {
		
		if (arr[j] < pivot) {
			
			i++;			
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);

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
void SortingUtil::Quicksort(int * arr, int sz)
{
	QuicksortUtil(arr, 0, sz - 1);
}

void Merge(int * arr, int l,int m, int r)
{
	//Take two sorted array
	int sz_first_half = m - l + 1;
	int sz_second_half = r - m;

	int * arr_first_half = new int[sz_first_half];
	int * arr_second_half = new int[sz_second_half];

	for (int i = 0; i < sz_first_half; i++) {
		arr_first_half[i] = arr[l + i];
	}
	for (int j = 0; j < sz_second_half; j++) {
		arr_second_half[j] = arr[m+1+j];
	}

	int k = 0;
	int i = 0, j = 0;
	while (i < sz_first_half && j < sz_second_half) {
		if (arr_first_half[i] < arr_second_half[j]) {
			arr[l + k] = arr_first_half[i];
			i++;
			k++;
		}
		else {
			arr[l + k] = arr_second_half[j];
			j++;
			k++;
		}
	}

	if (i < sz_first_half) {
		while(i < sz_first_half) {
			arr[l + k] = arr_first_half[i];
			i++;
			k++;
		}
	}
	if (j < sz_second_half) {
		while (j < sz_second_half) {
			arr[l + k] = arr_second_half[j];
			j++;
			k++;
		}
	}

	delete[] arr_first_half;
	delete[]  arr_second_half;
}

void MergesortUtil(int * arr, int l, int r)
{
	if (l >= r)
		return;

	int mid = l + (r - l) / 2;	
	MergesortUtil(arr, l, mid);
	MergesortUtil(arr, mid + 1, r);

	Merge(arr, l, mid, r);
}


void SortingUtil::Mergesort(int * arr, int sz)
{
	MergesortUtil(arr, 0, sz - 1);
}