<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#structure-variables'>Structure Variables</a>
  </li>    
  <li>
    <a href='#structure-types'>Structure Types</a>
  </li>    
  <li>
    <a href='#nested-arrays-and-structures'>Nested Arrays and Structures</a>
  </li>  
  <li>
    <a href='#unions'>Unions</a>
  </li>  
  <li>
    <a href='#enumerations'>Enumerations</a>
  </li>  
</ol>
</details>

## Structure Variables
<ul>
  <li>The elements of a structure do not have to be of the same type</li>
</ul>    

### Declaring Structure Variables
<ul>
  <li>Here is the syntax for declaring a structure variable

```cpp
struct variableName
{
    char variableOne;
    int variableTwo = 2;
    char name[12];
};
```
  </li>
  <li>The structure can contain any type of variable within it, such as chars, bools, ints, arrays, strings, ect</li>  
</ul>  

### Initializing Structure Variables
<ul>
  <li>Similar to an array, a structure variable can be initialized at the same time that it is declared</li>
  <li>Here is the syntax for initializing a structure variable:

```cpp
struct variableName
{
    char variableOne;
    int variableTwo;
    char name[12];
} Garrett = {'A', 21, "Garrett"},
  Evan = {'A', 22, "Evan"};
```
  </li>    
</ul>    

### Operations on Structures
<ul>
  <li>Rather than structures being accessed by position like arrays, structures are accessed by names</li>
  <li>To access a member of a structure, the dot operator is used. Here is the syntax for accessing a structure's members:

```cpp
structName.memberName;
```
  </li>
  <li>The assignment operator can be used on different variables of the same structure. By assigning one structure variable to another, the contents of the right-hand variable are copied to the contents of the left-hand variable
    <ul>
      <li>Here is an example of assigning one struct instance to another:

```cpp
struct part {
    int number;
    char name[LENGTH + 1];
};

part part1 = {528, "Garrett"}, part2;
part2 = part1;
```
  </li>
  </ul>
  </li>  
</ul>    

## Structure Types
### Declaring a Structure Tag
<ul>
  <li>A <em>structure tag</em> is a name used to identify a structure</li>
  <li>Here is the syntax for a structure tag:

```cpp
struct part
{
    int number;
    char name[nameLength + 1];
    int onHand;
}; 
```
  <ul>
    <li>Remember that there is a semicolon at the end of the braces is a semicolon</li>  
  </ul>
  </li>  
</ul>  

### Structures as Arguments and Return Values
<ul>
  <li>Functions can have structures as arguments and functions can return structure instances</li>
  <li>
    <a>Here is the syntax for passing a structure instance in a function call:</a>

```cpp
void functionName(struct strucName instanceName)k
{
    ...
}
```
  </li>
  <li>Here is the syntax for defining a function with a structure instance return type

```cpp
struct structName functionName(int variableName, char charVar)
{
    struct structName instanceName;

    return instanceName;
}
```
  </li>
</ul>  

## Nested Arrays and Structures
### Nested Structures
<ul>
  <li>Arrays can be used to store elements that are instances of struct variables</li>
  <li>Structures can even be nested within each other. For instance, an instance of structName can have a variable type of structName2</a>
    <ul>
      <li>Here is the syntax of a nested structure:

```cpp
struct Person {
    char first[FIRST + 1];
    char middle;
    char last[LAST + 1];
};

struct student {
    Person name;
    int id, age;
};
```
  </li>
  </ul>
  </li>
</ul>    

### Arrays of Structures
<ul>
  <li>Oftentimes, an array can be of type struct variable which means that the declared array contains instances of the struct</li>
  <li>Here is the syntax for creating an array of type struct variables:

```cpp
struct structVariable arrayName[arraySize];
```
  </li>
  <details>
    <summary>Write a structure called Students with the following fields: name, age, grade, and roll_number. Write a program to input details for five students, then display them in a formatted way</summary>

```cpp
//Complete the search function that loops up the part in inv (an array of struct part). The function prompts the user to enter a part number. If the part exists, print the name and quantity on hand; if not, print a "part not found" message. Parameter np contains the number of parts in the array

//Assume the structure part is defined as:
struct part {
    int number;
    char name[31];
    int on_hand;
};

void search(struct part inv[], int np)
{
    int number;
    cout << "Enter part number: ";
    cin >> number;
}
```
<ul>
  <details>
    <summary>Output</summary>

```cpp
void search(struct part inv[], int np)
{
    int number, found = 0;

    cout << "Enter part number: ";
    cin >> number;

    for (int i = 0; i < np; i++)
        if (inv[i].number == number) {
            cout << inv[i].name;
            cout << inv[i].on_hand;
        }

    if (!found)
        printf("part not found");
}
```
  </details>
    </ul>  
  </details>
</ul>    

## Unions
A union is a special data structure that allows different members to occupy the same memory address. This is different than a struct where each of the struct's member have their own memory address. Due to all members sharing the same slot in memory, only one of the union's members can hold a value at a time

```cpp
union Data {
    int i;
    float f;
    char c;
};

int main() {
    Data d;
    d.i = 42;
    cout << "d.i = " << d.i << endl;

    d.f = 3.14;
    cout << "d.f = " << d.f << endl;

    d.c = 'A';
    cout << "d.c = " << d.c << endl;

    //now d.i and d.f have been overwritten by d.c
    return 0;
}
```

## Enumerations
An <em>enumeration</em> is a data type that stores a set of integers whose's values are specified by the user

```cpp
enum Color {
    RED,     // 0
    GREEN,   // 1
    BLUE     // 2
};
```

By default, the first element in an enum is synonymous with the integer zero, where the elements following increase by one integer. However, an enum's values can be any integer and does not have to follow an order. The user can decide which integer to assign to an enum

The purpose for using enumeration is to improve the readability of one's code by avoiding the use of magic numbers
