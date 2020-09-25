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
		TNode * NewNode(T data) {
			return new TNode(data);
		}
		Tree() :root_(nullptr), size_(0) {}

		void ShowPreOrder(TNode * node) {
			if (node == nullptr) {
				return;
			}
			std::cout << node->data << "  ";
			ShowPreOrder(node->left);
			ShowPreOrder(node->right);
		}
		void ShowInorder(TNode * node) {
			if (node == nullptr) {
				return;
			}
			ShowInorder(node->left);
			std::cout << node->data << "  ";
			ShowInorder(node->right);
		}

		void ShowPostOrder(TNode * node) {
			if (node == nullptr) {
				return;
			}
			ShowPostOrder(node->left);
			ShowPostOrder(node->right);
			std::cout << node->data << "  ";
		}

		
		void Show(TraversalType traversal_type) {

			if (IsEmpty()) {
				std::cout << "Tree is Empty, No element to show!" << std::endl;
				return;
			}

			switch (traversal_type)
			{
			case TraversalType::TT_IN_ORDER:
				ShowInorder(root_);
				break;
			case TraversalType::TT_PRE_ORDER:
				ShowPreOrder(root_);
				break;
			case TraversalType::TT_POST_ORDER:
				ShowPostOrder(root_);
				break;
			default:
				break;
			}
			std::cout << std::endl;
			return;
		}
		bool IsEmpty() {
			return root_ == nullptr;
		}
		TNode * InsertUtil(TNode * node, T data) {

			if (node == nullptr) {
				node = NewNode(data);
				if (root_ == nullptr) {
					root_ = node;
				}
				return node;
			}

			if (data < node->data) {
				node->left = InsertUtil(node->left, data);
			}
			else {
				node->right = InsertUtil(node->right, data);
			}

			return node;
		}
		void Insert(T data) 
		{
			InsertUtil(root_, data);
			return;
		}
		Tree(std::initializer_list<T> list) : root_(nullptr), size_(0) {
			for (auto elem : list) {
				root_ = InsertUtil(root_, elem);
			}

		}
	private:
		TNode * root_;
		int size_;
	
	};
}

void DemoTraversal(ds::Tree<int>& tree)
{
	std::cout << "Demo : Pre Order Traversal" << std::endl;
	ds::TraversalType trv_type = ds::TraversalType::TT_PRE_ORDER;
	tree.Show(trv_type);

	std::cout << "\nDemo : In Order Traversal" << std::endl;
	trv_type = ds::TraversalType::TT_IN_ORDER;
	tree.Show(trv_type);


	std::cout << "\nDemo : Post Order Traversal" << std::endl;
	trv_type = ds::TraversalType::TT_POST_ORDER;
	tree.Show(trv_type);

	return;
}

int main() 
{
	std::cout << "Tree Demo" << std::endl;
	using Tree = ds::Tree<int>;
	Tree tree = {50,30,20,40,70,60,80};
	tree.Insert(100);
	
	DemoTraversal(tree);

	
	std::cin.get();
}
