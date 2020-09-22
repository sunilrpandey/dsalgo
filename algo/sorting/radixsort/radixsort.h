#pragma once
#include <iostream>
// Learning :
// Radix sort is extension of counint sort where you apply countin sort on each digit

namespace algos
{
	void Countingsort(int * arr, int sz, int place)
	{

		//digits would be from 0 to 9 hence range is 10
		int range = 10;
		int freq[10] = {0};
		
		for (int i = 0; i < sz; i++) {
			freq[(arr[i] / place) % 10]++;
		}

		#ifdef LOG_ENABLED
		std::cout << "\n Frequencies : " << std::endl;		
		for (int i = 0; i < range; i++) {
			std::cout << freq[i] << "  ";
		}
		#endif	

		//Calculate cumulative frequency which will give index of the number in final array
		for (int i = 1; i < range; i++) {
			freq[i] = freq[i] + freq[i - 1];
		}

		#ifdef LOG_ENABLED
		std::cout << "\n Cumulative Frequencies : " << std::endl;
		for (int i = 0; i < range; i++) {
			std::cout << freq[i] << "  ";
		}
		#endif

		int * outarray = new int[sz];
		for (int i = 0; i < sz; i++) {
			outarray[i] = 0;
		}

		// iterating from last to first is important as in second iteration we consider first as sorted
		// so last index should have last element from array.
		// in first iteration it wont matter
		for (int i = sz-1; i >= 0; i--) {
			//Get digit based on place value, place is 1,10,100 etc
			int index = (arr[i] / place) % 10;
			outarray[freq[index] - 1] = arr[i];
			freq[index]--;
		}
		for (int i = 0; i < sz; i++) {
			arr[i] = outarray[i];
		}

		#ifdef LOG_ENABLED
		std::cout << "\nArray after sorting at place : " << place << std::endl;
		for (int i = 0; i < sz; i++) {
			std::cout << arr[i] << "  ";
		}
		std::cout << std::endl;
		#endif

		delete[] outarray;

	}

	void Radixsort(int * arr, int sz)
	{
		//get max number to get max number of digit in given numbers
		int max = arr[0];

		for (int i = 1; i < sz; ++i) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		int num_digit = max / 10 + 1;
		int place_value = 1;
		for (int place_value = 1; max / place_value > 0; place_value *= 10) {
			algos::Countingsort(arr, sz, place_value);
		}

	}
};
