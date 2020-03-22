#include "ShortestPath.h"

// Function to find the shortest path to all nodes from a given source node
void ShortestPath::findShortestPath(int sourceNode) {
	vector<int> dist(noOfNodes, INT_MAX);
	int pathLength=0;
	double avgPathLength;
	int vertex, weight;

	queue.insertElement(0,sourceNode);
	dist[sourceNode] = 0;


	while (queue.returnSize() != 0)
	{
		int upper = queue.returnTop();
		queue.popElement();
		vector<int> neighbours = graph.neighbors(upper);

		for (int i = 0; i < neighbours.size(); i++)
		{
			vertex = neighbours[i];
			weight = graph.getDistance(upper, neighbours[i]);

			if (dist[vertex] > dist[upper]+weight)
			{
				dist[vertex] = dist[upper] + weight;
				queue.insertElement(dist[vertex], vertex);
			}
		}
	}

	cout<<"Vertex   Distance from Source\n";
	for (int i = 0; i < noOfNodes; ++i)
	{
		cout << i << "\t\t" << dist[i] << "\n";
		pathLength += dist[i];
	}

	avgPathLength = static_cast<double>(pathLength) / static_cast<double>((noOfNodes - 1));
	cout << "The average path length\n" << avgPathLength;
}


//Function to initiase and generate a random graph
void ShortestPath::setGraph(int node, double density, int distanceRange)
{
	this->noOfNodes = node;
	graph.readGraph(node);
	graph.generateRandomGraph(distanceRange, density);
	graph.displayGraph();
}

