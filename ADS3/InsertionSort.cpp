#include "pch.h"
#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
	std::cout << "\nWelcome to InsertionSort \n\n1: Create list \n2: Random list \n\nI choose:";
	bool keepLoop = true;
	while (std::cin >> choice) {
		switch (choice)
		{
		case 1:
			createUserList();
			keepLoop = false;
			break;
		case 2:
			int elements;
			std::cout << "\nNumber of elements: ";
			std::cin >> elements;
			getRandomList(elements);
			keepLoop = false;
			break;
		default:
			std::cout << "\nThat is not a valid number! Choose a new one: ";
			break;
		}
	}
	std::cout << "\nYour list is: ";
	printList();
	insertionSort();
	std::cout << "\nYour sorted list is: ";
	printList();

}


InsertionSort::~InsertionSort()
{
}

void InsertionSort::getRandomList(int elements) {
	for (int i = 0; i < elements; ++i) {
		linkedL.push_back(rand() % 1000);
	}
}

void InsertionSort::insertionSort() {
	for (std::list<int>::iterator current = linkedL.begin(); current != linkedL.end(); current = std::next(current)) {
		if (current != linkedL.begin()) {
			if (*current < *std::prev(current)) {
				std::list<int>::iterator temp = std::prev(current);
				std::swap(*current, *std::prev(current));
				if (prev(current) != linkedL.begin()) {
					current = std::prev(std::prev(current));
				}
			}
		}
	}
}

void InsertionSort::createUserList()
{
	int userNbr;
	std::cout << "Write the number you want on list, when done write a letter.\n";
	while (std::cin >> userNbr) {
		linkedL.push_back(userNbr);
	}
}

void InsertionSort::printList() {
	for (auto v : linkedL) {
		std::cout << v << ", ";
	}
}