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
    <a href='#doubly-linked-lists'>Doubly Linked Lists</a>
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

## Doubly Linked list
<ul>
  <li>A doubly linked list is similar to a singly linked list, with the difference being a doubly linked list has nodes that link to both the prior and next node in the chain</li>

  <details>
    <summary>Example Program</summary>

```cpp
//Write a function that inserts a new node to a doubly linked list after a given target integer

#include <iostream>
using namespace std;

//struct definition for doubly linked list
struct Node
{
    double value;
    Node *next, *previous;
};

//function for inserting new node before target node
void insertBefore(Node *&, const double &, const double &);

//function for printing the linked list
void printList(Node *&);

//function for freeing the entire list from memory
void deleteList(Node *&);

int main()
{
    Node *head = new Node{1, nullptr, nullptr};
    Node *second = new Node{2, nullptr, head};
    Node *third = new Node{2, nullptr, second};
    Node *fourth = new Node{3, nullptr, third};
    head->next = second;
    second->next = third;
    third->next = fourth;

    insertBefore(head, 2, 2.5);

    printList(head);
    deleteList(head);

    return 0;
}

void insertBefore(Node *&head, const double &initial, const double &value)
{
    Node *ptr = head;

    //for loop iterating through the list
    for (; ptr != nullptr; ptr = ptr->next)
    {
        //conditional statement saying if the target value is found, create a new node
        if (ptr->value == initial)
        {
            //new node creation where next points to ptr and previous points to ptr-previous
            Node *newNode = new Node{value, ptr, ptr->previous};

            //conditional statement checking if ptr is not the first item in the list; if this is true, set ptr->previous->next to point to the newNode rather than ptr
            if (ptr->previous != nullptr)
                ptr->previous->next = newNode;
            //otherwise, set the head to point to the new node
            else
                head = newNode;
            
            //set the previous attribute of ptr to point to newNode as ptr is now after newNode
            ptr->previous = newNode;
        }
    }
}

void printList(Node *&head)
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->value << endl;
}

void deleteList(Node *&head)
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
1
2.5
2
2.5
2
3
```
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Write functions that will insert a new head, insert a new tail, print, and delete memory from a doubly linked list

#include <iostream>
using namespace std;

//struct definition for doubly linked list
struct Node
{
    int value;
    Node *next;
    Node *previous;
};

//function for inserting new head to list
void insertFront(Node *&, const int &);

//function for inserting new tail to list
void insertEnd(Node *&, const int &);

//function for printing the linked list
void printList(Node *&);

//function for freeing the entire list from memory
void deleteList(Node *&);

int main()
{
    //creating first node in list
    Node *head = new Node{1, nullptr, nullptr};

    //creating second node in list
    Node *second = new Node{2, nullptr, head}; 
    head->next = second;

    //inserting new head
    insertFront(head, 0);
    //inserting new tail
    insertEnd(head, 3);
    //printing list
    printList(head);
    //freeing list's memory
    deleteList(head);

    return 0;
}
 
void insertFront(Node *&head, const int &value)
{
    Node *newNode = new Node{value, head, nullptr};
    
    if (head != nullptr)
        head->previous = newNode;

    head = newNode;
}

void insertEnd(Node *&head, const int &value)
{
    Node *ptr= head;

    for (; ptr->next != nullptr; ptr = ptr->next);

    Node *newNode = new Node;
    newNode->value = value;
    newNode->previous = ptr;
    newNode->next = nullptr;
    ptr->next = newNode;
}

void printList(Node *&head)
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->value << endl;
}

void deleteList(Node *&head)
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
0
1
3
2
```
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Write a function that counts the number of nodes in a linked list recursively

#include <iostream>
using namespace std;

//struct definition for doubly linked list
struct Node
{
    double value;
    Node *next, *previous;
};

int count(Node *);

//function for freeing the entire list from memory
void deleteList(Node *&);

int main()
{
    Node *head = new Node{1, nullptr, nullptr};
    Node *second = new Node{2, nullptr, head};
    Node *third = new Node{2, nullptr, second};
    Node *fourth = new Node{3, nullptr, third};
    head->next = second;
    second->next = third;
    third->next = fourth;

    cout << "Nodes: " << count(head);
    deleteList(head);

    return 0;
}

int count(Node *head)
{
    if (head == nullptr)
        return 0;
    
    return 1 + count(head->next);
}

void deleteList(Node *&head)
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
Nodes: 4
```
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Insert a new node into a sorted linked list so that the list remains sorted. Delete a node from a sorted list

#include <iostream>
using namespace std;

//class definition for doubly linked list
template <typename T>
class Node
{
    public:
        Node(T val, Node<T> * nxt = nullptr, Node<T> *prev = nullptr) 
            : value(val), next(nxt), previous(prev) {}
        T value;
        Node<T> *next;
        Node<T> *previous;
};

template<typename T>
void insert(Node<T> *&, const T &);

template<typename T>
void deleteValue(Node<T> *&, const T &);

template<typename T>
void free(Node<T> *&);

int main()
{
    Node<int> *head = new Node<int>(1);
    Node<int> *second = new Node<int>(2, nullptr, head);
    Node<int> *third = new Node<int>(3, nullptr, second);
    Node<int> *fourth = new Node<int>(5, nullptr, third);
    head->next = second;
    second->next = third;
    third->next = fourth;

    insert<int>(head, 4);

    deleteValue<int>(head, 4);

    for (Node<int> *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->value << endl;


    free(head);

    return 0;
}

template<typename T>
void insert(Node<T> *&head, const T &val)
{
    //instantiation of new node
    Node<T> *newNode = new Node<T>(val);

    //insert new node before head
    if (head == nullptr || val <= head->value)
    {
        newNode->next = head;

        if (head != nullptr)
            head->previous = newNode;

        head = newNode;

        return;
    }

    //insert new node after head
    for (Node<T> *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        //if inserting node at the end of the list
        if (ptr->next == nullptr) 
        {
            ptr->next = newNode;
            newNode->previous = ptr;
            break;
        }

        //if inserting node in the middle of the list
        if (ptr->next->value >= val)
        {
            newNode->next = ptr->next;
            newNode->previous = ptr;
            ptr->next->previous = newNode;
            ptr->next = newNode;
            break;
        }
    }
}

template <typename T>
void deleteValue(Node<T> *&head, const T &value)
{
    if (head->value == value)
    {
        Node<T> *copy = head;

        if (head->next != nullptr)
            head->next->previous = nullptr;

        head = head->next;

        delete copy;

        return;
    }

    for (Node<T> *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->next == nullptr && ptr->value == value)
        {
            ptr->previous->next = nullptr;
            delete ptr;

            return;
        }

        if (ptr->value == value)
        {
            if (ptr->previous) 
                ptr->previous->next = ptr->next;
            if (ptr->next) 
                ptr->next->previous = ptr->previous;

            delete ptr;

            return;
        }
    }
}

template <typename T>
void free(Node<T> *&head)
{
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}
```
<ul>
  <details>
    <summary>Output</summary>
1
2
3
5
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Reverse a linked list

#include <iostream>
using namespace std;

//class definition for doubly linked list
template <typename T>
class Node
{
    public:
        Node(T val, Node<T> * nxt = nullptr, Node<T> *prev = nullptr) 
            : value(val), next(nxt), previous(prev) {}
        T value;
        Node<T> *next;
        Node<T> *previous;
};

template<typename T>
void reverse(Node<T> *&, Node<T> *&);

template<typename T>
void free(Node<T> *&);

int main()
{
    Node<int> *head = new Node<int>(1);
    Node<int> *second = new Node<int>(2, nullptr, head);
    Node<int> *third = new Node<int>(3, nullptr, second);
    Node<int> *fourth = new Node<int>(5, nullptr, third);
    head->next = second;
    second->next = third;
    third->next = fourth;
    Node<int> *tail = fourth;
    
    reverse(head, tail);

    for (Node<int> *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->value << endl;


    free(head);

    return 0;
}

template <typename T>
void reverse(Node<T> *&head, Node<T> *&tail)
{
    for (Node<T> *ptrHead = head, *ptrTail = tail; ptrHead != ptrTail && ptrHead->previous != ptrTail; ptrHead = ptrHead->next, ptrTail = ptrTail->previous)
    {
        T value = ptrHead->value;
        ptrHead->value = ptrTail->value;
        ptrTail->value = value;
    }
}

template <typename T>
void free(Node<T> *&head)
{
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}
```
<ul>
  <details>
    <summary>Output</summary>
5
3
2
1
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Remove duplicates from a linked list

#include <iostream>
using namespace std;

//class definition for doubly linked list
template <typename T>
class Node
{
    public:
        Node(T val, Node<T> * nxt = nullptr, Node<T> *prev = nullptr) 
            : value(val), next(nxt), previous(prev) {}
        T value;
        Node<T> *next;
        Node<T> *previous;
};

template<typename T>
void remove(Node<T> *&);

template<typename T>
void free(Node<T> *&);

int main()
{
    Node<int> *head = new Node<int>(1);
    Node<int> *second = new Node<int>(1, nullptr, head);
    Node<int> *third = new Node<int>(1, nullptr, second);
    Node<int> *fourth = new Node<int>(1, nullptr, third);
    head->next = second;
    second->next = third;
    third->next = fourth;

    remove(head);

    for (Node<int> *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->value << endl;

    free(head);

    return 0;
}

template <typename T>
void remove(Node<T> *&head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    for (Node<T> *ptr = head; ptr != nullptr;)
    {
        if (ptr->next != nullptr && ptr->value == ptr->next->value)
        {
            Node<T> *copy = ptr->next;
            ptr->next = copy->next;

            if (copy->next != nullptr)
                copy->next->previous = ptr;

            delete copy;
        }

        else
            ptr = ptr->next;
    }
}

template <typename T>
void free(Node<T> *&head)
{
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}
```
<ul>
  <details>
    <summary>Output</summary>
1
  </details>
    </ul>  
  </details> 
</ul>  

## Circularly Linked Lists and List Reversal
### Circularly Linked LIsts
<ul>
  <li>A <em>circularly linked list</em> has the same kind of nodes as a singly linked list. That is, each node in a circularly linked list has a next pointer and an element value; however, rather than having a head or tail, the nodes of a circularly linked list are linked in a cycle</li>
  <li>If traversing the nodes of a circularly linked list from any node by the following <code>next</code> pointers, eventually all nodes will have been visited and will be cycled back to the starting node</li>
  <details>
    <summary>Example Program</summary>

```cpp
//Create a circularly linked list with the first node containing the integer 10. Then, insert a new node with the integer 20 at the end. Print the list twice around the output, so the output should be: 10 20 10 20

#include <iostream>
using namespace std;

//Node declaration for circularly linked list
struct Node
{
    int data;
    Node *next, *previous;
};

int main()
{
    //variable declaration and initialization for iteration counter
    int i = 0;

    //creation of circularly linked list's head
    Node *head = new Node();
    head->data = 10;

    //creation of second node in list
    Node *second = new Node();
    second->data = 20;
    head->next = second;
    head->previous = second;
    second->next = head;
    second->previous = head;

    //for loop which iterates through the circularly linked list
    for (Node *ptr = head;; ptr = ptr->next)
    {
        cout << ptr->data << " ";

        //increasing counter by one if one complete iteration through the circularly linked list has occurred
        if (ptr == second)
            i++;
        
        //breaking from the loop if the linked list has been iterated through two complete times
        if (i > 1)
            break;
    }

    //freeing memory
    Node *ptr = head->next;
    while (ptr != head)
    {
        Node *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    delete head;

    return 0;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
10 20 10 20 
```
  </details>
    </ul>  
  </details> 
  <details>
    <summary>Example Program</summary>

```cpp
//Check if a doubly circularly linked list is a palindrome

#include <iostream>
using namespace std;

//struct definition for doubly linked list
struct Node
{
    double value;
    Node *next, *previous;
};

bool check(const Node *, const Node *);
void deleteList(Node *&);

int main()
{
    Node *head = new Node{1, nullptr, nullptr};
    Node *second = new Node{2, nullptr, head};
    Node *third = new Node{3, nullptr, second};
    Node *fourth = new Node{0, nullptr, third};
    head->next = second;
    second->next = third;
    third->next = fourth;
    head->previous = fourth;
    fourth->next = head;

    cout << check(head, fourth);
    deleteList(head);

    return 0;
}

bool check(const Node *head, const Node *tail)
{
    for (const Node *ptrHead = head, *ptrTail = tail; ptrHead != ptrTail && ptrTail->previous != ptrHead; ptrHead = ptrHead->next, ptrTail = ptrTail->previous)
        if (ptrHead->value != ptrTail->value)
            return false;

    return true;
}

void deleteList(Node *&head)
{
    Node *current = head;

    do
    {
        Node *next = current->next;
        delete current;
        current = next;
    } while (current != head);

    head = nullptr;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
0
```
  </details>
    </ul>  
  </details> 
</ul>

### List Reversal
<details>
    <summary>Example Program</summary>

```cpp
//Create a circular doubly linked list and reverse the contents within the list

#include <iostream>
using namespace std;

//Node declaration for circularly linked list
struct Node
{
    int data;
    Node *next, *previous;
};

int main()
{
    //variable declaration and initialization for node counter
    int count = 1, iterations = 0;

    //creation of circularly linked list's head
    Node *head = new Node();
    head->data = 10;

    //creation of second node in list
    Node *second = new Node();
    second->data = 20;
    head->next = second;
    second->previous = head;

    //creation of third node in list
    Node *third = new Node();
    third->data = 30;
    second->next = third;
    third->previous = second;

    //creation of fourth node in list
    Node *fourth = new Node();
    fourth->data = 40;
    third->next = fourth;
    fourth->previous = third;
    fourth->next = head;
    head->previous = fourth;

    //pointer which will point to the end of the linked list
    Node *tail;

    //for loop which counts the number of nodes in the list
    for (Node *ptr = head;; ptr = ptr->next)
    {
        //selection statement which checks if we have yet to reach the last value in the list; if not, increment the counter and skip to the beginning of the loop
        if (ptr->next != head)
        {
            count++;
            continue;
        }

        //tail points to the last node of the list
        tail = ptr;
        break;
    }

    //for loop which iterates through the circularly linked list to reverse its contents
    for (Node *ptrHead = head, *ptrTail = tail;; ptrHead = ptrHead->next, ptrTail = ptrTail->previous)
    {
        //swapping the data within the lists
        int temp = ptrTail->data;
        ptrTail->data = ptrHead->data;
        ptrHead->data = temp;

        //counting number of loop iterations
        iterations++;

        //selection statement which terminates the reversal before ptrHead and ptrTail undo the data's reverse
        if (iterations >= count / 2)
            break;
    }

    //freeing memory
    Node *ptr = head->next;
    while (ptr != head)
    {
        Node *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    delete head;

    return 0;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
40 30 20 10 
```
  </details>
    </ul>  
  </details> 

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