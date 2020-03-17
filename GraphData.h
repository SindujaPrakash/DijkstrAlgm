#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>

class GraphData {
protected:
    int** graph;
    int noOfNodes;
    int noOfEdges;

public:

    //Default Constructor
    GraphData() : noOfNodes(0) {

    };

    //Parametrised Constructor to generate initial graph structure
   //Nodes: No. of nodes the graph has
    GraphData(int nodes) : noOfNodes(nodes) {
        graph = new int* [noOfNodes];
        for (int i = 0; i < noOfNodes; i++)
        {
            graph[i] = new int[noOfNodes];
            for (int j = 0; j < noOfNodes; j++)
            {
                graph[i][j] = 0;
            }
        }
    };
    void generateRandomGraph(int distanceRange, double density);
    void displayGraph();
    int getNoOfVertices();
    int getNoOfEdges();
    bool adjacent(int x, int y);
    std::vector<int> neighbors(int x);
    bool add(int x, int y, int distance);
    bool remove(int x, int y);
};



