#pragma once
#include "heap_util.h"
namespace ds 
{
	template <typename T>
	class MaxHeap
	{
	private:
		void BubbleUp(int i) {
			if (i == 0) {
				return;
			 }
			if (arr[Parent(i)] < arr[i]) {
				std::swap(arr[Parent(i)], arr[i]);
				BubbleUp(Parent(i));
			}
		}
	public:
		MaxHeap(std::initializer_list<T> list) {
			for (auto elem : list) {
				Insert(elem);
			}
		}
		void Insert(T item) {
			arr[size] = item;
			BubbleUp(size);
			size++;
		}
		T ExtractMax() {
			T mx = arr[0];
			std::swap(arr[0], arr[size - 1]);
			size--;
			MaxHeapify(0,arr,size);
			
			return mx;
		}
		T GetMax() {
			return arr[0];
		}
		//Basically to be used to increase priority of element at given position
		// for max heap
		void IncreaseMax(int pos, T new_value) {
			arr[pos] = new_value;
			BubbleUp(pos);
		}
		void DecreaseMax(int pos, T new_value) {
			arr[pos] = new_value;
			MaxHeapify(pos,arr,size);
		}


		void Show() {
			std::cout << "Heap Elements : ";
			for (int i = 0; i < size; i++) {
				std::cout << arr[i] << "  ";
			}
			std::cout << std::endl;
		}
	private:
		T arr[HEAP_SIZE];
		int size = 0;
	};
}
