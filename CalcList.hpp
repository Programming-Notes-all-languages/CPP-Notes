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
    class Node
    {
        Node *next;
        Node *previous;
        double value, stepTotal;
        int index;
        FUNCTIONS operation;

        public:
            Node (const FUNCTIONS op, const double val) : next(nullptr), previous(nullptr), value(val), operation(op) {}
            void setNext(Node *nxt) { this->next = nxt; }
            Node *getNext() const { return this->next; }
            void setPrevious(Node *prev) { this->previous = prev; }
            Node *getPrevious() const { return this->previous; }
            void setValue(const double total) { this->value = total; }
            double getValue() const { return this->value; }
            void setStepTotal(const double val) { this->stepTotal = val; }
            double getStepTotal() const { return this->stepTotal; }
            void setIndex(const int indx) { this->index = indx; }
            int getIndex() const { return this->index; }
            void setOperation(const FUNCTIONS value) { this->operation = value; }
            FUNCTIONS getOperation () const { return this->operation; }
        };

    Node *head;
    Node *tail;
    double runningTotal;
 
    public:
        CalcList() : head(nullptr), tail(nullptr), runningTotal(0) {}
        void setTotal(const double val) { this->runningTotal = val; }
        double total() const override { return this->runningTotal; }
        void newOperation(const FUNCTIONS func, const double operand) override
        {
            Node *newNode = new Node(func, operand);

            if (head != nullptr)
            {
                newNode->setPrevious(tail);
                tail->setNext(newNode);
                newNode->setIndex(tail->getIndex() + 1);
                tail = newNode;
            }

            else
            {
                head = tail = newNode;
                newNode->setIndex(1);
            }

            switch (newNode->getOperation())
            {
                case ADDITION: this->setTotal(this->total() + newNode->getValue()); break;
                    
                case SUBTRACTION: this->setTotal(this->total() - newNode->getValue()); break;
                    
                case MULTIPLICATION: this->setTotal(this->total() * newNode->getValue()); break;
                    
                case DIVISION:
                    if (newNode->getValue() != 0)
                        this->setTotal(this->total() / newNode->getValue());
                    else
                        throw invalid_argument("Cannot Divide By Zero");
                    break;
            }

            newNode->setStepTotal(this->total());
        }

        void removeLastOperation() override
        {
            if (tail == nullptr)
                throw runtime_error("No Operations to Remove");
            
            Node *ptr = tail;

            if (tail->getPrevious() != nullptr)
            {
                this->setTotal(tail->getPrevious()->getStepTotal());
                tail = tail->getPrevious();
            }

            else
                this->setTotal(0);

            if (tail != nullptr)
                tail->setNext(nullptr);
            else
                head = nullptr;

            delete ptr;
        }

        string toString(unsigned short precision) const override
        {
            ostringstream temp;

            temp << fixed << setprecision(precision);

            for (Node *ptr = tail; ptr != nullptr; ptr = ptr->getPrevious())
            {
                if (ptr->getPrevious() != nullptr)
                    temp << ptr->getIndex() << ": " << ptr->getPrevious()->getStepTotal();
                else
                    temp << ptr->getIndex() << ": " << 0;
                
                switch (ptr->getOperation())
                {
                    case ADDITION: temp << "+"; break;
                    case SUBTRACTION: temp << "-"; break;
                    case MULTIPLICATION: temp << "*"; break;
                    case DIVISION: temp << "/"; break;
                }

                temp << ptr->getValue() << "=" << ptr->getStepTotal() << "\n";
            }

            return temp.str();
        }

        ~CalcList() override
        {
            Node *ptr = head;

            while (ptr != nullptr)
            {
                Node *next = ptr->getNext();
                delete ptr;
                ptr = next;
            }

            head = tail = nullptr;
        }
};

#endif