<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#stacks'>Stacks</a>
  </li> 
  <li>
    <a href='#queues'>Queues</a>
  </li> 
  <li>
    <a href='#deques'>Deques</a>
  </li> 
</ol>
</details>

## Stacks
A stack store multiple elements in order, using <em>LIFO</em>

LIFO stands for last in, first out. This means that the most recent item in the stack is on the top, meaning the top must be removed to access the second most recent item

Unlike vectors, stacks are not accessed by indices. Only the top of the stack can be accessed

To use a stack, the <code>&lt;stack&gt;</code> header file

```cpp
#include <stack>
```

### Creating a Stack
To create a stack, use the <code>stack</code> keyword, and specify the data type for which the values in the stack will be of within angle brackets<code>&lt;&gt;</code> such as in the following:

```cpp
stack<dataType> stackName;
```

The data type of a stack cannot be changed after it has been declared

### Adding Elements to a Stack
To add elements to a stack, the <code>.push()</code> function can be used after the stack has been declared such as in the following:

```cpp
stack<string> cars;

cars.push("Volvo");
cars.push("BMW");
```

### Access Stack Elements
To access the top element in a stack, the <code>.top()</code> function can be used

```cpp
stack<string> cars;

cars.push("Volvo");
cars.push("BMW");

cout << cars.top(); //output will be BMW
```

To change the top element of a stack, the following can be done:

```cpp
cars.top() = "Tesla";
```

### Remove Stack Elements
To remove the last element that was added to the stack, the <code>.pop()</code> function can be used

```cpp
stack<string> cars;

cars.push("Volvo");
cars.push("BMW");

cars.pop();

cout << cars.top(); //output will be Volvo
```

### Size of the Stack
To find out how many elements a stack has, use the <code>.size()</code> function

### Check if Stack is Empty
Use the <code>.empty</code> function to find out if a stack is empty

The <code>.empty()</code> function returns <code>1</code> if the queue is empty and <code>0</code> otherwise

<details>
    <summary>Example program</summary>
This program reverse the string called name and utilizes a stack

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    //variable declarations and initialization
    string name = "Garrett";
    stack<char> Garrett;

    //for loop which iterates over the string
    for (int i = 0; i < name.size(); i++)
        //adding first characters in string to the top of the stack
        Garrett.push(name[i]);

    //for loop which iterates over the stack
    while (!Garrett.empty())
    {
        //printing top character in the stack
        cout << Garrett.top();
        //removing the top of the stack
        Garrett.pop();
    }

    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
tterraG
      </pre>  
    </details>
  </ul>  
</details> 

<details>
    <summary>Example program</summary>
This program recursively sorts a stack without using any data structures other than the stack alone

```cpp
#include <iostream>
#include <stack>
using namespace std;

//function prototype for sort which pops each element of the stack off to get the stack ready for sorting
void sort(stack<int> *);
//function prototype for insert which sorts the stack from greatest to smallest
void insert(stack<int> *, const int *);

int main()
{
    //variable declarations and initialization
    stack<int> numbers;
    int integers = 5, input;

    cout << "Enter five integers: " << endl;

    //getting the five integers from the user and storing the results in a stack
    for (int i = 0; i < integers; i++)
    {
        cout << i + 1 << ": ";
        cin >> input;

        //adding inputs to stack
        numbers.push(input);
    }

    //calling sort function
    sort(&numbers);

    cout << "Here are your five integers sorted: ";

    //while loop which prints the user's sorted stack
    while (!numbers.empty())
    {
        cout << numbers.top() << " ";
        numbers.pop();
    }

    return 0;
}

//function definition for sort
void sort(stack<int> *numbers)
{
    int top;

    //conditional statement checking if the stack is empty; if so, return control to main
    if (numbers->empty())
        return;

    //storing top of stack in top and popping off top
    top = numbers->top();
    numbers->pop();

    //recursively calling sort to pop off the next element in stack
    sort(numbers);
    //calling insert to sort the popped off element
    insert(numbers, &top);
}

//function definition for insert
void insert(stack<int> *numbers, const int *top)
{
    int temp;

    //conditional statement checking if the stack is empty or if the top parameter is greater than the stack's current top; if so, return control to sort
    if (numbers->empty() || *top > numbers->top())
    {
        numbers->push(*top);

        return;
    }

    //storing top of stack in temporary variable and popping the top off
    temp = numbers->top();
    numbers->pop();

    //recursively calling insert 
    insert(numbers, top);

    numbers->push(temp);
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Enter five integers: 
1: <u>3</u>
2: <u>8</u>
3: <u>6</u>
4: <u>1</u>
5: <u>0</u>
0 1 6 8 3 Here are your five integers sorted: 8 6 3 1 0
      </pre>  
    </details>
  </ul>  
</details> 

<details>
    <summary>Example program</summary>
This program recursively adds an element to the stack which is located at the bottom

```cpp
#include <iostream>
#include <stack>
using namespace std;

//function prototype for addBottom which pops off the top element in the stack until the stack is empty
void addBottom(stack<int> *);
//function prototype for insertion which inserts the bottom element and pushes the top elements onto the stack
void insertion(stack<int> *, const int *);

int main()
{
    //variable declarations and initialization
    stack<int> numbers;

    //adding the integers 1, 2, and 3 to the stack
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);

    //calling the addBottom function
    addBottom(&numbers);

    return 0;
}

//function definition for addBottom
void addBottom(stack<int> *numbers)
{
    int temp;

    //conditional statement which checks if stack is empty to terminate the recursion
    if (numbers->empty())
        return;

    //temporarily storing the top of the stack and popping the top
    temp = numbers->top();
    numbers->pop();

    //calling addBottom recursively to eventually empty the stack
    addBottom(numbers);

    //calling insertion to add new bottom and rest of elements to the stack
    insertion(numbers, &temp);
}

//function definition for insertion
void insertion(stack<int> *numbers, const int *top)
{
    int input;

    //conditional statement which checks if stack is empty; if so, it inserts an input to the bottom of the stack
    if (numbers->empty())
    {
        cout << "Enter an integer at the bottom of the stack: ";
        cin >> input;

        //pushing input and top to the bottom of the stack
        numbers->push(input);
        numbers->push(*top);

        return;
    }

    numbers->push(*top);
}
```
</details> 

## Queues
A queue stores multiple items in an order following <em>FIFO</em> which stands for first in, first out. The first item to enter the queue is the first item to leave the queue

Unlike vectors, items in a queue cannot be accessed via indices. Only the items at the front and the back of the queue can be accessed

To use a queue, the following header file must be included in the program:

```cpp
#include <queue>
```

### Creating a Queue
To create a queue, the <code>queue</code> keyword is needed, along with specifying the data type of the queue and the name of the queue

```cpp
queue<dataType> queueName;
```

### Adding Elements to a Queue
To add elements to a queue, use the <code>.push()</code> function once the queue has been declared

```cpp
queue<string> cars;

cars.push("Volvo");
cars.push("BMW");
```

### Access Queue Elements
To access the front or the back items in a queue, use <code>.front()</code> and <code>.back()</code>

```cpp
stack<string> cars;

cars.push("Volvo");
cars.push("BMW");

cout << cars.front(); //output will be Volvo
cout << cars.back();  //output will be BMW
```

Because of the built in <code>.front()</code> and <code>.back()</code> functions, the front and back elements in a queue can be altered

### Remove Queue Elements
To remove the first element that was added to the stack, the <code>.pop()</code> function can be used

```cpp
queue<string> cars;

cars.push("Volvo");
cars.push("BMW");

cars.pop();

cout << cars.top(); //output will be BMW
```

### Size of the Queue
To find out how many elements a queue has, use the <code>.size()</code> function

### Check if Queue is Empty
Use the <code>.empty</code> function to find out if a queue is empty

The <code>.empty()</code> function returns <code>1</code> if the queue is empty and <code>0</code> otherwise

<details>
    <summary>Example program</summary>
This program recursively reverses a queue without using any other data structures

```cpp
#include <iostream>
#include <queue>
using namespace std;

//function prototype for reverse which reverses the queue of integers
void reverse(queue<int> *);

int main()
{
    //variable declaration and initialization
    queue<int> numbers;

    //adding integers to the queue
    numbers.push(0);
    numbers.push(1);
    numbers.push(2);

    //calling the reverse function
    reverse(&numbers);

    return 0;
}

//function definition for reverse
void reverse(queue<int> *numbers)
{
    int temp;

    //conditional statement which checks if the queue is empty; if so, the recursion terminates
    if (numbers->empty())
        return;
    
    //storing the front of the list in a temporary variable and popping the front of the queue
    temp = numbers->front();
    numbers->pop();

    //calling the reverse function recursively to reverse the queue
    reverse(numbers);

    //pushing the back of the queue to the front
    numbers->push(temp);
}
```
</details> 

## Deque
A deque is a double ended queue that is much more flexible as items can be added and removed from both ends. In addition, elements of the deque can be accessed by index number

To use a deque, the header file <code>&lt;deque&gt;</code>

```cpp
#include <deque>
```

### Creating a Deque
To create a stack, use the <code>deque</code> keyword, and specify the data type for which the values in the stack will be of within angle brackets<code>&lt;&gt;</code> such as in the following:

```cpp
deque<dataType> stackName;
```

If one wants to add items to the deque at the time of declaration, this can be done by listing the items within braces <code>{}</code>

```cpp
deque<string> cars = {"Volvo", "BMW"}
```

### Access Deque Elements
Square brackets, <code>[]</code> can be used to access a deque element by referring to the items index number

```cpp
deque<string> cars = {"Volvo", "BMW"};

cout << cars[0]; //outputs Volvo

cout << cars[1]; //outputs BMW
```

Accessing the first or the last element of a deque can be done with the <code>.front()</code> and <code>.back()</code> functions

The <code>.at()</code> function can be used to access an item in a deque at a certain index. This is an alternative over the square brackets <code>[]</code> and is often preferred because the <code>.at()</code> function will throw an error message if the element is not in range

### Change a Deque Element
To change the value of an item, referring to the item's index number is needed. Changing its value is done identically to changing the value of an element of an array; however, it is preferred to use the <code>.at()</code>

### Adding Elements to a Deque
To add elements to a deque, one can use <code>.push_front()</code> to insert an element at the beginning of the deque and <code>.push_back()</code> to add an item at the end

### Remove Deque Elements
To remove elements from a deque, use <code>.pop_front()</code> to remove an element from the beginning of the deque and <code>.pop_back()</code> to remove an element at the end

### Size of the Deque
To find out how many elements a deque has, use the <code>.size()</code> function

### Check if Deque is Empty
Use the <code>.empty</code> function to find out if a stack is empty

The <code>.empty()</code> function returns <code>1</code> if the queue is empty and <code>0</code> otherwise

<details>
    <summary>Example program</summary>
This program recursively reverses a deque without using any other data structures

```cpp
#include <iostream>
#include <deque>
using namespace std;

//function prototype for deque which reverses a deque recursively
void reverse(deque<int> *);

int main()
{
    //variable declaration and initialization
    deque<int> numbers = {1, 2, 3, 4};

    //calling reverse function
    reverse(&numbers);

    return 0;
}

//function definition for reverse
void reverse(deque<int> *numbers)
{
    int temp;

    //conditional statement which checks if deque is empty; if so, terminate the recursion
    if (numbers->empty())
        return;

    //storing the back of deque temporarily and popping that number from the deque
    temp = numbers->back();
    numbers->pop_back();

    //calling the reverse function recursively to pop off the rest of the elements
    reverse(numbers);

    //adding the elements to the deque in the reverse order
    numbers->push_front(temp);
}
```
</details> 

<details>
    <summary>Example program</summary>
This program recursively checks if a deque is a palindrome without using any other data structures

```cpp
#include <iostream>
#include <deque>
using namespace std;

//function prototype for palindromeCheck which returns 1 if the deque passed as a parameter is a palindrome; otherwise, it returns a 0
bool palindromeCheck(deque<int> *);

int main()
{
    //variable declaration and initialization
    deque<int> palindrome = {1, 2, 3, 4, 3, 2, 1};

    return 0;
}

//function definition for palindromeCheck
bool palindromeCheck(deque<int> *data)
{
    //conditional statement which checks if deque is empty to terminate recursion
    if (data->empty())
        return true;
    
    //conditional statement which checks if the front and back elements of the deque are not the same; if so, the deque is not a palindrome
    if (data->front() != data->back())
        return false;
    
    //conditional statement which checks if the size of the deque is greater than 1; if so, the deque's front and back elements are popped
    if (data->size() > 1)
    {
        data->pop_front();
        data->pop_back();
    }

    //conditional statement which checks if the size of the deque is equal to 1; if so, pop off the last element
    else if (data->size() == 1)
        data->pop_front();

    //recursively calling the function to iterate through the entire deque
    return palindromeCheck(data);
}
```
</details> 
