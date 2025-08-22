<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#derived-classes'>Derived Classes</a>
  </li> 
  <li>
    <a href='#polymorphism'>Polymorphism</a>
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

### Virtual Functions
A <em>virtual function</em> is a C++ member function in a base class that is expected to be overridden in a derived class

A virtual function is declared with the keyword <code>virtual</code> in the base class

### Virtual Destructors
When writing a base class, it is generally not known whether a derived class may need to implement a destructor. So, to be safe, when defining and virtual functions, it is recommended that a virtual destructor is defined as well. The destructor may not do anything, but that is fine

## Polymorphism
<em>Polymorphism</em> allows objects of different classes to be treated as objects of a common base class, while behaving differently based on their actual derived type. This is usually through inheritance and virtual functions

<details>
    <summary>Example program</summary>

```cpp
//Create a base class called Person with a derived class called Student. Make a constructor for the Person class containing a virtual function for displaying a specified person's information

#include <iostream>
using namespace std;

//class declaration for Person
class Person
{
    //protected class members
    protected:
        string name;
        int age;
    
    public:
        //Person constructor
        Person(string Name, int Age) : name(Name), age(Age) {}
        //virtual function to display Person attributes
        virtual void display() const;
        //virtual destructor
        virtual ~Person() {}
};

//class declaration for Student, inheriting from Person
class Student : public Person
{
    //private member attribute
    string major;
    
    public:
        //Student constructor that inherits from Person
        Student(string Name, int Age, string Major) : Person(Name, Age), major(Major) {} 

        //display function which overrides a pointer of type Student from calling the same function in the base class
        void display() const override;
};

int main()
{
    //instantiating a pointer instance of Person 
    Person *garrett = new Student("Garrett Ellis", 22, "Computer Engineering");

    //calling display function from the derived class Student
    garrett->display();

    //freeing memory
    delete garrett;

    return 0;
}

//function definition for display from the base class
void Person::display() const
{
    cout << "Name: " << name << "\nAge: " << age << endl;
}

//function definition for display from the derived class
void Student::display() const
{
    cout << "Name: " << name << "\nAge: " << age << "\nMajor: " << major << endl;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Name: Garrett Ellis
Age: 22
Major: Computer Engineering
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

<details>
    <summary>Example program</summary>

```cpp
//Write an abstract class called Shape, with two derived classes: Circle and Rectangle, which display a shape's name and area using polymorphism

#include <iostream>
using namespace std;

//class definition for Shape abstract, base class
class Shape
{
    public:
        //pure virtual function allowing derived classes to calculate the shapes' areas
        virtual double area() const = 0;
        //pure virtual function allowing derived classes to display the shapes' information
        virtual void display() const = 0;
        virtual ~Shape() {}
};

//class definition for Circle derived class
class Circle : public Shape
{
    //private member attribute for the circle's radius
    double radius;
    
    public:
        //constructor instantiating a Circle instance
        Circle(double Radius) : radius(Radius) {}
        //member function which calculates the circle's area
        double area() const override { return radius * radius * 3.1415; }
        //member function which displays the shape's name and area
        void display() const override { cout << "Circle, Area: " << area() << endl; }
};

//class definition for Rectangle derived class
class Rectangle : public Shape
{
    //private member attributes for the rectangle's width and height
    double width, height;

    public:
        //constructor instantiating a Rectangle instance
        Rectangle(double Width, double Height) : width(Width), height(Height) {}
        //member function which calculates the rectangle's area
        double area() const override { return width * height; }
        //member function which displays the shape's area and name
        void display() const override { cout << "Rectangle, Area: " << area() << endl;}
};

int main()
{
    //declaration of array of type Shape * containing four shapes
    Shape *shapes[4];

    //instantiating the shapes to be circles and rectangles
    shapes[0] = new Circle(2.5);
    shapes[1] = new Circle(2.3);
    shapes[2] = new Rectangle(2, 3);
    shapes[3] = new Rectangle(4, 9);

    //for loop which iterates over the array of shapes
    for (int i = 0; i < 4; i++)
    {
        //display the shape's information, then freeing it from memory
        shapes[i]->display();
        delete shapes[i];
    }

    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Circle, Area: 19.6344
Circle, Area: 16.6185
Rectangle, Area: 6
Rectangle, Area: 36
      </pre>  
    </details>
  </ul>  
</details>  