#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "GraphBase.hpp"
#include <unordered_map>
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//priority queue class
class PriorityQueue
{
    //vector attribute for the heap
    vector<pair<string, unsigned long>> heap;

    public:
        //method for finding the parent index
        int parent(int);
        //method for finding the left index
        int left(int);
        //method for finding the right index
        int right(int);
        //method for heapify up
        void heapifyUp(int);
        //method for heapify down
        void heapifyDown(int);
        //method for pushing new node to the heap
        void push(string, unsigned long);
        //method for popping an element from the heap
        pair<string, unsigned long> pop();
        //method for checking if the heap is empty
        bool empty() const;
        //method for returning the root node
        pair<string, unsigned long> min() const;
};

#endif /* PRIORITYQUEUE_H */