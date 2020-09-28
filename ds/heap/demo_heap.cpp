#include "heap_util.h"
#include "max_heap.h"
#include "min_heap.h"

void DemoMaxHeap()
{
	ds::MaxHeap<int> mx_heap = { 9,5,1,3,18 };
	mx_heap.Show();

	std::cout << "Extract Max : " << mx_heap.ExtractMax() << std::endl;
	std::cout << "Now, Remaining heap : ";
	mx_heap.Show();

	return;
}

void DemoMinHeap()
{
	ds::MinHeap<int> min_heap = { 9,5,1,3,18 };
	min_heap.Show();

	std::cout << "Extract Min : " << min_heap.ExtractMin() << std::endl;
	std::cout << "Now, Remaining heap : ";
	min_heap.Show();

	std::cout << "Decrease 9 (at pos 1) to 2 .. ";
	min_heap.DecreaseMin(1, 2);
	min_heap.Show();

	std::cout << "Increase 2 to (at pos 1) 9 Again .. ";
	min_heap.IncreaseMin(1, 9);
	min_heap.Show();
	return;
}

void DemoHeapSort()
{
	std::cout << "Heap Sort Demo :" << std::endl;
	std::cout << "Given Array :  ";
	int arr[] = { 5, 12, 4, 2, 1, 8 };
	for (auto i : arr) {
		std::cout << i << "  ";
	}
	std::cout << std::endl;

	ds::Sort(arr, sizeof(arr) / sizeof(arr[0]));
	std::cout << "Sorted Array :  ";
	for (auto i : arr) {
		std::cout << i << "  ";
	}
	std::cout << std::endl;
	
	return;
}

int main()
{
	DemoMaxHeap();
	DemoMinHeap();
	
	DemoHeapSort();	
	std::cin.get();
	return 0;
}