#include <iostream>
#include <initializer_list>
#include <assert.h>

constexpr int STACK_SIZE = 1024;
#define INVALID_INT_VALUE -1

namespace ds
{
	enum TraversalType
	{
		TT_PRE_ORDER = 0,
		TT_IN_ORDER,
		TT_POST_ORDER,
	};
	template <typename T>
	class Tree
	{
	public:
		struct TNode
		{
			T data;
			TNode * left;
			TNode * right;

			TNode(int data = INVALID_INT_VALUE) : data(data), left(nullptr), right(nullptr) {}
		};
		
	public:
		Tree():root_(nullptr), size_(0) {}
		Tree(std::initializer_list<T> list);
        bool IsEmpty();
		
        void Traverse(TraversalType traversal_type);   
		void Insert(T data);
        TNode * Find(T item); 
        void DeleteNode(T key);

    private:
   		TNode * NewNode(T data);
        TNode * InsertUtil(TNode * node, T data);
		void TraversePreOrder(TNode * node);
		void TraverseInorder(TNode * node);
		void TraversePostOrder(TNode * node);		
        TNode * FindUtil(TNode * node, T item);
        TNode * DeleteNodeUtil(TNode * node, T key);
        auto InOrderSuccessor(TNode *node);

	private:
		TNode * root_;
		int size_;
	
	};	
}
#include "tree.inl"