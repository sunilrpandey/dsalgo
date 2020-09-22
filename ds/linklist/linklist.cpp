#include "linklist.h"
namespace ds
{
    LinkList::LinkList() :head_(nullptr),size_(0) {
        
    }
    LinkList::LinkList(std::initializer_list<int> list):head_(nullptr),size_(0){
        for (auto data : list) {
            Pushback(data);
        }
    }
    bool LinkList::IsEmpty() {
        return head_ == nullptr;
    }
    void LinkList::reset(){
        Node * node = head_;
        while(node){
            Node * temp = node;
            node = node->next;
            delete temp;
        }
        head_ = nullptr;
        size_ = 0;
        
    }

    Node * LinkList::CreateNode(int data) {
        return new Node(data);
    }
    Node * LinkList::LastNode() { //will be called only if list is not empty
        Node * node = head_;
        while (node->next) {
            node = node->next;
        }
        return node;			
    }
    void LinkList::Pushback(int data) {
        Node * node = CreateNode(data);
        if (IsEmpty()) {
            head_ = node;
            size_++;
            return;
        }
        LastNode()->next = node;
        size_++;
    }
    void LinkList::Pushfront(int data) {
        Node * node = CreateNode(data);
        node->next = head_;
        head_ = node;
        size_++;
    }
    void LinkList::RemoveNode(int pos) { // 0 based indexing
        if (pos == 0) {
            Node * node = head_;
            head_ = head_->next;
            delete node;
            size_--;
            return;
        }

        Node * prev = nullptr;
        Node * cur = head_;
        int pos_cntr = 0;
        while (pos_cntr != pos && cur != nullptr) {
            prev = cur;
            cur = cur->next;
            pos_cntr++;
        }
        assert(cur != nullptr);

        Node * node_to_delete = cur;
        prev->next = cur->next;

        delete node_to_delete;
        size_--;
    }
    void LinkList::Show() {
        std::cout << "List : ";
        Node * node = head_;
        while (node) {
            std::cout << node->data << "  ";
            node = node->next;
        }
        std::cout << std::endl;
    }
    int LinkList::Size() {
        return size_;
    }




















} // ds namespace