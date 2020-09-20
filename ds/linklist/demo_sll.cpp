#include <iostream>
#include "singly_lisnklist.h"


//if you are not recevingi it in constexpr function, it will work as normal function
// but if you are receiving it in constexpr, it will throw error 
constexpr int sq_func(const int n) {
    return n * n;
}

int main()
{
    int i = 4;
    
    //will always work if we pass 4 or i
    n1 = sq_func(i);

    //will not work as it will force func to evaluate at compile time only
    //constexpr int n1 = sq_func(i);
    std::cout << "const expr value : " << n1 << std::endl;
    //will work as n is not expected to be received at compile time
    //int n = sq_func(i);
    SingleLinkLIst<int> list;
    SingleLinkLIst<int>::SLLNode node;
    node.data = 4;
    node.next = nullptr;

    std::cout << std::boolalpha <<  (list.head() == nullptr);
    return 0;
}