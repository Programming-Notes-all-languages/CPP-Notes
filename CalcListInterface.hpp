#ifndef CALCLISTINTERFACE_H
#define CALCLISTINTERFACE_H

#include <iostream>
using namespace std;

//Enum that contains all the arithmetic functions needed for newOperation
typedef enum 
{ 
    ADDITION, 
    SUBTRACTION, 
    MULTIPLICATION, 
    DIVISION 
} FUNCTIONS;

//Abstract class for inheritance
class CalcListInterface 
{
    public:
        //pure virtual function for returning the running total of the calculator
        virtual double total() const = 0;
        //pure virtual function for adding a new operation to the calculator
        virtual void newOperation(const FUNCTIONS func, const double operand) = 0;
        //pure virtual function for removing the last operation from the calculator's linked list
        virtual void removeLastOperation() = 0;
        //pure virtual function for neatly printing the calculator's operations in reverse chronological order
        virtual string toString(unsigned short precision) const = 0;
        //destructor to be overriden by derived class
        virtual ~CalcListInterface() {}
};

#endif /* CALCLISTINTERFACE_H */