#include <iostream>
#include <initializer_list>
#include <assert.h>
constexpr int STACK_SIZE = 1024;
#define INVALID_INT_VALUE -1

namespace ds
{
	template <typename T>
	class Stack
	{
	public:
		Stack() = default;
		Stack(std::initializer_list<T> list);
		
        bool IsEmpty();
		bool IsFull();
        int Size();

		T Top();
		void Pop();
		void Push(T data);

        void Show();
    private:
		int top_index_ = -1;
		T arr_[STACK_SIZE];

	};
}

#include "stack.inl"