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