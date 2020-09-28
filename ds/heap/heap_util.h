#pragma once
#include <iostream>
#include <initializer_list>
#include <assert.h>
namespace ds 
{
    constexpr int HEAP_SIZE = 1024;

	int Left(int i) {
		return 2 * i + 1;
	}
	int Right(int i) {
		return 2 * i + 2;
	}
	int Parent(int i) {
		return (i - 1) / 2;
	}

	template<typename T>
	void MinHeapify(int i, T * arr, int size) {
		int min_index = i;
		if (Left(i) < size && arr[Left(i)] < arr[i]) {
			min_index = Left(i);
		}
		if (Right(i) < size && arr[Right(i)] < arr[min_index]) {
			min_index = Right(i);
		}
		if (i != min_index) {
			std::swap(arr[i], arr[min_index]);
			MinHeapify(min_index,arr,size);
		}
	}

	template<typename T>
	void MaxHeapify(int i, T * arr, int size) {
		int max_index = i;
		if (Left(i) < size && arr[Left(i)] > arr[i]) {
			max_index = Left(i);
		}
		if (Right(i) < size && arr[Right(i)] > arr[max_index]) {
			max_index = Right(i);
		}
		if (i != max_index) {
			std::swap(arr[i], arr[max_index]);
			MaxHeapify(max_index, arr, size);
		}
	}

	template<typename T>
	void Sort(T* arr, int sz) {

		//Prepare heap using MinHeapify
		for (int i = sz / 2; i >= 0; i--) {
			MaxHeapify(i,arr,sz);
		}
		
		//remove item one by one from heap and place it at the end to get it sorted
		int size = sz;
		while (size > 0) {
			size--;
			std::swap(arr[0], arr[size]);
			MaxHeapify(0, arr, size);
		}
	}

	
}