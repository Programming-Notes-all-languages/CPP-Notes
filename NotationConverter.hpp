#include <iostream>
using namespace std;

#define MAX 1000
#define GREATERPRECEDENCE 1
#define LESSPRECEDENCE 0

enum STATUS
{
    INFIX, PREFIX, POSTFIX
};

struct Node
{
    Node *next;
    Node *previous;
    string value;

public:
    Node(const string val) : next(nullptr), previous(nullptr), value(val) {}
};

class Deque
{
    Node *head;
    Node *tail;
    int count;

public:
    Deque() : head(nullptr), tail(nullptr), count(0) {}
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
    ~Deque();
};

int main()
{
    cout <<"dlfk";
    return 0;
}

void Deque::pushFront(const string &value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }

    this->count++;
}

void Deque::pushBack(const string &value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }

    this->count++;
}

void Deque::popFront()
{
    if (head == nullptr)
        return;

    if (head->next != nullptr)
    {
        Node *ptr = head->next;
        ptr->previous = nullptr;
        delete head;
        head = ptr;
    }

    else
    {
        delete head;
        head = tail = nullptr;
    }

    this->count--;
}

void Deque::popBack()
{
    if (tail == nullptr)
        return;

    if (tail->previous != nullptr)
    {
        Node *ptr = tail->previous;
        ptr->next = nullptr;
        delete tail;
        tail = ptr;
    }

    else
    {
        delete tail;
        head = tail = nullptr;
    }

    this->count--;
}

string Deque::front() const
{
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    return head->value;
}

string Deque::back() const
{
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    return tail->value;
}

bool Deque::empty() const
{
    if (head == nullptr)
        return true;

    return false;
}

int Deque::size() const
{
    return this->count;
}

Deque::~Deque()
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = tail = nullptr;
}

string Deque::infixToPostfix(string inStr)
{
    string output;
    bool precedenceStr, precedenceStack;

    for (int i = 0; i < inStr.size(); i++)
    {
        if (inStr[i] >= 'a' && inStr[i] <= 'z' || inStr[i] >= 'A' && inStr[i] <= 'Z')
            output += inStr[i] + " ";

        else if (inStr[i] == '(')
            this->pushBack("(");

        else if (inStr[i] == ')')
        {
            while(this->back() != "(")
            {
                output += this->back() + " ";
                this->popBack();
            }

            if (!this->empty())
                this->popBack();
        }

        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            if (!this->empty())
            {
                precedenceStr = (inStr[i] == '*' || inStr[i] == '/') ? GREATERPRECEDENCE : LESSPRECEDENCE;

                precedenceStack = (this->back() == "*" || this->back() == "/") ? GREATERPRECEDENCE : LESSPRECEDENCE;
                
                while (!this->empty() && precedenceStack >= precedenceStr)
                {
                    output += this->back() + " ";
                    this->popBack();

                    if (!this->empty())
                        precedenceStack = (this->back() == "*" || this->back() == "/") ? GREATERPRECEDENCE : LESSPRECEDENCE;
                }
            }

            this->pushBack(string(1, inStr[i]));
        }
    }

    while (!this->empty())
    {
        output += this->back() + " ";
        this->popBack();
    }

    return output;
}

string Deque::infixToPrefix(string inStr)
{
    return reverseStr(this->infixToPostfix(reverseStr(inStr)));
}

string Deque::postfixToInfix(string inStr)
{
    string output, rightOperand, leftOperand;

    for (int i = 0; i < inStr.size(); i++)
    {
        if (inStr[i] >= 'a' && inStr[i] <= 'z' || inStr[i] >= 'A' && inStr[i] <= 'Z')
            this->pushBack(string(1, inStr[i]));

        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            if (!this->empty())
            {
                rightOperand = this->back();
                this->popBack();

                leftOperand = this->back();
                this->popBack();
            }

            this->pushBack("(" + leftOperand + string(1, inStr[i]) + rightOperand + ")");
        }
    }

    while (!this->empty())
    {
        output += this->back();
        this->popBack();
    }

    return output;
}

string Deque::postfixToPrefix(string inStr)
{
    return infixToPrefix(postfixToInfix(inStr));
}

string Deque::prefixToInfix(string inStr)
{
    string rightOperand, leftOperand, output, reversed = reverseStr(inStr);

    for (int i = 0; i < reversed.size(); i++)
    {
        if (reversed[i] >= 'a' && reversed[i] <= 'z' || reversed[i] >= 'A' && reversed[i] <= 'Z')
            this->pushBack(string(1, reversed[i]));

        else if (reversed[i] == '*' || reversed[i] == '/' || reversed[i] == '-' || reversed[i] == '+')
        {
            if (!this->empty())
            {
                leftOperand = this->back();
                this->popBack();

                rightOperand = this->back();
                this->popBack();
            }

            this->pushBack("(" + leftOperand + " " + string(1, reversed[i]) + " " + rightOperand + ")");
        }
    }

    while (!this->empty())
    {
        output += this->back() + " ";
        this->popBack();
    }

    return output;
}

string Deque::prefixToPostfix(string inStr)
{
    return infixToPostfix(prefixToInfix(inStr));
}

string reverseStr(string inStr)
{
    string reverse;

    for (int i = inStr.size() - 1; i >= 0; i--)
        reverse += inStr[i];
    
    for (int i = 0; i < reverse.size(); i++)
    {
        if (reverse[i] == '(')
            reverse[i] = ')';
        else if (reverse[i] == ')')
            reverse[i] = '(';
    }

    return reverse;
}

bool validateString(string inStr, const STATUS &status)
{
    string valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+-*/ ()";

    switch (status)
    {
        case INFIX: break;
        case PREFIX: case POSTFIX: valid = valid.substr(0, valid.size() - 2); break;
    }

    for (int i = 0; i < inStr.size(); i++)
        for (int j = 0; j < valid.size(); j++)
        {
            if (inStr[i] == valid[j])
                break;
            else if (j + 1 == valid.size())
                return false;
        }
    
    return true;
}