//Check if a doubly circularly linked list is a palindrome

#include <iostream>
using namespace std;

//struct definition for doubly linked list
struct Node
{
    double value;
    Node *next, *previous;
};

bool check(const Node *, const Node *);
void deleteList(Node *&);

int main()
{
    Node *head = new Node{1, nullptr, nullptr};
    Node *second = new Node{2, nullptr, head};
    Node *third = new Node{3, nullptr, second};
    Node *fourth = new Node{0, nullptr, third};
    head->next = second;
    second->next = third;
    third->next = fourth;
    head->previous = fourth;
    fourth->next = head;

    cout << check(head, fourth);
    deleteList(head);

    return 0;
}

bool check(const Node *head, const Node *tail)
{
    for (const Node *ptrHead = head, *ptrTail = tail; ptrHead != ptrTail && ptrTail->previous != ptrHead; ptrHead = ptrHead->next, ptrTail = ptrTail->previous)
        if (ptrHead->value != ptrTail->value)
            return false;

    return true;
}

void deleteList(Node *&head)
{
    Node *current = head;

    do
    {
        Node *next = current->next;
        delete current;
        current = next;
    } while (current != head);

    head = nullptr;
}