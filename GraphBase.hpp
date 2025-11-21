#ifndef GRAPHBASE_H
#define GRAPHBASE_H

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

class GraphBase 
{
    //method for adding a vertext to the adjacency list
    virtual void addVertex(std::string label) = 0;
    //method for removing a vertex from the adjacency list
    virtual void removeVertex(std::string label) = 0;
    //method for adding an edge to the adjacency list
    virtual void addEdge(std::string label1, std::string label2, unsigned long weight) = 0;
    //method for removing an edge from the adjacency list
    virtual void removeEdge(std::string label1, std::string label2) = 0;
    //method for Dijkstra's algorithm to find the shortest path to a vertex
    virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) = 0;
};

#endif /* GRAPHBASE_H */