#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include "NotationConverterInterface.hpp"
#include <iostream>
using namespace std;

#define MAX 1000
#define GREATERPRECEDENCE 1
#define LESSPRECEDENCE 0

enum STATUS
{
    INFIX, PREFIX, POSTFIX
};

enum CHARACTER
{
    OPERAND, OPERATOR, OPEN_PAREN, CLOSE_PAREN, SPACE
};

struct Node
{
    Node *next;
    Node *previous;
    string value;

public:
    Node(const string val) : next(nullptr), previous(nullptr), value(val) {}
};

class NotationConverter
{
    Node *head;
    Node *tail;
    int count;

public:
    NotationConverter() : head(nullptr), tail(nullptr), count(0) {}
    void pushFront(const string &);
    void pushBack(const string &);
    void popFront();
    void popBack();
    string front() const;
    string back() const;
    bool empty() const;
    int size() const;
    string infixToPostfix(string inStr);
    string infixToPrefix(string inStr);
    string postfixToInfix(string inStr);
    string postfixToPrefix(string inStr);
    string prefixToInfix(string inStr);
    string prefixToPostfix(string inStr);
    ~NotationConverter();
};

string reverseStr(string);
bool validateString(string, const STATUS &);

#endif