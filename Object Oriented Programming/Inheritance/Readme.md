<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#derived-classes'>Derived Classes</a>
  </li> 
  <li>
    <a href='#abstract-classes'>Abstract Classes</a>
  </li> 
</ol>
</details>

## Derived Classes
In C++, inheriting attributes and methods from another class is possible. This relationship can be grouped into two categories:
<ul>
  <li><em>Derived class</em>: is the class that inherits from another class</li>
  <li><em>Base class</em>: is the class being inherited from</li>
</ul>

To inherit from a class, the <code>:</code> operator is used such as in the following example:

```cpp
class Vehicle
{
    public:
        string brand = "Lambo";

        void print() { cout << "Lambo" << endl; }
};

class Lambo : public Vehicle
{
    public:
        string model = "2025";
};
```

<details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

class Vehicle
{
    public:
        string brand = "Lambo";

        void print() { cout << "Lambo" << endl; }
};

class Lambo : public Vehicle
{
    public:
        string model = "2025";
};

int main()
{
    Lambo myCar;

    myCar.print();

    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Lambo
      </pre>  
    </details>
  </ul>  
</details>  

## Abstract Classes
An <em>abstract class</em> in C++ is a class that cannot have instances directly, rather it serves as a parent class for other classes to inherit from

A key feature of abstract classes is that they have at least one pure <em>virtual function</em>

Here is the syntax for a pure virtual function:

```cpp
virtual returnType functionName() = 0
```

The <code>override</code> keyword is used to indicate that a virtual function in a derived class is meant to be override a virtual function in the base class. In the following example, the draw function in the <code>Shape</code> class is a pure virtual function which is overridden by the virtual function within the <code>Circle</code> class

```cpp
class Shape
{
    public:
        virtual void draw() = 0;
};

class Circle : public Shape
{
    public:
        void draw() override { cout << "Drawing a circle"; }
};
```

<details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual void draw() = 0;
};

class Circle : public Shape
{
    public:
        void draw() override { cout << "Drawing a circle"; }
};

int main()
{
    Circle circle;

    circle.draw();

    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Drawing a circle
      </pre>  
    </details>
  </ul>  
</details>  
