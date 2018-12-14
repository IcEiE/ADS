#include "pch.h"
#include <iostream>
#include "InsertionSort.h"
#include "ModBucketSort.h"

int main()
{
	std::cout << "MENU \n \n";
	std::cout << "1: Insertion Sort\n";
	std::cout << "2: Modified Bucket Sort\n";
	std::cout << "\nI choose: ";
	int choice;
	InsertionSort *is;
	ModBucketSort *mbs;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		is = new InsertionSort();
		delete is;
		break;
	case 2:
		mbs = new ModBucketSort();
		delete mbs;
		break;
	default:
		break;
	}
	std::cout << "\n\n\n";
}