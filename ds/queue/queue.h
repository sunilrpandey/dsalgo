#pragma once

#include <iostream>
#include <initializer_list>
#include <assert.h>
constexpr int STACK_SIZE = 1024;
#define INVALID_INT_VALUE -1

namespace ds
{
	template<typename T>
	class Queue
	{
	public:
		static constexpr int CAPACITY = 1024;
		Queue() = default;
		Queue(std::initializer_list<T> list);
		void Enqueue(T data);
		T Dequeue();
		bool IsEmpty();
		bool IsFull();
		int Size();
		T Front();
		T Rear();
		void Show();
	//private:
		int rear_ = 0;
		int front_ = 0;
		int size_ = 0;
		T arr_[CAPACITY] = {0};
	};
}
#include "queue.inl"