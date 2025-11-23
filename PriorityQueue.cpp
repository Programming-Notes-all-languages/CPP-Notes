#include "PriorityQueue.hpp"
#include <algorithm>
using namespace std;

//finding parent index
int PriorityQueue::parent(int i)
{
    return (i - 2) / 2;
}

//finding left index
int PriorityQueue::left(int i)
{
    return 2 * i + 1; 
}

//finding right index
int PriorityQueue::right(int i)
{
    return 2 * i + 2;
}

//heapify up method for the priority queue
void PriorityQueue::heapifyUp(int i)
{
    int parentIndex;
    
    //while loop which iterates 
    while (i > 0)
    {
        parentIndex = (i - 1) / 2;

        //checking if the current node in the heap at index i is less than the node at index parendIndex
        if (heap[i].second < heap[parentIndex].second)
        {
            //swap function to swap items in the heap
            swap(heap[i], heap[parentIndex]);
            i = parentIndex;
        }
        
        else break;
    }
}

//heapify down method for priority queue
void PriorityQueue::heapifyDown(int i)
{
    //variable declarations
    int leftNode, rightNode, smallest;

    //while loop which just keeps iterating until the logic in the loop terminates the iterations
    while (true)
    {
        //getting left and right indices and storing them in variables
        leftNode = left(i);
        rightNode = right(i);
        smallest = i;

        //if the value of the heap node at leftNode is less than the heap node value at smallest, make smallest equal to leftNode
        if (leftNode < heap.size() && heap[leftNode].second < heap[smallest].second)
            smallest = leftNode;

        //if the value of the heap node at rightNode is less than the heap node value at smallest, make smallest equal to rightNode
        if (rightNode < heap.size() && heap[rightNode].second < heap[smallest].second)
            smallest = rightNode;

        //if the smallest index is equal to i, terminate from the loop
        if (smallest == i)
            break;

        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

//method for checking if the heap is empty
bool PriorityQueue::empty() const
{
    return heap.empty();
}

//method for finding the root of the priority queue
pair<string, unsigned long> PriorityQueue::min() const
{
    return heap[0];
}

//method for pushing a new node to the priority queue
void PriorityQueue::push(string vertex, unsigned long distance)
{
    //pushing the vertex onto the back of the queue and heapifying up
    heap.push_back({vertex, distance});
    heapifyUp(heap.size() - 1);
}

//method for popping the root node in the priority queue
pair<string, unsigned long> PriorityQueue::pop()
{
    //checking if the heap is empty; if so, throw an error
    if (heap.empty())
        throw out_of_range("Empty");
    
    //declaring and initializing a pair to store the root node in the heap
    pair<string, unsigned long> min = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    //recursively calling heapify down if the heap is not empty
    if (!heap.empty())
        heapifyDown(0);
    
    return min;
}