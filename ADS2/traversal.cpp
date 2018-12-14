// C program for different tree traversals 
#include "pch.h"
#include "traversal.h"

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void traversal::printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree 
	printPostorder(node->left);

	// then recur on right subtree 
	printPostorder(node->right);

	// now deal with the node 
	std::cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void traversal::printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	std::cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void traversal::printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	std::cout << node->data << " ";

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

//int main()
//{
//	traversal *tv = new traversal();
//	struct Node *root = new Node(1);
//	root->left = new Node(2);
//	root->right = new Node(3);
//	root->left->left = new Node(4);
//	root->left->right = new Node(5);
//
//	std::cout << "\nPreorder traversal of binary tree is \n";
//	tv->printPreorder(root);
//
//	std::cout << "\nInorder traversal of binary tree is \n";
//	tv->printInorder(root);
//
//	std::cout << "\nPostorder traversal of binary tree is \n";
//	tv->printPostorder(root);
//
//	return 0;
//}