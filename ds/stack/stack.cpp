#include "stack.h"
namespace ds{
    Stack::Stack(std::initializer_list<int> list) {
        for (auto elem : list) {
            Push(elem);
        }
    }
    int Stack::Size() {
        return top_index_ + 1;

    }
    void Stack::Show() {
        int i = 0;
        std::cout << "Stack : ";
        while (i <= top_index_) {
            std::cout << arr_[i] << "  ";
            i++;
        }
        std::cout << std::endl;
    }
    bool Stack::IsEmpty() {
        return top_index_ == -1;
    }
    bool Stack::IsFull() {
        return top_index_ == 1024;
    }
    int Stack::Top() {
        if (IsEmpty()) {
            return INVALID_INT_VALUE;
        }
        return arr_[top_index_];
    }
    int Stack::Pop() {
        if (IsEmpty()) {
            return INVALID_INT_VALUE;
        }
            int res = arr_[top_index_];
            top_index_--;
            return res;
    }
    void Stack::Push(int data) {
        top_index_++;
        assert(!IsFull());
        
        arr_[top_index_] = data;
	}
}