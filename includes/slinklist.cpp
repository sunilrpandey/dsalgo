#include <iostream>
#include "slinklist.h"
#define INVALID_ENTRY -1
using namespace std;

SNode* LySinglyLinklist::createNode(int val)
{
	return new SNode(val);
}

void LySinglyLinklist::push_back(int val)
{
	SNode * newNode = createNode(val);
	if (!head_) {
		head_ = newNode;
		return;
	}

	//Go to last node insert this node there
	SNode * itrNode = head_;
	while (itrNode->next) {
		itrNode = itrNode->next;
	}
	itrNode->next = newNode;
	return;
}
void LySinglyLinklist::push_front(int val)
{
	SNode * newNode = createNode(val);
	
	newNode->next = head_;
	head_ = newNode;
}
void LySinglyLinklist::insert(int pos, int val)
{
	if (pos == 0) {
		push_front(val);
		return;
	}
	int posIter = 0;
	SNode * node = head_;
	while (posIter < pos) {
		node = node->next;
	}
	SNode * tmpNode = node->next;
	node->next = createNode(val);
	node->next->next = tmpNode;

	return;
}
int LySinglyLinklist::front()
{
	if(head_)
		return head_->data;

	return INVALID_ENTRY;
}
int LySinglyLinklist::back()
{
	if (!head_)
		return INVALID_ENTRY;
	//Go to last node
	SNode * node = head_;
	while (node->next) {
		node = node->next;
	}
	return node->data;
}
int LySinglyLinklist::sizeRec(SNode * node)
{
	if (node == nullptr) {
		return 0;
	}
	return 1 + sizeRec(node->next);

}
void LySinglyLinklist::clearRec(SNode * node)
{
	if (node == nullptr) {
		return;
	}
	clearRec(node->next);
	delete node;
	node = nullptr;
}

int LySinglyLinklist::size(bool rec)
{
	if (rec) {
		return sizeRec(head_);
	}
	int sz = 0;
	SNode * node = head_;
	while (node) {
		node = node->next;
		sz++;
	}
	return sz;

}
void LySinglyLinklist::clear(bool rec)
{
	if (rec) {
		clearRec(head_);
		head_ = nullptr;
	}

	SNode * node = head_;
	SNode * temp;
	while (node) {
		temp = node;
		delete temp;
		node = node->next;
	}
	head_ = nullptr;
}
void LySinglyLinklist::show()
{
	cout << endl << "Displaying Nodes from the list" << endl;
	SNode * nd = head_;
	while (nd) {
		cout << nd->data << "    ";
		nd = nd->next;
	}
	cout << endl;
}
void LySinglyLinklist::reverse()
{
	SNode * cur = head_;
	if (!cur || !cur->next) {
		return;
	}

	SNode *prev = nullptr, *nxt = nullptr;
	while (cur) {
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}

	head_ = prev;

	return;
}