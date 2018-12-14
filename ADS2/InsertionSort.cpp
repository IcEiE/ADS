#include "pch.h"
#include "InsertionSort.h"


InsertionSort::InsertionSort()
{
	std::cout << "\nWelcome to InsertionSort \n\n1: Create list \n2: Random list \n\nI choose:";
	std::cin >> x;

	if (x == 2) {
		int elements;
		std::cout << "\nNumber of elements: ";
		std::cin >> elements;
		getRandomList(elements);

		std::cout << "\nYour list is: ";
		for (auto v : linkedL) {
			std::cout << v << ", ";
		}
	}
	std::cout << "\nSorted: ";
	insertionSort();
	std::cout << "\nYour sorted list is: ";
	for (auto v : linkedL) {
		std::cout << v << ", ";
	}

}


InsertionSort::~InsertionSort()
{
}

void InsertionSort::getRandomList(int elements) {
	for (int i = 0; i < elements; ++i) {
		linkedL.push_back(rand() % 1000);
	}
}

void InsertionSort::insertionSort () {
	for (std::list<int>::iterator current = linkedL.begin(); current != linkedL.end(); current = std::next(current)) {
		if (current != linkedL.begin()) {
			if (*current < *std::prev(current)) {
				std::list<int>::iterator temp = std::prev(current);
				//change values for the LL. 
				std::swap(*current, *std::prev(current));
				if (prev(current) != linkedL.begin()) {
					current = std::prev(std::prev(current));
				}
			}
		}
	}
}