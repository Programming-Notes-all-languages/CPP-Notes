<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#object-oriented-programming'>Object Oriented Programming</a>
  </li> 
  <li>
    <a href='#class-basics'>Class Basics</a>
  </li>    
  <li>
    <a href='#member-functions'>Member Functions</a>
  </li>    
  <li>
    <a href='#constructors'>Constructors</a>
  </li>   
  <li>
    <a href='#access-specifiers'>Access Specifiers</a>
  </li> 
  <li>
    <a href='#encapsulation'>Encapsulation</a>
  </li> 
  <li>
    <a href='#destructors'>Destructors</a>
  </li> 
</ol>
</details>



## Object Oriented Programming
Procedural programming is about writing functions that perform operations on given data which is different than object-oriented programming. Object-oriented programming is all about creating objects that contain data and functions

Here are some of the advantages of object-oriented programming over procedural programming:
<ul>
  <li>Object-oriented programming is faster</li>
  <li>Helps facilitate the "Do not Repeat Yourself" rule by making code more manageable</li>
</ul>

### Classes and Objects
Classes and objects are the two main parts of object-oriented programming

An example of the relationship between classes and objects is the following. There is a class called Fruit. Then, the different objects of type Fruit are: Apple, Banana, and Mango

## Class Basics
To create a class, use the <code>class</code> keyword:

```cpp
class Myclass 
{
    public:
        int myNum;
        string myString;
};
```
<ul>
  <li>In this example, the <code>class</code> keyword is used to create a class called <code>Myclass</code></li>
  <li>The <code>public</code> keyword is an <em>access specifier</em> which is used to determine if the methods of a class are accessible outside of the class</li>
  <li>In the class, there is an integer variable and a string variable. These are the attributes of the class</li>
  <li>All classes must have a semicolon after the closing brace, just like with structs</li>
</ul>

### Create an Object
Objects are created from a class in C++. To create an object, specify the name of the class followed by the object's name

To then access the class's attributes from an instance of the class, use the dot syntax, <code>.</code> on the object:

```cpp
class Myclass 
{
    public:
        int myNum;
        string myString;
};

int main()
{
    Myclass object;

    object.myNum = 15;
    object.myString = "Garrett";

    return 0;
}
```

A class can have infinitely many instances, objects, as long as each object is named differently

## Member Functions
Functions that are declared within the definition of a class are called <em>member functions</em> which can be called throughout the duration of the program

There are two ways to define functions belonging to a class:
<ul>
  <li>Inside the class' definition</li>
  <li>Outside the class' definition</li>
</ul>

### Member Function Definition Inside Class

```cpp
class MyClass 
{
    public:
        void myMethod() {cout << "Garrett Ellis" << endl;}
};

int main()
{
    MyClass object;

    object.myMethod();

    return 0;
}
```

### Member Function Definition Outside Class
To define a function outside of its class' definition, the function needs to be declared within the class and then the function's definition needs to be defined outside of the class. This can be accomplished by writing the name of the class, followed by the scope resolution operator, <code>::</code>, followed by the name of the function

```cpp
class MyClass 
{
    public:
        void myMethod();
};

int main()
{
    MyClass object;

    object.myMethod();

    return 0;
}

void MyClass::myMethod()
{
    cout << "Garrett Ellis" << endl;
}
```

### Default Copying
By default, objects can be copied. This is done by a class' object being initialized with a copy of a different object within the same class:

```cpp
MyClass object1 = object2; //initialization
MyClass object1 {object2}; //initialization
```

### Access Control
Given the following class definition:

```cpp
class Date
{
    int day, month, year;

    public:
        void initialize(int, int, int);
};
```

The <code>public</code> access specifier separates the class' body into two parts. The declarations in the first part of the class are <em>private</em> and can only be used by the class' member functions

The second part, <em>public</em>, constitutes the part of the class that is public via the objects of the class. A <code>struct</code> is a <code>class</code> whose members are public by default whereas with a <code>class</code> its members are private by default

## Constructors
A better approach to declaring an object is by using a <em>constructor</em>. A constructor has the same name as the class itself and is a member function. For example:

```cpp
class Date
{
    int day, month, year;

    public:
        Date(int, int, int);    //constructor
};
```

### Constructor Parameters
Constructors can also take parameters which is useful for setting initial values for attributes. Here is an example of using a constructor to initialize an object

```cpp
class Car
{
    public:
        string brand, model;
        int year;
        Car(string x, string y, int z)
        {
            brand = x;
            model = y;
            year = z;
        }
};
```

Just like with functions, constructors can also be defined outside of its class

```cpp
class Car
{
    public:
        string brand, model;
        int year;
        Car(string, string, int);
};

Car::Car(string x, string y, int z)
{
    brand = x;
    model = y;
    year = z;
}
```

Here is a better way of initializing attributes of a class:

```cpp
class Car
{
    public:
        string brand, model;
        int year;
        Car(string brandX, string modelY, int yearZ)
            : brand(brandX), model(modelY), year(yearZ) {}
};
```

### Default Constructor
A default constructor is a constructor that can be called with no arguments. There can be multiple constructors in a single class as shown in the following:

```cpp
class Person
{
    private:
        string name;
        int age;
    
    public:
        //default constructor
        Person() : name("Unknown"), age(0) {}
        //constructor with name only
        Person(string nameX) : name(nameX), age(0) {}
        //constructor with both name and age
        Person(string nameX, int ageX) : name(nameX), age(ageX) {}
}
```

### Static Members
Static variables within classes are variables that belong to the class--not the instances of the class. All objects of the class will share the same copy of this variable

Static methods within classes also belong to the class and can be called without the need of using an object of the class. It cannot access members that are non-static

## Access Specifiers
Access specifiers define how the members, including the methods and attributes, of a class are accessed

In C++, there are three access specifiers:
<ul>
  <li><code>public</code> members are accessible from outside the class</li>
  <li><code>private</code> members cannot be accessed from outside the class</li>
  <li><code>protected</code> members cannot be accessed from outside the class; however, they can be accessed in inherited classes</li>
</ul>

```cpp
class MyClass
{
    public:
        int x;
    private:
        int y;
};

int main()
{
    MyClass myObject;
    myObject.x = 25 //allowed
    myObject.y = 50 //not allowed

    return 0;
}
```

## Encapsulation
<em>Encapsulation</em> is the principle to make sure that sensitive data is hidden from the users. This can be achieved by using the <code>private</code> access specifier. Public <em>get</em> and <em>set</em> methods are useful for using the sensitive information hidden with the <code>private</code> specifier

### Get and Set Methods
To access a private attribute, use public get and set methods such as in the following

```cpp
class Employee
{
    private:
        int salary;
    
    public:
        void setSalary(int newSalary) { salary = newSalary; }
        int getSalary() const { return salary; }
};
```

It is good practice to declare as many attributes as private. Encapsulation ensures better control over data

### Destructors
A destructor in C++ is a special member function of a class that is automatically called when the class' objects go out of scope or are explicitly deleted

The purpose of using a destructor is to free up heap memory

```cpp
class Demo {
public:
    Demo() {
        cout << "Constructor called" << endl;
    }

    ~Demo() {
        cout << "Destructor called" << endl;
    }
};
```
