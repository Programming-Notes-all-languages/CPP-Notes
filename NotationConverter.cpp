#include "NotationConverter.hpp"
#include <iostream>
using namespace std;

void NotationConverter::pushFront(const string &value)
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

void NotationConverter::pushBack(const string &value)
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

void NotationConverter::popFront()
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

void NotationConverter::popBack()
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

string NotationConverter::front() const
{
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    return head->value;
}

string NotationConverter::back() const
{
    if (head == nullptr)
        throw runtime_error("Queue is empty");

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