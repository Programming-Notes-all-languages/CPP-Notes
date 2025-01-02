<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#the-while-loop'>The while Loop</a>
  </li> 
  <li>
    <a href='#the-do-statement'>The do Statement</a>
  </li> 
  <li>
    <a href='#the-for-statement'>The for Statement</a>
  </li> 
  <li>
    <a href='#exiting-from-a-loop'>Exiting from a Loop</a>
  </li> 
</ol>
</details>

## The while Loop
<ul>
  <li>Here is the syntax for a while loop: <code>while (expression) statement</code>;
    <ul>
      <li>The expression inside the parentheses is the controlling expression</li>
      <li>The statement after the parentheses is the body of the while loop. Note that the parentheses are mandatory for the encapsulation of the controlling expression</li>
    </ul>       
  </li>
  <li>When a while loop is executed, the first step is evaluating the loop's controlling expression. If its controlling expression evaluates to a nonzero number, the loop's body is executed; otherwise, the loop's body is skipped</li>
  <li>Similar to conditional statements, the braces that enclose the body of the while loop are optional--only if the body of the loop is only one line long. If the loop's body is more than one line long, its body needs to be encapsulated in braces</li>
  <li>Since the controlling expression is evaluated first in the execution of the while loop, there is a chance that the while loop may never run at all. This is because if the controlling expression of the while loop evaluates to false its first time, the loop is skipped entirely</li>
  <li>Another scenario is that if there is no functionality to make the controlling expression evaluate to false at some point, then the loop iterates repeatedly</li>   
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initializations
    int input = -1, sum = 0;
    
    cout << "This program sums all the user's integer inputs.\n";
    cout << "Enter integers (0 to terminate): ";
    
    //loop to continuously read and add user inputs until 0 is entered
    while (input != 0)
    {
        cin >> input;
        sum += input;
    }
    
    cout << "The sum of all entered integers is: " << sum;
    
    return 0;
}
``` 
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Enter integers (0 to terminate): <u>5 6 7 8 9
0</u>
The sum of all entered integers is: 35
          </code>
        </pre>  
      </details>
    </ul>  
  </details>     
  <li>Putting a semicolon after the parentheses following an if, while, or for statement creates a null statement</li>  
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    int i = 3;
    
    //while loop which iterates while i is greater than 0
    while (i > 0);
    {
        cout << i;
        --i;
    }

    return 0;
}
```
<ul> 
  <details>
  <summary>Output</summary>
    <pre>
      <code>
Infinite loop
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
    //variable declaration and initialization
    int i = 3;
    
    //while loop which iterates while i is greater than 0
    while (--i > 0);
        cout << i;
     
    return 0;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
0
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
    //variable declaration and initialization
    int x = 0;
    
    //while loop which iterates until x is no longer less than 3
    while (x++ < 3);
        cout << "x = " << x;
     
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
x = 4
        </code>
      </pre>  
    </details>
  </ul>  
  </details>        
</ul>    

## The do Statement
<ul>
  <li>The do statement is very closely related to the while statement. The difference with the do statement is that the loop body is  executed once before its controlling expression is evaluated. After the body's first iteration, the controlling expression will be evaluated once before every future iteration of the loop</li>
  <li>Here is the syntax of a do-while loop: do statement while (expression);</li>  
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initializations
    int input = -1, sum = 0;
    
    cout << "This program sums all the user's integer inputs.\n";
    cout << "Enter integers (0 to terminate): ";
    
    //loop to continuously read and add user inputs until 0 is entered
    do
    {
        cin >> input;
        sum += input;
    } while (input != 0);
    
    cout << "The sum of all entered integers is: " << sum;
    
    return 0;
}
```
<ul>   
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Enter integers (0 to terminate): <u>5 6 7 8 9
0</u>
The sum of all entered integers is: 35
          </code>
        </pre>  
      </details>
    </ul>  
  </details>  
</ul>    

## The for Statement
<ul>
  <li>The for statement has the following syntax: <code>for (expr1; expr2; expr3)</code> statement
    <ul>
      <li>expr1 is the initialization step of the for loop which is performed only once during the execution of the loop. expr1 runs before the loop begins its execution</li>  
      <li>expr2 is the controlling expression that determines when the loop should stop iterating. This happens when expr2 is equal to zero</li>
      <li>expr3 is the operation that happens at the end of the loop's iteration</li>    
    </ul>    
  </li>
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    int n;
    
    //for loop which prints value of n when n is not equal to 0
    for (n = 9; n != 0; n--)
        cout << n--;
       
    return 0;
}
```
<ul>   
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Infinite loop
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
    //variable declaration and initialization
    int i, j;
    
    //for loop which iterates from 0 to 2, inclusive
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++);
        cout << "i = " << i << ", j = " << j << endl;
    }
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
i = 0, j = 3
i = 1, j = 3
i = 2, j = 3
        </code>
      </pre>  
    </details>
  </ul>  
  </details>         
</ul>

### Omitting Expressions in a for Statement
<ul>  
  <li>The for statements is very flexible as some for loops may not need all three expressions that are enclosed within the parentheses. If the first expression is omitted, no initialization is performed before the execution of the loop. If the third expression is omitted, then the loop's body is responsible for ensuring that the second expression evaluates to false at some point to exit the loop</li>  
  <li>The second expression in the for loop can be omitted. Doing so defaults the second expression to evaluate to true. A for loop which also omits the first expression and the third expression creates an infinite loop <code>(for;;)</code></li>  
</ul>    

### The comma Operator
<ul>
  <li>Sometimes, there may need to be multiple initializations in the first expression of the for statement. This can be accomplished with the comma operator</li>
  <li>Here is the syntax for the comma operator: <code>expr1, expr2</code></li>  
</ul>    

## Exiting from a Loop
### The break Statement
<ul>
  <li> Just like with the switch statement, the break statement can be used with while, do, and for loops</li>
  <li>The break statement exits one level of nesting in a switch statement, for loop, while loop, and a do-while loop. The control is then brought outside of the switch statement or loop</li>  
  <li>The break statement ends control within a single level of nesting in a switch statement and any loop statement. Consider the case below where there is a switch statement that is enclosed within a while loop:

```cpp
while (...)
{
    switch (...)
    {
        ...
        break;
        ...
    }
}
```
The break statement will exit one level of nesting and will bring control out of the switch statement, to the while loop--not outside of the while loop as break only can leave one level of nesting</li>  
  <details>
    <summary>Example Program</summary>

```cpp
#include <stdio.h>

int main()
{
    //variable declaration and initialization
    int sum = 0;
    
    //for loop which iterates from 0 to 2, inclusive
    for (int i = 0; i < 3; i++)
    {
        //conditional statement which checks if i modulus 2 is 1
        if (i % 2 == 1)
            break;
        sum += i;
    }
    
    cout << "sum = " << sum << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
sum = 0
        </code>
      </pre>  
    </details>
  </ul>  
</details>  
</ul>  

### The continue Statement
<ul>
  <li>The continue statement does not make control leave one layer of nesting; instead, the control is brought just before the end of the loop's body</li>
  <li>There are a few differences between break and continue:
    <ul>
      <li>break leaves the loop it is embedded in and continue keeps the control within the loop</li>
      <li>break can be used in loops in addition to switch statements. continue can only be used in loops and not in switch statements</li>
    </ul>
  </li>  
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    int sum = 0;
    
    //for loop which iterates from 0 to 2, inclusive
    for (int i = 0; i < 3; i++)
    {
        //conditional statement which checks if i modulus 2 is 1
        if (i % 2 == 1)
            continue;
        sum += i;
    }
    
    cout << "sum = " << sum << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
sum = 2
        </code>
      </pre>  
    </details>
  </ul>  
</details>        
</ul>   
