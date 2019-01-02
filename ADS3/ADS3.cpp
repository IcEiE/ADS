#include "pch.h"
#include <iostream>
#include "InsertionSort.h"
#include "ModBucketSort.h"
#include "BinaryTree.h"
#include "AdversaryGraph.h"

int main()
{
	std::cout << "MENU \n \n";
	std::cout << "1: Insertion Sort\n";
	std::cout << "2: Modified Bucket Sort\n";
	std::cout << "3: Binary Tree\n";
	std::cout << "5: Adversary Graph with BFS\n";
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
	else if (choice == 5) {
		AdversaryGraph *g = new AdversaryGraph(7);
		g->addEdge(0, 1);
		g->addEdge(0, 2);
		g->addEdge(1, 3);
		g->addEdge(1, 4);
		g->addEdge(1, 5);
		g->addEdge(3, 4);
		g->addEdge(2, 5);
		g->addEdge(2, 6);

		g->addEdge(1, 0);
		g->addEdge(2, 0);
		g->addEdge(3, 1);
		g->addEdge(4, 1);
		g->addEdge(5, 1);
		g->addEdge(4, 3);
		g->addEdge(5, 2);
		g->addEdge(6, 2);
		std::list<int> friends = g->findAllFriends(0);
		std::cout << "Friends: ";
		for (auto f : friends) {
			std::cout << f << ", ";
		}
		delete g;
	}
	std::cout << "\n\n\n";
}