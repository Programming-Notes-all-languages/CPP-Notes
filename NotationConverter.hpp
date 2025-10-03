#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include "NotationConverterInterface.hpp"
#include <iostream>
using namespace std;

//macro definition assigning GREATERPRECEDENCE to be a higher quantitative value compared to LESSPRECEDENCE. GREATERPRECEDENCE signifies that the operator is * or /, whereas LESSPRECEDENCE signifies that the operator is + or -
#define GREATERPRECEDENCE 1
#define LESSPRECEDENCE 0

//enum definition for STATUS which assigns an integer value for what type of statement is given, whether that be infix, prefix, or postfix
enum STATUS
{
    INFIX, PREFIX, POSTFIX
};

//enum definition for CHARACTER which assigns an integer value for what type of character is found in a statement. This helps avoid magic numbers
enum CHARACTER
{
    OPERAND, OPERATOR, OPEN_PAREN, CLOSE_PAREN, SPACE
};

//struct definition for Node which defines the interface for a doubly linked list
struct Node
{
    //Node attributes contains a pointer point to the next and previous items in the list, and the string value that each Node contains
    Node *next;
    Node *previous;
    string value;

public:
    //constructor which initializes each node of the linked list
    Node(const string val) : next(nullptr), previous(nullptr), value(val) {}
};

//class definition for NotationConverter which defines the interface for how each function is converted from its initial infix, prefix, or postfix form
class NotationConverter : public NotationConverterInterface
{
    //private attributes which store the head of the linked list, the tail, and a count 
    Node *head;
    Node *tail;
    int count;

public:
    //constructor for NotationConverter which initializes the linked list data structure
    NotationConverter() : head(nullptr), tail(nullptr), count(0) {}
    //pushing new node to the front of the deque
    void pushFront(const string &);
    //pushing new node to the back of the deque
    void pushBack(const string &);
    //removing the first element in the queue
    void popFront();
    //removing the last element in the queue
    void popBack();
    //returning the string value of the first node in the doubly linked list
    string front() const;
    //returning the string value of the last node in the doubly linked list
    string back() const;
    //returns a boolean value of whether the linked list is empty, if so, it returns true; otherwise, it returns false
    bool empty() const;
    //returns the current number of total nodes in the linked list
    int size() const;
    //converts an infix expression to a postfix expression
    string infixToPostfix(string inStr) override; 
    //converts an infix expression to a prefix expression
    string infixToPrefix(string inStr) override;
    //converts a postfix expression to an infix expression
    string postfixToInfix(string inStr) override;
    //converts a postfix expression to a prefix expression
    string postfixToPrefix(string inStr) override;
    //converts a prefix expression to an infix expression
    string prefixToInfix(string inStr) override;
    //converts a prefix expression to a postfix expression
    string prefixToPostfix(string inStr) override;
    //destructor to free the doubly linked list from memory
    ~NotationConverter();
};

//function declaration for reverseStr which reverses the contents of the string passed in as a parameter
string reverseStr(string);
//function definition for validateString which checks if the string expression is valid or not. it returns true if it is valid and otherwise false
bool validateString(string, const STATUS &);

#endif