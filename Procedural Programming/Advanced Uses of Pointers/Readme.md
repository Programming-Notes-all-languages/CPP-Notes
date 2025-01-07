<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#dynamic-storage-allocation'>Dynamic Storage Allocation</a>
  </li>    
  <li>
    <a href='#dynamically-allocated-strings'>Dynamically Allocated Strings</a>
  </li>    
  <li>
    <a href='#dynamically-allocated-arrays'>Dynamically Allocated Arrays</a>
  </li>  
  <li>
    <a href='#deallocating-storage'>Deallocating Storage</a>
  </li>  
  <li>
    <a href='#linked-lists'>Linked Lists</a>
  </li>  
  <li>
    <a href='#function-pointers'>Function Pointers</a>
  </li>  
</ol>
</details>

## Dynamic Storage Allocation
### Memory Allocation Functions
<ul>
  <li>C++ allows for dynamically allocated memory management through the following operators: new and delete
    <ul>
      <li>The new operator allocates memory for an object and it automatically initializes the dynamically allocated memory. In C, the malloc function just allocates enough memory but does not initialize the memory
        <ul>
          <li>To allocate memory for a single object of type int, the following declaration can be made: <code>int *ptr = new int; //allocated memory for a single integer</code></li>
          <li>To dynamically allocate memory and initialize a single object of type int, the following declaration can be made: <code>int *ptr = new int(5); //allocates memory for a single integer and initializes it to the value 5</code></li>
          <li>To dynamically allocate memory for an array, the following declaration can be made: <code>int *arr = new int[10]; //allocates memory for an array of 10 integers</code></li>
        </ul>  
      <li>The delete operator deallocates memory that was dynamically allocated using new
        <ul>
          <li>To free a single dynamically allocated object, the following can be done: <code>delete ptr;</code></li>
          <li>To free a dynamically allocated array, the following can be done: <code>delete[] array;</code></li>
        </ul>
      </li>    
    </ul>  
  <li>To allocate storage dynamically, one of the three following functions needs to be called within the stdlib.h header:
    <ul>
      <li>malloc: allocates a block of memory but does not initialize it</li>
      <li>calloc: allocates a block of memory and clears it</li>
      <li>realloc: resizes a previously allocated block of memory</li>
    </ul>
  </li>
  <details>
    <summary>Example Program</summary>

```cpp
//Suppose you have just opened the file text.txt and execute the statements shown below:
char buffer[6];
ifstream inFile("text.txt");

inFile >> buffer;
cout << buffer;

//File text.txt consists of a single line of text:
The quick brown fox jumped over the lazy dogs back.
//What will be the output from the printf?
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
        The
        </code>
      </pre>        
    </details>
    </ul>  
  </details> 
</ul>    
  <details>
    <summary>Example Program</summary>

```cpp
//Write a statement that declares a dynamic allocated array a of integers of size n using the new operator
```  
<ul>
  <details>

```c
int *a = new int[n];
```       
  </details>
    </ul>  
  </details>  
</ul>       

### Null Pointers
<ul>
  <li>When one of the above memory allocation functions is called, there is always a possibility that the compiler will not be able to allocate a block of memory. If this is the case, the function will return a <em>null pointer</em>. A null pointer is a pointer that points to nothing</li>  
  <li>To test if the memory allocation function returned a value other than null, the following can be used:

```c 
int *array, size = 10;
array = malloc(size * sizeof(int));

if (array == NULL)
    printf("Memory allocation function failed\n");
```
  </li>
  <li>When dynamically allocating memory for variables using new, there is no need to check for NULL since new will throw an error message if the memory allocation function failed</li>
</ul>

## Dynamically Allocated Strings
<ul>
  <li>To allocate space in memory for a C string with n characters and store it in a variable of type char *, the following declaration can be made: <code>char *str = new char[n];</code></li>
  <li>To allocate space in memory for a C++ string with n characters and store it in a variable of type string, the following declaration can be made: <code>string *str = new string("Hello dynamic string!")</code></li>
</ul>  

## Dynamically Allocated Arrays
<ul>
  <li>The malloc function can be used to allocate memory for an array the same way it was used to allocate enough memory for a string</li>
  <li>Here is the syntax for creating a dynamically allocated array of size n:

```cpp
int *array = new int[n];
```
  </li>
</ul>       

## Deallocating Storage
<ul>
  <li>The memory allocation functions obtain blocks of memory from a storage pool known as the <em>heap</em></li>
  <li>Data that is not freed at the end of a program is said to be <em>garbage</em>. Programs that leave behind garbage have <em>memory leaks</em></li>
</ul>    

### The free Function
<ul>
  <li>The free function has the following prototype:

```cpp
void free(void *ptr);
```
  </li>
  <li>Calling the free function releases a block of memory that ptr points to</li>  
</ul> 

### The delete function
<ul>
  <li>The delete function has the following prototype:

```cpp
void delete(void *ptr);
```
  </li>
</ul>  

## Linked Lists
<ul>
  <li>A <em>linked list</em> consists of a chain of structures, which are called <em>nodes</em>, where each node contains a pointer to the next node in the chain</li>
  <li>A linked list is an alternative to an array as it is more flexible. Nodes can be easily inserted and removed from a linked list whereas the elements of the array cannot be removed or have elements inserted</li>  
  <details>
    <summary>Example Program</summary>

```cpp
//Assume that the node structure is declared as:
struct node {
    int value;
    node *next;
};
//The following function returns the number of nodes that contains n; it returns 0 if n does not appear in the list. The list parameter points to a linked list
int count_n(node *list, int n) {
    node *p;
    int count = 0;

    for (p = list; p != nullptr; p = p->next)
        //missing statements

    return count;    
}
//Write statements in place of missing statements that will compare the value of the nodes in the linked list with n and update count if the value equals to n
```
<ul>
  <details>
    <summary>Output</summary>

```c
struct node {
    int value;
    node *next;
};

int count_n(struct node *list, int n) {
    node *p;
    int count = 0;
    for (p = list; p != nullptr; p = p->next)
        if (p->value == n)
            count++;

    return count;    
}
```
  </details>
    </ul>  
  </details> 
</ul>       

### Declaring a Node Types
<ul>
  <li>To make a linked list, the first thing that is needed is a structure to represent a single node in the list. Here is what a node structure looks like:

```cpp
struct Node {
    int value;         //data stored in the node
    Node *next; //pointer to the next node
};
```  
  </li>
  <li>Next, a variable will be needed that always points to the first node in the list. The following declaration can be made:

```cpp
Node *first = nullptr;
```
  </li>
  <li>Here are the steps involved in creating a node:
    <ul>
      <li>Allocate memory for the node</li>
      <li>Store data in the node</li>
      <li>Insert the node into the list</li>
    </ul>        
  </li>
  <li>When creating a node, a temporary variable is needed to point to the node temporarily: Node *newNode;</a>
    <ul>
      <li>The malloc or new function is used to allocate memory for the new node: <code>newNode = new Node;</code></li>
      <li>newNode now points to a block of memory that is just large enough to hold a Node structure</li>
    </ul>    
  </li>  
  <li>The last node in the list points to a nullptr</a>
  </li>  
  <details>
    <summary>Example Program</summary>

```cpp 
#include <iostream>
using namespace std;

//structure definition for a Node in a linked list
struct Node
{
    int value;
    Node *next;
};

int main()
{
    //initializing head node
    Node *head = new Node;
    head->value = 1;
    head->next = nullptr;

    //initializing second node
    Node *second = new Node;
    second->value = 2;
    second->next = nullptr;
    head->next = second;

    //initializing third node
    Node *third = new Node;
    third->value = 3;
    third->next = NULL;
    second->next = third;
    
    //freeing dynamically allocated memory
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
```
  </details>
</ul>   

### The -> Operator
<ul>
  <li>The <em>right arrow selection</em> is a minus sign followed by the >. The -> operator is a combination of the * and . operators. Essentially, this operator dereferences the node while selecting one of the structure's members</li>
  <li>Using the -> operator, <code>newNode->value = 10;</code> is equivalent to <code>(*newNode).value = 10;</code></li>  
<details>
    <summary>Example Program</summary>

```cpp 
//Given a linked list of node declared as follows, how would you know if a linked list of node named list is an empty list?
struct node {
    int number;
    node *next;
};
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
The first and only item in the linked list would be of type node * and would have a value of nullptr        
        </code>
        </pre>  
      </details>
    </ul>  
  </details>
</ul>  

### Inserting a Node at the Beginning of a Linked List
<ul>
  <li>An advantage of a linked list is that nodes can be added at any point in the linked list. The below is an example of how to add a new node to the beginning of a linked list</li>
  <details>
    <summary>Example Program</summary>

```cpp 
#include <iostream>
using namespace std;

//structure definition for a Node in a linked list
struct Node
{
    int value;
    Node *next;
};

//function to insert a new node with a given value at the beginning of the linked list
Node *insertFirst(Node *, const int *);

int main()
{
    const int value = 4;

    //initializing head node
    Node *head = new Node;
    head->value = 1;
    head->next = NULL;

    //initializing second node
    Node *second = new Node;
    second->value = 2;
    second->next = NULL;
    head->next = second;

    //initializing third node
    Node *third = new Node;
    third->value = 3;
    third->next = NULL;
    second->next = third;

    //inserting a new node with value 4 at the beginning of the linked list
    head = insertFirst(head, &value);

    //freeing dynamically allocated memory
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}

//function to insert a new node with a given value at the beginning of the linked list
Node *insertFirst(Node *head, const int *intValue)
{
    //allocating memory for the new node 
    Node *first = new Node;
    first->value = *intValue;
    first->next = head;

    return first;
}
```
  </details>
</ul>     

### Searching a Linked List
<ul>
  <li>To search through a linked list, a for statement is often used</li>
  <li>This is the syntax used for iterating through a linked list:

```cpp
for (Node *p = first; p != nullptr; p = p->next)
    ...
```
  </li>
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

//structure definition for a Node in a linked list
struct Node
{
    int value;
    struct Node *next;
};

int main()
{
    //head node in linked list
    Node *head = new Node;
    head->value = 1;
    head->next = NULL;

    //second node in linked list
    Node *second = new Node;
    second->value = 2;
    second->next = NULL;
    head->next = second;

    //third node in linked list
    Node *third = new Node;
    third->value = 3;
    third->next = NULL;
    second->next = third;

    //printing the values of nodes in linked list
    for (Node *p = head; p != NULL; p = p->next)
        printf("%d ", p->value);

    //freeing dynamically allocated memory
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        free(current);
        current = temp;
    }    

    return 0;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
1 2 3
        </code>
        </pre>  
      </details>
    </ul>  
  </details>
</ul>    

### Deleting a Node from a Linked List
<ul>
  <li>Deleting a node involves the following three steps:
    <ul>
      <li>Locate the node to be deleted</li>
      <li>Alter the previous node so that it skips the deleted node</li>
      <li>Call the delete function to release the memory that was previously occupied by the deleted node
        <ul>
          <li>Here is the syntax for delete free function:

```cpp
delete structPtr;
```
  </li>
    </ul>        
  </li>
  </ul>
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

//structure definition for a Node in a linked list
struct Node
{
    int value;
    Node *next;
};

int main()
{
    //head node in linked list
    Node *head = new Node;
    head->value = 1;
    head->next = NULL;

    //second node in linked list
    Node *second = new Node;
    second->value = 2;
    second->next = NULL;
    head->next = second;

    //third node in linked list
    Node *third = new Node;
    third->value = 3;
    third->next = NULL;
    second->next = third;

    //deleting the second node in linked list
    head->next = third;
    delete second;

    //printing the values of nodes in linked list
    for (Node *p = head; p != nullptr; p = p->next)
        printf("%d ", p->value);

    //freeing dynamically allocated memory
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        free(current);
        current = temp;
    }   

    return 0;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
1 3
        </code>
        </pre>  
      </details>
    </ul>  
  </details>
  <details>
    <summary>Example Program</summary>

```cpp
//Write a program that includes a function that deletes a node from a linked list that has an integer value of 1
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *delete(struct Node *);

int main()
{
    Node *head = new Node;
    head->value = 0;
    head->next = NULL;

    Node *second = new Node;
    second->value = 1;
    head->next = second;
    second->next = NULL;

    Node *third = new Node;
    third->value = 2;
    second->next = third;
    third->next = NULL;

    head = delete(head);

    for (struct Node *ptr = head; ptr != NULL; ptr = ptr->next)
        printf("%d\n", ptr->value);

    return 0;
}

Node *delete(Node *head)
{
    Node *cur, *prev;

    for (cur = head, prev = NULL; cur != NULL && cur->value != 1; prev = cur, cur = cur->next);

    if (cur == NULL)
        return head;
    if (prev == NULL)
        return head->next;
    else
        prev->next = cur->next;    
    
    delete (cur);
    return head;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
0
2
        </code>
        </pre>  
      </details>
    </ul>  
  </details>
  <details>
    <summary>Example Program</summary>

```cpp
//Complete the function clear_list to release all nodes from a linked list

struct node {
    int value;
    node *next;
};

void clear_list(node *list) {
    node *temp;

    while (list != NULL) {
        temp = list;
        //missing code here
    }
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
void clear_list(node *list) {
    node *temp;

    while (list != NULL) {
        temp = list;
        list = temp->next;
        delete temp;
    }
}
```
  </details>
    </ul>  
  </details>
</ul>    

### Ordered Lists
<ul>
  <li>When the nodes of a list are stored by the data stored inside of the nodes, then that is called an <em>ordered</em> linked list</li>
  <li>Inserting a node into an ordered linked list is more difficult; however, searching through an ordered linked list is faster</li> 
  <details>
    <summary>Example Program</summary>

```c 
#include <iostream>
using namespace std;

//structure definition for a Node in a linked list
struct Node
{
    int value;
    Node *next;
};

//function prototype for sorting a linked list to be an ordered linked list
void sorted(struct Node *);

int main()
{
    //head node in linked list
    Node *head = new Node;
    head->value = 5;
    head->next = NULL;

    //second node in linked list
    Node *second = new Node;
    second->value = 2;
    second->next = NULL;
    head->next = second;

    //third node in linked list
    Node *third = new Node;
    third->value = 4;
    third->next = NULL;
    second->next = third;

    sorted(head);

    for (struct Node *i = head; i != NULL; i = i->next)
        printf("%d ", i->value);

    //freeing dynamically allocated memory
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        free(current);
        current = temp;
    }     

    return 0;
}

//function definition for sorting a linked list
void sorted(struct Node *head)
{
    //nested for loop for iterating over the list
    for (struct Node *i = head; i != NULL; i = i->next)
        for (struct Node *j = i->next; j != NULL; j = j->next)
            //swapping linked list values
            if (i->value > j->value)
            {
                int temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
2 4 5
        </code>
        </pre>  
      </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Here is a linked list. Implement a function that reverses the list. The node struct is defined as:

struct node {
    int value;
    node *next;
}

//Write a function called reverse_list that reverses the linked list, and returns the head of the new reversed list

node *reverse_list(node *head) {

}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
node *reverse_list(node *head) {
    int nodes = 0, i = 0;

    for (struct node *ptr = head; ptr != NULL; ptr = ptr->next, nodes++);

    node allNodes[nodes];

    for (struct node *ptr = head; ptr != NULL; ptr = ptr->next)
        allNodes[i++] = *ptr;

    for (struct node *ptr = head; ptr != NULL; ptr = ptr->next)
        ptr->value = allNodes[--i].value;

    return head;
}
```
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Write a function to insert a new node into its proper place in an ordered list, returning a pointer to the first node in the modified list

struct node {
    int value;
    node *next;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
struct node {
    int value;
    node *next;
}

struct node *insert_into_ordered_list(node *list, node *new_node)
{
    node *cur, *prev;

    for (cur = list, prev = NULL; cur != NULL && new_node->value > cur->value; prev = cur, cur = cur->next);

    new_node->next = cur;

    if (prev == NULL)
      return new_node;
    else {
        prev->next = new_node;
        return list;
    }  
}
```
  </details>
    </ul>  
  </details> 
</ul>    

## Function Pointers
<ul>
  <li>Function pointers are common in C++ as functions can be passed as arguments. When passing a function pointer as an argument, the function pointer must be declared</li>
  <li>Here is the syntax for the declaration of a function pointer:

```cpp
returnType (*ptrFunction) (anotherReturnType)
```
  <ul>
      <li>returnType: this will point to functions that return a variable of type returnType</li>
      <li>*ptrFunction: this is the name of the function pointer variable</li>
      <li>anotherReturnType: this will point to functions that have one parameter of type anotherReturnType</li>
    </ul>        
  </li>
  <li>Essentially, function pointers are pointers to functions. This enables pointers to call functions rather than just calling the function itself. Below is an example of how a function pointer can be used:</li>  
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

void function(int x)
{
    cout << "x: " << x << endl;
}

int main()
{
    void (*functionPtr) (int) = function;

    (*functionPtr) (4);
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
x: 4  //an alternate call to function is functionPtr(4);
        </code>
        </pre>  
      </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//What is the output of the following program?
#include <iostream>
using namespace std;

int f1(int (*f) (int));
int f2(int i);

int main(void) {
    cout << f1(f2) << endl;
    return 0;
}

int f1(int (*f) (int)) {
    int n, num = 0;
    for (n = 0; n < 3; n++)
        num = f(n);
    return num;    
}

int f2(int i) {
    return i * i + i;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
6
        </code>
        </pre>  
      </details>
    </ul>  
  </details>   
  <details>
    <summary>Example Program</summary>
A function named integrate that integrates a mathematical function f can be made by passing f as an argument and a and b are the range for the integration, both a and b are of type double. Function f can be any function that takes a double parameter and returns a double. The function integrate returns a double. Write a function prototype for the integrate function
<ul>
  <details>
    <summary>Output</summary>

```cpp
double integrate(double (*f) (double x), double a, double b);
```
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>
Write a program that creates three functions: add(int, int), subtract(int, int), and multiply(int, int); stores pointers to these functions in an array of function pointers; and prompts the user to choose an operation (add, subtract, multiply) on two numbers, then uses the appropriate function pointer from the array to perform the operation
<ul>
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
using namespace std;

int add(int, int);
int subtract(int, int);
int multiply(int, int);

int main()
{
    int (*addPtr) (int, int) = add;
    int (*subtractPtr) (int, int) = subtract;
    int (*multiplyPtr) (int, int) = multiply;
    int (*functionPtrs[3]) (int, int) = {addPtr, subtractPtr, multiplyPtr};
    int numOne, numTwo, selection;

    cout << "Enter two numbers:\nNumber 1: ";
    cin >> numOne;
    cout << "Number 2: ";
    cin >> numTwo;

    cout << "Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\nSelection: ";
    cin >> selection;

    if (selection < 1 || selection > 3) {
        cout << "Invalid selection. Exiting...\n" << endl;
        return 1;
    }

    else
    {
        if (selection == 1)
            cout << "Result: " << functionPtrs[0](numOne, numTwo) << endl;
        else if (selection == 2)
            cout << "Result: " << functionPtrs[1](numOne, numTwo) << endl;
        else
            cout << "Result: " << functionPtrs[2](numOne, numTwo) << endl;        
    }

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}
```
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>
Write a function apply_operation that: takes a function pointer as one of its parameters; takes two integers as additional parameters; and calls the function pointer with the two integers and returns the result
<ul>
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
using namespace std;

int add(int, int);
int subtract(int, int);
int applyOperation(int (int, int), int, int);

int main()
{
    int num1, num2, selection;
    int (*addPtr) (int, int) = add;
    int (*subtractPtr) (int, int) = subtract;
    int (*applyPtr) (int (int, int), int, int) = applyOperation;

    cout << "Enter two integers:\nInteger 1: ";
    cin >> num1;
    cout << "Integer 2: ";
    cin >> num2;

    cout << "Choose an operation (1. Addition or 2. Subtraction):\nSelection: ";
    cin >> selection;

    if (selection < 1 || selection > 2)
    {
        cout << "Invalid selection. Exiting...\n";
        return 1;
    }

    if (selection == 1)
        cout << "The sum of " << num1 << " and " << num2 << " is: " << applyPtr(addPtr, num1, num2) << endl;
    else if (selection == 2)
        cout << "The subtraction of " << num1 << " from " << num2 << " is: " << applyPtr(subtractPtr, num1, num2) << endl;

    return 0;
}

int add(int a, int b) {return a + b;}
int subtract(int a, int b) {return a - b;}
int applyOperation(int (*operation)(int, int), int a, int b) {return operation(a, b);}
```
  </details>
    </ul>  
  </details>
</ul>    

### The qsort Function
<ul>
  <li>
    <a>The qsort function belongs to the <code>stdlib.h</code> header</a>
  </li>
  <li>
    <a>The qsort function purpose is that it is capable of sorting an array</a>
  </li>
  <li>
    <a>Here is the qsort function syntax:</a>

```c
int compare(const void *x_void, const void *y_void)
{
    //converting the type of pointer from void pointer to int pointer
    int x = *(int *)x_void;
    int y = *(int *)y_void;

    //let's say x = 2 and y = 5. Since x - y is less than 0, that tells qsort that x should go before y in the array. That means that the array is being sorted in ascending order
    return x - y;
}

void qsort(void *array, int arrayLength, int sizeof(int), int compare /*function name can be anything but must be of type int*/);

//we need to provide qsort a special function
//
//int comparator(const void *x, const void *y);
//
//return value of the function will affect the sorting order
//
// < 0 if x should go before y
// 0 if x is equivalent to y
// > 0 if x should go after y
//
```
  </li>
  <details>
    <summary>Example Program</summary>

```c 
#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void *, const void *);

int main()
{
    int a[] = {8, 7, 9, 10, 111, 345, 3, 2, 1, 1};
    int length = 10;

    qsort(a, length, sizeof(int), compare);

    for (int *ptr = a, i = 0; ptr < a + length; i++, ptr++)
        cout << "a[" << i << "] = " << *ptr << endl;

    return 0;    
}

int compare(const void *x_void, const void *y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;

    return x - y;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
a[0] = 1                                                                                                                       
a[1] = 1
a[2] = 2
a[3] = 3
a[4] = 7
a[5] = 8
a[6] = 9
a[7] = 10
a[8] = 111
a[9] = 345
        </code>
        </pre>  
      </details>
    </ul>  
  </details> 
</ul>      
