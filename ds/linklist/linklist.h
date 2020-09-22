#pragma once 
#include <iostream>
#include <assert.h>
#include <initializer_list>

#define INVALID_DATA_VALUE -1

namespace ds
{
	struct Node
	{
		int data;
		Node * next;
		explicit Node(int data = INVALID_DATA_VALUE) : data(data), next(nullptr) {}
	};
	class LinkList
	{
	public:
		explicit LinkList();
		LinkList(std::initializer_list<int> list);
		bool IsEmpty();
        void reset();

	private:
		Node * CreateNode(int data);
		Node * LastNode(); //will be called only if list is not empty
	public:
		void Pushback(int data);
		void Pushfront(int data);
		void RemoveNode(int pos);
		void Show();
		int Size();
	private:
		Node * head_;
		int size_;
	};

}