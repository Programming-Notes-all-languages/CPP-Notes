#include "PriorityQueue.hpp"
#include <algorithm>
using namespace std;

int PriorityQueue::parent(int i)
{
    return (i - 2) / 2;
}

int PriorityQueue::left(int i)
{
    return 2 * i + 1; 
}

int PriorityQueue::right(int i)
{
    return 2 * i + 2;
}

void PriorityQueue::heapifyUp(int i)
{
    int parentIndex;
    
    while (i > 0)
    {
        parentIndex = (i - 1) / 2;

        if (heap[i].second < heap[parentIndex].second)
        {
            swap(heap[i], heap[parentIndex]);
            i = parentIndex;
        }
        
        else break;
    }
}

void PriorityQueue::heapifyDown(int i)
{
    int leftNode, rightNode, smallest;

    while (true)
    {
        leftNode = left(i);
        rightNode = right(i);
        smallest = i;

        if (leftNode < heap.size() && heap[leftNode].second < heap[smallest].second)
            smallest = leftNode;

        if (rightNode < heap.size() && heap[rightNode].second < heap[smallest].second)
            smallest = rightNode;

        if (smallest == i)
            break;

        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

bool PriorityQueue::empty() const
{
    return heap.empty();
}

pair<string, unsigned long> PriorityQueue::min() const
{
    return heap[0];
}

void PriorityQueue::push(string vertex, unsigned long distance)
{
    heap.push_back({vertex, distance});
    heapifyUp(heap.size() - 1);
}

pair<string, unsigned long> PriorityQueue::pop()
{
    if (heap.empty())
        throw out_of_range("Empty");
    
    pair<string, unsigned long> min = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
        heapifyDown(0);
    
    return min;
}