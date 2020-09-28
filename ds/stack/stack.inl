namespace ds{
    template <typename T> 
	Stack<T>::Stack(std::initializer_list<T> list) {
        for (auto elem : list) {
            Push(elem);
        }
    }
    template <typename T> 
	int Stack<T>::Size() {
        return top_index_ + 1;

    }
    template <typename T> 
	void Stack<T>::Show() {
        int i = 0;
        std::cout << "Stack : ";
        while (i <= top_index_) {
            std::cout << arr_[i] << "  ";
            i++;
        }
        std::cout << std::endl;
    }
    template <typename T> 
	bool Stack<T>::IsEmpty() {
        return top_index_ == -1;
    }
    template <typename T> 
	bool Stack<T>::IsFull() {
        return top_index_ == STACK_SIZE-1;
    }
    template <typename T> 
	T Stack<T>::Top() {
        if (IsEmpty()) {
            return INVALID_INT_VALUE;
        }
        return arr_[top_index_];
    }
    template <typename T> 
	void Stack<T>::Pop() {
        if (IsEmpty()) {
            return;
        }
        int res = arr_[top_index_];
        top_index_--;
        return res;
    }
    template <typename T> 
	void Stack<T>::Push(T data) {
        top_index_++;
        assert(!IsFull());
        
        arr_[top_index_] = data;
	}
}