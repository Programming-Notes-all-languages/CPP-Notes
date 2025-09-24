#ifndef CALCLIST_H
#define CALCLIST_H

#include "CalcListInterface.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class CalcList : public CalcListInterface
{
    //private class Node for 
    class Node
    {
        //list pointer for head and next
        Node *next;
        Node *previous;
        //variables for step operand, step index, and total result at current step
        double value, stepTotal;
        int index;
        //enum variable for operation
        FUNCTIONS operation;

        public:
            //constructor for instantiating new node taking in the operation and operand, while assigning the pointers to nullptr
            Node (const FUNCTIONS op, const double val) : next(nullptr), previous(nullptr), value(val), operation(op) {}
            //setter for *next
            void setNext(Node *nxt) { this->next = nxt; }
            //getter for *next
            Node *getNext() const { return this->next; }
            //setter for *previous
            void setPrevious(Node *prev) { this->previous = prev; }
            //getter for *previous
            Node *getPrevious() const { return this->previous; }
            //setter for value
            void setValue(const double total) { this->value = total; }
            //getter for value
            double getValue() const { return this->value; }
            //setter for stepTotal
            void setStepTotal(const double val) { this->stepTotal = val; }
            //getter for stepTotal
            double getStepTotal() const { return this->stepTotal; }
            //setter for index
            void setIndex(const int indx) { this->index = indx; }
            //getter for index
            int getIndex() const { return this->index; }
            //setter for operation
            void setOperation(const FUNCTIONS value) { this->operation = value; }
            //getter for operation
            FUNCTIONS getOperation () const { return this->operation; }
        };

    //head node and tail node pointers for doubly linked list
    Node *head;
    Node *tail;
    //total value in the calculator after the last calculation
    double runningTotal;
 
    public:
        //constructor instantiating an instance of the calculator having head and tail point to nullptr, while giving the calculator an initial total of 0
        CalcList() : head(nullptr), tail(nullptr), runningTotal(0) {}
        //setter for total with the variable name-"runningTotal"
        void setTotal(const double val) { this->runningTotal = val; }
        //getter for total with the variable name-"runningTotal"
        double total() const override { return this->runningTotal; }
        //newOperation function which enables the user to choose an operation to perform using a given operand on the calculator's total stored value. The user's operation and operand are passed to this function. The function ensures that the new operation is added to the list successfully and ensures no division by zero occurs as this is illegal
        void newOperation(const FUNCTIONS func, const double operand) override;
        //removeLastOperation removes the last operation that the user performed from the linked list of operations. The function ensures that the linked list is always pointing to a valid piece of memory to avoid segmentation faults. The running total of the calculator's operation is set back to the running total from the prior operation. The function also ensures that the last operation of the linked list now points to nullptr as the prior operation is now the tail node
        void removeLastOperation() override;
        //toString returns a string value that represents all the operations that have been performed by the user in reverse chronological order. It does so by traversing the linked list from the head to the tail, printing out each operand, operation, step index, and step total for each use of the calculator. The function takes in a short which specifies the precision of the results. The floats are converted to integers using ostringstream which are then appended to prior portions of the string to print a neat string of text showing all the operations performed by the user on the calculator
        string toString(unsigned short precision) const override;
        //destructor needed for freeing the dynamically allocated memory needed for the double linked list
        ~CalcList() override;
};

#endif