#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <unordered_map>
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Graph : public GraphBase 
{
    unordered_map<string, vector<pair<string, unsigned long>>> adjacentList;

    public:
        void addVertex(string) override;
        void removeVertex(string) override;
        void addEdge(string, string, unsigned long) override;
        void removeEdge(string label1, string) override;
        unsigned long shortestPath(string, string, vector<string> &) override;
        void print() const;
        ~Graph();
};

#endif /* GRAPH_H */