#include "pch.h"
#include "AdversaryGraph.h"


AdversaryGraph::AdversaryGraph(int V)
{
	this->numberOfVerticis = V;
	adjNodeList = new std::list<int>[V];
}


AdversaryGraph::~AdversaryGraph()
{
}

void AdversaryGraph::addEdge(int v1, int v2) {
	adjNodeList[v1].push_back(v2);
}

bool AdversaryGraph::isEdge(int v1, int v2) {
	for (auto node : adjNodeList[v1]) {
		if (node == v2) return true;
	}
	return false;
}

int AdversaryGraph::getNumbOfNodes() {
	return numberOfVerticis;
}

void AdversaryGraph::printGraph() {
	for (int v = 0; v < numberOfVerticis; ++v)
	{
		std::cout << "\n Adjacency list of vertex "
			<< v << "\n head ";

		//Iterate over adj[v]
		std::list<int>::iterator i;
		for (i = adjNodeList[v].begin(); i != adjNodeList[v].end(); ++i)
			std::cout << "-> " << *i;

		printf("\n");
	}
}

//Get nodes that v is pointing to. 
std::list<int> AdversaryGraph::successors(int v) {

	std::list <int> v_sucessors;
	std::list<int>::iterator i;
	for (i = adjNodeList[v].begin(); i != adjNodeList[v].end(); ++i)
		v_sucessors.push_front(*i);

	return v_sucessors;
}


std::list<int> AdversaryGraph::findAllFriends(int startVertex) {
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

			for (auto foe : adjNodeList[nextInQueue]) {
				if (!visited[foe]) {
					openList->push(foe);
					visited[foe] = true;
				}
			}
		}
	}
	return friends;
}