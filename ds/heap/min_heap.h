#pragma once
#include "heap_util.h"
namespace ds 
{
	template<typename T>
	class MinHeap
	{
	private:
		void BubbleUp(int i) {
			if (i == 0) {
				return;
			}
			if (arr[Parent(i)] > arr[i]) {
				std::swap(arr[Parent(i)], arr[i]);
				BubbleUp(Parent(i));
			}
		}

	public:
		MinHeap(std::initializer_list<T> list) {
			for (auto elem : list) {
				Insert(elem);
			}
		}
		void Insert(T item) {
			arr[size] = item;
			BubbleUp(size);
			size++;
		}

		T ExtractMin() {
			T min = arr[0];
			std::swap(arr[0], arr[size - 1]);
			size--;
			MinHeapify(0,arr,size);

			return min;
		}
		T GetMin() {
			return arr[0];
		}
		void DecreaseMin(int pos, T new_value) {
			arr[pos] = new_value;
			BubbleUp(pos);
		}

		void IncreaseMin(int pos, T new_value) {
			arr[pos] = new_value;
			MinHeapify (pos,arr,size);
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
