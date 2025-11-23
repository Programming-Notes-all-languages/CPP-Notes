#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

int main() {

    //the following main function is an example of running Dijkstra's algorithm
    Graph g;

    //add vertices to the graph
    vector<string> vertices = { "1", "2", "3", "4", "5", "6" };
    for (auto &v : vertices)
        g.addVertex(v);

    //add edges to the graph
    g.addEdge("1", "2", 7);
    g.addEdge("1", "3", 9);
    g.addEdge("1", "6", 14);
    g.addEdge("2", "3", 10);
    g.addEdge("2", "4", 15);
    g.addEdge("3", "4", 11);
    g.addEdge("3", "6", 2);
    g.addEdge("4", "5", 6);
    g.addEdge("5", "6", 9);

    //run Dijkstra algorithm
    vector<string> path;
    unsigned long result = g.shortestPath("1", "5", path);

    //print results
    cout << "Shortest path cost: " << result << endl;
    cout << "Path: ";
    for (string &step : path)
        cout << step << " ";
    cout << endl;

    return 0;
}
