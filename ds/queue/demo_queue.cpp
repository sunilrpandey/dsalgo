#include "queue.h"
int main() 
{
	// Init q with initializer_list
    std::cout << "Init queue with integers 3 - 7" << std::endl;
	ds::Queue q = { 3,4,5,6,7 };
	q.Show();
	std::cout << "Queue Size : " << q.Size() << std::endl;
    
    std::cout << "Dequeuing all items.. " << std::endl;
    while (q.Size()) {
		std::cout << "Dequeuing " << q.Dequeue() << " ...\n ";
	}
	std::cout << std::endl << "Now, Size (should be zero :-)) : " << q.Size() << std::endl;
    
    //No need to expose this
    std::cout << " Front Index: " << q.front_ << "  Rear  Index: " << q.rear_ << std::endl;
	
    std::cout << "Adding new items from 1-5" << std::endl;
    int i = 0;
	while (i < 5) {
		q.Enqueue(i+1);
		i++;
	}
	q.Show();
    std::cout << "Now Front Index: " << q.front_ << "  Rear  Index: " << q.rear_ << std::endl;

	std::cin.get();
}
