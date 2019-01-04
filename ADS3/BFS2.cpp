#include "pch.h"
#include "BFS2.h"
BFS2::BFS2()
{
	AdversaryGraph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(3, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 6);

	g.addEdge(1, 0);
	g.addEdge(2, 0);
	g.addEdge(3, 1);
	g.addEdge(4, 1);
	g.addEdge(5, 1);
	g.addEdge(4, 3);
	g.addEdge(5, 2);
	g.addEdge(6, 2);
	std::list<int> friends = findAllFriends(g, 0);
	for (auto f : friends) {
		std::cout << f << ", ";
	}
}
std::list<int> BFS2::findAllFriends(AdversaryGraph adjNodeList, int startVertex) {
	int numberOfVerticis = adjNodeList.getNumbOfNodes();
	bool *visited = new bool[numberOfVerticis];
	for (int i = 0; i < numberOfVerticis; i++) {
		visited[i] = false;
	}
	std::list<int> friends;
	std::queue<int> *openList = new std::queue<int>;

	openList->push(startVertex);
	visited[startVertex] = true;
	int nextInQueue;
	int depth = 0;
	openList->push(-1);

	while (!openList->empty()) {
		nextInQueue = openList->front();
		openList->pop();
		if (nextInQueue == -1 && openList->size() > 0) {
			++depth;
			openList->push(-1);
		}
		else if (nextInQueue != -1) {

			if (depth > 0 && depth % 2 == 0) friends.push_back(nextInQueue);


			for (auto foe : adjNodeList.successors(nextInQueue)) {
				if (!visited[foe]) {
					openList->push(foe);
					visited[foe] = true;
				}
			}
		}
	}
	return friends;
}