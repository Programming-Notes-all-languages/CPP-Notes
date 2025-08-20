#include <iostream>
using namespace std;

//Node declaration for linked list
struct Node
{
    int data;
    Node *next, *previous;
};

//function declaration for insertAfterAll which inserts a new node with a specified data value after an existing node with a different data value
Node *insertAfterAll(Node *, const int *, const int *);

int main()
{
    //variable declarations
    int target = 1, value = 3;

    //creating the head
    Node *head = new Node();
    head->data = 1;
    head->previous = nullptr;
    
    //creating the node after the head
    Node *second = new Node();
    second->data = 2;
    head->next = second;
    second->previous = head;
    second->next = nullptr;

    //calling pushFront to create a new head to the list
    head = insertAfterAll(head, &target, &value);

    //for loop which iterates through the list and prints each node's data
    for (Node *p = head; p != nullptr; p = p->next)
        cout << p->data << endl;

    return 0;
}

//function definition for insertAfterAll
Node *insertAfterAll(Node *head, const int *target, const int *value)
{
    //for loop which iterates through the linked list
    for (Node *p = head; p != nullptr; p = p->next)
    {
        //conditional statement which checks if the current node's data matches the target's value
        if (p->data == *target)
        {
            //
            Node *newNode = new Node();
            newNode->data = *value;
            newNode->previous = p;
            newNode->next = p->next;
            p->next = newNode;

            //conditional statement which checks if the next item after the new node in the list is not nullptr; if so, make the next node's previous point to the new node
            if (newNode->next != nullptr)
                newNode->next->previous = newNode;

            //set p to point to the new node to skip over this node in the loop
            p = newNode;
        }
    }

    return head;
}