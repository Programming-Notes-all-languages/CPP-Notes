<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#lists'>Lists</a>
  </li> 
  <li>
    <a href='#vectors'>Vectors</a>
  </li> 
</ol>
</details>

## Lists
A list is similar to a vector in that it can store many elements of the same data type

However, there are two major differences between lists and vectors:
<ul>
  <li>Can add and remove elements from both the beginning and at the end of the list whereas with vectors they are built for adding and removing elements from the end</li>
  <li>Unlike vectors, a list does not support accessing elements by index numbers</li>
</ul>

To use a list, include the <code>&lt;list&gt;</code> header file:

```cpp
#include <list>
```

### Creating a List
To create a list, use the <code>list</code> keyword and specify the data type of the elements within the angle brackets <code>&lt;&gt;</code>. What follows is the name off the list

```cpp
list<dataType> listName;
```

If the programmer would like to add elements at the time of declaration, the list's elements can be in a comma-separated list enclosed in braces <code>{}</code> such as in the following:

```cpp
list<string> cars = {"Volvo", "BMW"}
```

### Access List Elements
List elements cannot be accessed by referring to index numbers like with arrays and vectors; however, the first and the last elements can be accessed with the <code>.front()</code> and <code>.back()</code> functions

### Change a List Element
Only the first and the last elements can be changed with the <code>.front()</code> and <code>.back()</code> functions

### Adding Elements to a List
To add elements to a list, use the <code>.push_front()</code> to insert an element at the beginning of the list and <code>.push_back()</code> to add an element at the end of the list

### Remove List Elements
To remove elements from a list, use <code>.pop_front()</code> to remove an element from the beginning of the list and <code>.pop_back()</code> to remove an element at the end of the list

### Size of the List
To find out the number of elements a list has, use the <code>.size()</code> function

### Check if list is Empty
Use the <code>.empty()</code> function to find out if the list is empty or not. If the list is empty, the function will return 1; otherwise, the function will return 0

<details>
    <summary>Example program</summary>
This program recursively checks if a list is a palindrome without using any other data structures

```cpp
#include <iostream>
#include <list>
using namespace std;

//function prototype for palindrome which checks if the list passed as a parameter is a palindrome
bool palindrome(list<int> *);

int main()
{
    //variable declaration and initialization
    list<int> integers = {1, 2, 3, 2, 1};

    return 0;
}

//function definition for palindrome
bool palindrome(list<int> *integers)
{
    //conditional statement which checks if the sie of the list is zero; if so, terminate the recursion
    if (integers->empty())
        return true;

    //conditional statement which checks if both ends of the palindrome are equal in value to satisfy the rules for palindromes
    if (integers->front() != integers->back())
        return false;
    
    //conditional statement which checks if the size of the list is greater than one to avoid segmentation fault when popping elements from the list
    if (integers->size() > 1)
    {
        integers->pop_front();
        integers->pop_back();
    }

    //conditional statement which checks if the size of the lest is equal to one to only pop one element off from the list
    else
        integers->pop_front();

    //recursively calling palindrome until there are no elements left in the list
    return palindrome(integers);
}
```
</details> 

## Vectors
A vector is like a resizable array in C++ that stores elements of the same data type. The difference between an array and a vector is the an array's size cannot be modified after declaration; however, the size of a vector can grow and shrink after declaration 

To use a vector, the <code>&lt;vector&gt;</code> header file is needed

```cpp
#include <vector>
```

### Create a Vector
To declare a vector, use the <code>&lt;vector&gt;</code> keyword, specify the data type of the vector within the angle brackets <code>&lt;&gt;</code>, and then the name of the vector

```cpp
vector<dataType> vectorName;
```

To add elements to a vector at the time of declaration, the items can be listed with commas. The items then need to be encapsulated in braces <code>{}</code> just like with arrays

### Access a Vector
A vector can be accessed by referring to an index number using the square brackets <code>[]</code>

An advantage of using vectors is that the vector library supports the <code>.front()</code> and <code>.back()</code> functions like with other data structures

The <code>.at()</code> function can be used to access an element of a vector at a specified index. The <code>.at()</code> function is often the preferred method of accessing vectors compared to the square brackets. An error condition occurs if i is out of range

### Change a Vector Element
Changing an element of a vector can be used by using array subscripting to access an item and then alter its value; however, the <code>.at()</code> function is still preferred

Changing an element of a vector can also be done using the <code>.set()</code> function where given <code>.set(i, e)</code>, the value e replaces the vector element at index i. An error condition occurs if i is out of range

### Adding Elements to a Vector
To add an element to a vector, the <code>.push_back()</code> function is needed which adds an element to the end of the vector

### Inserting Element to a Vector
To insert an element at any position in the vector, the <code>.insert()</code> function is needed which given <code>.insert(i, e)</code>, a new element of the vector with the value e is inserted at index i. An error condition occurs if i is out of range

### Remove Vector Elements
To remove the last element from a vector, use the <code>.pop_back()</code> function

To remove any element of the vector at any index, use the <code>.erase()</code> function. When given the following function call, <code>.erase(i)</code>, the element in the vector at index i is removed. An error condition occurs if i is out of range

### Size of a Vector
To find out how many elements are in a vector, use the <code>.size()</code> function

### Check if Vector is Empty
Use the <code>.empty()</code> function to find out if the vector is empty or not. If the vector is empty, the function will return 1; otherwise, the function will return 0
