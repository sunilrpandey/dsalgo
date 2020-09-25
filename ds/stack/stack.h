#include <iostream>
#include <initializer_list>
#include <assert.h>
constexpr int STACK_SIZE = 1024;
#define INVALID_INT_VALUE -1

namespace ds
{
	class Stack
	{
	public:
		Stack() = default;
		Stack(std::initializer_list<int> list);
		
        bool IsEmpty();
		bool IsFull();
        int Size();

		int Top();
		int Pop();
		void Push(int data);

        void Show();
    private:
		int top_index_ = -1;
		int arr_[STACK_SIZE];

	};
}

