#pragma once
#include <iostream>

namespace algos
{
void Bubblesort (int * arr, int sz)
{
	for(int i = 0; i < sz-1; i++) {
		bool swapped = false;	
		for(int j = 0; j < sz - i- 1; j++) {
			if(arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
				swapped = true;
			}			
		}
		// if swap did not happedn it means array is already sorted.
		if(!swapped) { 
				return;
			}
	}
}
};