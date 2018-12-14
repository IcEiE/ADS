#include "pch.h"
#include <iostream>
#include "InsertionSort.h"

int main()
{
	std::cout << "MENU \n \n";
	std::cout << "1: Sorting functions\n";
	std::cout << "\nI choose: ";
	int choice;
	InsertionSort *is;
	std::cin >> choice;
	switch (choice)
	{
		case 1:
			is = new InsertionSort();
			delete is;
			break;
		default:
			break;
	}
	std::cout << "\n\n\n";
}