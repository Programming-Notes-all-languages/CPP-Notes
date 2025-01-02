<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#operator-precedence-and-associativity'>Operator Precedence and Associativity</a>
  </li> 
  <li>
    <a href='#assignment-operators'>Assignment Operators</a>
  </li>
  <li>
    <a href='#shorthand-assignment-operators'>Shorthand Assignment Operators</a>
  </li>
  <li>
    <a href='#increment-and-decrement-operators'>Increment and Decrement Operators</a>
  </li>
  <li>
    <a href='#expression-evaluation'>Expression Evaluation</a>
  </li>
</ol>
</details>

## Operator Precedence and Associativity
### Operator Precedence
<table>
  <thead>
    <tr>
      <th><strong>Precedence</strong></th>
      <th><strong>Operator</strong></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>(postfix) Increment (++) and Decrement (--)</td>
    </tr>
    <tr>
      <td>2</td>
      <td>(prefix) Increment (++) and Decrement (--) and Unary (+), (-)</td>
    </tr>
    <tr>
      <td>3</td>
      <td>Multiplication (*), Division (/), and Modulus (%)</td>
    </tr>
    <tr>
      <td>3</td>
      <td>Multiplication (*), Division (/), and Modulus (%)</td>
    </tr>
    <tr>
      <td>4</td>
      <td>Addition (+) and Subtraction (-)</td>
    </tr>
    <tr>
      <td>5</td>
      <td>Assignment (= *= /= %= += -=)</td>
    </tr>
  </tbody>
</table>    

<ul>
  <li>Here is the associativity of the most common operators:
    <ul>
      <li>Left to right:<br />
        --> Addition and Subtraction<br />
        --> Multiplication, Division, and Modulus<br />
        --> Increment and Decrement (postfix)</li>
      <li>Right to left:<br />
        --> Assignment (= *= /= %= += -=)<br />
        --> Unary<br />
        --> Increment and Decrement (prefix)</li>  
    </ul>    
  <li>Here is a list of examples that show the precedence of the most common operators:
    <ul>
      <li><code>i + j * k</code> is equivalent to <code>i + (j * k)</code></li>
      <li><code>-i * -j</code> is equivalent to <code>(-i) * (-j)</code></li>  
      <li><code>+i + j / k</code> is equivalent to <code>(+i) + (j / k)</code></li>  
      <li><code>i - j - k</code> is equivalent to <code>(i - j) - k</code></li>
      <li><code>i * j / k</code> is equivalent to <code>(i * j) / k</code></li> 
      <li><code>- + i</code> is equivalent to <code>-(+i)</code></li> 
    </ul>
  </li>      
</ul>    

## Assignment Operators
<ul>
  <li>The assignment operator, =, is a common operator that is used in the initialization of variables</li>
  <li>Several assignments can be chained together using the assignment operator such as in the following: <code>i = j = k = 0;</code></li> 
  <li>The assignment operator is right-associative, meaning that <code>i = j = k = 0;</code> is equivalent to <code>i = (j = (k = 0));</code> Here, k is assigned the integer value 0; j is assigned to k containing the integer value of 0; and lastly; i is assigned to j containing the integer value of 0</li>   
  <li>When using the assignment operator, the operand on the left side of the operator must be an object stored in the computer's memory rather than a constant. It is illegal to put any kind of expression on the left side of the assignment operator other than an object stored in memory itself</li>  
</ul>    

## Shorthand Assignment Operators
<ul>
  <li><em>Addition assignment operator</em>: adds the value on the right-hand side of the operator to the value on the left-hand side and stores the summation in the variable on the left-hand side of the operator
    <ul>
      <li><code>x += y; //means x equals the sum of x and y</code></li>
      <li>--> <code>x = x + y;</code></li>  
    </ul>
  </li>
  <li><em>Subtraction assignment operator</em>: subtracts the value on the right-hand side of the operator from the value on the left-hand side and stores the subtraction in the variable on the left-hand side of the operator
    <ul>
      <li><code>x -= y; //means x equals the subtraction of y from x</code></li>
      <li>--> <code>x = x - y;</code></li>
    </ul>
  </li>
  <li><em>Multiplication assignment operator</em>: multiplies the value on the right-hand side of the operator to the value on the left-hand side and stores the product in the variable on the left-hand side of the operator
    <ul>
      <li><code>x *= y; //means x equals the product of x and y</code></li>
      <li>--> <code>x = x * y;</code></li>
    </ul>
  </li>
  <li><em>Division assignment operator</em>: divides the value on the left-hand side of the operator to the value on the left-hand side of the operator and stores the division in the variable on the left-hand side of the operator
    <ul>
      <li><code>x /= y; //means x equals x divided by y</code></a>
      </li>
      <li>--> <code>x = x / y;</code></li>
    </ul>
  </li>                  
</ul> 

## Increment and Decrement Operators
<ul>  
  <li><em>Pre-increment operator</em>: incrementing is done before the variable is used within the written line of code
    <ul>
      <li><code>++x; //increases the value of the variable by one integer</code></li>
    </ul>
  </li>
  <li><em>Post-increment operator</em>: incrementing is done after the variable is used within the written line of code</a>
    <ul>
      <li><code>x++; /increases the value of the variable by one integer</code></li>
    </ul>
  </li>
  <li><em>Pre-decrement operator</em>: decrementing is done before the variable is used within the written line of code
    <ul>
      <li><code>--x; //decreases the value of the variable by one integer</code></li>
    </ul>
  </li>
  <li><em>Post-decrement operator</em>: decrementing is done after the variable is used within the written line of code
    <ul>
      <li><code>x--; //decreases the value of the variable by one integer</code></li>
    </ul>
  </li>
</ul>  

## Expression Evaluation
<details>
  <summary>Evaluate the expression using parentheses for a:<br />
  <code>a = b += (c++) - d + --e / -f</code></summary>
  <ul>
    <details>
    <summary>Output</summary>
      <pre>
        <code>
a = b += (c++) - d + --e / -f
a = b += (c++) - d + (--e) / -f
a = b += (c++) - d + (--e) / (-f)
a = b += (c++) - d + ((--e) / (-f))
a = b += ((c++) - d) + ((--e) / (-f))
a = b += (((c++) - d) + ((--e) / (-f)))
a = (b += (((c++) - d) + ((--e) / (-f))))
        </code>
      </pre>  
    </details>
  </ul>  
</details>  

<details>
  <summary>Evaluate the expression for c:

```cpp
int a = 5, b;
int c = (b = a + 2) - (a = 1);
```
</summary>
  <ul>
    <details>
    <summary>Output</summary>
      <pre>
        <code>
c = (b = 5 + 2) - 1;
c = (b = 7) - 1;
c = 7 - 1;
c = 6;
        </code>
      </pre>  
    </details>    
  </ul>  
</details> 

<details>
  <summary>Evaluate the expression for x:

```cpp
int x = 7;
int y = 4;
x = ++x + y++ + ++y;
```
</summary>
  <ul>
    <details>
    <summary>Output</summary>
      <pre>
        <code>
x = 8 + 4 + 6;
x = 18;
        </code>
      </pre>
    </details>      
  </ul>  
</details> 
