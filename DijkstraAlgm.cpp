// DijkstraAlgm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>

#include "ShortestPath.h"

using namespace std;

int main()
{
    int node, distanceRange;
    double density;

    int sourceNode;

    std::cout << "To create a random graph";
    std::cout << "\n" << "Enter No of nodes\n";
    std::cin >> node;
    std::cout << "\n Enter the density\n";
    std::cin >> density;
    std::cout << "\n Enter the distance range\n";
    std::cin >> distanceRange;

    // Class containing the Dijkstra's Algorithm
    ShortestPath s1;
    s1.setGraph(node, density, distanceRange);

    std::cout << "\nEnter source node\n";
    std::cin >> sourceNode;
    
    // Function to find and display the shortest path and average path length
    s1.findShortestPath(sourceNode);
    while (1)
    {

    }
    // To test Graph class functions
    /*while (1)
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
            for (int i = 0; i<(list.max_size()-1); i++)
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
    }*/
}

