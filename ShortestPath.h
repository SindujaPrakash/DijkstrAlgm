//Class containing the Dijkstra's algorithm

#include "PriorityQueue.h"
#include "GraphData.h"
#include <vector>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

class ShortestPath
{

private:
	GraphData graph;
	int noOfNodes;
	PriorityQueue queue;

public:
	void setGraph(int node, double density, int distanceRange);
	void findShortestPath(int sourceNode);
};

