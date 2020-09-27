namespace ds {
	template <typename T> 
	typename Tree<T>::TNode * Tree<T>::NewNode(T data) {
			return new Tree<T>::TNode(data);
		}

	template <typename T> 
	Tree<T>::Tree(std::initializer_list<T> list) : root_(nullptr), size_(0) {
		for (auto elem : list) {
			root_ = InsertUtil(root_, elem);
		}

	}
	template<typename T>
	void Tree<T>::DeleteNode(T key) {
			std::cout << "Deleting " << key << "..." << std::endl;
			DeleteNodeUtil(root_, key);
			return;
	}

	template<typename T>
	typename Tree<T>::TNode * Tree<T>::DeleteNodeUtil(TNode * node, T key) {
		if (!node) {
			return node;
		}
		if (key < node->data) {
			node->left = DeleteNodeUtil(node->left, key);
		}
		else if (key > node->data) {
			node->right = DeleteNodeUtil(node->right, key);
		}
		else { // that means key == node->data

			TNode * cur_node = nullptr;
			if (nullptr == node->left) {
				cur_node = node->right;
				delete node;
				return cur_node;
			}
			else if (nullptr == node->right) {
				cur_node = node->left;
				delete node;
				return cur_node;
			} 

			// It means node has both left and right
			TNode * nextBigNode = InOrderSuccessor(node->right);
			node->data = nextBigNode->data;
			node->right = DeleteNodeUtil(node->right, nextBigNode->data);
		}
		return node;
	}
	template<typename T>
	auto Tree<T>::InOrderSuccessor(TNode *node) {
			TNode * cur = node;
			while (cur && cur->left) {
				cur = cur->left;
			}
			return cur;
		}
	template<typename T>
	typename Tree<T>::TNode* Tree<T>::FindUtil(TNode * node, T item) {

		if (node == nullptr) {
			return node;
		}
		if (node->data == item) {
			return node;
		}
		if (item < node->data) {
			return FindUtil(node->left, item);
		}
		else {
			return FindUtil(node->right, item);
		}
	}
	template<typename T>
	typename Tree<T>::TNode * Tree<T>::Find(T item) {
		return FindUtil(root_,item);
	}

	template <typename T> 
	void Tree<T>::Insert(T data) 
	{
		InsertUtil(root_, data);
		return;
	}
	template <typename T> // typename is needed as TNode is dependent on Tree'T
	typename Tree<T>::TNode * Tree<T>::InsertUtil(TNode * node, T data) {

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

	template<typename T>
	bool Tree<T>::IsEmpty() {
		return root_ == nullptr;
	}
	
	template<typename T>
	void Tree<T>::Traverse(TraversalType traversal_type) {

		if (IsEmpty()) {
			std::cout << "Tree is Empty, No element to Traverse!" << std::endl;
			return;
		}

		switch (traversal_type)
		{
		case TraversalType::TT_IN_ORDER:
			TraverseInorder(root_);
			break;
		case TraversalType::TT_PRE_ORDER:
			TraversePreOrder(root_);
			break;
		case TraversalType::TT_POST_ORDER:
			TraversePostOrder(root_);
			break;
		default:
			break;
		}
		std::cout << std::endl;
		return;
	}
	template<typename T>
	void Tree<T>::TraversePreOrder(TNode * node) {
		if (node == nullptr) {
			return;
		}
		std::cout << node->data << "  ";
		TraversePreOrder(node->left);
		TraversePreOrder(node->right);
	}
	template<typename T>
	void Tree<T>::TraverseInorder(TNode * node) {
		if (node == nullptr) {
			return;
		}
		TraverseInorder(node->left);
		std::cout << node->data << "  ";
		TraverseInorder(node->right);
	}
	template<typename T>
	void Tree<T>::TraversePostOrder(TNode * node) {
		if (node == nullptr) {
			return;
		}
		TraversePostOrder(node->left);
		TraversePostOrder(node->right);
		std::cout << node->data << "  ";
	}

		
}
