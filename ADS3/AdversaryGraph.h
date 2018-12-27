#pragma once
class AdversaryGraph
{
public:
	AdversaryGraph(int V);
	~AdversaryGraph();
	void addEdge(int v1, int v2);
	bool isEdge(int v1, int v2);
	int getNumbOfNodes();
	void printGraph();
	std::list<int> successors(int vertex);
	std::list<int> findAllFriends(int v);
private:
	int V;
	std::list<int> *adjNodeList;
};