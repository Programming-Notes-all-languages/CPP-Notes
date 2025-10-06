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

//method for returning the string value of the tail node
string NotationConverter::back() const
{
    //checking if the linked list is empty; if so, throw an error
    if (head == nullptr)
        throw runtime_error("Queue is empty");

    //returning the string value of the tail node
    return tail->value;
}

//method for returning a boolean value about if the linked list is empty or not
bool NotationConverter::empty() const
{
    //checking if the linked list is empty; if so, return true indicating the list is empty
    if (head == nullptr)
        return true;

    return false;
}

//method for returning the total number of nodes in the linked list
int NotationConverter::size() const
{
    return this->count;
}

//destructor that frees the nodes from the list from memory
NotationConverter::~NotationConverter()
{
    //assigning current to point to the head of the list
    Node *current = head;

    //while loop which iterates until the list is empty
    while (current != nullptr)
    {
        //assigning next to point to the next node after current
        Node *next = current->next;
        //deleting current
        delete current;
        //assign current to point to the next node to continue with the deletion
        current = next;
    }
    
    //having head and tail point to nullptr to avoid dangling pointer
    head = tail = nullptr;
}

//method for converting infix expression to postfix expression
string NotationConverter::infixToPostfix(string inStr)
{
    //variable declarations
    string output;
    bool precedenceStr, precedenceStack;

    //while loop which frees all the nodes in the list
    while (!this->empty())
        this->popBack();

    //calling validateString function which ensures the input string contains valid characters; otherwise, an error is thrown
    if (!validateString(inStr, INFIX))
        throw runtime_error("Invalid input string");

    //for loop which iterates through the string
    for (size_t i = 0; i < inStr.size(); i++)
    {
        //if the character at index i is a whitespace, iterate back to the top of the loop
        if (inStr[i] == ' ')
            continue;

        //if the character at index i is an operand, add the character to the output string
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            output += string(1, inStr[i]) + " ";

        //otherwise, if the character at index i is a left parenthesis, add the character to the linked list
        else if (inStr[i] == '(')
            this->pushBack("(");

        //otherwise, if the character at index i is a right parenthesis, loop through the linked list, starting from the tail, until a left parenthesis is found. Add each character in the list to the output string and pop the last element from the stack. The loop will terminate if the list is empty or if the left parentheseis is found
        else if (inStr[i] == ')')
        {
            //loopint through the linked list, starting from the tail, until a left parenthesis is found. Add each character in the list to the output string and pop the last element from the stack. The loop will terminate if the list is empty or if the left parentheseis is found
            while(!this->empty() && this->back() != "(")
            {
                output += this->back() + " ";
                this->popBack();
            }

            //this will remove the left parenthesis character from the linked list
            if (!this->empty())
                this->popBack();
        }

        //otherwise, if the character at index i is an operation, compare the precedence of the current character to that at the back of the linked list
        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            //setting the precedence of the string character to 1 if the operator is * or /; otherwise, the precedence is set to 0
            precedenceStr = (inStr[i] == '*' || inStr[i] == '/') ? GREATERPRECEDENCE : LESSPRECEDENCE;
            
            //while loop which iterates from the tail of the linked list until a left parenthesis character is found, or until the list is empty
            while (!this->empty() && this->back() != "(")
            {
                //setting the precedence of the stack element to 1 if the operator is * or /; otherwise, the precedence is set to 0
                precedenceStack = (this->back() == "*" || this->back() == "/") ? GREATERPRECEDENCE : LESSPRECEDENCE;
                
                //exit from the loop if the precedence of the character at index i in the string is greater than the precedence of the element in the stack, meaning the operator of the string character is * or /
                if (precedenceStr > precedenceStack)
                    break;

                //appending the last element of the linked list to the string output and popping the last element of the list
                output += this->back() + " ";
                this->popBack();
            }

            //adding the character at index i to the back of the linked list
            this->pushBack(string(1, inStr[i]));
        }
    }

    //while loop which iterates until the linked list is empty
    while (!this->empty())
    {
        //appending the last element of the linked list to the output string and popping that element
        output += this->back() + " ";
        this->popBack();
    }

    //removing the trailing whitespace from the end of the output string
    if (!output.empty() && output.back() == ' ')
        output.pop_back();

    return output;
}

//method for converting infix expression to prefix expression
string NotationConverter::infixToPrefix(string inStr)
{
    //variable declarations
    string reversed, postfix;

    //emptying the stack until it is emtpy
    while (!this->empty())
        this->popBack();
    
    //calling validateString function and checking to ensure that the input string contains only valid characters; otherwise, throw an error
    if (!validateString(inStr, INFIX))
        throw runtime_error("Invalid input string");

    //reverse the valid input string and convert the reverse string to its postfix version
    reversed = reverseStr(inStr);
    postfix = infixToPostfix(reversed);

    //reverse the postfix expression to get the prefix expression
    return reverseStr(postfix);
}

//method for converting postfix expression to infix expression
string NotationConverter::postfixToInfix(string inStr)
{
    //variable declarations
    string output, rightOperand, leftOperand;

    //while loop which empties the linked list
    while (!this->empty())
        this->popBack();

    //calling validateString to ensure the intput string is valid
    if (!validateString(inStr, POSTFIX))
        throw runtime_error("Invalid input string");

    //for loop which iterates over each character in the string
    for (size_t i = 0; i < inStr.size(); i++)
    {
        //checking if the character is an operand; if so, add the operand to the end of the linked list
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            this->pushBack(string(1, inStr[i]));
    
        //otherwise, if the character is an operator
        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            //if the linked list is not empty
            if (!this->empty())
            {
                //store the right operand with the last element of the list, then pop the last element of the linked list
                rightOperand = this->back();
                this->popBack();

                //store the left operand with the last element of the list, then pop the last element of the linked list
                leftOperand = this->back();
                this->popBack();
            }

            //push the string shown below to the last element of the linked list
            this->pushBack("(" + leftOperand + " " + string(1, inStr[i]) + " " + rightOperand + ")");
        }
    }

    //while loop which iterates until the linked list is empty
    while (!this->empty())
    {
        //append each element of the list to the output string, then pop the last item of the linked list
        output += this->back();
        this->popBack();
    }

    return output;
}

//method for converting postfix expression to a prefix expression
string NotationConverter::postfixToPrefix(string inStr)
{
    //variable declarations
    string rightOperand, leftOperand;

    //while loop which iterates until the lined list is empty
    while (!this->empty())
        this->popBack();
    
    //calling validateString function to ensure the input string is valid; otherwise, throw an error
    if (!validateString(inStr, POSTFIX))
        throw runtime_error("Invalid input string");

    //for loop which iterates over each character in the string
    for (size_t i = 0; i < inStr.size(); i++)
    {
        //if the character is an operand, add the character to the back of the linked list
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            this->pushBack(string(1, inStr[i]));
        
        //otherwise, if the character is an operator
        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            //if the linked list is not empty
            if (!this->empty())
            {
                //store the back element of the linked list to the rightOperand variable, then pop the back element from the list
                rightOperand = this->back();
                this->popBack();

                //store the back element of the linked list to the leftOperand variable, then pop the back element from the list
                leftOperand = this->back();
                this->popBack();
            }

            //push the string shown below to the back of the linked list
            this->pushBack(string(1, inStr[i]) + " " + leftOperand + " " + rightOperand);
        }
    }

    return this->back();
}

//method for converting prefix expression to an infix expression
string NotationConverter::prefixToInfix(string inStr)
{
    //variable declarations
    string rightOperand, leftOperand, output, reversed = reverseStr(inStr);

    //while loop which removes each element from the linked list
    while (!this->empty())
        this->popBack();

    //calling validateString function to ensure that the input string is valid; otherwise, throw an error
    if (!validateString(inStr, PREFIX))
        throw runtime_error("Invalid input string");

    //for loop which iterates over each character in the input string
    for (size_t i = 0; i < reversed.size(); i++)
    {
        //if the character in the reversed string is an operand, add the character to the back of the linked list
        if ((reversed[i] >= 'a' && reversed[i] <= 'z') || (reversed[i] >= 'A' && reversed[i] <= 'Z'))
            this->pushBack(string(1, reversed[i]));

        //otherwise, if the character in the reversed string is an operator
        else if (reversed[i] == '*' || reversed[i] == '/' || reversed[i] == '-' || reversed[i] == '+')
        {
            //if the linked list is not empty
            if (!this->empty())
            {
                //store the last element of the linked list into the leftOperand variable and pop the last element of the linked list
                leftOperand = this->back();
                this->popBack();

                //store the last element of the linked list into the rightOperand variable and pop the last element of the linked list
                rightOperand = this->back();
                this->popBack();
            }

            //push the following string to the back of the linked list
            this->pushBack("(" + leftOperand + " " + string(1, reversed[i]) + " " + rightOperand + ")");
        }
    }

    //while loop which iterates until the list is empty
    while (!this->empty())
    {
        //appended the last element of the linked list to the output string and pop the last element of the list
        output += this->back() + " ";
        this->popBack();
    }

    //trim the trialing whitespace, if any, from the output string
    if (!output.empty() && output.back() == ' ')
        output.pop_back();

    return output;
}

//method to convert prefix expression to a postfix expression
string NotationConverter::prefixToPostfix(string inStr)
{
    //variable declarations
    string rightOperand, leftOperand;

    //while loop which iterates until the list is empty and removes each element of the linked list
    while (!this->empty())
        this->popBack();
    
    //calling validateString function to ensure the input string is valid; if it is not valid, an error is thrown
    if (!validateString(inStr, PREFIX))
        throw runtime_error("Invalid input string");

    //for loop which iterates through each character of the string
    for (size_t i = inStr.size(); i-- > 0;)
    {
        //if the character is an operand, add the operand character to the end of the linked list
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            this->pushBack(string(1, inStr[i]));
        
        //otherwise, if the character is an operator
        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
        {
            //if the linked list is not empty
            if (!this->empty())
            {
                //the leftOperand stores the last element in the linked list which is then popped
                leftOperand = this->back();
                this->popBack();

                //the rightOperand stores the last element in the linked list which is then popped
                rightOperand = this->back();
                this->popBack();
            }

            //push the following string to the end of the linked list
            this->pushBack(leftOperand + " " + rightOperand + " " + string(1, inStr[i]) );
        }
    }

    return this->back();
}

//function definition for reverseStr which reverses the string given as a parameter
string reverseStr(string inStr)
{
    //variable declaration
    string reverse;

    //for loop which iterates over each character in the string and appends each character to a new string called reverse
    for (int i = static_cast<int>(inStr.size()) - 1; i >= 0; i--)
        reverse += inStr[i];
    
    //for loop which iterates over each character in the string and reverses the parentheses
    for (size_t i = 0; i < reverse.size(); i++)
    {
        //if the current character is a left parenthesis, change it to a right parenthesis
        if (reverse[i] == '(')
            reverse[i] = ')';
        //otherwise, if the current character is a right parenthesis, change it to a left parenthesis
        else if (reverse[i] == ')')
            reverse[i] = '(';
    }

    return reverse;
}

//function definition for validateString which returns a boolean value indicating the validity of the string passed in as a parameter
bool validateString(string inStr, const STATUS &status)
{
    //variable declarations and initializations
    char previous = '\0', current;
    int parenthesesCount = 0, prePostCount = 0;
    bool firstCharacter = true;

    //for loop which iterates over the entire string passed as a parameter
    for (size_t i = 0; i < inStr.size(); i++)
    {
        //if the current character is a whitespace, skip this loop iteration
        if (inStr[i] == ' ')
            continue;
        
        //otherwise, if the current character is an operand, skip this loop iteration
        else if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
            continue;
        
        //otherwise, if the current character is an operator, skip this loop iteration
        else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
            continue;

        //if the current character is a parentheses and the expression is in infix style, skip this loop iteration
        if (status == INFIX && (inStr[i] == '(' || inStr[i] == ')'))
            continue;
        
        //if none of the conditions were met above, have the function return false to indicate that the expression is invalid
        return false;
    }

    //switch statement which will bring the compiler to the case that is associated with the expression type of the input string
    switch (status)
    {
        //INFIX case for expressions in the infix style
        case INFIX:
            //for loop which iterates over each character of the string
            for (size_t i = 0; i < inStr.size(); i++)
            {
                //if the current character is a whitespace, skip this loop iteration
                if (inStr[i] == ' ')
                    continue;

                //otherwise, if the current character is an operator, set current to an enum OPERATOR
                else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
                    current = OPERATOR;

                //otherwise, if the current character is a left parenthesis, set current to the OPEN_PAREN enum and increment the parentheses count
                else if (inStr[i] == '(')
                {
                    current = OPEN_PAREN;
                    parenthesesCount++;
                }

                //otherwise, if the current character is the right parenthesis, set current to CLOSE_PAREN enum and decrement the parentheses count
                else if (inStr[i] == ')')
                {
                    current = CLOSE_PAREN;
                    parenthesesCount--;

                    //if the number of parentheses ever gets negative, the string is invalid
                    if (parenthesesCount < 0)
                        return false;
                }

                //otherwise, the current character is an operand and assigns current to OPERAND
                else
                    current = OPERAND;
                
                //if the first character has not been evaluated yet
                if (firstCharacter)
                {
                    //if the current first character is not equal to an open parenthesis and is not an operand, the string is invalid
                    if (current != OPEN_PAREN && current != OPERAND)
                        return false;

                    //otherwise, the first character is valid and now the first character has been evaluated
                    firstCharacter = false;
                }

                //otherwise if the first character has been evaluated
                else
                    //switch statement with cases dependent on the type of character current is set to
                    switch (current)
                    {
                        //case in which the current character is an operator
                        case OPERATOR:
                            //if the prior character was an operator or and open parenthesis, the string is invalid
                            if (previous == OPERATOR || previous == OPEN_PAREN)
                                return false;
                            break;
                        
                        //case in which the current character is an operand
                        case OPERAND:
                            //if the prior character was an operand or a closed parenthesis, the string is invalid
                            if (previous == OPERAND || previous == CLOSE_PAREN)
                                return false;
                            break;

                        //case in which the current character is an open parenthesis
                        case OPEN_PAREN:
                            //if the prior character was a closed parenthesis or an operand, the string is invalid
                            if (previous == CLOSE_PAREN || previous == OPERAND)
                                return false;
                            break;
                        
                        //case in which the current character is a closed parenthesis
                        case CLOSE_PAREN:
                            //if the prior character was an open parenthesis, the string is invalid
                            if (previous == OPEN_PAREN)
                                return false;
                            break;
                    }

                //set previous to be the current character in preparation for the next iteration of the loop
                previous = current;
            }
            
            //if the parentheses total is anything other than zero after each character of the string has been evaluated, the string is invalid
            if (parenthesesCount > 0)
                return false;
            
            //if the last character of the expression was an operator or an open parenthesis, the string is invalid
            if (previous == OPERATOR || previous == OPEN_PAREN)
                return false;

            break;
        
        //case in which the expression is in postfix form
        case POSTFIX:
            //for loop iterating over each character of the string
            for (size_t i = 0; i < inStr.size(); i++)
            {
                //if the current character is a whitespace, skip this iteration
                if (inStr[i] == ' ')
                    continue;

                //otherwise, if the current character is an operator, assign current to be an operator and decrement the counter that counts the number of operands
                else if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
                {
                    current = OPERATOR;
                    prePostCount--;

                    //if the number of operands at this stage of the expression is less than one, the string is invalid
                    if (prePostCount < 1)
                        return false;
                }
                
                //otherwise, if the current character is an operand, assign current to be an operator and increment the counter that counts the number of operands
                else if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z'))
                {
                    current = OPERAND;
                    prePostCount++;
                }
                
                //otherwise, an invalid character has been stumbled upon and the string is invalid
                else
                    return false;

            }

            //if the number of operands minus the number of operators is not equal to one at the end of the iterations, the expression is invalid
            if (prePostCount != 1)
                return false;

            break;
        
        //case in which the expression is in prefix form
        case PREFIX:
            //for loop which iterates through each character in the string
            for (size_t i = inStr.size(); i-- > 0;)
            {
                //if the current character is an operator, assign current to OPERATOR and decrement the operand counter
                if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '-' || inStr[i] == '+')
                {
                    current = OPERATOR;
                    prePostCount--;
                }
                
                //otherwise, if the current character is a whitespace, the character is an operand and the operand count will be incremented
                else if (inStr[i] != ' ')
                {
                    current = OPERAND;
                    prePostCount++;
                }
                
                else
                    continue;
                
                //if the number of operands is less than one at any point, the string is invalid
                if (prePostCount < 1)
                    return false;

                //if the first character is an operand, the string is invalid
                if (i == 0 && current == OPERAND)
                    return false;
                
                //if the last character is an operand, the string is invalid
                if (i == inStr.size() - 1 && current == OPERATOR)
                    return false;
            }

            //if the number of operands is not equal to one after the string's evaluation, the string is invalid
            if (prePostCount != 1)
                return false;

            break;
    }
    
    return true;
}