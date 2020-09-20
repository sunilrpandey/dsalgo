#pragma once
#include <iostream>

namespace algos
{
void Selectionsort (int * arr, int sz)
{
	for(int i = 0; i < sz-1; i++) {
		int min_index = i;	
		for(int j = i + 1; j < sz; j++) {
			if(arr[j] < arr[min_index]) {				
				min_index = j;
			}			
		}
		if(min_index != i)
			std::swap(arr[i],arr[min_index]);		
	}
}
};