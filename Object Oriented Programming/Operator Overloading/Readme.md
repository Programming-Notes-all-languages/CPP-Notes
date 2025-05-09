<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#operator-functions'>Operator Functions</a>
  </li> 
</ol>
</details>

## Operator Functions
Here are some of the commonly overloaded operators:

<ul>
  <li>Arithmetic: <code>+</code>, <code>-</code>, <code>*</code>, <code>/</code>, <code>%</code></li>
  <li>Comparison: <code>==</code>, <code>!=</code>, <code><</code>, <code>></code>, <code><=</code>, <code>>=</code></li>
  <li>Assignment: <code>=</code>, <code>+=</code>, <code>-=</code>, <code>*=</code>, <code>/=</code>, <code>%=</code></li>
  <li>Unary: <code>++</code>, <code>--</code>, <code>-</code>, <code>!</code></li>
  <li>Subscript: <code>[]</code></li>
  <li>Function Call: <code>()</code></li>
  <li>Dereference: <code>*</code>, <code>-></code>, <code>->*</code></li>
  <li>Input/Output: <code><<</code>, <code>>></code></li>
</ul>

### <code>friend</code> Functions
For overloading operators, some functions required for overloading the operator need to be friend functions. This is mainly the case for overloading the insertion and extraction operator. The <code>friend</code> keyword gives external functions or classes access to private or protected members

Even though <code>friend</code> functions are declared inside of a class, <code>friend</code> functions are not members of the class in which they are declared. This means that when defining <code>friend</code> functions, this is done without the scope operator

### Overloading <code>ostream</code> and <code>istream</code>
<code>ostream</code> is the output stream which is used by <code>cout</code>

<code>istream</code> is the input stream which is used by <code>cin</code>

```cpp
class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        friend ostream& operator<<(ostream &out, const Person &p);
};
```

<details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        friend ostream& operator<<(ostream &out, const Person &p);
};

int main()
{
    Person Garrett("Garrett", 22);

    cout << Garrett;

    return 0;
}

ostream& operator<<(ostream &out, const Person &p)
{
    out << "Name: " << p.name << endl << "Age: " << p.age << endl;

    return out;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Name: Garrett
Age: 22
      </pre>  
    </details>
  </ul>  
</details>  

### Overloading <code>+</code> (Addition) and <code>-</code> (Subtraction) Operator
```cpp
class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        Person operator+(const Person &other) { return Person(other.name, other.age + age); }
};
```

<details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        Person operator+(const Person &other) { return Person(other.name, other.age + age); }

        void display() { cout << name << endl << age << endl; }
};

int main()
{
    Person Garrett("Garrett", 22);
    Person Seth("Seth", 23);
    Person result = Garrett + Seth;

    result.display();

    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Seth
45
      </pre>  
    </details>
  </ul>  
</details>  

### Overloading Pre-Increment (<code>++a</code>) and Pre-Decrement (<code>--a</code>)
When overloading these operators, the <code>this</code> pointer is often used. The <code>this</code> pointer points to the object that is invoking the member function. Therefore, dereferencing <code>this</code> like this, <code>*this</code>, gives access to the actual object

```cpp
class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        Person& operator++()
        {
            ++age;
            return *this;
        }
};
```

<details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        Person& operator++()
        {
            ++age;
            return *this;
        }

        void display() const { cout << "Age: " << age << endl; }
};

int main()
{
    Person Garrett("Garrett", 22);
   
    ++Garrett;
    
    Garrett.display();

    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Age: 23
      </pre>  
    </details>
  </ul>  
</details>  

### Overloading Post-Increment (<code>a++</code>) and Post-Decrement (<code>a--</code>)

```cpp
class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        Person operator++(int)
        {
            Person temp = *this;
            ++age;
            return temp;
        }
};
```

<details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    
    public:
        Person() : name("NULL"), age(0) {}
        Person(string nameX, int ageY) : name(nameX), age(ageY) {}

        Person operator++(int)
        {
            Person temp = *this;
            ++age;
            return temp;
        }

        void display() const { cout << "Age: " << age << endl; }
};

int main()
{
    Person Garrett("Garrett", 22);
   
    Garrett++;
    
    Garrett.display();

    return 0;
}
```

<ul>  
  <details>
    <summary>Output</summary>
      <pre>
Age: 23
      </pre>  
    </details>
  </ul>  
</details>  
