#include <iostream>
#include <initializer_list>
#include <assert.h>
constexpr int STACK_SIZE = 1024;
#define INVALID_INT_VALUE -1

namespace ds
{
	class Queue
	{
	public:
		static constexpr int CAPACITY = 1024;
		Queue() = default;
		Queue(std::initializer_list<int> list);
		void Enqueue(int data);
		int Dequeue();
		bool IsEmpty();
		bool IsFull();
		int Size();
		int Front();
		int Rear();
		void Show();
	//private:
		int rear_ = 0;
		int front_ = 0;
		int size_ = 0;
		int arr_[CAPACITY] = {0};
	};
}
