#include "NotationConverter.hpp"
#include <iostream>
using namespace std;

//method for pushing new item to the back of the linked list
void NotationConverter::pushFront(const string &value)
{
    //instantiating new node
    Node *newNode = new Node(value);

    //checking if the linked list is empty; if so, have the head and tail pointers point to the newly created node
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    //if the linked list has at least one node, add the new node to the beginning of the linked list
    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }

    //increment the total node count by one to account for the newly inserted node
    this->count++;
}

//method for pushing new item the back of the linked list
void NotationConverter::pushBack(const string &value)
{
    //instantiating new node
    Node *newNode = new Node(value);

    //checking if the linked list is empty; if so, have the head and tail pointers point to the newly created node
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    //if the linked list has at least one node, add the new node to the end of the linked list
    else
    {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }

    //increment the total node count by one to account for the newly inserted node    
    this->count++;
}

//method for removing the head of the linked list
void NotationConverter::popFront()
{
    //checking if the linked list is empty; if so, do nothing since there is no node to remove
    if (head == nullptr)
        return;

    //checking if the the linked list has more than one node; if so, remove the head node and assign the head pointer to point to the node right after head
    if (head->next != nullptr)
    {
        Node *ptr = head->next;
        ptr->previous = nullptr;
        delete head;
        head = ptr;
    }

    //if the linked list only has one node, delete the head pointer, which is also the tail pointer, and have head and tail point to nullptr to leave no dangling pointers
    else
    {
        delete head;
        head = tail = nullptr;
    }

    //decrement the count of the total number of nodes in the list by one
    this->count--;
}

//method for removing the last element in the linked list
void NotationConverter::popBack()
{
    //checking if the linked list has no nodes; if so, do nothing as there is no node to remove
    if (tail == nullptr)
        return;

    //checking if the linked list has more than one node; if so, remove the tail pointer from memory and assign the node just before the existing tail to be the new tail
    if (tail->previous != nullptr)
    {
        Node *ptr = tail->previous;
        ptr->next = nullptr;
        delete tail;
        tail = ptr;
    }

    //if the linked list has only one node; remove the tail node, which is also the head node, and set head and tail to point to nullptr to leave no dangling pointers
    else
    {
        delete tail;
        head = tail = nullptr;
    }

    //decrement the count of the total number of nodes in the list by one
    this->count--;
}

//method for returning the string value of the head node
string NotationConverter::front() const
{
    //checking if the linked list is empty; if so, throw an error
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    //returning the string value of the head node
    return head->value;
}

string NotationConverter::back() const
{
    //checking if the linked list is empty; if so, throw an error
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    //returning the string value of the tail node
    return tail->value;
}

bool NotationConverter::empty() const
{
    if (head == nullptr)
        return true;

    return false;
}

int NotationConverter::size() const
{
    return this->count;
}

NotationConverter::~NotationConverter()
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

string NotationConverter::infixToPostfix(string inStr)
{
    string output;
    bool precedenceStr, precedenceStack;

    while (!this->empty())
        this->popBack();

    if (!validateString(inStr, INFIX))
        throw runtime_error("Invalid input string");

    for (size_t i = 0; i < inStr.size(); i++)
    {
        if (inStr[i] == ' ')
            continue;

        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            output += string(1, inStr[i]) + " ";

        else if (inStr[i] == '(')
            this->pushBack("(");

        else if (inStr[i] == ')')
        {
            while(!this->empty() && this->back() != "(")
            {
                output += this->back() + " ";
                this->popBack();
            }

            if (!this->empty())
                this->popBack();
        }

        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            precedenceStr = (inStr[i] == '*' || inStr[i] == '/') ? GREATERPRECEDENCE : LESSPRECEDENCE;
                
            while (!this->empty() && this->back() != "(")
            {
                precedenceStack = (this->back() == "*" || this->back() == "/") ? GREATERPRECEDENCE : LESSPRECEDENCE;
                
                if (precedenceStr > precedenceStack)
                    break;

                output += this->back() + " ";
                this->popBack();
            }

            this->pushBack(string(1, inStr[i]));
        }
    }

    while (!this->empty())
    {
        output += this->back() + " ";
        this->popBack();
    }

    if (!output.empty() && output.back() == ' ')
        output.pop_back();

    return output;
}

string NotationConverter::infixToPrefix(string inStr)
{
    while (!this->empty())
        this->popBack();
    
    if (!validateString(inStr, INFIX))
        throw runtime_error("Invalid input string");

    string reversed = reverseStr(inStr);

    // Convert to postfix
    string postfix = infixToPostfix(reversed);

    // Reverse postfix to get prefix
    return reverseStr(postfix);
}

string NotationConverter::postfixToInfix(string inStr)
{
    string output, rightOperand, leftOperand;

    while (!this->empty())
        this->popBack();

    if (!validateString(inStr, POSTFIX))
        throw runtime_error("Invalid input string");

    for (size_t i = 0; i < inStr.size(); i++)
    {
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
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

            this->pushBack("(" + leftOperand + " " + string(1, inStr[i]) + " " + rightOperand + ")");
        }
    }

    while (!this->empty())
    {
        output += this->back();
        this->popBack();
    }

    return output;
}

string NotationConverter::postfixToPrefix(string inStr)
{
    string rightOperand, leftOperand;

    while (!this->empty())
        this->popBack();
    
    if (!validateString(inStr, POSTFIX))
        throw runtime_error("Invalid input string");

    for (size_t i = 0; i < inStr.size(); i++)
    {
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
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

            this->pushBack(string(1, inStr[i]) + " " + leftOperand + " " + rightOperand);
        }
    }

    return this->back();
}

string NotationConverter::prefixToInfix(string inStr)
{
    string rightOperand, leftOperand, output, reversed = reverseStr(inStr);

    while (!this->empty())
        this->popBack();

    if (!validateString(inStr, PREFIX))
        throw runtime_error("Invalid input string");

    for (size_t i = 0; i < reversed.size(); i++)
    {
        if ((reversed[i] >= 'a' && reversed[i] <= 'z') || (reversed[i] >= 'A' && reversed[i] <= 'Z'))
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

    if (!output.empty() && output.back() == ' ')
        output.pop_back();

    return output;
}

string NotationConverter::prefixToPostfix(string inStr)
{
    string rightOperand, leftOperand;

    while (!this->empty())
        this->popBack();
    
    if (!validateString(inStr, PREFIX))
        throw runtime_error("Invalid input string");

    for (size_t i = inStr.size(); i-- > 0;)
    {
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            this->pushBack(string(1, inStr[i]));
        
        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            if (!this->empty())
            {
                leftOperand = this->back();
                this->popBack();

                rightOperand = this->back();
                this->popBack();
            }

            this->pushBack(leftOperand + " " + rightOperand + " " + string(1, inStr[i]) );
        }
    }

    return this->back();
}

string reverseStr(string inStr)
{
    string reverse;

    for (int i = static_cast<int>(inStr.size()) - 1; i >= 0; i--)
        reverse += inStr[i];
    
    for (size_t i = 0; i < reverse.size(); i++)
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
    char previous = '\0', current;
    int parenthesesCount = 0, prePostCount = 0;
    bool firstCharacter = true;

    for (size_t i = 0; i < inStr.size(); i++)
    {
        if (inStr[i] == ' ')
            continue;
        
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            continue;
        
        if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
            continue;

        if (status == INFIX && (inStr[i] == '(' || inStr[i] == ')'))
            continue;
        
        return false;
    }

    switch (status)
    {
        case INFIX:
            for (size_t i = 0; i < inStr.size(); i++)
            {
                if (inStr[i] == ' ')
                    continue;

                if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
                    current = OPERATOR;

                else if (inStr[i] == '(')
                {
                    current = OPEN_PAREN;
                    parenthesesCount++;
                }

                else if (inStr[i] == ')')
                {
                    current = CLOSE_PAREN;
                    parenthesesCount--;

                    if (parenthesesCount < 0)
                        return false;
                }

                else
                    current = OPERAND;
                
                if (firstCharacter)
                {
                    if (current != OPEN_PAREN && current != OPERAND)
                        return false;

                    firstCharacter = false;
                }

                else
                    switch (current)
                    {
                        case OPERATOR:
                            if (previous == OPERATOR || previous == OPEN_PAREN)
                                return false;
                            break;
                        
                        case OPERAND:
                            if (previous == OPERAND || previous == CLOSE_PAREN)
                                return false;
                            break;

                        case OPEN_PAREN:
                            if (previous == CLOSE_PAREN || previous == OPERAND)
                                return false;
                            break;
                        
                        case CLOSE_PAREN:
                            if (previous == OPEN_PAREN)
                                return false;
                            break;
                    }

                previous = current;
            }
            
            if (parenthesesCount > 0)
                return false;
            
            if (previous == OPERATOR || previous == OPEN_PAREN)
                return false;

            break;
        
        case POSTFIX:
            for (size_t i = 0; i < inStr.size(); i++)
            {
                if (inStr[i] == ' ')
                    continue;

                if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
                {
                    current = OPERATOR;
                    prePostCount--;

                    if (prePostCount < 1)
                        return false;
                }
                
                else if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
                {
                    current = OPERAND;
                    prePostCount++;
                }
                
                else
                    return false;

            }

            if (prePostCount != 1)
                return false;

            break;
        
        case PREFIX:
            for (size_t i = inStr.size(); i-- > 0;)
            {
                if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
                {
                    current = OPERATOR;
                    prePostCount--;
                }
                
                else if (inStr[i] != ' ')
                {
                    current = OPERAND;
                    prePostCount++;
                }
                
                else
                    continue;
                
                if (prePostCount < 1)
                    return false;

                if (i == 0 && current == OPERAND)
                    return false;
                
                if (i == inStr.size() - 1 && current == OPERATOR)
                    return false;
            }

            if (prePostCount != 1)
                return false;

            break;
    }
    
    return true;
}