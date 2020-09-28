namespace ds{
    template<typename T>
    Queue<T>::Queue(std::initializer_list<T> list) :rear_(CAPACITY-1), front_(0),size_(0)
        {
            for (auto elem : list) {
                Enqueue(elem);
            }
        }
    template<typename T>
    void Queue<T>::Enqueue(T data) {
        if (IsFull()) {
            std::cout << "Stack Overflow !!" << std::endl;
            return;
        }

			rear_ = (rear_ + 1) % CAPACITY;
			arr_[rear_] = data;
			size_++;

			return;
		}
	
    template<typename T>
    T Queue<T>::Dequeue() {
        if (IsEmpty()) {
            std::cout << "Queue Underflow !!" << std::endl;
            return INVALID_INT_VALUE;
        }
        T ret_value = arr_[front_];
        front_ = (front_ + 1) % CAPACITY;
        size_--;

        return ret_value;
    }
    
    template<typename T>
    bool Queue<T>::IsEmpty() {
        return size_ == 0;
    }
    
    template<typename T>
    bool Queue<T>::IsFull() {
        return size_ == CAPACITY;
    }
    
    template<typename T>
    int Queue<T>::Size() {
        return size_;
    }
    
    template<typename T>
    T Queue<T>::Front() {
        return arr_[front_];
    }
    
    template<typename T>
    T Queue<T>::Rear() {
        return arr_[rear_];
    }

    template<typename T>
    void Queue<T>::Show() {
        std::cout << "Queue : ";
        for (int i = 0; i < size_; i++) {
            std::cout << arr_[front_ + i] << "  ";
        }
        std::cout << std::endl;

        return;
    }
}