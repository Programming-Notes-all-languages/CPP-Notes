#ifndef CALCLIST_H
#define CALCLIST_H

#include "CalcListInterface.hpp"
#include <iostream>
using namespace std;

class CalcList : public CalcListInterface
{
    CalcList *next;
    CalcList *previous;
    double value;
    FUNCTIONS operation;

    public:
        CalcList(const FUNCTIONS op, const double val) : next(nullptr), operation(op), value(val)
        {
            if (this->getPrevious() == nullptr)
                this->setPrevious(nullptr);
            else
                this->setPrevious(this->getPrevious());
        }
        void setNext() { this->next = nullptr; }
        CalcList *getNext() const { return this->next; }
        void setPrevious(CalcList *prev) { this->previous = prev; }
        CalcList *getPrevious() const { return this->previous; }
        void setTotal(const double total) { this->value = total; }
        double total() const override { return this->value; }
        void setOperation(const FUNCTIONS value) { this->operation = value; }
        FUNCTIONS getOperation () const { return this->operation; }
        void newOperation(const FUNCTIONS func, const double operand) override
        {
            if (this->getPrevious() != nullptr)
                switch (this->getOperation())
                {
                    case 0:
                        this->setTotal(this->getPrevious()->total() + operand);
                    
                    case 1:
                        this->setTotal(this->getPrevious()->total() - operand);
                    
                    case 2:
                        this->setTotal(this->getPrevious()->total() * operand);
                    
                    case 3:
                        if (operand != 0)
                            this->setTotal(this->getPrevious()->total() / operand);
                        else
                            cout << "Cannot Divide By Zero" << endl;
                }
            
            else
                this->setTotal(0);
        }
        void removeLastOperation() override
        {
            CalcList *ptr = this;
            ptr->getPrevious()->getPrevious()->setNext();
            delete ptr->getPrevious();
        }
        string toString(unsigned short precision) const
        {

        }
        ~CalcList() {}
};

#endif