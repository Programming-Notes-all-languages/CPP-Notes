<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#logical-expressions'>Logical Expressions</a>
  </li> 
  <li>
    <a href='#the-if-statement'>The if Statement</a>
  </li>
  <li>
    <a href='#boolean-values'>Boolean Values</a>
  </li>
  <li>
    <a href='#the-switch-statement'>The switch Statement</a>
  </li>
</ol>
</details>

## Logical Expressions
### Relational Operators
<table>
    <thead>
        <tr>
            <td><strong>Operator</strong></td>
            <td><strong>Operator Name</strong></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><</td>
            <td>less than</td>
        </tr>
        <tr>
            <td>></td>
            <td>greater than</td>
        </tr>
        <tr>
            <td><=</td>
            <td>less than or equal to</td>
        </tr>
        <tr>
            <td>>=</td>
            <td>greater than or equal to</td>
        </tr>
    </tbody>        
</table>        

<ul>
  <li>When relational operators are used in expressions, they produce either 0 (false) or 1 (true). For example, if the expression <code>10 < 11</code> were to be evaluated, it results in 1; otherwise, the expression <code>10 > 11</code> evaluates to 0</li>
  <li>Relational operators can be used to compare integers and floats, where operands on either side of the operator can be of different data types</li>  
  <li>Relational operators have left to right associativity
    <ul>
      <li><code>i < j < k</code> evaluates to <code>(i < j) < k</code></li>
    </ul>    
  </li>  
</ul>  

### Equality Operators
<table>
    <thead>
        <tr>
            <td><strong>Operator</strong></td>
            <td><strong>Operator Name</strong></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>==</td>
            <td>equal to</td>
        </tr>
        <tr>
            <td>!=</td>
            <td>not equal to</td>
        </tr>
    </tbody>        
</table>       

<ul>
  <li>The equality operators have left-to-right associativity like the relational operators and produce either a 0 or 1 when evaluated</li>
</ul>    

### Logical Operators
<table>
    <thead>
        <tr>
            <td><strong>Operator</strong></td>
            <td><strong>Operator Name</strong></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>!</td>
            <td>logical negation</td>
        </tr>
        <tr>
            <td>&&</td>
            <td>logical and</td>
        </tr>
        <tr>
            <td>||</td>
            <td>logical or</td>
        </tr>
    </tbody>        
</table> 

<ul>
  <li>The logical operators have left-to-right associativity like the relational operators and produce either a 0 or 1 when evaluated</li>
  <li>!expr has the value 1 if expr has the value 0</li>
  <li>expr1 && and expr2 have the value 1; both expr1 and expr2 are nonzero values</li>
  <li>expr1 || expr2 has the value 1 if expr1 has a nonzero value and/or if expr2 has a nonzero value</li>  
</ul>    

### Precedence of all Operators
<table>
    <thead>
        <tr>
            <td><strong>Precedence</strong></td>
            <td><strong>Operator</strong></td>
            <td><strong>Operator Name</strong></td>
            <td><strong>Associativity</strong></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>x++, x--</td>
            <td>(postfix) Increment (++) and Decrement (--)</td>
            <td>Left-to-Right</td>
        </tr>
        <tr>
            <td>2</td>
            <td>!x, ++x, --x, (type)x, *x, &x, sizeof(x), +x, -x</td>
            <td>Logical Negation, (prefix) Increment and Decrement, Cast Operator, Deference Operator, Addressof Operator, sizeof, and Unary</td>
            <td>Right-to-Left</td>
        </tr>
        <tr>
            <td>3</td>
            <td>*, /, %</td>
            <td>Multiplication, Division, and Modulus</td>
            <td>Left-to-Right</td>
        </tr>
        <tr>
            <td>4</td>
            <td>+, -</td>
            <td>Addition and Subtraction</td>
            <td>Left-to-Right</td>
        </tr>
        <tr>
            <td>5</td>
            <td><, >, <=, >=</td>
            <td>Relational Operators</td>
            <td>Left-to-Right</td>
        </tr>
        <tr>
            <td>6</td>
            <td>==, !=</td>
            <td>Equality Operators</td>
            <td>Left-to-Right</td>
        </tr>
        <tr>
            <td>7</td>
            <td>&&</td>
            <td>Logical and</td>
            <td>Left-to-Right</td>
        </tr>
        <tr>
            <td>8</td>
            <td>||</td>
            <td>Logical or</td>
            <td>Left-to-Right</td>
        </tr>
        <tr>
            <td>9</td>
            <td>=, *=, /=, %=, +=, -=</td>
            <td>Assignment</td>
            <td>Right-to-Left</td>
        </tr>
        <tr>
            <td>10</td>
            <td>,</td>
            <td>Comma</td>
            <td>Left-to-Right</td>
        </tr>
    </tbody>        
</table> 

### Precedence Practice
<details>
  <summary>What does the following code print to the screen, if anything at all?

```cpp
int i = 3; j = 2; k = 1;

cout << i < j == j < k;
```
</summary>

```cpp
(i < j) == (j < k)
(3 < 2) == (2 < 1)
0 == 0
```
<ul>    
  <details>
    <summary>Output</summary>
      <pre>
        <code>
1
        </code>
      </pre>  
    </details>
  </ul>  
</details>
<details>
  <summary>What does the following code print to the screen, if anything at all?

```cpp
int i = 3; j = 2; k = 1;

cout << i % j + k > 2;
```
</summary>

```cpp
(i % j) + k > 2
(3 % 2) + 1 > 2
1 + 1 > 2
2 > 2
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

## The if Statement
<ul>
  <li>The if statement enables a program to evaluate an expression with two differing results that affect the functioning of the rest of the program. If the value of the expression is a nonzero integer, the expression is true and the code associated with the selection statement is executed; otherwise, if the value of the expression is zero, the expression is false and the code associated with the selection statement is not executed</li>
  <li>The if statement has the following form if the code associated with the if statement is only one line long:

```cpp
if (expression)
    statement;
```    
  </li>
  <li>The if statement has the following form; if the code associated with the if statement is longer than one line long:

```cpp
if (expression)
{
    statements;
}
```  
</li>
  <li>The parentheses around the expression following if are required, as this is the syntax of selection statements, rather than part of the expression</li> 
  <details>
    <summary>What does the following code print to the screen, if anything at all?

```cpp
int n = 12;

if (n >= 1 <= 10)
    cout << n;
```
</summary>

```cpp
((n >= 1) <= 10)
((12 >= 1) <= 10)
(1 <= 10)
1 --> true
if (1)
    cout << n;
//Therefore, n is printed to the screen
```
<ul>
<details>
  <summary>Output</summary>
    <pre>
      <code>
12
      </code>
    </pre>  
  </details>     
</ul>  
</details>   
<details>
  <summary>What does the following code print to the screen, if anything at all?

```cpp
int a = 3, b = 2, and c = 1;

if (a > b > c)
    cout << "Wohoo!\n";
```  
</summary>

```cpp
(a > b) > c
(3 > 2) > 1
1 > 1
0 --> false
if (0)
    cout << "Wohoo";
//Therefore, Wohoo is not printed to the screen
```
<ul>
<details>
  <summary>Output</summary>
    <pre>
      <code>
      </code>
    </pre>  
  </details>     
</ul>  
</details>  
</ul>

### The else Clause
<ul>
  <li>An if statement may also have an else clause, which has the following format:

```cpp
if (expression)
    statement;
else
    statement;
```
</li>
  <li>If the expression associated with the if statement evaluates to true, then the code associated with the if statement runs and the code associated with the else clause is skipped; however, if the if statement's expression evaluates to false, then the code associated with the else clause runs</li>  
  <li>There is no limit as to what code is associated with an if and else statement. In fact, it is not unusual for if statements to be nested within other selection statements. There is no limit on how much nesting can be done within selection statements
    <ul>
      <li>Here is an example of selection statements nested within each other:

```cpp
if (x == 1)
{
    if (y == 2)
        max = 2;
    else
        max = 1;   
}
else
    max = 0;
```
</li>
</ul>
  </li>  
</ul>    

### The else if Statement
<ul>
  <li>The else if statement is useful for  coding instances where there are more than two outcomes. When using if and else statements, either the code associated with the if statement runs or the code associated with the else statement runs. Using the if else statement, there can be more than two scenarios that affect the execution of the program</li>
  <li>Unlike the if and else statements, where there can only be one if statement and only one else clause per selection chain, there is no limit on how many else if statements can be written within a conditional chain
  <li>Here is the syntax for a condition chain that contains else if statements:

```cpp
if (expression)
    statement;
else if (expression1)
    statement;
else if (expression2)
    statement;
else if (expressionN)
    statement;
else
    statement;
```
  </li>  
</ul>    

### Conditional Expression
<ul>
  <li>The <em>conditional operator</em> is a shortcut to an if followed by an else clause, which uses the two symbols ? and :</li>
  <li>Here is the syntax for the conditional operator: (expr1) ? (expr2) : (expr3). To explain what this conditional operator does, here is a more elaborate syntax for it: (condition) ? value return if condition is true : value returned if condition is false</li>  
  <details>
    <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initializations
    int x = 1, y = 2, z;
    
    //getting the value of z
    z= (x > y) ? (x++) : (y++);

    cout << "z = " << z << endl;
    
    return 0;
}
```
<ul>   
  <details>
    <summary>Output</summary>
      <pre>
        <code>
z = 2
        </code>
      </pre>  
    </details>
  </ul>  
</details>
</ul>    

## Boolean Values
<ul>
  <li>Boolean values have either a true or a false value. The integer representations of true and false are as follows: true has any nonzero value and false has the value 0</li>
  <li>A common use for boolean values is to create flags, variables that are often of type boolean that control the flow of a program. Flags will hold the value of true or false and are often used in if/else if expressions
    <ul>
      <li>When flags are used in selection expressions, they can look like this: if (flag == true)...</li>
      <li>A more simple expression that has the same meaning as the one above is: if (flag)... What this statement does is insert the value of flag into the expression. If the flag is false, if (false), then the code associated with the if statement does not run; however, if the flag is true, if (true), then the code associated with the if statement runs</li>  
      <li>If one would like to run a section of code if flag is false rather than true, then the negation operator can be placed in front of the flag in the if expression: if (!flag)</li>  
    </ul>    
  </li>   
</ul> 

## The switch Statement
<ul>
  <li> Rather than having a large chain of else if statements embedded within the conditional chain, the switch statement may be handy. A switch statement is often easier to read than a large number of else if statements, and they too are faster than if statements when there are many cases</li>
  <li>Here is the syntax for a switch statement:

```cpp
switch (expression)
{
    case constantExpression: statement;
    case constantExpression: statement;
    default: statement:   
}
```
  </li>  
  <li>Here are the key elements that go into the creation of a switch block:
    <ul>
      <li><em>Controlling expression</em>: this is the expression that follows switch that is enclosed in parentheses. The expression must result in a value of type integer--either a char or an int. The switch statement does not work with strings, floats, and doubles</li>
      <li>Each case of the switch statement begins with a <em>case label</em> as follows: case constantExpression:</li>
      <li>The <em>constant expression</em> cannot contain variables or any call to the function. Here are some examples of constant expressions: 5 is a constant expression, even 5 + 10 is a constant expression, and n + 10 is not a constant expression--unless n is a macro that represents a constant. The constant expression in the case label must be an integer value (remember that a character is an integer as a character is represented by an ASCII character)</li>  
      <li>The <em>statements</em> come after each case label, and there can be as many cases as needed. Unlike with if statements, multiple statements associated with a switch's case do not need to be encapsulated by braces</li>  
    </ul>
  </li>     
  <li>Duplicate case labels are not allowed, and the cases do not have to follow any particular order. Even the default case does not have to be the last case within the switch's body</li>   
  <li>The switch statement does not have to have a default statement. If a switch statement is missing the default case and none of the constant expressions match the controlling expression, the computer just moves on to the line of code that is the next statement after the switch's body
    <ul>
      <li>The default statement does not need to have a break statement</li>
    </ul>    
  </li>  
</ul>    

### The Role of the break Statement
<ul>
  <li>Without a break statement, the control may fall through a case x and all cases including case x, and the cases, below it, will run. To prevent this from happening, a break statement can be used</li>
  <li>Here is a switch statement with no break statement:
    <details>
      <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    int number = 3;
    
    //switch statement to evaluate the number
    switch (number)
    {
        case 4: cout << "Excellent\n";
        case 3: cout << "Very good\n";
        case 2: cout << "Good\n";
        case 1: cout << "Satisfactory\n";
        case 0: cout << "Failed\n";
        default: cout << "Invalid input\n";    
    }
    
    return 0;
}
```
<ul>
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Very good
Good
Satisfactory
Failed
Invalid input
        </code>
      </pre>  
    </details>
  </ul>  
</details>
  </li>    
  <li>Here is the same switch statement with the addition of break statements in all the case statements:
    <details>
      <summary>Example Program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declaration and initialization
    int number = 3;
    
    //switch statement to evaluate the number
    switch (number)
    {
        case 4: cout << "Excellent\n"; break;
        case 3: cout << "Very good\n"; break;
        case 2: cout << "Good\n"; break;
        case 1: cout << "Satisfactory\n"; break;
        case 0: cout << "Failed\n"; break;
        default: cout << "Invalid input\n";    
    }
    
    return 0;
}    
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Very good
        </code>
      </pre>  
    </details>
  </ul>  
</details>
  </li>  
</ul>    
