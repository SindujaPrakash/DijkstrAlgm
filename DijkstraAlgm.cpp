// DijkstraAlgm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

//Class Graph
class graphData {

protected:
    int** graph;
    int noOfNodes;
    int noOfEdges;

public:

    //Constructor to generate initial graph structure
    //Nodes: No. of nodes the graph has
    graphData(int nodes) : noOfNodes(nodes) {
        graph = new int*[noOfNodes];
        for (int i = 0; i < noOfNodes; i++)
        {
            graph[i] = new int[noOfNodes];
            for (int j = 0; j < noOfNodes; j++)
            {
                graph[i][j] = 0;
            }
        }
    };

    //Generates a random graph using density and distance range
    void generateRandomGraph(int distanceRange, double density)
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
    void displayGraph()
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
    int getNoOfVertices()
    {
        return noOfNodes;
    }

    //Get No of Edges
    int getNoOfEdges()
    {
        return noOfEdges;
    }

    //Test wheather there is an edge from Node x to Node y
    bool adjacent(int x, int y)
    {
        if (graph[x][y] > 0)
            return true;
        else
            return false;
    }

    //Lists all nodes Y such that there is an edge from Node X to Node Y
    std::vector<int> neighbors(int x)
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
    bool add(int x, int y, int distance)
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
    bool remove(int x, int y)
    {
        if (graph[x][y] > 0)
        {
            graph[x][y] = 0;
            return true;
        }
        else
            return false;
    }
};


int main()
{
    int node, distanceRange;
    double density;

    std::cout << "To create a random graph";
    std::cout << "\n" << "Enter No of nodes\n";
    std::cin >> node;
    std::cout << "\n Enter the density\n";
    std::cin >> density;
    std::cout << "\n Enter the distance range\n";
    std::cin >> distanceRange;

    graphData g1(node);
    g1.generateRandomGraph(distanceRange, density);

    while (1)
    {
        int option, number, x, y;
        std::vector<int> list;
        bool result;

        cout << "Enter the function to perform\n";
        cout << "1. Display graph\n 2. Get No. of Nodes\n 3. Get No. of Edges\n 4. Test if edge exists\n 5. List neighbors of X";
        cout << "\n6. Add edge from x to y\n7. Delete an edge from x to y\n 8. Find shortest path from x to y\n";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "\nThe generated graph is\n";
            g1.displayGraph();
            break;
        case 2:
            number = g1.getNoOfVertices();
            cout << "\nNo of Nodes" << number;
            break;
        case 3:
            number = g1.getNoOfEdges();
            cout << "\nNo of Edges" << number;
            break;
        case 4: 
            cout << "\nEnter source node\n";
            cin >> x;
            cout << "\nEnter destination node\n";
            cin >> y;
            result = g1.adjacent(x, y);
            cout << "\nThe test result is" << result;
            break;
        case 5: 
            cout << "\nEnter source node\n";
            cin >> x;
            list = g1.neighbors(x);
            cout << "\nThe neighbors are\t";
            for (int i = 0; i < list.max_size()-1; i++)
            {
                cout << list[i] << "\t";
            }
            break;
        case 6:
            cout << "\nEnter source node\n";
            cin >> x;
            cout << "\nEnter destination node\n";
            cin >> y;
            cout << "\nEnter distance\n";
            cin >> number;
            result = g1.add(x, y, number);
            cout << "\n The result is" << result;
            break;
        case 7:
            cout << "\nEnter source node\n";
            cin >> x;
            cout << "\nEnter destination node\n";
            cin >> y;
            result = g1.remove(x, y);
            cout << "\n The result is" << result;
            break;
        case 8:
            cout << "\nFinding shortest path";
            break;
        default:
            break;
        }
    }
}

