//Remove duplicates from a linked list

#include <iostream>
using namespace std;

//class definition for doubly linked list
template <typename T>
class Node
{
    public:
        Node(T val, Node<T> *nxt = nullptr, Node<T> *prev = nullptr) 
            : value(val), next(nxt), previous(prev) {}
        T value;
        Node<T> *next;
        Node<T> *previous;
};

template<typename T>
void free(Node<T> *&);

int main()
{
    Node<int> *head = new Node<int>(1);
    Node<int> *second = new Node<int>(2, nullptr, head);
    Node<int> *third = new Node<int>(2, nullptr, second);
    Node<int> *fourth = new Node<int>(1, nullptr, third);
    head->next = second;
    second->next = third;
    third->next = fourth;
    Node<int> *tail = fourth;

    reverse(head, tail);

    free(head);

    return 0;
}

template <typename T>
void free(Node<T> *&head)
{
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}