<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#integer-types'>Integer Types</a>
  </li> 
  <li>
    <a href='#floating-types'>Floating Types</a>
  </li> 
  <li>
    <a href='#character-types'>Character Types</a>
  </li> 
  <li>
    <a href='#type-conversion'>Type Conversion</a>
  </li> 
  <li>
    <a href='#type-definitions'>Type Definitions</a>
  </li> 
  <li>
    <a href='#the-sizeof-operator'>The sizeof Operator</a>
  </li> 
</ol>
</details>

## Integer Types
<ul>
  <li>C++ supports two different types of numerical data types: integers and floats. Numbers of <em>integer type</em> are whole numbers with no radix point unlike floating type numbers who can have a radix point and numbers to the right of the radix point</li>
  <li>Integer types are split into two categories: signed or unsigned
    <ul>
      <li>The leftmost of a <em>signed integer</em>, also known as the <em>sign bit</em>, is 0 if the integer number is positive or is 1 if the number is negative</li>
    </ul>      
  </li> 
  <li>When declaring a variable of type int, it will be signed automatically. There are four keywords that help in creating an int that meets the needs of the programmer: long, short, signed, and unsigned
    <ul>
      <li>Because of all variables of type int being signed by default, there are six unique combinations of different variables types, all being of type int:
        <ul>
          <li>short int</li>
          <li>unsigned short int</li>
          <li>int</li>
          <li>unsigned int</li>
          <li>long int</li>
          <li>unsigned long int</li>
        </ul>
      </li>
    </ul>
  </li>              
</ul>    

| Type | Smallest Value | Largest Value |
| :--- | :------------- | :------------ |
| short int | -32,768 | 32,767 |
| unsigned short int | 0 | 65,535 |
| int | -2,147,483,648 | ,147,483,648 |
| unsigned int | 0 | 4,294,967,295 |
| long int | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,808 |
| unsigned long int | 0 | 18,446,744,073,709,551,615 |    

## Floating Types
<ul>
  <li>There are three types of floating-point formats:
    <ul>
      <li>float</li>
      <li>double</li>
      <li>long double</li>
    </ul>        
  </li>
</ul>    

| Type | Smallest Positive Value | Largest Value | Precision |
| :--- | :---------------------- | :------------ | :-------- |
| float | 1.17549 x 10 ^ -38 | 3.40282 x 10 ^ 38 | 6 digits |
| double | 2.22507 x 10 ^ -308 | 1.79769 x 10 ^ 308 | 15 digits |   

## Character Types
<ul>
  <li>C++ treats char values as small integers, which variables of type char are in fact integers</li>
  <li>Just like with integers, variables of type char also can be signed or unsigned. Signed characters have values from -128 to 127 whereas unsigned characters have values from 0 to 255</li>  
  <li>chars can either be signed or unsigned when declared and initialized. unsigned char and signed char are legal variable types</li>  
</ul>    

### Reading and Writing Characters using getchar and putchar
<ul>
  <li>There are alternatives to read and write characters instead of cin and cout</li>
  <li>The putchar function writes a single character to the screen. The function takes in a single character within its parentheses and prints that character to the screen
    <ul>
      <li>Here is the syntax for the putchar function: <code>putchar(ch);</code></li> 
    </ul>
  </li>   
  <li>The getchar function reads in one character from the user. To save this character, the assignment operator can be used to store that value into a variable of type char
    <ul>
      <li>Here is the syntax for the getchar function: <code>ch = getchar();</code></li>
      <li>This function actually returns an int value rather than a char one</li>  
    </ul>
  </li>  
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initializations
    int len = 0;
    
    //get the length of the input message/
    cout << "Enter a message: ";
    while (getchar() != '\n')
        len++;
    
    cout << "Your message was " << len << " character(s) long.\n";
    
    return 0;
}
```
  <ul>
  <details>
      <summary>Output</summary>
        <pre>
          <code>   
Enter a message: <u>Garrett</u>
Your message was 7 character(s) long.
          </code>
        </pre>  
      </details>
    </ul>  
  </details>       
</ul>   

## Type Conversion
<ul>
  <li>There are two different types of type conversion in C: <em>implicit conversion</em> and <em>explicit conversion</em>
  <ul>
    <li>Implicit conversion happens when:
      <ul>
        <li>The operands in an expression are not matching</a>
          <ul>
            <li>The strategy when implicitly converting an operand to match the other when performing arithmetic is to convert the operand of the smaller data type to be the same data type as the other operand</li>
            <li>Here is the order of data types listed from greatest in size to least in size:
              <ul>
                <li>long double</li>
                <li>double</li>
                <li>float</li>
                <li>unsigned long int</li>
                <li>long int</li>
                <li>unsigned int</li>
                <li>int</li>
                <li>unsigned short int</li>
                <li>short int</li>
                <li>char</li>
              </ul>
            </li> 
            <li>When a signed operand is combined with an unsigned operand, the signed operand is converted to unsigned</li>                    
          </ul>
        </li>
      </ul>        
    </li>
    <li>Explicit conversion happens with <em>type casting</em> which is where the programmer has to manually change to the type of a variable to be of another data type
      <ul>
        <li>Here is the syntax for manually converting a variable's data type to another type: <code>(typeName) expression</code></li>
        <details>
          <summary>Example Program</summary>

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //variable declarations and initializations  
    double x = 1.1, y = 7.2;
    int intx, inty;

    cout << "The value of x is: " << fixed << showpoint << setprecision(1) << x << " and the value of y is: " << y << endl;
    
    //variable initializations
    intx = (int)x;
    inty = (int)y;
    
    cout << "The value of x is: " << intx << " and the value of y is: " << inty << endl;
    
    return 0;
}
```
<ul>
            <details>
            <summary>Output</summary>
              <pre>
                <code>
The value of x is: 1.1 and the value of y is: 7.2
The value of x is: 1 and the value of y is: 7
                </code>
              </pre>  
            </details>
          </ul>  
        </details>
        <li>(typeName) is treated as a unary operator so it often has the highest precedence in the statement</li>  
      </ul>    
    </li> 
    <li>Another type of explicit conversion, but with this being C++ style, is the following: <code>static_cast<toBeConvertedTo>(variableName);</code>
      <ul>
        <li>Here is an example of using static_cast which is found in the iostream library: <code>doubleValue = static_cast<double>(intValue);</code></li>
      </ul>
    </li>    
  </ul>  
</ul>     

## Type Definitions
<ul>
  <li><em>Type definitions</em> are often useful for creating alias for already established data types in C++
    <ul>
      <li>Here is the syntax for type definitions: <code>typdef CtypeName createdName;</code></li>
      <li>Here is an example of a typedef: typedef float Dollars; Dollars is now an alias for float. Dollars has the exact same functionality as float--the only difference is that Dollars is called Dollars and not float</li>
      <li>Type definitions are normally inserted outside of main so they are global variables. This means that it can be used in all functions within the program</li>  
    </ul>    
  </li>
</ul>   

## The sizeof Operator
<ul>
  <li>To determine how much memory is being used by a data type on one's system, the sizeof operator can be useful</li>
  <li>Here is the syntax for the sizeof operator: sizeof (typeName) sizeof will return a number of type int which represents how much storage within memory is being used by the variable enclosed within the parentheses</li>
</ul>    
