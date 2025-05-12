<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#introduction'>Introduction</a>
  </li> 
  <li>
    <a href='#begin-and-end'>begin and end</a>
  </li> 
  <li>
    <a href='#the-auto-keyword'>The auto Keyword</a>
  </li> 
</ol>
</details>

## Introduction
Iterators are used to iterate through elements of data structures by pointing to them

Here are the steps to creating an iterator to loop through a data structure:
<ol>
  <li>First, create a data structure, such as a vector or a list</li>
  <li>Then, create an iterator, such as a vector iterator, called <code>it</code>, which will be used to loop through the vector</li>
  <li>Then use a loop to loop through the vector. The iterator, <code>it</code>, points to the first element of the vector</li>
  <li>To increment the iterator for looping, use <code>it++</code></li>
  <li>The dereference operator <code>*it</code> accesses the element the iterator points to</li>
</ol>

here is how to declare an iterator:

```cpp
dataStructureType<dataType>::iterator it;
```

## <code>begin()</code> and <code>end()</code>
The <code>begin()</code> and <code>end()</code> functions do not belong to the iterator, rather the data structures themselves, such as vectors and lists. Instead, these functions are used to access the beginning and end items in a data structure

<ul>
  <li><code>begin()</code> returns an iterator that points to the first item in the data structure</li>
  <li><code>end()</code> returns an iterator that points past the last element in the data structure. This is why dereferencing at <code>end()</code> results in undefined behavior</li>
</ul>

For instance, the following will have the iterator point to the first element in a data set:

```cpp
it = dataStructure.begin();
```

## The <code>auto</code> Keyword
In later versions of C++, the <code>auto</code> keyword was created for declaring iterators. The <code>auto</code> keyword makes the declaration of iterators more readable such as in the following:

```cpp
auto it = dataStructureName.begin();
```

<details>
    <summary>Example program</summary>
This program prints the reverse of a list using an

```cpp
#include <iostream>
#include <list>
using namespace std;

//function prototype for reversePrint which prints the reverse of the list passed in as a parameter
void reversePrint(const list<int> *);

int main()
{
    //variable declaration and initialization
    list<int> integers = {1, 2, 3};

    //calling reversePrint function
    reversePrint(&integers);

    return 0;
}

//function definition for reversePrint
void reversePrint(const list<int> *integers)
{
    //iterator initialization
    auto it = integers->end();
    --it;
    
    //for loop which iterates from the end of the list to the beginning, printing each value in the list
    for (; it != integers->begin(); it--)
        cout << *it << " ";

    cout << *it;
}
```
</details> 
