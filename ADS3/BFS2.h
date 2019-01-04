#pragma once

#include "AdversaryGraph.h"
#include <list>
#include <queue>

class BFS2 {
public:
	BFS2();
	std::list<int> findAllFriends(AdversaryGraph adjNodeList, int startVertex);
};