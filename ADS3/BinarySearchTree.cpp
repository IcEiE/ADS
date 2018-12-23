#include "pch.h"
#include "BinarySearchTree.h"

struct node {
	int data;
	node *left;
	node *right;
	node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

BinarySearchTree::BinarySearchTree(int root)
{
	
}

void BinarySearchTree::insert(int value) {
	node *n = new node(value);
	if (root == NULL) {
		root = n;
	}
	//Root created, loop through to check if value < root value --> Go to left node. else right node. First need to check if value == root value.
	//else {
	//	if 
	//}
}

BinarySearchTree::~BinarySearchTree()
{
}
