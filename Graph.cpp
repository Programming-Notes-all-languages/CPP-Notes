#include "Graph.hpp"
#include "PriorityQueue.hpp"
using namespace std;

void Graph::addVertex(string label)
{
    auto it = adjacentList.begin();

    for (; it != adjacentList.end(); it++)
        if (it->first == label)
            return;

    vector<pair<string, unsigned long>> empty;
    adjacentList[label] = empty;
}

void Graph::addEdge(string label1, string label2, unsigned long weight)
{
    bool foundLabel1 = false, foundLabel2 = false;
    auto it = adjacentList.begin();

    for (; it != adjacentList.end(); it++)
    {
        if (it->first == label1)
            foundLabel1 = true;
        else if (it->first == label2)
            foundLabel2 = true;
    }

    if ((!foundLabel1 || !foundLabel2) || label1 == label2)
        return;
    
    for (auto it = adjacentList[label1].begin(); it != adjacentList[label1].end(); it++)
        if (it->first == label2)
            return;

    pair<string, unsigned long> edge1(label2, weight);
    pair<string, unsigned long> edge2(label1, weight);

    adjacentList[label1].push_back(edge1);
    adjacentList[label2].push_back(edge2);
}

void Graph::removeVertex(string label)
{
    bool foundLabel = false;
    auto it = adjacentList.begin();

    for (; it != adjacentList.end(); it++)
        if (it->first == label)
            foundLabel = true;
    
    if (!foundLabel)
        return;
    
    for (auto it = adjacentList.begin(); it != adjacentList.end(); it++)
        for (auto it2 = it->second.begin(); it2 != it->second.end();)
            (it2->first == label) ? it2 = it->second.erase(it2) : it2++;
            
    adjacentList.erase(label);
}

void Graph::removeEdge(string label1, string label2)
{
    bool foundLabel1 = false, foundLabel2 = false;
    auto it = adjacentList.begin();

    for (; it != adjacentList.end(); it++)
    {
        if (it->first == label1)
            foundLabel1 = true;
        else if (it->first == label2)
            foundLabel2 = true;
    }

    if (!foundLabel1 || !foundLabel2)
        return;

    for (auto it2 = adjacentList[label1].begin(); it2 != adjacentList[label1].end();)
        (it2->first == label2) ? it2 = adjacentList[label1].erase(it2) : it2++;

    for (auto it2 = adjacentList[label2].begin(); it2 != adjacentList[label2].end();)
        (it2->first == label1) ? it2 = adjacentList[label2].erase(it2) : it2++;
}

unsigned long Graph::shortestPath(string labelStart, string labelEnd, vector<string> &path)
{
    bool foundLabel1 = false, foundLabel2 = false;
    auto it = adjacentList.begin();
    unordered_map<string, unsigned long> dist;
    unordered_map<string, string> prev;
    unordered_map<string, bool> visited;
    PriorityQueue queue;
    int min;

    queue.push(labelStart, 0);

    for (; it != adjacentList.end(); it++)
    {
        if (it->first == labelStart)
            foundLabel1 = true;
        else if (it->first == labelEnd)
            foundLabel2 = true;
    }

    if (!foundLabel1 || !foundLabel2)
        return ULONG_MAX;
    
    for (; it != adjacentList.end(); it++)
    {
        dist[it->first] = ULONG_MAX;
        prev[it->first] = "";
        visited[it->first] = false;
    }

    dist[labelStart] = 0;

    while (!queue.empty())
    {
        
    }
}