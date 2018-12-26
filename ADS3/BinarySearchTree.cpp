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
	insert(root);
	std::cout << "\nWelcome to Bisection Search Tree \n\n1: Insert node in tree\n2: Print tree \n\nI choose:";
	bool keepLoop = true;
	while (keepLoop) {
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "\nInsert all nodes, when done write a non-integer. ";
			int nodeValue;
			while (std::cin >> nodeValue) {
				insert(nodeValue);
			}
			keepLoop = false;
			break;
		case 2:
			keepLoop = false;
			break;
		default:
			std::cout << "\nThat is not a valid number! Choose a new one: ";
			break;
		}
	}
}

void BinarySearchTree::insert(int value) {
	node *incNode = new node(value);
	if (root == NULL) {
		root = incNode;
		return;
	}
	//Root created, loop through to check if value < root value --> Go to left node. else right node. First need to check if value == root value.
	else {
		node *tempNode = root;
		while (true) {
			if (value < tempNode->data) {
				if (tempNode->left) {
					tempNode = tempNode->left;
				}
				else {
					tempNode->left = incNode;
					return;
				}
			}
			else if (value > tempNode->data) {
				if (tempNode->right) {
					tempNode = tempNode->right;
				}
				else {
					tempNode->right = incNode;
					return;
				}
			}
			else {
				return;
			}
		}
	}
}

BinarySearchTree::~BinarySearchTree()
{
}
