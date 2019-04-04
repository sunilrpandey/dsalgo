#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node * prev;
	Node * next;

	Node(T value) {
		data = value, prev = nullptr, next = nullptr;
	}
};

template<typename T>
struct LyTree
{
	
	Node<T> * root_;
	Node<T> * head_;
	Node<T> * tail_;
	LyTree(T * arr, int sz) {
		root_ = nullptr;
		head_ = nullptr;
		tail_ = nullptr;
		for (int i = 0; i < sz; i++)
			insert(root_, arr[i]);
	}
	Node<T> * createNode(T value) {
		return new Node<T>(value);
	}

	void TraverseInorderUtil(Node<T> * node) {
		if (node == nullptr) {
			return;
		}
		TraverseInorderUtil(node->prev);
		cout << node->data << "\t";
		TraverseInorderUtil(node->next);

		return;
	}

	void traverseInOrder() {
		
		cout << endl << "Traversing tree inorder :";
		TraverseInorderUtil(root_);

		return;

	}
	Node<T> * insert(Node<T> * par, T value) {
		Node<T> * newNode = createNode(value);
		if (!root_) {
			root_ = newNode; 
			return root_;
		}
		
		if (!par) {
			par = newNode;
			return par;
		}
		if (value < par->data)
			par->prev = insert(par->prev, value);
		else
			par->next = insert(par->next, value);

		return par;
	}
	   
	Node<T> * getDoublyLinklist();
	Node<T> * getDoublyLinklistUtil(Node<T> * node, Node<T> *& lastNode); // lastNode should persist across recursive call
	std::pair<Node<T> *, Node<T> *> getDoublyCircularLinklist();
	Node<T> * getDoublyCircularLinklistUtil(Node<T> * node); // lastNode should persist across recursive call
};

template<typename T>
Node<T> * LyTree<T>:: getDoublyLinklistUtil(Node<T> * node, Node<T> *& lastNode)
{
	if (node == nullptr) {
		return node;
	}
	getDoublyLinklistUtil(node->prev, lastNode);
	if (lastNode == nullptr)
		head_ = node;
	else {
		node->prev = lastNode;
		lastNode->next = node;
	}
	lastNode = node;

	getDoublyLinklistUtil(node->next, lastNode);
	
	return node;
}
template<typename T>
std::pair<Node<T> *, Node<T> *> LyTree<T>::getDoublyCircularLinklist()
{
	getDoublyCircularLinklistUtil(root_);
	head_ = root_;
	while (head_->prev)
		head_ = head_->prev;
	tail_ = root_;
	while (tail_->next)
		tail_ = tail_->next;

	tail_->next = head_;
	head_->prev = tail_;
	return make_pair/*<Node<T> *, Node<T> *>*/(head_, tail_);
}

template<typename T>
Node<T> * LyTree<T>::getDoublyCircularLinklistUtil(Node<T> * node)
{
	if (node == nullptr)
		return node;

	if (node->prev) {
		Node<T> * left = getDoublyCircularLinklistUtil(node->prev);
		while (left->next)
			left = left->next;
		left->next = node;
		node->prev = left;
	}
	if (node->next) {
		Node<T> * right = getDoublyCircularLinklistUtil(node->next);
		while (right->prev)
			right = right->prev;
		node->next = right;
		right->prev = node;
	}
	return node;
}

template<typename T>
Node<T> * LyTree<T>::getDoublyLinklist()
{
	Node<T> * lastUpdatedNode = nullptr;
	getDoublyLinklistUtil(root_, lastUpdatedNode);
	Node<T> * tail_ = prevNode;
	assert(head_);

	return head_;
}


int main()
{
	int arr[] = { 12, 7, 3, 9, 18, 16 };
	cout << sizeof arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	LyTree<int> lyTree(arr, sz);
#if 1 // BST->doubly linklist
	lyTree.traverseInOrder();
	Node<int> * dll = lyTree.getDoublyLinklist();
	cout << "\nprinting doubly link list of bst above : ";
	while (dll) {
		cout << dll->data << "\t";
		dll = dll->next;
	}
#endif
#if 0 // BST to circular doubly link list
	std::pair<Node<int>*, Node<int>*> headtailPair	= lyTree.getDoublyCircularLinklist();
		
	//Displaying circular doubly linklist
	Node<int>* head = headtailPair.first;
	Node<int> * cdll = head;
	do {
		cout << cdll->data << "\t";

		cdll = cdll->next;
	} while (cdll != head);
#endif
	return 0;
}




