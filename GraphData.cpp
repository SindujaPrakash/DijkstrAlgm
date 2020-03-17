#include "GraphData.h"


using namespace std;

//Generates a random graph using density and distance range
void GraphData::generateRandomGraph(int distanceRange, double density)
{
	std::default_random_engine generator;
	//Normal distribution to calculate probability
	std::normal_distribution<double> distribution(0, 1);
	std::uniform_int_distribution<> cost(1, distanceRange);

	for (int i = 0; i < noOfNodes; i++)
	{
		for (int j = 0; j < noOfNodes; j++)
		{
			if (i == j)
			{
				graph[i][j] = 0;
			}
			else
			{
				double number = distribution(generator);
				if (number <= density)
				{
					graph[i][j] = cost(generator);
					noOfEdges++;
				}
			}
		}
	}
}

//Displays the generated graph
void GraphData::displayGraph()
{
	for (int i = 0; i < noOfNodes; i++)
	{
		for (int j = 0; j < noOfNodes; j++)
		{
			std::cout << graph[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

//Get No of vertices
int GraphData::getNoOfVertices()
{
	return noOfNodes;
}

//Get No of Edges
int GraphData::getNoOfEdges()
{
	return noOfEdges;
}

//Test wheather there is an edge from Node x to Node y
bool GraphData::adjacent(int x, int y)
{
	if (graph[x][y] > 0)
		return true;
	else
		return false;
}

//Lists all nodes Y such that there is an edge from Node X to Node Y
std::vector<int> GraphData::neighbors(int x)
{
	std::vector<int> nodeList;
	for (int i = 0; i < noOfNodes; i++)
	{
		if (graph[x][i] > 0)
		{
			nodeList.push_back(i);
		}
	}
	return nodeList;
}

// Add an edge from Node X to Node Y, if not present already
bool GraphData::add(int x, int y, int distance)
{
	if (graph[x][y] == 0)
	{
		graph[x][y] = distance;
		return true;
	}
	else
		return false;
}

//Remove an edge from Node X to Node Y, if it is present
bool GraphData::remove(int x, int y)
{
	if (graph[x][y] > 0)
	{
		graph[x][y] = 0;
		return true;
	}
	else
		return false;
}

