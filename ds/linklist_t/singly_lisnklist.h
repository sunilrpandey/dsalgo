#include <iostream>

template<typename T>
class SingleLinkLIst
{
    public:
    
    struct SLLNode
    {
        T data;
        SLLNode * next = nullptr; 
    };

    class Iterator
    {
        public:
        Iterator() noexcept: list_(nullptr) {}
        Iterator(SLLNode * node) noexcept : list_(node){}

        Iterator& operator = (const Iterator& rhs) {
            list_ = rhs.list_;
        }

        Iterator& operator ++ () {
            if(list_) {
                list_ = list_->next;
            }
            return *this;
        }  
        Iterator& operator ++ (int) {
            Iterator iter = *this;
            this->list_ = this->list_->next;
            return iter;
        }
        T operator * () 
        {
            return list_->data;
        }
        
        private: 
            SLLNode * list_;
    };
    
    SingleLinkLIst() : head_(nullptr){}
    ~SingleLinkLIst(){}
    
    SingleLinkLIst(const SingleLinkLIst& rhs);
    SingleLinkLIst(SingleLinkLIst&& rhs);
    
    SingleLinkLIst& operator = (const SingleLinkLIst& rhs);
    SingleLinkLIst& operator = (std::initializer_list<T> rhs);

    
    T front();
    T back();
    void push_back(const T& value);
    T pop_back();
    void push_front(const T& value);
    T pop_front();
    
    void insert(int pos, int value);
    void erase(int pos);

    bool empty();
    int size();
    SLLNode * head() {return head_;}

    void assign( int count, const T& value );
    template< class InputIt >
    void assign( InputIt first, InputIt last );
    void assign( std::initializer_list<T> in_list);

    //iter functions
    Iterator begin() { return Iterator(head_);}
    
    
    private:
    T * create_node();
    
    private:
    
    int size_ = 0;
    SLLNode * head_;
    friend class Iterator;
};