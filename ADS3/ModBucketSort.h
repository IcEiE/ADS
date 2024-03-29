#pragma once
class ModBucketSort
{
public:
	ModBucketSort();
	~ModBucketSort();


private:
	int choice;
	int largestNbrInList;
	std::list<int> incomList;
	std::vector<int> bucketList;
	void getRandomList(int elements);
	void createUserList();
	void printUnsortedList();
	void printSortedList();
	void bucketSort();
	void getBiggestNrInList();
};