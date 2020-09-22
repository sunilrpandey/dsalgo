#pragma once
#include <iostream>
// Learning :
// Counting sort is used when we numbers from a given range and also there may be multiple 
// duplicates as well
namespace algos
{
void Countingsort (int * arr, int sz)
{
	int max = arr[0];
	int min = arr[0];

	for(int i  = 1; i < sz; ++i){
		 if(arr[i] > max) {
			 max =  arr[i];
		 }
		 if(arr[i] < min) {
			 min = arr[i];
		 }
	}

	std::cout << "min : " << min << "   max : " << max << std::endl;

	int range = max - min + 1;
	int * freq  = new int[range];
	for(int i = 0; i < range; i++) {
		freq[i] = 0;
	}

	std::cout << "\n Frequencies : " << std::endl;
	for(int i = 0; i < sz; i++){
		freq[arr[i] - min]++;
	}

	for(int i = 0; i < range; i++) {
		std::cout << freq[i] << "  ";
	}

	for(int i = 1; i < sz; i++){
		freq[i] = freq[i] + freq[i-1];		
	}

	std::cout << "\n Cumulative Frequencies : " << std::endl;
	for(int i = 0; i < range; i++) {
		std::cout << freq[i] << "  ";
	}

	int * outarray = new int[sz];
	for(int i = 0; i < sz; i++){
		outarray[i] = 0;
	}

	for(int i = 0; i < sz; i++){
		outarray[freq[arr[i] - min] - 1] = arr[i];
		freq[arr[i]-min]--;
	}
	for(int i = 0; i < sz; i++){
		arr[i] = outarray[i];
	}
	std::cout << std::endl;
		
	delete[]  freq;
	delete[] outarray;
}
};