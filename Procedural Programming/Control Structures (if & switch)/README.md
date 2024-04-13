<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#comparison-operators'>Comparison Operators</a>
  </li>
  <li>
    <a href='#logical-operators'>Logical Operators</a>
  </li>
  <li>
    <a href='#conditional-statements'>Conditional Statements</a>
  </li>  
  <li>
    <a href='#switch-statement'>Switch Statements</a>
  </li>              
</ol>
</details>

## Comparison Operators

<ul>
  <li>
    <a><em>Equal to operator</em>: compares two values and evaluates to true if the value on the left-hand side of the operator equals the value on the right-hand side of the operator; otherwise, evaluates to false</a>
    <ul>
      <li>
        <a>(x == y) //compares the values x and y</a>
      </li>
    </ul>
  </li> 
  <li>
    <a><em>Not equal to operator</em>: compares two values and evaluates to false if the value on the left-hand side of the operator equals the value on the right-hand side of the operator; otherwise, evaluates to true</em></a>    
    <ul>
      <li>
        <a>(x != y) //compares the values x and y</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Less than operator</em>: compares two values and evaluates to true if the value on the left-hand side of the operator is less than the value on the right-hand side of the operator; otherwise, evaluates to false</a>   
    <ul>
      <li>
        <a>(x < y) //compares the values x and y</a> 
      </li>
    </ul>
  </li>
  <li>
    <a><em>Greater than operator</em>: compares two values and evaluates to true if the value on the left-hand side of the operator is greater than the value on the right-hand side of the operator; otherwise, evaluates to false</a> 
    <ul>
      <li>
        <a>(x > y) //compares the values x and y</a>
      </li>
    </ul>      
  </li> 
  <li>
    <a><em>Less than or equal to operator</em>: compares two values and evaluates to true if the value on the left-hand side of the operator is less than or equal to the value on the right-hand side of the operator; otherwise, evaluates to false</a> 
    <ul>
      <li>
        <a>(x <= y) //compares the values x and y</a>
      </li>
    </ul>
  </li>  
  <li>
    <a><em>Greater than or equal to operator</em>: compares two values and evaluates to true if the value on the left-hand side of the operator is greater than or equal to the value on the right-hand side of the operator; otherwise, evaluates to false</a> 
    <ul>
      <li>
        <a>(x >= y) //compares the values x and y</a>
      </li>
    </ul>
  </li>        
</ul>

## Logical Operators
<ul>
  <li>
    <a><em>Logical and operator</em>: compares two statements and evaluates to true if the statement on the left-hand side of the operator is true and if the statement on the right-hand side of the operator is true; otherwise, evaluates to false</a>
    <ul>
      <li>
        <a>(x && y) //compares the statements x and y</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Logical or operator</em>: compares two statements and evaluates to true if at least one of the statements on either the left-hand side or the right-hand side of the operator evaluates to true; otherwise, evaluates to false</a>
    <ul>
      <li>
        <a>(x || y) //compares the statements x and y</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Logical not operator</em>: evaluates to true if a statement or set of statements evaluates to false; otherwise, evaluates to false</a>
    <ul>
      <li>
        <a>!(x && y) //compares the statements x and y and negates its value</a>
      </li>
    </ul>
  </li>
</ul>     

## Conditional Statements
<ul>
  <li>
    <a><em>Conditional statements</em>: test whether conditions evaluates to true and if a condition evaluates to true, the body of code associated with that conditional statement runs. However, if the condition does not evaluate to true, all the code associated with that selection statement is skipped</a>
    <ul>
      <li>
      <a>Here is the syntax for a pair of conditional statements that each contain one line of code:<br /></a>
      <a>&emsp;&emsp;if (expression)<br />
      &emsp;&emsp;&emsp;&emsp;statement;<br />
      &emsp;&emsp;else<br />
      &emsp;&emsp;&emsp;&emsp;statement;<br /></a>    
      </li>
      <li>
        <a>If the statement like in the above example is a single line of code, then no braces are required to surround that line of code. Braces can be added around a singular line of code, but it is not required. However, if the statement is not a single line of code, but rather multiple lines of code, then braces must wrap around those statements</a>
      </li>  
      <li>
        <a>Here is the syntax for a pair of conditional statements where one contains multiple lines of code and the other contains a single line of code:<br /></a> 
        <a>&emsp;&emsp;if (expression)<br />
        &emsp;&emsp;{<br />
        &emsp;&emsp;&emsp;&emsp;statements;<br />
        &emsp;&emsp;}<br />
        &emsp;&emsp;else<br />
        &emsp;&emsp;&emsp;&emsp;statement;<br /></a>
      </li> 
      <li>
        <a>If there is the need to have more than one condition that either evaluates to true or false, then there is the else if statement. The else if statement precedes the else statement and lies below the if statement. There can be an infinite number of else if conditional tests; however, there can only be one if statement and one else statement per conditional chain</a>
      </li>
      <details>
      <summary>Example Program</summary>    
        <ul>
          <pre>
            <code>
              #include <<a>iostream</a>><br />
              using namespace std;<br />
              <br />
              int main()<br />
              {<br />
              &emsp;&emsp;double grade = 89.5;<br />
              <br />
              &emsp;&emsp;if (grade > 70 && grade != 100)<br />
              &emsp;&emsp;&emsp;&emsp;cout << "You passed the class!" << endl;<br />
              &emsp;&emsp;else if (grade == 100)<br />
              &emsp;&emsp;&emsp;&emsp;cout << "You passed and got a perfect score!" << endl;<br />
              &emsp;&emsp;else<br />
              &emsp;&emsp;&emsp;&emsp;cout << "You failed!" << endl;<br />  
              <br />
              &emsp;&emsp;return 0;<br />
              }<br />
            </code>
          </pre>  
          <details>
          <summary>Output</summary>
            <pre>
              <code>
                You passed the class!<br />
              </code>
            </pre>  
          </details>
        </ul>  
      </details>
    </ul>  
  </li>   
</ul> 

## Switch Statement
<ul>
  <li>
    <a><em>Switch statement</em>: takes in an expression, one that evaluates to a constant value, and then compares the statement's cases. If the given value matches a case, the code associated with that case runs. For the cases where the provided value does not match the case, that code is skipped by the compiler</a>
    <ul>
      <li>
        <a>The values of the case labels must be constants and can only be of integer types: int, char, and enums</a>
      </li>
      <li>
        <a>Each case value must be different from all other case values within the switch statement</a>
      <li>
        <a>If the passed-in value matches a case, each case underneath that case with the matching value will run up until the compiler has read a break statement. A <em>break statement</em> is needed to stop the execution of code within a switch block</a>
      <li>
        <a>To prevent the compiler from falling through into the next case, a break statement is needed. Let's say that there are three cases in the following order from start to finish: 'A', 'B', and 'C'. If the value passed into the switch statement stores memory address to the literal 'A', then the code associated with case 'A' runs. Let's also say there is no break statement in case 'A', 'B', or 'C'. Since the literal 'A' matches case 'A', the code associated with case 'A' runs. Since there is no break statement within case 'A', the code associated with case 'B' runs. Again, since there is no break statement within case 'B', the code associated with case 'C' runs</a>
        <details>
        <summary>Example Program</summary>    
          <ul>
            <pre>
              <code>
                #include <<a>iostream</a>><br />
                using namespace std;<br />
                <br />
                int main()<br />
                {<br />
                &emsp;&emsp;char grade = 'A';<br />
                <br />
                &emsp;&emsp;switch(grade)<br />
                &emsp;&emsp;{<br />
                &emsp;&emsp;&emsp;&emsp;case 'A':<br />
                &emsp;&emsp;&emsp;&emsp;case 'B':<br />
                &emsp;&emsp;&emsp;&emsp;case 'C':<br />
                &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;cout << "Case C ran even though the grade is " << grade << "!" << endl;<br />
                &emsp;&emsp;}<br />
                <br />
                &emsp;&emsp;return 0;<br />
                }<br />
              </code>
            </pre>  
            <details>
            <summary>Output</summary>
              <pre>
                <code>
                  Case C ran even though the grade is A!<br />
                </code>
              </pre>  
            </details>
          </ul>  
        </details>
      </li>
    </ul>    
  </li>
</ul>        
