#pragma once

namespace algos
{

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


void Mergesort (int * arr, int sz)
{
	MergesortUtil(arr, 0, sz - 1);
}
};