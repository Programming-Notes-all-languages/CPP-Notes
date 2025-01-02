<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#compiling-and-linking'>Compiling and Linking</a>
  </li> 
  <li>
    <a href='#general-form-of-a-simple-program'>General Form of a Simple Program</a>
  </li>    
  <li>
    <a href='#comments'>Comments</a>
  </li>  
  <li>
    <a href='#variable-assignment-and-initialization'>Variable Assignment and Initialization</a>
  </li>  
  <li>
    <a href='#naming-and-using-variables'>Naming and Using Variables</a>
  </li>  
  <li>
    <a href='#whitespace-and-basic-formatting'>General Form of a Simple Program</a>
  </li>  
  <li>
    <a href='#introduction-to-literals-and-operators'>Introduction to Literals and Operators</a>
  </li>
  <li>
    <a href='#atomic-data-types-and-type-conversion'>Atomic Data Types and Type Conversion</a>
  </li>
  <li>
    <a href='#introduction-to-iostream'>Introduction to iostream</a>
  </li>  
  <li>
    <a href='#constant-variables'>Constant Variables</a>
  </li> 
  <li>
    <a href='#escape-sequences'>Escape Sequences</a>
  </li>
  <li>
    <a href='#arithmetic-operators'>Arithmetic Operators</a>
  </li>    
</ol>
</details>

## Compiling and Linking
<ul>
  <li>There are three steps in running C++ code:
    <ul>
      <li><em>Preprocessing</em>: this is the step where the program is given to the preprocessor which obeys <em>directives</em> like <code>#include</code> and <code>#define</code></li>
      <li><em>Compiling</em>: the code that was just modified by the preprocessor is now modified by the <em>compiler</em>. The compiler translates the code into <em>object code</em>. Object code is a machine-readable form of program, but is not yet executable</li>  
      <li><em>Linking</em>: this is the final step in running C code where the <em>linker</em> combines the object code produced through the compilation process with any additional code needed to run the program completely. This combination of code creates an executable file which can be used to run the program</li>
    </ul>
  </li>
  <li>To compile code within the terminal of an IDE, proceed with the following. The file that contains the program is called main.c; therefore, its compilation can be accomplished with the following command: g++ -Wall -o program main.cpp
    <ul>
      <li><code>-Wall</code> enables all warnings; if there are any warnings, they will be printed on the screen</li>
      <li><code>-o program</code> specifies the executable's file name; in this case, the executable's name is program</li>
      <li>main.cpp is the source file to be compiled</li>  
    </ul>  
  </li>  
  <li>To then execute the program, type the following command into the terminal: ./program</li>
</ul>    

## General Form of a Simple Program
<ul>
  <li>
    <a>Here is the general form of a C++ program:

```cpp
directives
int main()
{
    statements;
}
```
</a>
  </li>
  <li>Before a program can be compiled, it needs to be edited first by the preprocessor. The code that is used by the preprocessor is called directives. One very common directive is the <code>#include <iostream></code> directive which contains information regarding C++'s standard input and output processes. By including the <code>#include <iostream></code> directive within a program, the information that is associated with stdio.h library is added to the program before compilation
    <ul>
      <li>Directives will always start with the # symbol; they will always be only one line long; and they do not need any special marker at the end of the directive (like a semicolon)</li>
    </ul>    
  </li>  
  <li>A program can also contain additional functions in addition to the main function. The main function is mandatory and is a special function--it is always called when a program executes</li>  
  <li>At the end of the main function, it normally returns 0;. This statement has two effects: it terminates the main function which ends the program and upon termination, the main function returns the integer zero. The return of the integer zero determines the normal termination of the program</li>
  <li>A <em>statement</em> is a command that is to be executed upon running the program. An example of a statement is the return 0; statement</li>  
</ul>  

## Comments
<ul>
  <li><em>Comments</em> are notes created by the programmer that are included within the program. The compiler ignores these comments as they are only there for the programmer's use</li>
  <li>In C++ there are two styles of comments:
    <ul>
      <li><em>Single-line comments</em>: are denoted with the double forward slash characters, //, and tell the compiler to ignore all code from the two forward slashes to the end of the line of code. Line comments are usually safer</li>
        <details>
        <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    //Everything here is ignored

    return 0;
}
```
<ul>
        <details>
        <summary>Output</summary>
            <pre>
            <code>
        Hello world!
            </code>
            </pre>  
            </details>
          </ul>      
        </details>
      <li><em>Multi-line comments</em>: are denoted by the /* and */ set of characters. Everything that is enclosed within the /* and */ set of characters is a comment and therefore ignored by the compiler</li>  
        <details>
        <summary>Example Program</summary>

```cpp  
#include <iostream>
using namespace std;

int main()
{
    /*This is a multi-line comment.
    This line will be ignored.
    So will this one.*/

    return 0;
}
```
<ul>
        <details>
        <summary>Output</summary>
            <pre>
            <code>
            </code>
            </pre>  
        </details>
        </details>
        </ul>
    </ul>    
  </li> 
  <li>Multi-line comments can be comprised of multiple single-line comments; however, multi-line comments cannot be embedded with any multi-line comments</li>       
  <li>Comments are useful to explain what certain lines and blocks of code do, especially when other programmers are reading the code</li>  
</ul> 

## Variable Assignment and Initialization
<ul>
  <li>A <em>variable</em> is a name given to an instance of a data type not defined by the user. The name of this instance is also called an <em>identifier</em>. Variables and identifiers are two words that mean the same thing</li>
  <li>Every variable must have a <em>type</em> which specifies the type of data that the variable will store</li> 
</ul>

### Declaration
<ul>   
  <li>A variable must <em>declared</em> before it can be used within the program. To declare a variable within C, two things are needed: first, the <em>type</em> of the variable and then the variable's <em>name</em></li>
    <ul>
      <li>Here are two examples of variable declaration:

```cpp
int height;
double profit;
```
<ul>
          <li>What the declarations above say are that height can store an integer value and float can store a decimal value</li>
        </ul>
      </li>  
    </ul>    
  <li>If multiple variables need to be declared of the same type, their declarations can be combined as shown in the following: int height, length, width, volume;</li>  
</ul>

### Initialization
<ul>
  <li><em>Initialization</em> is the process in which a variable is assigned a memory address</li>
  <li>After a variable has been defined, it can be assigned a value using the <em>assignment operator</em>. The assignment operator is the equals sign character, =. The process of a variable being initialized is called <em>assignment</em>. Assignment and initialization are two words that mean the same thing</li>
  <ul>
    <li><code>int variable = "literal"; //literal on the right side of the assignment operator is assigned to the variable on the left side of the assignment operator</code></li>
  </ul>              
  <li>An <em>initializer</em> is the information, whether that be a literal or another variable, that is used to initialize a variable</li>
  <li>Here are the multiple types of initialization:
    <ul>
      <li><em>Default initialization</em>: when a identifier is not assigned an initializer by the user. In this scenario, the variable is assigned a garbage value given by the computer
        <ul>
          <li><code>int a;</code></li>
        </ul>    
      </li>
      <li><em>Copy initialization</em>: when an initializer is provided after the identifier and assignment operator</a>
        <ul>
          <li><code>int b = 5;</code></li>
        </ul>
      </li>
      <li><em>Copy initialization</em>: when an initializer is provided after the assignment operator within braces</a>
        <ul>
          <li><code>int e = {7}</code></li>
        </ul>
      </li>  
    </ul>
  </li>   
  <li>Multiple variables can be initialized on the same line where commas separate each variable's assignment. An example of this is the following: <code>int height = 8, length = 12, width = 10;</code></li> 
  <li>A variable that has not been initialized is called an <em>uninitialized variable</em>
    <ul>
      <li>Printing out an uninitialized variable to the console causes a random value to be stored in the variable's memory address</li>
    </ul>    
  </li>   
</ul>

## Naming and Using Variables
<ul>
  <li>There are a few rules that need to be adhered to when initializing variables within C++:
    <ul>
      <li>Variable names can only contain the following: letters, numbers, and underscores. Variable names can start with letters and underscores, but not numbers. Do not start a variable, however, with an underscore. An identifier cannot contain the following character: -</li>
      <li>C++ does not allow spaces within any portion of a variable's name</li>
      <li>C++ is a case-sensitive language that distinguishes between upper and lower-case characters in identifiers</li>  
      <li>A good practice is to avoid using keywords and function names as variable names. An identifier cannot be one of C++'s keywords<</li>
    </ul>  
  </li>
</ul>  

## Whitespace and Basic Formatting
<ul>
  <li><em>Whitespace</em> is a term that refers to characters that are used for formatting purposes; in C++, this refers primarily to spaces, tabs, and newlines</li>  
  <li>The C++ compiler generally ignores whitespaces; therefore, C++ is a whitespace-independent language
    <ul>
      <li>The one exception where the C++ compiler does not pay attention to whitespace is inside quoted text</li>
    </ul>    
  </li>  
  <li>Variable names cannot contain whitespaces</li> 
</ul>

## Introduction to Literals and Operators
<ul>
  <li>
    <a><em>Literals</em> are fixed values that have been inserted directly into the source code</a>
    <ul>
      <li>Examples of literals are 1, 2.5, "garrett", and 'c'. These are literals because you cannot assign different values to those terms</li>
    </ul>
  </li>
  <li><em>Operators</em> are symbols that perform operations on variables and values
    <ul>
      <li>Operators can be chained together; the output of one operation can be used as the input for another operator</li>
    </ul>
  </li>
</ul>   

## Atomic Data Types and Type Conversion
<ul>
  <li><em>bool</em>: has two possible values and stores one of the following: true or false</li>
  <li><em>string</em>: used to store a list of characters or a single character; however, C++ does not have a built-in string type. A string in C++ behaves as an array of characters</li>
</ul>

### Integer
<ul>
  <li>Four qualifiers may be applied to C++'s integer types: signed, unsigned, long, and short. Identifiers with a variable type of type integer with the signed qualifier represent all positive or negative integers including zero. Identifiers with a variable type of type integer with the unsigned qualifier represent all integers greater than or equal to zero. Identifiers with a long modifier specifies a larger integer type and a short modifier specifies a smaller integer type</li> 
  <li><em>char</em>: typically used to store a character</li>
    <ul>
      <li>According to the ASCII table, each character is assigned to an integer meaning that each character on a keyboard can be represented by an integer. char is an integer, but it also represents the integer form of all characters</li>
    </ul>    
  <li><em>int</em>: used to store an integer</li>   
  <li>int and char are all signed by default, meaning that the declaration of these variables without the signed qualifier still has the same functionality as if the signed qualifier was included in the identifier's initialization</li>   
</ul>  

### Float  
<ul>  
  <li><em>float</em>: used to store a decimal number</li>
  <li>
    <a><em>double</em>: used to store a decimal number</a>
    <ul>
      <li>long doubles exist which store 10 bytes instead of double which is eight bytes</li>
    </ul>    
  </li>
</ul>

### Size Comparisons of Data Types
<ul>    
  <li>SMALLEST --- char << int << float << double --- GREATEST
    <ul>
      <li>Smaller data types can be stored in a larger data type. For example, an int can be stored in a float or a double; however, larger data types cannot be stored in a containers of smaller storage types</li>
    </ul>     
  </li> 
</ul>

## Introduction to iostream
<ul>
  <li><em>Input/output library</em>: is part of C++'s iostream library and deals with basic user input and output. To use this library, it must be included at the top of the program. This is done by adding <code>#include <iostream></code></li>
  <li><em>cout << </em>: allows for text and information to be printed to the console. No newline character is printed after cout << ; therefore, the newline character would need to be included at the end of the print statement</a>
  </li> 
  <details>
  <summary>Example Program</summary>    

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n"; //prints Hello World! to the console
    
    return 0;
}
```
<ul>
<details>
  <summary>Output</summary>
    <pre>
      <code>
Hello World!
      </code>
      </pre>  
    </details> 
  </ul>   
  </details>  
  <details>
  <summary>Example Program</summary>    
    
```cpp
#include <iostream>
using namespace std;

int main()
{
    unsigned height = 1, weight = 2;

    cout << "Height: " << height << " Weight: " << weight << endl;
    
    return 0;
}
```
<ul>
<details>
  <summary>Output</summary>
    <pre>
      <code>
Height: 1 weight: 2
      </code>
    </pre>  
  </details>
  </ul>  
  </details>  
  <li><em>cin >></em>: reads input from the user's keyboard</li>  
  <details>
  <summary>Example Program</summary>    

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration
    char firstLetter;

    cout << "What is the first letter of your name?: ";
    cin >> firstLetter;
    cout << "The first letter of your name is: " << firstLetter << endl;
    
    return 0;
}
```
<ul> 
  <details>
    <summary>Output</summary>
      <pre>
        <code>
The first letter of your name is: G
        </code>
      </pre>  
    </details>
  </ul>  
  </details>  
  <details>
  <summary>Example Program</summary>    

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration
    string name;

    cout << "What is your name?: ";
    cin >> name;
    cout << "Your name is: " << name << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Your name is: Garrett
        </code>
      </pre>  
    </details>
  </ul>  
  </details>           
</ul> 

## Constant Variables
<ul>
  <li><em>Constant variable</em>: a variable whose value cannot change once it is declared and initialized
    <ul>
      <li>Must use the keyword <em>const</em> or the define preprocessor directive</li>
      <li>Must declare and initialize the const variable on the same line</li>
      <ul>
        <li><code>const double SIZE = 3.14; //legal</code></li>
        <li><code>const double;<br />SIZE = 3.14; //illegal since variable declaration and initialization do not take place on the same line of code</code> </li>
      </ul>
      <li>By convention, the name of all constant variables are uppercase</li>  
      <li>The syntax for the define preprocessor statement is the following: <code>#define identifier literal</code> and occurs above the main() function</a>
        <ul>
          <li><code>#define PI 3.14159</code>
            <ul>
              <li>Now a macro has been defined. The name of the macro is PI and the macro's value is 3.14159</li>
            </ul>    
          </li>
        </ul>    
        <details>
        <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

#define MAX 10

int main()
{
    cout << "The value of MAX is " << MAX << endl;
    
    return 0;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
The value of MAX is 10
        </code>
        </pre>  
        </details>
        </ul>  
        </details>
        <ul>
          <li>When combining macros, the compiler does not compute the embedded macros on the line of declaration; instead, the line of macros, with or without constants, is treated as a line of variables where this line has no greater precedence than the code that comes before or after the macro's call within main or any other function. An example of this is in the following program:
            <ul>
            <details>
            <summary>Example Program</summary>

```cpp   
#include <iostream>
using namespace std;

//preprocessor directives definitions
#define ONE 1
#define TEN 10
#define HUNDRED ONE + TEN + TEN
#define THOUSAND HUNDRED + TEN

int main()
{
    cout << THOUSAND * 10 << endl;
    
    return 0;
}
```    
<ul>                 
  <details>
    <summary>Output</summary>
      <pre>
        <code>
121
        </code>
      </pre>  
    </details>
    </ul>  
  </details>
  <details>
    <summary>Example Program</summary>

```cpp             
#include <iostream>
using namespace std;

//preprocessor directives definitions
#define ONE 1
#define TEN 10
#define HUNDRED ONE + TEN + TEN
#define THOUSAND (HUNDRED + TEN)

int main()
{
    cout << THOUSAND / 10 << endl;
    
    return 0;
}
```
<ul> 
<details>
  <summary>Output</summary>
    <pre>
      <code>
3
      </code>
    </pre>  
  </details>
  </ul>  
  </details>
  </ul>
  </li>
  </ul>   
  </li> 
  </ul>
  </li>     
</ul>    

## Precision Handling
<ul>
  <li>To change the number of decimal places that a variable displays temporarily, including the <code><iomanip></code> preprocessor is a must. To then alter how many decimal values are printed to the screen, a call to the <code>setprecision</code> function within the iomanip library is needed. This function takes in one argument during its call which specifies the number of decimal points to print</li>    
  <details>
  <summary>Example Program</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //variable declaration and initialization
    float number = 4.4;

    cout << setprecision(0) << "Number: " << number << endl;
    
    return 0;
}
```  
<ul>
<details>
  <summary>Output</summary>
    <pre>
      <code>
Number: 4
      </code>
      </pre>  
      </details>
    </ul>  
  </details>
</ul>     

## Escape Sequences
<ul>
  <li>
    <a>The backslash, \, is the indicator of an escape sequence</a>
  </li>
  <li>
    <a>Some of the common escape sequences are listed below:</a>
    <ul>
      <li>\n: newline</li>
      <li>\t: tab</li>
      <li>\\: backslash</li>
      <li>\": double quote</li>
      <details>
      <summary>Example Program</summary>

```cpp        
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "This is how to print the backslash key using cout function: \\" << endl;
    cout << "This is how to print the quote key using cout function: \"This is a quote\"" << endl;
    
    return 0;
}
```
<ul>
<details>
  <summary>Output</summary>
    <pre>
      <code>
This is how to print the backslash key using cout function: \
This is how to print the quote key using cout function: "This is a quote"
      </code>
    </pre>  
  </details>
  </ul>  
</details>     
</ul>
</li>
</ul>

## Arithmetic Operators
<ul>
  <li><em>Addition operator</em>: adds the value on the left-hand side of the operator to the value on the right-hand side of the operator
    <ul>
      <li>x + y //sums the values x and y</li>
    </ul>    
  </li>
  <li><em>Subtraction operator</em>: subtracts the value on the right-hand side of the operator from the value on the left-hand side of the operator
    <ul>
      <li>x - y //subtracts the value y from the value x</li>
    </ul>    
  </li>
  <li><em>Multiplication operator</em>: multiplies the value on the right-hand side of the operator to the value on the left-hand side of the operator
    <ul>
      <li>x * y //multiplies the values x and y</li>
    </ul>    
  </li>
  <li><em>Division operator</em>: divides the value on the left-hand side of the operator by the value on the right-hand side of the operator
    <ul>
      <li>x / y //divides the x value by the value y</li>
    </ul>    
  </li>
  <li><em>Modulus operator</em>: divides the value on the left-hand side of the operator by the value on the right-hand side of the operator and returns the remainder
    <ul>
      <li>x % y //finds the remainder of the value x divided by value y</li>
    </ul>     
  </li>
</ul>   
