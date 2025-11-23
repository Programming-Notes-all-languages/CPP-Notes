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
    
    //for loop which iterates through the adjacency list vectors
    for (auto it = adjacentList.begin(); it != adjacentList.end(); it++)
        //for loop which iterates through each edge of the vecter
        for (auto it2 = it->second.begin(); it2 != it->second.end();)
        //ternary expression which evaluates to true if the edge matches the label; if so, erase that edge; otherwise, iterate to the next edge    
        (it2->first == label) ? it2 = it->second.erase(it2) : it2++;
            
    //remove the vertex label
    adjacentList.erase(label);
}

//method for removing an edge from the adjacency list
void Graph::removeEdge(string label1, string label2)
{
    //variable declarations and initializations
    bool foundLabel1 = false, foundLabel2 = false;
    auto it = adjacentList.begin();

    //for loop which iterates over each vertex in the adjacency list
    for (; it != adjacentList.end(); it++)
    {
        //if vertex label1 is found, mark the boolean as true
        if (it->first == label1)
            foundLabel1 = true;
        //otherwise, if vertex label2 is found, mark the boolean as true
        else if (it->first == label2)
            foundLabel2 = true;
    }

    //if either vertex was found, return from this function
    if (!foundLabel1 || !foundLabel2)
        return;

    //for loop which iterates over each edge of vertex label1
    for (auto it2 = adjacentList[label1].begin(); it2 != adjacentList[label1].end();)
        //conditional expression where if the second label is found, erase that edge; otherwise, iterate to the next edge
        (it2->first == label2) ? it2 = adjacentList[label1].erase(it2) : it2++;

    //for loop which iterates over each edge of vertex label2
    for (auto it2 = adjacentList[label2].begin(); it2 != adjacentList[label2].end();)
        //conditional expression where if the first label is found, erase that edge; otherwise, iterate to the next edge
        (it2->first == label1) ? it2 = adjacentList[label2].erase(it2) : it2++;
}

//method for implementing Dijkstra's algorithm to find the shortest path from a starting vertex to an ending vertex
unsigned long Graph::shortestPath(string labelStart, string labelEnd, vector<string> &path)
{
    //variable declarations and initializations
    bool foundLabel1 = false, foundLabel2 = false;
    auto it = adjacentList.begin();
    unordered_map<string, unsigned long> dist;
    unordered_map<string, string> prev;
    unordered_map<string, bool> visited;
    //head of the priority queue
    PriorityQueue queue;
    unsigned long alternate;
    string current;

    //pushing the first element into the priority queue
    queue.push(labelStart, 0);

    //for loop which iterates through the adjacency list
    for (; it != adjacentList.end(); it++)
    {
        //if the first vertex is found, labelStart, then mark the boolean as true
        if (it->first == labelStart)
            foundLabel1 = true;
        //if the second vertex is found, labelEnd, then mark the second boolean as true 
        else if (it->first == labelEnd)
            foundLabel2 = true;
    }

    //if one of the two vertices above was found, return from the function
    if (!foundLabel1 || !foundLabel2)
        return ULONG_MAX;
    
    //for loop which iterates through the adjacency list
    for (it = adjacentList.begin(); it != adjacentList.end(); it++)
    {
        //assigning the dist, prev, and visited properties to the current vertex being looked at in the list
        dist[it->first] = ULONG_MAX;
        prev[it->first] = "";
        visited[it->first] = false;
    }

    dist[labelStart] = 0;

    //while loop which iterates through the entire priority queue until it is empty
    while (!queue.empty())
    {
        //poping the head of the queue and storing it into a pair
        auto[u, d] = queue.pop();

        //if the current visited property is true, skip this iteration of the loop and go to the next iteration
        if (visited[u])
            continue;
        
        visited[u] = true;

        //if the current vertex that is being looked at is the parameter labelEnd, then stop iterating in the loop
        if (u == labelEnd)
            break;
        
        //for loop which iterates over each edge on the current vertex
        for (auto it = adjacentList[u].begin(); it != adjacentList[u].end(); it++)
        {
            //finding the length of the path
            alternate = dist[u] + it->second;

            //selection statement seeing if the current length is less than the distance from the first vertex
            if (alternate < dist[it->first])
            {
                dist[it->first] = alternate;
                prev[it->first] = u;

                //push the current vertex to the priority queue
                queue.push(it->first, alternate);
            }
        }
    }

    path.clear();
    current = labelEnd;

    //while loop which iterates until the current vertex is not blank and other condition
    while (current != "" && prev.find(current) != prev.end())
    {
        path.push_back(current);
        current = prev[current];
    }

    //calling the reverse function from the algorithm library to reverse the front and end nodes of path
    reverse(path.begin(), path.end());

    //returning the shortest path to the vertex
    return dist[labelEnd];
}

//Graph destructor
Graph::~Graph()
{
    
}