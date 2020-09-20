#pragma once
#include <iostream>

namespace algos
{
void Insertionsort (int * arr, int sz)
{
	for(int i = 1; i < sz; i++) {
		int key = arr[i];
		int j = i-1;
		for(; j >=0 && arr[j] > key; j--) {
			arr[j+1] = arr[j];			
		}
		arr[j+1] = key;
	}
}
};