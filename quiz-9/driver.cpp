#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    Graph g; // undirected and unweighted (can be connected or disconnected)
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    // g.addVertex(5);
    // g.addVertex(6);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    // g.addEdge(2, 4);
    // g.addEdge(1, 4);
    // g.addEdge(1, 6);
    // g.addEdge(3, 5);
    // g.addEdge(4, 5);
    g.fun()? cout << "True" << endl: cout << "False" << endl;


    return 0;
}
