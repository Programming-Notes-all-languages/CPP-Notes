#include <iostream>
using namespace std;

#define MAX 1000

struct Node
{
    Node *next;
    Node *previous;
    int value;

public:
    Node(const int val) : next(nullptr), previous(nullptr), value(val) {}
};

class Deque
{
    Node *head;
    Node *tail;
    int count;

public:
    Deque() : head(nullptr), tail(nullptr), count(0) {}
    void pushFront(const int *&);
    void pushBack(const int *&);
    void popFront();
    void popBack();
    int front() const;
    int back() const;
    bool empty() const;
    int size() const;
    ~Deque();
};

int main()
{

    return 0;
}

void Deque::pushFront(const int *&value)
{
    Node *newNode = new Node(*value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }

    this->count++;
}

void Deque::pushBack(const int *&value)
{
    Node *newNode = new Node(*value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }

    this->count++;
}

void Deque::popFront()
{
    if (head == nullptr)
        return;

    if (head->next != nullptr)
    {
        Node *ptr = head->next;
        ptr->previous = nullptr;
        delete head;
        head = ptr;
    }

    else
    {
        delete head;
        head = tail = nullptr;
    }

    this->count--;
}

void Deque::popBack()
{
    if (tail == nullptr)
        return;

    if (tail->previous != nullptr)
    {
        Node *ptr = tail->previous;
        ptr->next = nullptr;
        delete tail;
        tail = ptr;
    }

    else
    {
        delete tail;
        head = tail = nullptr;
    }

    this->count--;
}

int Deque::front() const
{
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    return head->value;
}

int Deque::back() const
{
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    return tail->value;
}

bool Deque::empty() const
{
    if (head == nullptr)
        return true;

    return false;
}

int Deque::size() const
{
    return this->count;
}

Deque::~Deque()
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = tail = nullptr;
}

class Stack
{
    
};