#include "Tree.h"
#include <iostream>

using namespace std;

TreeNode* Tree::search(int key) {
	TreeNode* current = root;

	if (!root){
		cout << "The tree is empty.\n";
		return nullptr;
	}
	else {
		while (true) {
			if (!current) {
				cout << "The key " << key << " isn't in the tree.\n";
				return nullptr;
			}
			else if (key < current->data) {
				current = current->leftChild;
			}
			else if (key > current->data) {
				current = current->rightChild;
			}
			else if (key == current->data) {
				return current;
			}
		}
	}
}

TreeNode* Tree::ancestor(int key, TreeNode** parent) {
	TreeNode* current = root;

	if (!root) {
		cout << "The tree is empty.\n";
		return nullptr;
	}
	else {
		while (true) {
			if (!current) {
				cout << "The key " << key << " isn't in the tree.\n";
				return nullptr;
			}
			else if (key < current->data) {
				*parent = current;
				current = current->leftChild;
			}
			else if (key > current->data) {
				*parent = current;
				current = current->rightChild;
			}
			else if (key == current->data) {
				return current;
			}
		}
	}
}

int Tree::Find(int key) {
	TreeNode* exist = search(key);
	if (exist == nullptr) {
		return -1;
	}
	TreeNode* current = root;
	int rank;
	bool right = false;
	if (key < current->data) {
		do {
			current = current->leftChild;
		} while (key < current->data);
		rank = leftsize(current);
		while (key != current->data) {
			if (key > current->data) {
				do {
					current = current->rightChild;
					rank += leftsize(current);
					right = true;
				} while (key > current->data);
			}
			if (key < current->data) {
				if (right) {
					rank -= leftsize(current);
					do {
						current = current->leftChild;
					} while (key < current->data);
					rank += leftsize(current);
					right = false;
				}
				else {
					do {
						current = current->leftChild;
					} while (key < current->data);
					rank -= leftsize(current);
				}
			}
		}
	}
	else {
		rank = leftsize(root);
		while (key != current->data) {
			if (key > current->data) {
				do {
					current = current->rightChild;
					rank += leftsize(current);
				} while (key > current->data);
			}
			if (key < current->data) {
				if (right) {
					rank -= leftsize(current);
					do {
						current = current->leftChild;
					} while (key < current->data);
					rank += leftsize(current);
					right = false;
				}
				do {
					current = current->leftChild;
				} while (key < current->data);
				rank -= leftsize(current);
				right = 0;
			}
		}
	}

	return rank;

}

void Tree::Insert(int key) {
	TreeNode* current = root;
	TreeNode* NewNode = new TreeNode(key);

	if (!root){
		root = NewNode;
	}
	else {
		while (true) {
			if (key < current->data) {
				if (current->leftChild) {
					current = current->leftChild;
					continue;
				}
				else {
					current->leftChild = NewNode;
					break;
				}
			}
			else if (key > current->data) {
				if (current->rightChild) {
					current = current->rightChild;
					continue;
				}
				else {
					current->rightChild = NewNode;
					break;
				}
			}
			else if (key == current->data) {
				cout << "The key " << key << " is already in the tree.\n";
				break;
			}
		}
	}
}

void Tree::Delete(int key) {
	if (!root) {
		cout << "The tree is empty.\n";
	}

	TreeNode* parent = nullptr;
	TreeNode* current = ancestor(key, &parent);
	if (current->leftChild && current->rightChild) {
		current->data = Successor(current)->data;
		delete Successor(current);
	}
	else if (!current->leftChild && !current->rightChild){
		delete current;
	}
	else if (current->leftChild || current->rightChild) {
		if (current == parent->leftChild) {
			if (current->leftChild) {
				parent->leftChild = current->leftChild;
			}
			else {
				parent->leftChild = current->rightChild;
			}
		}
		else {
			if (current == parent->rightChild) {
				if (current->leftChild) {
					parent->rightChild = current->leftChild;
				}
				else {
					parent->rightChild = current->rightChild;
				}

			}
		}
	}
}

void Tree::Show() {
	cout << "Inorder: ";
	inorderTraversal(root);
	cout << "\n";
	cout << "Preorder: ";
	preorderTraversal(root);
	cout << "\n";
}

TreeNode* Tree::Successor(TreeNode* current) {
	if (!current->rightChild) {
		current = current->rightChild;
		while (!current->leftChild) {
			current = current->leftChild;
		}
	}

	return current;
}

TreeNode* Tree::Predecessor(TreeNode* current) {
	if (!current->leftChild) {
		while (current->rightChild) {
			current = current->rightChild;
		}
	}

	return current;
}

int Tree::total_node(TreeNode* current) {
	int size = 0;

	if (current) {
		size++;
		if (!current->leftChild && !current->rightChild) {
			return size;
		}
		if (current->leftChild) {
			size += total_node(current->leftChild);
		}
		if (current->rightChild) {
			size += total_node(current->rightChild);
		}
	}

	return size;
}

int Tree::leftsize(TreeNode* current) {
	current = current->leftChild;

	if (!current) {
		return 1;
	}

	return total_node(current) + 1;
}

void Tree::inorderTraversal(TreeNode* current) {
	if (current->leftChild) {
		inorderTraversal(current->leftChild);
	}

	cout << current->data << " ";
	
	if (current->rightChild) {
		inorderTraversal(current->rightChild);
	}
}

void Tree::preorderTraversal(TreeNode* current) {
	cout << current->data << " ";

	if (current->leftChild) {
		preorderTraversal(current->leftChild);
	}

	if (current->rightChild) {
		preorderTraversal(current->rightChild);
	}
}