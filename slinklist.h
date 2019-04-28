#pragma once
struct SNode
{
	int data;
	int notneeded;
	Node * next;
	SNode(int val) {
		data = val;
		next = nullptr;
	}
};
class LySinglyLinklist
{
	SNode * head_;
public:
	LySinglyLinklist() :head_(nullptr)
	{
	}
	void createNode(int val);
	void push_back(int val);
	void push_front(int val);
	void insert(int pos, int val);
	int front();
	int back();
	int size(bool rec = true);
	void clear(bool rec = true);
	int sizeRec();
	void clearRec();
	//added this comment
};
