#include "pch.h"
#include "BinarySearchTree.h"

//template<typename Comparable>
//BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree & rhs) : BinarySearchTree<Comparable>::root{ nullptr }
//{
//	//BinarySearchTree<Comparable>::root = clone(rhs.root);
//}

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
}

//template<typename Comparable>
//BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::clone(BinaryNode *t) const
//{
//	if (t == nullptr)
//		return nullptr;
//	else
//		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
//}

template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}

template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode * & t)
{
	if (t != nullptr)
		{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
		}
	t = nullptr;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode * & t) {
	if (t == nullptr)
		t = new BinaryNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable && x, BinaryNode * & t) {
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true; // Match
}