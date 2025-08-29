<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#one-dimensional-arrays'>One-Dimensional Arrays</a> 
  </li> 
  <li>
    <a href='#multidimensional-arrays'>Multidimensional Arrays</a>
  </li> 
  <li>
    <a href='#variable-length-arrays'>Variable-Length Arrays</a>
  </li> 
  <li>
    <a href='#dynamic-arrays'>Dynamic Arrays</a>
  </li> 
</ol>
</details>

## One-Dimensional Arrays
<ul>
  <li>An <em>array</em> is a type of data structure that contains a set number of values of the same data type</li>
  <li>Each value within an array is known as an <em>element</em> which has a numerical position within the array</li>
  <li>It is good practice to use macros for the length of the array</li>  
  <li>To declare an array, the array's type must be specified first, followed by the name of the array, and lastly the number of elements the array has, which is enclosed in brackets following the name of the array
    <ul>
      <li>Here is the syntax for an array declaration: <code>dataType arrayName[integerValue];</code>
      </li>
    </ul>    
  </li>     
</ul>    

### Array Subscripting
<ul>
  <li>To access an element of an array, the array's name is written followed by the array's element's index which is enclosed in brackets</li>
  <li>Array elements start at index 0, up to one less than the length of the array. For example, an array with 5 elements starts at index 0 and ends at index 4, a[0], a[1], ... a[4]</li>
  <li>Expressions with the form arrayName[index] can be treated as any ordinary variable</li> 
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    int array[10];
    
    //inputting numbers into the array
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++)
        cin >> array[i];
    
    //printing the array in reverse order
    cout << "In reverse order: ";
    for (int i = 9; i >= 0; i--)
        cout << array[i];
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Enter 10 numbers: <u>1 2 3 4 5 6 7 8 9 10</u>
In reverse order: 10 9 8 7 6 5 4 3 2 1
          </code>
        </pre>  
      </details>
    </ul>  
  </details>   
</ul> 

### Array Initialization
<ul>
  <li>Just like other variables, arrays can be initialized at the time of declaration</li>
  <li>The most common type of <em>array initializer</em> is a list of constants enclosed within braces, where each element is separated by commas
    <ul>
      <li>Here is an example of initializing all elements of an array: <code>int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};</code></li>
    </ul>    
  </li> 
  <li>If the initializer does not have a constant for each element of the array, the remainder of elements without a constant to initialize them would be initialized to 0
    <ul>
      <li>Here is an example of initializing all elements of an array without an initializer for all elements: <code>int array[10] = {1, 2, 3, 4, 5, 6};</code></li>
      <li>array[6], array[7], array[8], and array[9] are now initialized with 0</li>  
    </ul>    
  </li>
  <li>If one would like to initialize all elements of an array to zero, this can be done: <code>int array[10] = {0};</code> Here, all elements of the array are initialized to zero</li>  
  <li>If the length of an array is omitted in the array's declaration, yet there is an initializer with x elements, then the array's size is x elements and each element is initialized with its designated initializer</li>  
</ul>    

### Designated Initializers
<ul>
  <li>If only certain elements of an array should be initialized, then <em>designated initializers</em> can be used. Here is an example of initializing certain elements of an array: <code>int array[15] = {[2] = 29, [9] = 6, [14] = 48};</code></li>
  <li>If the size of the array is not present when using designated initializers, then the last index of the array is one less than the size of the array. In this example, <code>int b[] = {[5] = 10, [15] = 29};</code>, the size of the array is 16</li>  
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    char ch;
    int seen[10] = {0}, maxSeen = 0;
    
    cout << "Enter a number: ";

    //do-while loop which iterates until the user enters the newline character
    do
    {
        ch = getchar();
        
        //conditional statement which checks if user entered a number
        if (ch >= '0' && ch <= '9')
            //for loop which iterates over all indices of the seen array
            for (int i = 0; i < 10; i++)
                //conditional statement which checks if user entered a number that is the same as i
                if (ch - 48 == i)
                    seen[i]++;
    } while (ch != '\n');
    
    //for loop which iterates over all indices of the seen array
    for (int i = 0; i < 10; i++)
        //conditional statement which is used to find the maximum number of common digits the user input
        if (seen[i] > maxSeen)
            maxSeen = seen[i];
     
    //conditional statement which checks if the user input and repeated digits
    if (maxSeen > 1)
        printf("Repeated digit\n");
    //conditional statement which runs if the user input all unique digits    
    else
        printf("No repeated digit\n");
          
    return 0;
}
```
<ul>  
  <details>
      <summary>Output</summary>
        <pre>
          <code>
Enter a number: <u>123494</u>
Repeated digit
          </code>
        </pre>  
      </details>
    </ul>  
  </details> 
</ul>    

## Multidimensional Arrays
<ul>
  <li>An array can have any number of dimensions</li>
  <li>Here is the syntax for declaring a multidimensional array: <code>dataType arrayName[x][y];</code>
    <ul>
      <li>If this declaration were to be made in a program: <code>int array[5][9];</code>, then this array has five elements, where each of the five elements has nine sub-elements</li>
    </ul>
  </li> 
  <li>Here is an example for initializing a multidimensional array: <code>dataType arrayName[3][2] = {{0, 1}, {1, 0}, {1, 1}};</code></li>
  <li>Just like with a single-dimensional array, the same practices apply for declaring and initializing the elements of the multidimensional array</li>        
</ul>    

### Constant Arrays
<ul>
  <li>One or multidimensional arrays can be made constant which means that its elements' contents cannot be modified throughout the duration of the program</li>
  <li>Here is the syntax for declaring and initializing the elements of a const array: <code>const dataType arrayName[size] = {value0, value1, ..., valueN};</code></li>  
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    const int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    //for loop which prints the array's elements
    cout << "Here are the array's elements: ";
    for (int i = 0; i < 10; i++)
        cout << i;
    
    return 0;
}
```
<ul>   
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Enter a number: <u>123494</u>
Repeated digit
        </code>
      </pre>  
    </details>
  </ul>  
</details> 
</ul>    

## Variable-Length Arrays
<ul>
  <li>In newer versions of C++, a variable, rather than a constant of type integer, can be used when declaring the size of an array</li>
  <li>When using a variable to declare the size of the array, the array can only be declared on that line--the array can be initialized later on lower lines. The const modifier does not work with variable-length arrays either</li> 
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    char ch;
    int number10;
    
    //prompt the user to enter a number
    cout << "Enter the size of the array: ";
    cin >> number10;
    int array[number10];
    
    //for loop which iterates from 0 to 9
    for (int i = 0; i < number10; i++)
        array[i] = i;

    //for loop which prints the array reversed
    cout << "Here is the array reversed: ";
    for (int i = number10 - 1; i >= 0; i--)
        cout << array[i];
    
    return 0;
}
```   
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Enter a number: <u>123494</u>
Repeated digit
        </code>
      </pre>  
    </details>
  </ul>  
</details>  
</ul>   

## Dynamic Arrays
<ul>
  <li>A <em>dynamic array</em> is an array whose size is determined at runtime. In C++, <em>static arrays</em> have a size that is fixed at compile time, opposed to dynamic arrays whose size is allocated on the heap using <code>new</code> and <code>delete</code></li>
  <li>Here is the syntax for creating a dynamically allocated array:

```cpp
int *arrayName = new int[sizeVariable];
```
  </li>
  <li>To then clean up the memory created by the array once it is no longer needed, the memory can then be deleted. This is best and must be done manually to prevent memory leaks</li>
  <li>Here is the syntax for freeing memory from a dynamically allocated array:

```cpp
delete [] arrayName;
```

  </li>
</ul>