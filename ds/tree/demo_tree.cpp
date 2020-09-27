#include "tree.h"

void DemoTraversal(ds::Tree<int>& tree)
{
	std::cout << "Demo : Pre Order Traversal" << std::endl;
	ds::TraversalType trv_type = ds::TraversalType::TT_PRE_ORDER;
	tree.Traverse(trv_type);

	std::cout << "\nDemo : In Order Traversal" << std::endl;
	trv_type = ds::TraversalType::TT_IN_ORDER;
	tree.Traverse(trv_type);


	std::cout << "\nDemo : Post Order Traversal" << std::endl;
	trv_type = ds::TraversalType::TT_POST_ORDER;
	tree.Traverse(trv_type);

	return;
}

void DemoFindItem(ds::Tree<int>& tree) {
	using Tree = ds::Tree<int>;

	Tree::TNode * node = tree.Find(20);
	if (node) {
		std::cout << "Found : " << node->data << std::endl;
	}
	else {
		std::cout << "Search Item not Found!!" << std::endl;
	}

	node = tree.Find(210);
	if (node) {
		std::cout << "Found : " << node->data << std::endl;
	}
	else {
		std::cout << "Search Item not Found!!" << std::endl;
	}
}

void DemoDeleteItem(ds::Tree<int>& tree) {

	tree.Traverse(ds::TraversalType::TT_IN_ORDER);

	tree.DeleteNode(80);
	tree.Traverse(ds::TraversalType::TT_IN_ORDER);

	tree.DeleteNode(60);
	tree.Traverse(ds::TraversalType::TT_IN_ORDER);

	tree.DeleteNode(30);
	tree.Traverse(ds::TraversalType::TT_IN_ORDER);

	return;
}



int main() 
{
	std::cout << "Tree Demo" << std::endl;
	using Tree = ds::Tree<int>;
	Tree tree = {50,30,20,40,70,60,80};
	tree.Insert(100);
	
	DemoTraversal(tree);
	DemoFindItem(tree);
	DemoDeleteItem(tree);
	
	std::cin.get();
}
