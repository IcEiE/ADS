#pragma once
class InsertionSort
{
public:
	InsertionSort();
	~InsertionSort();
private:
	void createUserList();
	void printList();
	void insertionSort();
	void getRandomList(int elements);
	int choice;
	std::list<int> linkedL;
};

