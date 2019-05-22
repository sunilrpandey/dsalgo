#pragma once
struct SNode
{
	public:
	int data;

	SNode * next;
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
	void push_back(int val);
	void push_front(int val);
	void insert(int pos, int val);
	int front();
	int back();
	
	int size(bool rec = true);
	void clear(bool rec = true);

	void show();
	void reverse();

private:
	SNode* createNode(int val);
	int sizeRec(SNode * node);
	void clearRec(SNode * node);

};
