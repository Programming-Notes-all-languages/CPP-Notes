<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#function-templates'>Function Templates</a>
  </li> 
  <li>
    <a href='#class-templates'>Class Templates</a>
  </li> 
</ol>
</details>

## Function Templates
C++ provides an automatic mechanism, called the <em>function templates</em>, to produce a generic function for an arbitrary type <code>T</code>.

Here is the syntax for creating a template function:

```cpp
template <typename T>
T functionName(T variableName)
    return variableName;
```

<details>
    <summary>Example program</summary>

Write a template function that swaps two variables

<ul>  
  <details>
    <summary>Output</summary>

```cpp
template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
```
    
</details>
  </ul>  
</details>  

## Class Templates
In addition to function templates, C++ allows classes to be templated. A class template is a blueprint for a class that works with any data type

Here is the syntax for creating a template class:

```cpp
template <typename T>
class ClassName
{
    private:
        T data;
    
    public:
        ClassName(T variable) : data(variable) {}
}
```

<details>
    <summary>Example program</summary>

```cpp
//Write a template class Person<T1, T2> that holds two values of possibly different types and implement a constructor that instantiates the object

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Person
{
    T1 name;
    T2 age;
    
    public:
        Person(T1 Name, T2 Age) : name(Name), age(Age) {}
        void display() { cout << name << ", " << age << endl; }
};

int main()
{
    Person<string, string> *garrett = new Person<string, string>("Garrett Ellis", "22");
    
    garrett->display();
    
    delete garrett;
    
    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
Garrett Ellis, 22
</details>
  </ul>  
</details>  

<details>
    <summary>Example program</summary>

```cpp
//Write a class called Point with two private attributes. This class is to have multiple constructors and a print method to print the points information. Use a template class to allow functionality for all variable types

#include <iostream>
using namespace std;

//template class Point declaration
template <typename T>
class Point
{
    //private member attributes
    T x, y;

    public:
        //constructors for class
        Point() : x(0), y(0) {}
        Point(T X) : x(X), y(X) {}
        Point(T X, T Y) : x(X), y(Y) {}
        Point(const Point &);

        //print method for printing the object's information
        void print() const;
};

template <typename T>
Point<T>::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
}

template <typename T>
void Point<T>::print() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}


int main()
{
    Point<int> *arr[3];

    arr[0] = new Point<int>(1, 2);
    arr[1] = new Point<int>(5);
    arr[2] = new Point<int>();

    for (int i = 0; i < 3; i++)
        arr[i]->print();
    
    for (int i = 0; i < 3; i++)
        delete arr[i];

    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>

(1, 2)
(5, 5)
(0, 0)
</details>
  </ul>  
</details>  