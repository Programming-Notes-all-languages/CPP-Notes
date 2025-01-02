<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#pointer-variables'>Pointer Variables</a>
  </li> 
  <li>
    <a href='#the-address-and-indirection-operators'>The Address and Indirection Operators</a>
  </li> 
  <li>
    <a href='#pointer-assignment'>Pointer Assignment</a>
  </li> 
  <li>
    <a href='#pointers-as-arguments'>Pointers as Arguments</a>
  </li> 
  <li>
    <a href='#pointers-as-return-values'>Pointers as Return Values</a>
  </li> 
</ol>
</details>

## Pointer Variables
### Declaring Pointer Variables
<ul>
  <li>A pointer variable is declared very similarly to a normal variable, the only difference with a pointer variable is that the name of the pointer variable is preceded with a asterisk, *</li>
  <li>Here is an example of declaring a pointer variable: <code>int *ptr;</code></li>
  <li>Pointer variables can be declared on the same line as other variables: <code>int *ptr, num = 1, array[100];</code></li>  
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initialization
    int arr[] = {5, 8, 2, 9}, *ptr, n = 9;
    ptr = &n;
    
    cout << "The memory address of ptr is: " << ptr << endl;
    
    //for loop which displays the memory addresses of each index of an array
    for (int i = 0; i < 4; i++)
        cout << "Memory address of arr[" << i << "] = " << &arr[i] << endl;    
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
The memory address of ptr is: 0x16b31342c
Memory address of arr[0] = 0x16b313440
Memory address of arr[1] = 0x16b313444
Memory address of arr[2] = 0x16b313448
Memory address of arr[3] = 0x16b31344c
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a function definition that would exchange the values of the variables i and j successfully? swap(&i, &j);
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}        
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
</ul>

## The Address and Indirection Operators
<ul>
  <li>To find the address to which a pointer points to, the & operator can be used. If y is declared, &y is the address in memory to which y is stored</li>
</ul> 

### The Address Operator
<ul>
  <li>To initialize a pointer, the following can be done:<code>
    int i, *ptr;<br />
    ptr = &i;</code>
  </li>
</ul> 

### The Indirection Operator
<ul>
  <li>Once a pointer points to an object, the value of the pointer can be dereferenced using the indirection operator, *. For instance, if ptr points to i, then the value of i can be printed to the screen with the following statement: <code>cout << *ptr << endl;</code></li>
  <li>As long a ptr points to i, *p is simply an alias for i. Furthermore, any alteration to *p changes i and vice versa</li>  
  <details>
    <summary>Example program</summary>

```cpp
//What are the errors in this program?
#include <iostream>            //1
using namespace std;

int main()                     //2
{
    int a = 10, *p;            //3
    *p = &a;                   //4
    
    if (a == 10)               //5
        int a = 20;            //6
    else                       //7
        p = a;                 //8
    
    cout << *p << a << endl;   //9       
    
    return 0;                  //10
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
4. Dereferenced pointer cannot be assigned a variable's address
6. Variable a has already been declared int line 3
8. Pointer only can be assigned a variable's address
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//What are the errors in this program?
#include <iostream>                   //1
using namespace std;

int main()                            //2
{
    int arr[3] = {1, 2, 3}            //3
    int *ptr = arr;                   //4
    
    for (int i = 0; i < 4; i++)       //5
    {
        if (i = 2)                    //6
            cout << *(ptr++) << " ";  //7
        else if (ptr[i] > 3)          //8
            cout << ptr[i] << " ";    //9 
    }               
    
    return 0;                         //10
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
6. Comparison operator is ==
8. ptr[3] is out of bounds as size of array is 3, not 4 
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
</ul>    

## Pointer Assignment
<ul>
  <li>An example of pointer assignment is the following:
  <code>int i, j, *p, *q;<br />
    //The statement p = &i; is a pointer assignment as p now points to the memory address that i is stored in<br />
    q = p;<br />
    //Now, q is a pointer that points to the same memory address as p. q and p are pointers to i. Any alterations to either one of these three variables will be reflected in *p, *q, and i</code></li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initialization
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    cout << "Initial: *ptr = " << *ptr << endl;          
    cout << "Next: *(ptr + 2) = " << *(ptr + 2) << endl; 
    *ptr += 2;                                     
    *(ptr + 3) -= 1;                               
    
    cout << "After modification: *ptr = " << *ptr << ", *(ptr + 3) = " << *(ptr + 3) << endl;
    
    ptr++;
    cout << "Pointer moved: *ptr = " << *ptr << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Initial: *ptr = 1
Next: *(ptr + 2) = 3
After modification: *ptr = 3, *(ptr + 3) = 3
Pointer moved: *ptr = 2
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
    //variable declarations and initialization
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = arr;     //*ptr1 = 10
    int *ptr2 = arr + 3; //*ptr2 = 40
    
    *ptr1 = *ptr2;       //*ptr1 = 40, arr[0] = 40
    ptr2 = ptr1 + 1;     //ptr2 = arr + 1, *ptr2 = 20
    
    cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    
    *ptr2 = 100;
    
    for (int i = 0; i < 5; i++)
        cout << "arr[" << i << "] = " << arr[i] << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
*ptr1 = 40, *ptr2 = 20
arr[0] = 40
arr[1] = 100
arr[2] = 30
arr[3] = 40
arr[4] = 50          
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
    //variable declarations and initialization
    int x = 10;
    int y = 20;
    int *ptr1 = &x;
    int *ptr2 = &y;
    
    cout << "Before: x = " << x << ", y = " << y << endl;
    
    *ptr1 = *ptr2;    //*ptr1 = 20, x = 20
    ptr2 = ptr1;      //ptr2 = &x, x = 20, ptr1
    *ptr2 = 50;       //*ptr2 = 50, x = 50
    
    cout << "After: x = " << x << ", y = " << y << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Before: x = 10, y = 20
After: x = 50, y = 20     
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
    //variable declarations and initialization
    int a = 100, b = 200, c = 300;
    int *ptr1 = &a;    //*ptr1 = 100  
    int *ptr2 = &b;    //*ptr2 = 200 
    int *ptr3 = &c;    //*ptr3 = 300
    
    *ptr2 = *ptr1;     //*ptr2 = 100, b = 100
    ptr3 = ptr1;       //ptr3 now points to a, ptr1 = &a, ptr3 = &a, *ptr3 = a, a = 100
    
    cout << "After assignments: a = " << a << ", b = " << b << ", c = " << c << endl;
    
    *ptr3 = 500;       //ptr3 = &a, *ptr3 = 500, a = 500
    
    cout << "After modification: a = " << a << ", b = " << b << ", c = " << c << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
After assignments: a = 100, b = 100, c = 300
After modification: a = 500, b = 100, c = 300   
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
    //variable declarations and initialization
    int a = 5;
    int b = 10;
    int *ptr1 = &a;
    int *ptr2 = &b;
    
    *ptr1 = *ptr2;       //*ptr1 = 10, ptr1 = &a, a = 10
    *ptr2 = *ptr1 + 5;   //*ptr2 = 15, prt2 = &b, b = 15
    
    cout << "a = " << a << ", b = " << b << endl;
    cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
a = 10, b = 15
*ptr1 = 10, *ptr2 = 15
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
    //variable declarations and initialization
    int a = 100, b = 200;
    int *p1 = &a;
    int *p2 = &b;
    int *temp = p1;
    
    p1 = p2;        //p1 is assigned the value stored in p2, *p1 = 200, p1 now points to b
    p2 = temp;      //p2 is assigned the address stored in temp, *p2 = 100, p2 now points to a
    
    *p1 += 10;      //*p1 = 200 + 10 = 210, b = 210
    *p2 -= 10;      //*p2 = 100 - 10 = 90, a = 90
    
    cout << "a = " << a << ", b = " << b << endl;
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
a = 90, b = 210
*p1 = 210, *p2 = 90
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
    //variable declarations and initialization
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;               //p points to &arr[0]
    
    cout << *(p++) << " ";      //p points to arr, *p = 1
    cout << *p << " ";          //p points to arr + 1, *p = 2
    cout << *(++p) << " ";      //p points to arr + 2, *p = 3
    cout << *(p + 1) << " ";    //p points to arr + 2, *(p + 1) = 4
    cout << *(p - 1) << " ";   //p points to arr + 2, *(p - 1) = 2
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
1 2 3 4 2
        </code>
      </pre>  
    </details>
  </ul>  
  </details>
</ul>    

## Pointers as Arguments
<ul>
  <li>Pointers offer a solution to the problem where C is by default a pass-by-value language. This is accomplished by passing the memory addresses of variables as arguments to the function's call rather than the variable itself. Now, modifications to the variables declared in main within functions outside of main will be reflected within main after the outside functions' termination</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

//macro definition for array size
#define MAX 10

//function prototype for arrayFun
void arrayFun(int[], int *, int *);

int main()
{
    //variable declaration and initialization
    int input, array[MAX], iterations = 0, max, min;
    
    cout << "Enter 10 numbers: ";
    
    //do-while loop which iterates until 
    do
    {
        cin >> input;
        
        array[iterations++] = input;
    } while (iterations < MAX);
    
    //calling arrayFun function
    arrayFun(array, &max, &min);
    
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Enter 10 numbers: <u>43 93 -9 2 3 93 3 23 9 -33</u>
Maximum: 93
Minimum: -33
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

//global variable declaration and initialization
int global_var = 10;

//function prototypes for func1 and func2
void func1(int *p);
void func2(int p);

int main()
{
    //variable declarations and initializations
    int local_var = 20;
    int *ptr = &local_var;
    
    //calling func1 and printing variable values to the screen
    func1(ptr);
    cout << "After func1: local_var = " << local_var << ", global_var = " << global_var << endl;
    
    //calling func2 and printing variable values to the screen
    func2(global_var);
    cout << "After func2: global_var = " << global_var << endl;
    
    return 0;
}

void func1(int *p)
{
    (*p)++;             //(*p)++, 20++, 21
    p = &global_var;    //p = &global_var, *p = 10
    (*p) += 5;          //(*p) += 5, *p = 10 + 5, *p = 15
}

void func2(int p)
{
    p++;                //p = &p + 1
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
After func1: local_var = 21, global_var = 15
After func2: global_var = 15
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

//function definition for modify
void modify(int *a, int *b)
{
    //*a = 3, *b = 4
    //*a = *a + *b, *a = 3 + 4, *a = 7
    //*b = *a + *b, *b = 7 + 4, *b = 11

    //*a = 11, *b = 7
    //*a = *a + *b, *a = 11 + 7, *a = 18
    //*b = *a + *b, *b = 18 + 7, *b = 25
    *a += *b;     
    *b += *a;     
}

int main()
{
    //variable declarations and initializations
    int x = 3, y = 4;
    
    modify(&x, &y);
    cout << x << " " << y << " "; //7 11
    
    modify(&y, &x);
    cout << x << " " << y << " "; //25 18
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
7 11 25 18
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

//global variable declaration
int *global_ptr;

//function definition for modifyGlobalPointer
void modifyGlobalPointer(int *p)
{
    global_ptr = p;       //global_ptr is assigned the value stored in p, *p = local_var, global_ptr now points to local_var which contains the value 5
    *global_ptr += 10;    //global_var = 10 + 5 = 15, local_var = 15
}

int main()
{
    //variable declaration and initialization
    int local_var = 5;
    
    //calling modifyGlobalPointer
    modifyGlobalPointer(&local_var);  
    
    //printing variable values to the screen        
    cout << "local_var = " << local_var << endl;    
    cout << "*global_ptr = " << *global_ptr << endl; 
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
local_var = 15
*global_ptr = 15
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

//global variable declaration
int *global_ptr;

//function definition for setGlobal
void setGlobal(int *p)
{
    global_ptr = p; 
}

//function definition for modifyGlobal
void modifyGlobal()
{
    *global_ptr = 100;
}

int main()
{
    //variable declaration and initialization
    int local_var = 20;
    
    //calling setGlobal function
    setGlobal(&local_var);      
    
    //calling modifyGlobal function           
    modifyGlobal();      
                    
    cout << "local_var = " << local_var << endl; 
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
100
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

//global variable declarations
int *global_ptr1, *global_ptr2;

//function definition for setPointers
void setPointers(int *p1, int *p2)
{
    global_ptr1 = p1;
    global_ptr2 = p2; 
}

//function definition for swap
void swap()
{
    int temp = *global_ptr1;
    *global_ptr1 = *global_ptr2;
    *global_ptr2 = temp;
}

int main()
{
    //variable declarations and initializations
    int a = 5, b = 10;
    
    //calling setPointers function
    setPointers(&a, &b);     
    
    //calling swap function         
    swap();   
                         
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
a = 10, b = 5
        </code>
      </pre>  
    </details>
  </ul>  
  </details>  
</ul>    

### Using const to Protect Arguments
<ul>
  <li>To ensure that a function does not modify an argument passed into the function's call, the const modifier can be used. Here, const is placed in the parameter list just before the parameter's data type such as in the following example</li> 
</ul>  

## Pointers as Return Values
<ul>
  <li>Functions can too return types that are pointers</li>
</ul>    
