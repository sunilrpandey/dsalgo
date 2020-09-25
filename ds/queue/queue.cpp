#include "queue.h"
namespace ds{
    Queue::Queue(std::initializer_list<int> list) :rear_(CAPACITY-1), front_(0),size_(0)
        {
            for (auto elem : list) {
                Enqueue(elem);
            }
        }
    void Queue::Enqueue(int data) {
        if (IsFull()) {
            std::cout << "Stack Overflow !!" << std::endl;
            return;
        }

			rear_ = (rear_ + 1) % CAPACITY;
			arr_[rear_] = data;
			size_++;

			return;
		}
	int Queue::Dequeue() {
        if (IsEmpty()) {
            std::cout << "Queue Underflow !!" << std::endl;
            return INVALID_INT_VALUE;
        }

			
        int ret_value = arr_[front_];
        front_ = (front_ + 1) % CAPACITY;
        size_--;
        
        return ret_value;
    }
    bool Queue::IsEmpty() {
        return size_ == 0;
    }
    bool Queue::IsFull() {
        return size_ == CAPACITY;
    }
    int Queue::Size() {
        return size_;
    }
    int Queue::Front() {
        return arr_[front_];
    }
    int Queue::Rear() {
        return arr_[rear_];
    }

    void Queue::Show() {
        std::cout << "Queue : ";
        for (int i = 0; i < size_; i++) {
            std::cout << arr_[front_ + i] << "  ";
        }
        std::cout << std::endl;

        return;
    }
}