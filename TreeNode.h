#ifndef TREENODE_H
#define TREENODE_H


class TreeNode {
public:
	TreeNode() : leftChild(nullptr), rightChild(nullptr), data(0) {};
	TreeNode(int data) : leftChild(nullptr), rightChild(nullptr), data(data) {};
	friend class Tree;

private:
	TreeNode* leftChild;
	TreeNode* rightChild;
	int data;
};


#endif