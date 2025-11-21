#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <unordered_map>
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//derived class Graph from GraphBase
class Graph : public GraphBase 
{
    //map attribute for the adjacency list
    unordered_map<string, vector<pair<string, unsigned long>>> adjacentList;

    public:
        //method for adding a vertext to the adjacency list
        void addVertex(string) override;
        //method for removing a vertex from the adjacency list
        void removeVertex(string) override;
        //method for adding an edge to the adjacency list
        void addEdge(string, string, unsigned long) override;
        //method for removing an edge from the adjacency list
        void removeEdge(string label1, string) override;
        //method for Dijkstra's algorithm to find the shortest path to a vertex
        unsigned long shortestPath(string, string, vector<string> &) override;
        //method for printing the result
        void print() const;
        //destructor
        ~Graph();
};

#endif /* GRAPH_H */