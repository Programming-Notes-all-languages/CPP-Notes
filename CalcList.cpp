#include <iostream>
#include "CalcList.hpp"
using namespace std;

//newOperation function which enables the user to choose an operation to perform using a given operand on the calculator's total stored value. The user's operation and operand are passed to this function. The function ensures that the new operation is added to the list successfully and ensures no division by zero occurs as this is illegal
void CalcList::newOperation(const FUNCTIONS func, const double operand)
{
    //declaration of new node to be added to link list, initializing the node's operand and operation
    Node *newNode = new Node(func, operand);

    //checking if head does points to nothing; if head is not pointing to nullptr, then we are adding a node to an existing list rather than assigning this new node to head
    if (head != nullptr)
    {
        //setting new node's previous attribute to point to the last operation which is tail
        newNode->setPrevious(tail);
        //setting the existing tail's next attribute to point to the new node as tail now needs to point to the new tail
        tail->setNext(newNode);
        //incrementing the index of the new node by one as this operation is the next new operation to be performed
        newNode->setIndex(tail->getIndex() + 1);
        //updating tail to point to the new node
        tail = newNode;
    }

    //if head does point to nullptr, then we are just going to have head and tail point to the new node as this is the first element in the list
    else
    {
        //assigning head and tail to point to new node
        head = tail = newNode;
        //setting the step index for the first operation to 1
        newNode->setIndex(1);
    }

    //switch statement which tells the compiler to perform a certain operation based on what operation the user wanted to perform
    switch (newNode->getOperation())
    {
        //if addition needs to be perform, the current running total of the calculator is updated to equal the existing running total plus the operand the user input
        case ADDITION: this->setTotal(this->total() + newNode->getValue()); break;
        
        //if subtraction needs to be perform, the current running total of the calculator is updated to equal the existing running total minus the operand the user input
        case SUBTRACTION: this->setTotal(this->total() - newNode->getValue()); break;
        
        //if multiplication needs to be perform, the current running total of the calculator is updated to equal the existing running total times the operand the user input
        case MULTIPLICATION: this->setTotal(this->total() * newNode->getValue()); break;
        
        ////if division needs to be perform, the current running total of the calculator is updated to equal the existing running total divided by the operand the user input
        case DIVISION:
            //this case checks to make sure division by zero does not occur
            if (newNode->getValue() != 0)
                //since division by zero does not occur, tabulate the division
                this->setTotal(this->total() / newNode->getValue());
            else
                //throwing an error due to the user trying to divide by zero
                throw invalid_argument("Cannot Divide By Zero");
            break;
    }

    newNode->setStepTotal(this->total());
}

//removeLastOperation removes the last operation that the user performed from the linked list of operations. The function ensures that the linked list is always pointing to a valid piece of memory to avoid segmentation faults. The running total of the calculator's operation is set back to the running total from the prior operation. The function also ensures that the last operation of the linked list now points to nullptr as the prior operation is now the tail node
void CalcList::removeLastOperation()
{
    //if there are no nodes to be removed from the list, meaning that the linked list is currently empty
    if (tail == nullptr)
        //throw an error saying you cannot remove an operation since there are no operations to perform
        throw runtime_error("No Operations to Remove");
            
    Node *ptr = tail;

    //if the node right before the tail node is not pointing to nullptr
    if (tail->getPrevious() != nullptr)
    {
        //set the running total of the calculator to equal the total value of the calculator found just before the step trying to be removed
        this->setTotal(tail->getPrevious()->getStepTotal());
        //have tail now point to the prior node as we are going to be deleting the last operation
        tail = tail->getPrevious();
        //setting the tail's next attribute to point to nullptr
        tail->setNext(nullptr);
    }

    //if there is no node before tail, meaning tail is the only node in the linked list
    else
    {
        //set the running total of the calculator to zero
        this->setTotal(0);
        //have head and tail point to nullptr as there are no nodes in the linked list
        head = tail = nullptr;
    }

    //freeing the previous tail from memory
    delete ptr;
}

//toString returns a string value that represents all the operations that have been performed by the user in reverse chronological order. It does so by traversing the linked list from the head to the tail, printing out each operand, operation, step index, and step total for each use of the calculator. The function takes in a short which specifies the precision of the results. The floats are converted to integers using ostringstream which are then appended to prior portions of the string to print a neat string of text showing all the operations performed by the user on the calculator
string CalcList::toString(unsigned short precision) const
{
    ostringstream temp;

    //setting the precision of the doubles to the variable precision
    temp << fixed << setprecision(precision);

    //for loop which iterates from the tail of the linked list to the head of the linked list
    for (Node *ptr = tail; ptr != nullptr; ptr = ptr->getPrevious())
    {
        //checking if the node in the list is not the head node so no segmentation fault occurs
        if (ptr->getPrevious() != nullptr)
            temp << ptr->getIndex() << ": " << ptr->getPrevious()->getStepTotal();
        //condition will run if head node has been reached
        else
            temp << ptr->getIndex() << ": " << 0;
                
        //switch statement which appends the operation to the existing string temp based on what operation occurred at step ptr
        switch (ptr->getOperation())
        {
            case ADDITION: temp << "+"; break;
            case SUBTRACTION: temp << "-"; break;
            case MULTIPLICATION: temp << "*"; break;
            case DIVISION: temp << "/"; break;
        }

        temp << ptr->getValue() << "=" << ptr->getStepTotal() << "\n";
    }

    //returning temp and converting it to a string value
    return temp.str();
}

//destructor needed for freeing the dynamically allocated memory needed for the double linked list
CalcList::~CalcList()
{
    Node *ptr = head;

    //while loop which iterates until each node of the linked list has been freed from memory
    while (ptr != nullptr)
    {
        //assigning next ptr to point to the next node in the last after ptr
        Node *next = ptr->getNext();
        //deleting the current node from the list
        delete ptr;
        //assigning the next node to now be the current node
        ptr = next;
    }

    //having head and tail point to nullptr to ensure there are no dangling pointers
    head = tail = nullptr;
}