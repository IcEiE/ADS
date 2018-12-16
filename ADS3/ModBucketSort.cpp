#include "pch.h"
#include "ModBucketSort.h"


ModBucketSort::ModBucketSort()
{
	std::cout << "\nWelcome to the modified Bucket Sort \n\n1: Create list \n2: Random list \n\nI choose:";
	bool keepLoop = true;
	while (keepLoop) {
		std::cin >> choice;
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
	printUnsortedList();
	bucketSort();
	std::cout << "\nYour sorted list is: ";
	printSortedList();
}


ModBucketSort::~ModBucketSort()
{
}

void ModBucketSort::getRandomList(int elements) {
	for (int i = 0; i < elements; ++i) {
		incomList.push_back(rand() % 1000);
	}
}

void ModBucketSort::createUserList()
{
	int userNbr;
	std::cout << "Write the number you want on list, when done write a letter." << std::endl;
	while (std::cin >> userNbr) {
		incomList.push_back(userNbr);
	}
}

void ModBucketSort::printUnsortedList() {
	for (auto element : incomList) {
		std::cout << element << ", ";
	}
	std::cout << std::endl;
}

void ModBucketSort::printSortedList() {
	for (int bucketNr = 0; bucketNr < bucketList.size(); ++bucketNr) {
		for (int bucketValue = 0; bucketValue < bucketList[bucketNr]; ++bucketValue) {
			std::cout << bucketNr << ", ";
		}
	}
	std::cout << std::endl;
}

void ModBucketSort::bucketSort() {
	getBiggestNrInList();
	bucketList.resize(largestNbrInList + 1);
	for (auto element : incomList) {
		bucketList[element]++;
	}
}

void ModBucketSort::getBiggestNrInList() {
	for (auto element : incomList) {
		largestNbrInList = (element > largestNbrInList ? element : largestNbrInList);
	}
}