<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#local-variables'>Local Variables</a>
  </li> 
  <li>
    <a href='#external-variables'>External Variables</a>
  </li> 
  <li>
    <a href='#blocks'>Blocks</a>
  </li> 
  <li>
    <a href='#organizing-a-c-program'>Organizing a C++ Program</a>
  </li> 
</ol>
</details>

## Local Variables
<ul>
  <li>A variable that is declared within the body of the function is said to be <em>local</em></li>
  <li>A local variable will keep its value during the duration of the function's execution. When the function terminates, the variable may or may not retain the value from the previous execution of the function</li> 
  <li>The <em>scope</em> of a variable is within the function it was declared in. This means that other functions within the program can share variable names that appeared in other functions</li>   
</ul>    

### Static Local Variables
<ul>
  <li>A variable can have the identifier <em>static</em> in front of it which means that the variable occupies a permanent storage location. For instance, if a static variable is declared in a function outside of main, even after that outside function terminates, the static variable will still hold its value</li>
  <li>Static variables still have scope which means it is not visible to other functions--only the function in which the static variable was declared and initialized</li>
  <li>Here is the syntax for a static variable: <code>static dataType variableName;</code></li>    
</ul>    

## External Variables
<ul>
  <li>External variables, also known as <em>global variables</em> have two key properties that are different than local variables
    <ul>
      <li>They have static variable properties meaning that there is a permanent spot in memory for them</li>
      <li>They have scope both within and outside of the variable in which they were declared. They are accessible anywhere in the program</li>
    </ul>
  </li>
  <li>It is often best practice to limit the use of external variables and have functions communicate via their parameters</li>  
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initializations
    int arr[] = {1, 2, 3, 4, 5};
    int n = 10;
    {
        int n = 20;
        for (int i = 0; i < 3; i++)
        {
            int n = i;
            cout << n << " ";
        }
        cout << n << " ";
    }
    cout << n << " ";
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
0 1 2 20 10
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

//function definition for test
void test(int a)
{
    cout << a << " "; // prints the value of 'a' passed to the function
}

int main()
{
    int a = 5;
    test(a);
    {
        int a = 10;
        test(a);
        {
            int a = 15;
            test(a);
        }
        test(a);
    }
    test(a);
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
5 10 15 10 5
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

int main()
{
    //variable declaration and initialization
    int i = 1;

    //nested for loops
    for (int i = 0; i < 3; i++)
    {
        for (int i = 0; i < 2; i++)
            cout << i << " ";
        cout << i << " ";
    }
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
0 1 0 0 1 1 0 1 2
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

int main()
{
    int i = 5;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            int i = 10;
            i++;
            cout << i << " ";
        }
        cout << i << " ";
    }
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
11 11 11 0 11 11 1 11 2
        </code>
      </pre>  
    </details>
  </ul>  
  </details>
</ul>     

## Blocks
<ul>
  <li>Variables that are declared within blocks, { declarations statements }, have block scope which means they cannot be referenced outside of the block that encapsulates them. Variables declared within blocks can be declared static</li>
</ul>  

## Organizing a C++ Program
<ul>
  <li>Here is the proper way to organize a program in C++:
    <ul>
      <li>#include directives</li>  
      <li>#define directives</li> 
      <li>Type definitions</li> 
      <li>Declarations of external variables</li> 
      <li>Prototypes for functions other than main</li> 
      <li>Definition of main</li> 
      <li>Definitions of other functions</li> 
    </ul>
  </li>
</ul>      
