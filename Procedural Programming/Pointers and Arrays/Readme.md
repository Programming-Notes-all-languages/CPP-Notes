<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#pointer-arithmetic'>Pointer Arithmetic</a>
  </li> 
  <li>
    <a href='#using-pointers-for-array-processing'>Using Pointers for Array Processing</a>
  </li> 
  <li>
    <a href='#pointers-and-multidimensional-arrays'>Pointers and Multidimensional Arrays</a>
  </li> 
</ol>
</details>

## Pointer Arithmetic
<ul>
  <li><em>Pointer arithmetic</em> is useful for when a pointer points to an array. Pointer arithmetic in this case makes it so other elements within the array can be easily accessed</li>
  <li>There are three types of pointer arithmetic: adding an integer to a pointer, subtracting an integer from a pointer, and subtracting one pointer from another</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

void modify(int *x, int y) {
    *x = *x + y;        //*x = 30
    y = *x - y;         //y = 10
    *x = *x - y;        //*x = 20
}

int main() {
    int a = 10, b = 20;

    modify(&a, b);
    cout << a << b << endl;    //20 20

    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
20 20
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
</ul>

### Adding an Integer to a Pointer
<ul>
  <li>Let's say that there is an array defined along with a pointer and an integer j. If the pointer points to the element at index zero of the array, <code>ptr = &a[0]</code>, then <code>ptr + j</code> makes the pointer now point to the array's element j indices after index zero</li>
  <details>
    <summary>Example program</summary>

```cpp
//Given the following declarations:

#define SIZE 7
int data[SIZE] = {3, 5, 7, 8, 10, 14, 17};
int sum = 0;

//Write a loop using a pointer that adds all elements at odd indices to sum
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
using namespace std;

#define SIZE 7

int main()
{
    int data[SIZE] = {3, 5, 7, 8, 10, 14, 17};
    int sum = 0, *ptr = data;

    for (; ptr < data + SIZE; ptr++)
        if ((ptr - data) % 2 == 1)
            sum += *ptr;

    cout << "Sum: " << sum;        

    return 0;
}
```
  </details>
  </ul>  
  </details> 
</ul>

### Subtracting an Integer from a Pointer
<ul>
  <li>Let's say that there is an array defined along with a pointer and an integer j. If the pointer points to element at index eight, <code>ptr = &a[8]</code>, then <code>ptr - j</code> makes the pointer now point to the array's element j indices before index eight</li>
</ul>

### Subtracting One Pointer from Another
<ul>
  <li>One pointer can be subtracted from another and the result is the number of indices between the two elements that the pointers point to</li>
  <li>For example, let's say that there is an array that and been declared with a size of eight. There are two pointers, p1 and p2. <code>p1 = &a[1]</code> and <code>p2 = &a[2]</code>. Subtracting p2 from p1, or vice versa, finds the distance between both pointers and in this case, p1 - p2 is equal to -1</li>
  <li>Subtracting one pointer from another is only defined when both pointers point to elements within the same array; otherwise, this pointer arithmetic will be undefined</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initialization
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];
    
    cout << (q - 3) << endl;
    cout << p - q << endl;
    cout << *p - *q << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
34
-4
13
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Given the following declarations:

int arr[] = {10, 20, 30, 40, 50, 60, 70};
int *p = arr + 3;
int *q = arr + 6;

//What is the value of *(q - 4)
//What does p - q evaluate to?
//Write a code snippet to swap *p and *q without using any additional variables
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
//a) *(q - 4) = 30
//b) p - q = -3
//c)
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int *p = arr + 3;
    int *q = arr + 6;

    *arr = *p;
    p = q;
    q = arr;

    cout << *p << endl;     //70
    cout << *q << endl;     //40

    return 0;
}
```
  </details>
  </ul>  
  </details> 
</ul>         

### Comparing Pointers
<ul>
  <li>Pointers can be compared using the relational operators and the equality operators. Using these operators to compare pointers can be meaningful only when the pointer variables both point elements within the same array</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initialization
    int array[4] = {1, 2, 3, 4}, *ptr1 = &array[1], *ptr2 = &array[3];
    
    //selection statement which checks if ptr1 is greater than ptr2
    (ptr1 > ptr2) ? (cout << *ptr1 << " ") : (cout << *ptr2 << " ");
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
4
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Given the following declarations:

int arr[] = {3, 7, 1, 4, 9, 2, 6, 5};
int *start = arr, *end = arr + 7;

//Write a function that swaps the largest and smallest values in the array using pointer arithmetic
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <stdio.h>

void swap(int *, const int);

int main()
{
    int arr[] = {3, 7, 1, 4, 9, 2, 6, 5};
    int *start = arr, *end = arr + 7;

    swap(arr, 8);

    while (start <= end)
        cout << *start++ << " ";
    putchar('\n');
}

void swap(int *a, const int n)
{
    int *ptrMax = a, *ptrMin = a, *ptr = a, temp;

    for (; ptr < a + n; ptr++) {
        if (*ptr > *ptrMax)
            ptrMax = ptr;
        else if (*ptr < *ptrMin)
            ptrMin = ptr;    
    }

    temp = *ptrMax;
    *ptrMax = *ptrMin;
    *ptrMin = temp;
}
```
  </details>
  </ul>  
  </details> 
</ul> 

### Combining the * and ++ Operator
<ul>
  <li>Oftentimes, programmers will likely combine the dereferencing operator and incrementing operator (prefix and postfix variations). The purpose of combining these operators is to navigate through an array while dereferencing the array's elements</li>
  <li>The postfix operator takes precedence over the dereferencing operator. So, *ptr++ is equivalent to the following: *(ptr++)
    <ul>
      <li>In this scenario, the pointer is incremented using the postfix version and is then dereferenced</li>
    </ul>
  </li>
  <li>The prefix operator takes precedence over the dereferencing operator; however, the prefix operator and the dereferencing operator have right-to-left associativity. So, *++ptr is equivalent to the following: *(++ptr)      
    <ul>
      <li>In this scenario, the pointer is incremented using the prefix version and is then dereferenced</li>
    </ul>
  </li>      
</ul>    

## Using Pointers for Array Processing
<ul>
  <li>Pointer arithmetic enables a pointer pointing to an array to be analyzed as if it were an array</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initialization
    int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8}, *ptr = arr, sum = 0;
    
    //for loop which iterates over a pointer to find the sum of an array
    for (; ptr < arr + 9; ptr++)
        sum += *ptr;
    
    cout << "Sum: " << sum << endl;  
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Sum: 36
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

//macro definition for length of the array
#define N 5

int main()
{
    //variable declarations and initialization
    int a[N] = {6, 2, 3, 9, 4};
    int sum = 0, *p;
    
    //for loop which iterates through the array using a pointer
    for (p = a; p < a + N; p++)
        if ((p - a) % 2 == 1)
            sum += *p;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
sum = 2 + 9 = 11
        </code>
      </pre>  
    </details>
  </ul>  
  </details>  
  <details>
    <summary>Example program</summary>

```cpp
//What will be the contents of a array after the following statements are executed?
#include <iostream>
using namespace std;

//macro definition for length of the array
#define N 10

int main()
{
    //variable declarations and initialization
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = a, *q = a + N - 1;
    
    //while loop which iterates while the pointer address of p is less than the pointer address of q
    while (p < q) {
        *p = *q;
        *q = *p;
        p++;
        q--;
    }
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
a[N] = {10, 9, 8, 7, 6, 6, 7, 8, 9, 10}
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

//function prototype for func
void func(int *, int);

int main()
{
    //variable declaration and initialization
    int a1[5] = {0};
    
    //calling function
    func(a1, 5);
    
    cout << a1[3] << endl;
    
    return 0;
}

//function definition for func
void func(int *a, int n)
{
    //variable declarations and initializations
    int *p;
    *a = 0;
    
    //for loop which iterates through the array
    for (p = a + 1; p < a + n; p++)
        *p = p - a + *(p - 1);
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
6
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

//macro definition for length of the array
#define N 5

int main()
{
    //variable declarations and initialization
    int a[N] = {4, 1, 5, 6, 3};
    int *p = a, *q = a + N - 1;
    
    //while loop which iterates while the address of p is before q
    while (p < q) {
        if ((*p + *q) % 2 == 1)
            p++;
        else 
            q--;
    }
    
    cout << *q << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
6
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//This program compiles but when it runs, it causes a segmentation fault. Which line causes the segmentation fault?
#include <iostream>
using namespace std;

//function prototype for func
void max_min(int *, int, int *, int *);

int main()
{
    //variable declarations and initializations
    int a[] = {6, 8, 14, 5, 9, 23, 45, 65};
    int max_a, min_a;
    
    //calling function
    max_min(a, 8, &max_a, &min_a);
    cout << max_a << " " << min_a;
    
    return 0;
}

//function definition for func
void max_min(int *a, int n, int *max, int *min)
{
    //variable declarations and initializations
    int *p;
    max = min = *a;
    
    //for loop which iterates through the array
    for (p = a; p < a + n; p++) {
        if (*max < *p)
            *max = *p;
        if (*min > *p)
            *min = *p;
    }    
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
The error is in the line max = min = *a;. *a is of type integer whereas max and min are of type pointer to an integer. The correct code is as follows: max = min = a.
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
</ul>

## Using an Array Name as a Pointer
<ul>
  <li>The name of an array can be used as a pointer to point to the first element of an array. Remember, an array is a pointer</li>
  <li>For example, if the following declaration is made, <code>int a[10];</code>, then <code>*a = 7</code> will store the integer 7 in a[0]. a[1] can be modified by dereferencing a after incrementing a by one: <code>*(a + 1) = 12;</code></li>  
  <li>If a pointer is initialized to point to an array, then the pointer can be treated just like an array when using the pointer</li>  
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    char *colors[] = {"red", "green", "blue", "yellow"};
    char **p = colors + 1;

    cout << *p++ << " ";          //green
    cout << *++p << " ";          //yellow
    cout << colors[0];            //red

    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
green yellow red
        </code>
      </pre>  
    </details>
  </ul>  
  </details>
</ul>    

## Pointers and Multidimensional Arrays
### Processing the Rows of a Multidimensional Array
<ul>
  <li>Pointers can also point to multidimensional arrays. To get a pointer to point to a row within a multidimensional array, the following declarations can be made: <code>a[2][3] = {{1 , 3}, {4, 5, 6}}, *ptr = a[0];</code>. Now, ptr points to the first element within the first row of the multidimensional array declared as a
    <ul>
      <li>To then iterate through the multidimensional array using a pointer that points to a row within a multidimensional array, the following declarations and code can be written:
        <details>
        <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initialization
    int a[2][3] = {{1, 2, 7}, {1, 2, 9}}, *ptr = a[0], sum = 0;
    
    //for loop iterating through the first row of the multidimensional array a
    for (; ptr < a[0] + 3; sum += *ptr, ptr++);
    cout << "Sum: " << sum << endl;
    
    //for loop iterating through the first column of the multidimensional array a
    sum = 0, ptr = a[0];
    for (int i = 0; i < 2; sum += *ptr, ptr = a[++i]);
    cout << "Sum: " << sum << endl; 
    
    return 0;
}
```
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Sum: 10
Sum: 2
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
  </li></ul>
  </li>
</ul>    

### Processing the Columns of a Multidimensional Array
<ul>
  <li>To get a pointer to point to a column within a multidimensional array is not as simple as it is with an array's rows</li>
</ul>    
