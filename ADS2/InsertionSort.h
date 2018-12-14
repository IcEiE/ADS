#pragma once
class InsertionSort
{
public:
	InsertionSort();
	~InsertionSort();
	void getRandomList(int elements);

	void insertionSort();

private:
	int x;
	std::list<int> linkedL;
};

