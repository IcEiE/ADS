#pragma once
class BinarySearchTree
{
public:
	void insert(int value);
	BinarySearchTree(int root);
	~BinarySearchTree();
private:
	struct node *root;
};

