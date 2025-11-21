#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include <algorithm>
using namespace std;

//method for adding vertex to list
void Graph::addVertex(string label)
{
    //declaring iterator to iterate through the adjacency list
    auto it = adjacentList.begin();

    //for loop which iterates through the list and returns if the vertex's name matches the label
    for (; it != adjacentList.end(); it++)
        //returning if the vertex's name matches the label
        if (it->first == label)
            return;

    //replacing the vertex label with an empty map
    vector<pair<string, unsigned long>> empty;
    adjacentList[label] = empty;
}

//method for adding an edge to the list
void Graph::addEdge(string label1, string label2, unsigned long weight)
{
    //variable declarations and initialization
    bool foundLabel1 = false, foundLabel2 = false;
    auto it = adjacentList.begin();

    //for loop which iterates and verifies that the parameters are the names of at least one of the vertices
    for (; it != adjacentList.end(); it++)
    {
        if (it->first == label1)
            foundLabel1 = true;
        else if (it->first == label2)
            foundLabel2 = true;
    }

    //if one of the vertices is not found, return back to main
    if ((!foundLabel1 || !foundLabel2) || label1 == label2)
        return;
    
    //for loop which iterates through the edges of vertex label1 and ensures it does not equal to 
    for (auto it = adjacentList[label1].begin(); it != adjacentList[label1].end(); it++)
        if (it->first == label2)
            return;

    //creating two new weighted edges
    pair<string, unsigned long> edge1(label2, weight);
    pair<string, unsigned long> edge2(label1, weight);

    //adding both edges to vertices label1 and label2
    adjacentList[label1].push_back(edge1);
    adjacentList[label2].push_back(edge2);
}

//method for removing a vertex from the adjacency list
void Graph::removeVertex(string label)
{
    //variable declarations and initialization
    bool foundLabel = false;
    auto it = adjacentList.begin();

    //for loop which iterates through the vertices of the adjacency list
    for (; it != adjacentList.end(); it++)
        //conditional statement which checks if the current iterator is pointing at vertex label; if so, the boolean is marked as true
        if (it->first == label)
            foundLabel = true;
    
    //if the label vertex was not found, return from this function
    if (!foundLabel)
        return;
    
    //for loop 
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
    unsigned long alternate;
    string current;

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
    
    for (it = adjacentList.begin(); it != adjacentList.end(); it++)
    {
        dist[it->first] = ULONG_MAX;
        prev[it->first] = "";
        visited[it->first] = false;
    }

    dist[labelStart] = 0;

    while (!queue.empty())
    {
        auto[u, d] = queue.pop();

        if (visited[u])
            continue;
        
        visited[u] = true;

        if (u == labelEnd)
            break;
        
        for (auto it = adjacentList[u].begin(); it != adjacentList[u].end(); it++)
        {
            alternate = dist[u] + it->second;

            if (alternate < dist[it->first])
            {
                dist[it->first] = alternate;
                prev[it->first] = u;

                queue.push(it->first, alternate);
            }
        }
    }

    path.clear();
    current = labelEnd;

    while (current != "" && prev.find(current) != prev.end())
    {
        path.push_back(current);
        current = prev[current];
    }

    reverse(path.begin(), path.end());

    return dist[labelEnd];
}

Graph::~Graph()
{
    
}