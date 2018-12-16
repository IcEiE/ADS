#include "pch.h"
#include "BinaryTree.h"

struct Node
{
	int data;
	Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

BinaryTree::BinaryTree()
{
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	std::cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	std::cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	std::cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);
}

void BinaryTree::printPreorder(Node *node) {
	if (node == NULL) {
		return;
	}
	std::cout << node->data << " ";
	printPreorder(node->left);
	printPreorder(node->right);
}

void BinaryTree::printPostorder(Node *node) {
	if (node == NULL) {
		return;
	}
	printPostorder(node->left);
	printPostorder(node->right);
	std::cout << node->data << " ";
}

void BinaryTree::printInorder(Node *node) {
	if (node == NULL) {
		return;
	}
	printInorder(node->left);
	std::cout << node->data << " ";
	printInorder(node->right);
}