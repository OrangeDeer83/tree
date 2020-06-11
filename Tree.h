#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include <iostream>

class Tree {
public:
	Tree() : root(nullptr) {};
	int Find(int key);
	void Insert(int key);
	void Delete(int key);
	void Show();
	TreeNode* Successor(TreeNode* current);
	TreeNode* Predecessor(TreeNode* current);

private:
	TreeNode* root;
	TreeNode* search(int key);
	TreeNode* ancestor(int key, TreeNode** parent);
	int total_node(TreeNode* current);
	int leftsize(TreeNode* current);
	void inorderTraversal(TreeNode* current);
	void preorderTraversal(TreeNode* current);
};



#endif
