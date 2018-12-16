#include "pch.h"
#include <iostream>
#include "InsertionSort.h"
#include "ModBucketSort.h"
#include "BinaryTree.h"

int main()
{
	std::cout << "MENU \n \n";
	std::cout << "1: Insertion Sort\n";
	std::cout << "2: Modified Bucket Sort\n";
	std::cout << "3: Binary Tree\n";
	std::cout << "\nI choose: ";
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		InsertionSort *is = new InsertionSort();
		delete is;
	}
	else if (choice == 2) {
		ModBucketSort *mbs = new ModBucketSort();
		delete mbs;
	}
	else if (choice == 3) {
		BinaryTree *bt = new BinaryTree();
		delete bt;
	}
	std::cout << "\n\n\n";
}