#include "PriorityQueue.h"
#include "GraphData.h"
#include <vector>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

class ShortestPath
{
protected:
	map<int,int> sizeOfPath;

public:
	PriorityQueue pq;
	GraphData graph;

	ShortestPath() {

	};
	std::vector<int> findShortestPath(int sourceNode, int destinationNode);
	int pathSize(int sourceNode, int destinationNode);
};

