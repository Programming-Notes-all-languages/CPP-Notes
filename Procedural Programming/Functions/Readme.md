<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#defining-and-calling-functions'>Defining and Calling Functions</a>
  </li> 
  <li>
    <a href='#function-declarations'>Function Declarations</a>
  </li> 
  <li>
    <a href='#arguments'>Arguments</a>
  </li> 
  <li>
    <a href='#the-return-statement'>The return Statement</a>
  </li> 
  <li>
    <a href='#program-termination'>Program Termination</a>
  </li> 
  <li>
    <a href='#recursion'>Recursion</a>
  </li> 
</ol>
</details>

## Defining and Calling Functions
### Function Definitions
<ul>
  <li>Here is the syntax for a <em>function definition</em> in C++:

```cpp
returnType functionName (parameters) 
{
    statements;
}
```
</li>
    </ul>    
  </li>
  <li>Here are a few rules governing the return type of a function:
    <ul>
      <li>Functions cannot return arrays but can return any other data types</li>
      <li>Having a return type of void means that the function does not return a value unlike a function of type int and char</li>
      <li>In older versions of C++, if the return type of a function was omitted, then the return type defaulted as int; however, in newer versions of C++, a return type is required when writing the definition of a function</li>    
    </ul>
  </li>   
  <li>After the return type and name of the function comes the function's parameters. Each parameter needs a data type and a name. If there is more than one parameter, each parameter is separated by a comma</li>
  <li>If a function has no parameters, then the word void should appear where the parameters of a function would normally appear</li> 
  <li>A function can have variable declarations like within the main function. However, the variables declared within the function belong exclusively to that function and not other functions</li>      
</ul>    

### Function Calls
<ul>
  <li>A function call contains the name of the function followed by the names of the parameters, just their names and not their return type, enclosed in parentheses</li>
  <li>A void function is always followed by a semicolon to turn the function's call into a statement</li>
  <li>On the other hand, a function with a return type other than void can be stored in a variable to save the value being returned by the function</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;
          
//isEven function definition which returns a boolean value indicating whether its parameter is even or not
bool isEven(int n)
{
    //conditional statement which checks if n is not even
    if (n % 2 == 0)
        return false;
    else
        return true;
}

int main()
{
    //variable declarations and initializations
    int input;
    bool isPrimeFlag = true;
    
    //getting number from the user
    cout << "Enter a number: ";
   cin >> input;
    
    //conditional statement which prints whether input is a even or not
    if (isEven(input))
        cout << input << " is even\n";
    else
        cout << input << " is not even\n";
    return 0;
}
```
  <ul>  
    <details>
      <summary>Output</summary>
        <pre>
          <code>
Enter a number: <u>3456345</u>
3456345 is even
          </code>
        </pre>  
      </details>
    </ul>  
  </details>     
</ul>    

## Function Declarations
<ul>
  <li>C++ does not require that the definition of the function come before main. It is good practice to declare all functions before main and then define them after main</li>
  <li>Here is the syntax for a <em>function declaration</em>: <code>returnType functionName(parameters);</code></li> 
  <li>Function declarations are also known as <em>function prototypes</em>. Function prototypes do not have to include the names of the function's prototypes. Only the data types of the function need to be in the function's declaration. For example, if a function has four parameters of type double, then double, double, double, double needs to be within the parentheses in the function's declaration</li>  
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

//function prototype for isEven function
bool isEven(int);

int main()
{
    //variable declarations and initializations
    int input;
    bool isPrimeFlag = true;

    //getting number from the user
    cout << "Enter a number: ";
    cin >> input;
    
    //conditional statement which prints whether input is a even or not
    if (isEven(input))
        cout << input << " is even\n";
    else
        cout << input " is not even\n";
    
    return 0;
}

//isEven function definition which returns a boolean value indicating whether its parameter is even or not
bool isEven(int n)
{
    //conditional statement which checks if n is not even
    if (n % 2 == 0)
        return false;
    else
        return true;
}
```
  <ul>
    <details>
      <summary>Output</summary>
        <pre>
          <code>
Enter a number: <u>3456345</u>
3456345 is even
          </code>
        </pre>  
      </details>
    </ul>  
  </details>  
</ul>    

## Arguments
<ul>
  <li>The difference between parameters and <em>arguments</em> is that parameters exist in the function's definition and declaration whereas arguments appear within the function's call</li>
  <li>In C++, arguments are <em>passed by value</em> which means that when a function is called, copies of the arguments' values are passed to the function and any changes made to the arguments' values within the function are not reflected within the function in which the function is called</li>
</ul>    

### Function Overloading
<ul>
  <li><em>Overloading</em> means defining two or more functions or operators that have the same name, but whose effect depends on the types of their actual arguments</li>
  <li><em>Function overloading</em> occurs when two or more functions are defined with the same name but with different argument lists</li>
  <li>Here is an example of function overloading within a program:</li>
<details>
    <summary>Example program</summary>

```cpp
void print();
void print(const int);
```
<ul>   
  <details>
    <summary>Output</summary>

```cpp
//Both functions have the same name, but the compiler considers the type of the actual argument and invokes the appropriate functions, that is, the one with the signature closest to the actual argument
```
  </details>
  </ul>  
</details> 
</ul> 

### Array Arguments
<ul>
  <li>Often, arrays are used as arguments when a function is called. Arrays are also often parameters within a function</li>
  <li>When making an array as a parameter of a function, the data type is needed, then the name of the function followed by []. A second parameter is needed for the size of the array which is just an int parameter</li>  
  <li>When calling a function with a parameter of an array, the brackets are omitted when passing the array in the function call. For instance, let's say that there is a function called fun which contains two parameters: an int array and an int that contains the size of the array. The call to this function could be as follows: <code>x = functionName(array, arraySize);</code></li>  
  <details>
    <summary>Example program</summary>

```cpp
//Write a function that reverses the elements of an integer array
//void reverse(int a[], int n)
```
<ul>   
  <details>
    <summary>Output</summary>

```cpp
//function definition for reverse
void reverse(int a[], int n)
{
    //for loop which reverses the elements of the array
    for (int i = 0, j = n - 1; i < j; i++, j--) 
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}   
```
  </details>
  </ul>  
</details>
<details>
    <summary>Example program</summary>

```cpp
//Write a function that sorts the elements of an integer array a in non-decreasing order using selection sort. For example, if a contains the elements {2, 3, 6, 3, 5}, the function will sort the elements of the array so it contains {2, 3, 3, 5, 6}. The function has the following parameters: a is the integer array, n is the length of a. You are not allowed to use any other arrays except array a to solve this problem
//void my_sort(int a[], int n)
```
<ul>   
  <details>
    <summary>Output</summary>

```cpp
//function definition for my_sort which sorts the elements of an integer array a in non-decreasing order using selection sort
void my_sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (j = i; j < n; j++)
        {
            if (a[j] < a[smallest])
                smallest = j;
        }

        int temp = a[smallest];
        a[smallest] = a[i];
        a[i] = temp;
    }
}
```
  </details>
  </ul>  
</details>
<details>
    <summary>Example program</summary>

```cpp
//Write a function that rotates an array of integers to the right by a given number of steps. For example, given an array {1, 2, 3, 4, 5} and k = 2, the array should become {4, 5, 1, 2, 3}
//void rotateArray(int arr[], int n, int k)
```
<ul>   
  <details>
    <summary>Output</summary>

```cpp
//function definition for rotateArray which rotates an array of integers to the right by a given number of steps
void rotateArray(int arr[], int n, int k)
{
    //variable declaration and initialization
    int temp[n];

    //for loop which moves the elements of the array to the right by k steps
    for (int i = 0, j = k; i < n; i++, j++)
    {
        if (j == n)
            j = 0;
        temp[j] = arr[i];
    }
} 
```
  </details>
  </ul>  
</details>
</ul>  

### Variable-Length Array Parameters
<ul>
  <li>In later versions of C, when arrays are a size of variable length, the variable determining the size of the array can actually be encapsulated within the brackets within the function's definition such as in the following: int sumArray(int size, int array[size])... The parameter specifying the size of the array must come first in the parameter list before the array parameter</li>  
  <li>When writing the function's prototype for a function that contains a variable-length array as a parameter, the following can be done: int sumArray(int, int[*]); Here, the * notation says that the size of the array is determined by the integer value of the first parameter preceding the int array</li>
</ul>  

### Using static in Array Parameter Declarations
<ul>
  <li>In later versions of C, the static keyword can be encapsulated within the brackets of an array parameter in a function's declaration and definition. After the keyword static comes an integer number which represents the minimum length of the array. What this does is that it lets the compiler know to store x amount of data for the array with a minimum size of static x. If an array is multidimensional, static may only be used in the array's first dimension</li>
</ul>    

### Compound Literals
<ul>
  <li>In later versions of C++, an array can be created within a function's call and that array can be an argument that is passed to the function</li>
  <li>Here is the syntax for a compound literal: <code>variableX = functionName((dataType []){element0, element1, element2, ...}, parameter1, parameter2, ...);</code></li>  
</ul>   

## The return Statement
<ul>
  <li>A function that has a return type, other than void, must use the return statement at least once to specify what value will be returned when a function is called</li>
  <li>Here is the syntax for the return statement: <code>return expression;</code></li>
  <li>Sometimes, more complex expressions can be expressions following the return statement, such as a conditional operator: <code>return (n >= 0) ? (n) : (0);</code></li>
  <li>If the return type of the function does not match the function's return type, then the value being returned by the function will be implicitly converted to match the function's return type</li> 
  <li>return statements may appear in functions that are of type void; however, the return statement must not contain an expression, just return alone</li>    
  <li>The return statement stops the execution of the function immediately and returns control back to the function's call</li>  
</ul>  

## Program Termination
<ul>
  <li>To terminate the program in main, the return statement can be used. Another way of terminating the program in main is using the exit function. exit belongs to the <a><</a>stdlib.h<a>></a> library</li>
  <li>To indicate normal termination of the program, 0 can be passed to the exit function like the following: exit(0);</li>  
</ul>    

## Recursion
<ul>
  <li>A function is recursive if it calls itself</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

//function prototype for factorial
int factorial(int);

int main()
{
    //variable declaration and initialization
    int number;
    
    //getting user input for number variable
    cout << "Enter a number: ";
    cin >> number;
    
    //calling factorial function and printing result
    cout << number << "! is: " << factorial(number) << endl;
    
    return 0;
}

//recursive function to calculate factorial of a number
int factorial(int n)
{
    //conditional statement which checks if n is equal to 1
    if (n == 1)
        return n;
    
    //conditional statement which evaluates to true if n is yet to equal one    
    else
        return n-- * factorial(n);
}
```
<ul>   
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Enter a number: <u>10</u>
10! is: 3628800
        </code>
      </pre>  
    </details>
  </ul>  
</details>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

//function definition for countUpDown 
void countUpDown(int n)
{
    //conditional statement if n is greater than 0
    if (n > 0)
    {
        cout << n;
        countUpDown(n - 1);
        cout << n;
    }
}

int main()
{
    //calling countUpDown function
    countUpDown(3);
    
    return 0;
}
```
<ul>   
  <details>
    <summary>Output</summary>
      <pre>
        <code>
3 2 1 1 2 3
        </code>
      </pre>  
    </details>
  </ul>  
</details>
  <details>
    <summary>Example program</summary>

```c
#include <iostream>
using namespace std;

//function definition for reversePrint
void reversePrint(int n)
{
    //conditional statement which checks if n is not equal to 0
    if (n != 0)
    {
        cout << n % 10;
        reversePrint(n / 10);
    }
}

int main()
{
    //calling reversePrint function
    reversePrint(1234);
    
    return 0;
}
```
<ul> 
  <details>
    <summary>Output</summary>
      <pre>
        <code>
4 3 2 1
        </code>
      </pre>  
    </details>
  </ul>  
</details>
  <details>
    <summary>Example program</summary>

```c
#include <stdio.h>
using namespace std;

//function definition for oddDigitsReverse
void oddDigitsReverse(int n)
{
    //conditional statement which checks if n does not equal 0
    if (n != 0)
    {
        if ((n % 10) % 2 != 0)
            cout << n % 10;
        
        oddDigitsReverse(n / 10);
    }
}

int main()
{
    //calling oddDigitsReverse function 
    oddDigitsReverse(13578);
    
    return 0;
}
```
<ul>   
  <details>
    <summary>Output</summary>
      <pre>
        <code>
7531
        </code>
      </pre>  
    </details>
  </ul>  
</details>
<details>
    <summary>Example program</summary>

```cpp
//Write a function that sorts an array in ascending order recursively
//void mergeSort(int a[], int start, int end)
```
<ul>   
  <details>
    <summary>Output</summary>

```cpp
//function definition for mergeSort which sorts an array in ascending order recursively
void mergeSort(int a[], int start, int end)
{
    //conditional statement which checks if end is equal to 1
    if (end == 1)
        return;

    //conditional statement which checks if end is greater than 1
    else
    {
        //for loop which finds the largest element in the array and moves it to the last position in the array
        int max = a[end - 1], temp;
        for (int i = 0, max = a[end - 1], temp; i < end; i++)
            if (a[i] > max)
            {
                max = temp = a[i];
                a[i] = a[end - 1];
                a[end - 1] = temp;
            }

        return mergeSort(a, 0, --end);
    }    
}
```
  </details>
  </ul>  
</details>
</ul>    
