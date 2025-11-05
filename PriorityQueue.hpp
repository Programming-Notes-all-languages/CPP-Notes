#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "GraphBase.hpp"
#include <unordered_map>
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class PriorityQueue
{
    vector<pair<string, unsigned long>> heap;

    public:
        int parent(int);
        int left(int);
        int right(int);
        void heapifyUp(int);
        void heapifyDown(int);
        void push(string, unsigned long);
        pair<string, unsigned long> pop();
        bool empty() const;
        pair<string, unsigned long> min() const;
};

#endif /* PRIORITYQUEUE_H */