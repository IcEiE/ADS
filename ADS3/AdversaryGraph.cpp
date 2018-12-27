#include "pch.h"
#include "AdversaryGraph.h"


AdversaryGraph::AdversaryGraph(int V)
{
	this->V = V;
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
	return V;
}

void AdversaryGraph::printGraph() {
	for (int v = 0; v < V; ++v)
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

//Get nodes that v is poiting to. 
std::list<int> AdversaryGraph::successors(int v) {

	std::list <int> v_sucessors;
	std::list<int>::iterator i;
	for (i = adjNodeList[v].begin(); i != adjNodeList[v].end(); ++i)
		v_sucessors.push_front(*i);

	return v_sucessors;
}


std::list<int> AdversaryGraph::findAllFriends(int startVertex) {
	std::list<int> *foundNodes = new std::list<int>;
	std::list<int> *friends = new std::list<int>;
	std::queue<int> *openList = new std::queue<int>;

	openList->push(startVertex);
	int nextInQueue;
	int layer = 0;
	while (!openList->empty()) {
		nextInQueue = openList->front();
		openList->pop();
		foundNodes->push_back(nextInQueue);
		if (layer < 0 && layer % 2 == 0) friends->push_back(nextInQueue);
		for (auto foe : adjNodeList[nextInQueue]) {
			//This can only occur if foe is not already in found nodes.
			openList->push(foe);
		}
	}

	//while (!openList->empty()) {
	//	++layer;
	//	nextInQueue = openList->front();
	//	openList->pop();
	//	foundNodes->push_back(nextInQueue);
	//	for (auto adversity : )
	//}
}