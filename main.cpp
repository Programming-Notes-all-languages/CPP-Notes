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
bool palindrome(Node<T> *&);

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

    cout << palindrome(head);

    free(head);

    return 0;
}

template <typename T>
bool palindrome(Node<T> *&head)
{
    int count = 0, i = 0;

    for (Node<T> *ptr = head; ptr != nullptr; ptr = ptr->next, count++);

    T *array = new T[count];

    for (Node<T> *ptr = head; ptr != nullptr; array[i] = ptr->value, ptr = ptr->next, i++);

    for (int i = 0, j = count - 1; i != j && j > i; i++, j--)
        if (array[i] != array[j])
        {
            delete [] array;
            return false;
        }

    delete [] array;
    return true;
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