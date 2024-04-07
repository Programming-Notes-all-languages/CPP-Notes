<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#comments'>Comments</a>
  </li>
  <li>
    <a href='#objects-and-variables'>Objects and Variables</a>
  </li>
  <li>
    <a href='#introduction-to-iostream'>Introduction to iostream</a>
  </li>  
  <li>
    <a href='#whitespace-and-basic-formatting'>Whitespace and Basic Formatting</a>
  </li> 
  <li>
    <a href='#introduction-to-literals-and-operators'>Introduction to Literals and Operators</a>
  </li>
  <li>
    <a href='#atomic-data-types-and-type-conversion'>Atomic Data Types and Type Conversion</a>
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
  <li>
    <a href='#shorthand-assignment-operators'>Shortcut Assignment Operators</a>
  </li>        
  <li>
    <a href='#header-files'>Header Files</a>
  </li>             
</ol>
</details>

## Comments
<ul>
  <li>
    <a><em>Comments</em> are notes created by the programmer that are included within the program. The compiler ignores these comments and are only there for the programmer's use</a>
  </li>
  <li>
    <a>In C++ there are two styles of comments:</a>
    <ul>
      <li>
        <a><em>Single-line comments</em></span>: are denoted with the double forward slash characters, //, and tell the compiler to ignore all code from the two forward slashes to end of the line of code</a>
      </li>
      <details>
      <summary>Example Program</summary>
        <ul>
          <pre>
            <code>
              #include <<a>iostream</a>>
              using namespace std;<br />
              <br />
              int main()<br />
              {<br />
                  cout << "Hello world!" << endl;<br />
                  //Everything here is ignored<br />
                  <br />
                  return 0;<br />
              }<be />
            </code>
          </pre>    
          <details>
          <summary>Output</summary>
            <pre>
              <code>
                Hello world!<br />
              </code>
            </pre>  
          </details>
        </ul>  
      </details>
      <li>
        <a><em>Multi-line comments</em>: are denoted by the /* and */ set of character. Everything that is enclosed within the /* and */ set of characters is a comment and therefore ignored by the compiler</a>
      </li>  
      <details>
      <summary>Example Program</summary>
        <ul>
          <pre>
            <code>
              #include <<a>iostream</a>>
              using namespace std;<br />
              <br />
              int main()<br />
              {<br />
                  /*This is a multi-line comment.<br />
                  This line will be ignored.<br />
                  So will this one.*/<br />
                  <br />
                  return 0;<br />
              }<be />
            </code>
          </pre>  
          <details>
          <summary>Output</summary>
            <pre>
              <code>
                <br />
              </code>
            </pre>  
          </details>
        </ul>  
      </details>
    </ul>
  </li> 
  <li>
    <a>Multi-line comments can be comprised of multiple single-line comments; however, multi-line comments cannot be embedded with any multi-line comments</a>
  </li>       
  <li>
    <a>Comments are useful to explain what certain lines and blocks of code do, especially when other programmers are reading the code</a>
  </li>  
</ul> 

## Variable Assignment and Initialization
<ul>
  <li>
    <a>A <em>variable</em> is a name given to an instance of a data type not defined by the user. The name of this instance is also called an <em>identifier</em>. Variables and identifiers are two words that mean the exact same thing</a>
  </li>
  <li>
    <a><em>Initialization</em> is the process in which a variable is assigned a memory address</a>
  </li>
  <li>
    <a>After a variable has been defined, it can be assigned a value using the <em>assignment operator</em>. The assignment operator is the equals sign character, =. The process of a variable being initialized is called <em>assignment</em>. Assignment and initialization are two words that mean the same thing</a>
  </li>
  <ul>
    <li>
      <a>int variable = "literal"; //literal on the right side of the assignment operator is assigned to the variable on the left side of the assignment operator</a>
    </li>
  </ul>              
  <li>
    <a>An <em>initializer</em> is the information, whether that be a literal or another variable, that is used to initialize a variable</a>
  </li>
  <li>
    <a>Here are the multiple types of initialization:</a>
    <ul>
      <li>
        <a><em>Default initialization</em>: when a identifier is not assigned an initializer by the user. In this scenario, the variable is assigned a garbage value given by the computer</a>
        <ul>
          <li>
            <a>int a;</a>
          </li>
        </ul>    
      </li>
      <li>
        <a><em>Copy initialization</em>: when an initializer is provided after the identifier and assignment operator</a>
        <ul>
          <li>
            <a>int b = 5;</a>
          </li>
        </ul>
      </li>  
      <li>
        <a><em>Direct initialization</em>: when an initializer is provided within parentheses after the identifier</a>
        <ul>
          <li>
            <a>int c(6);</a>
          </li>
        </ul>
      </li>
      <li>
        <a><em>Zero initialization</em>: a form of value initialization that initializes the variable to zero with an empty set of braces</a>
        <ul>
          <li>
            <a>int d{};</a>
          </li>
        </ul>
      </li>
      <li>
        <a><em>Copy initialization</em>: when an initializer is provided after the assignment operator within braces</a>
        <ul>
          <li>
            <a>int e = {7}</a>
          </li>
        </ul>
      </li>  
    </ul>
  </li>   
  <li>
    <a>Multiple variables can be initialized on the same line where commas separate each variable's assignment</a>
  </li> 
  <li>
    <a>A variable that has not been initialized is called an <em>uninitialized variable</em></a>  
    <ul>
      <li>
        <a>Printing out an uninitialized variable to the console causes a random value to be stored into the variable's memory address</a>
      </li>
    </ul>    
  </li>   
</ul>

## Introduction to iostream
<ul>
  <li>
    <a><em>Input/output library</em>: is the part of C++'s iostream library and deals with basic user input and output. To use this library, it must be included at the top of the program. This is done by adding #include <a><</a><a>iostream</a><a>></a>
  </li>
  <li>
    <a><em>cout</em>: allows for text and information to be printed to the console after the buffer is flushed by using the <em>insertion operator</em>: <a><<</a></a>
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
          &emsp;&emsp;cout << "Hello World! << endl; //prints Hello World! to the console<br />
          <br />
          &emsp;&emsp;return 0;<br />
          }<br />
        </code>
      </pre>  
      <details>
      <summary>Output</summary>
        <pre>
          <code>
            Hello World!<br />
          </code>
        </pre>  
      </details>
    </ul>  
  </details>  
  <li>
    <a>endl versus \n:</a>
    <ul>
      <li>
        <a>Output is typically not sent to the console immediately; instead, the requested output waits in a queue. This queue is a storage location of memory called a <em>buffer</em></a>
      </li>
      <li>
        <a>The buffer is <em>flushed</em> periodically, meaning all the information that has been stored in the buffer will be printed to the console</a>
      </li>
      <li>
        <a>endl has two jobs: endl moves the curser to the next line of code in the program and it flushes the buffer</a>
      </li>
      <li>
        <a>The \n character is often preferred because it moves the cursor to the next line of the console, but does not request a flush. Since the program will be flushed less when the \n character is used instead of endl, compilation time will be shorter</a>
      </li>      
    </ul>
  </li>
  <li>
    <a><em>cin</em>: reads input from the keyboard using the <em>extraction operator</em>: >>
  </li>          
</ul> 

## Whitespace and Basic Formatting
<ul>
  <li>
    <a><em>Whitespace</em> is a term that refers to characters that are used for formatting purposes; in C++, this refers primarily to spaces, tabs, and newlines</a>
  </li>  
  <li>
    <a>The C++ compiler generally ignores whitespaces; therefore, C++ is a whitespace-independent language</a>
    <ul>
      <li>
        <a>The one exception where the C++ compiler does not pay attention to whitespace is inside quoted text</a>
      </li>
    </ul>    
  </li>  
  <li>
    <a>Variable names cannot contain whitespaces</a>
  </li> 
</ul>

## Introduction to Literals and Operators
<ul>
  <li>
    <a><em>Literals</em> are fixed values that have been inserted directly into the source code</a>
    <ul>
      <li>
        <a>Examples of literals are 1, 2.5, "garrett", and 'c'. These are literals because you cannot assign different values to those terms</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Operators</em> are symbols that perform operations on variables and values</a>
    <ul>
      <li>
        <a>Operators can be chained together; the output of one operation can be used as the input for another operator</a>
      </li>
    </ul>
  </li>
</ul>    

## Atomic Data Types and Type Conversion
<ul>
  <li>
    <a><em>bool</em>: has two possible values: true or false</a>
  </li>
  <li>
    <a><em>string</em>: used to store a list of characters</a>
  </li>
  <li>
    <a>Integer types:</a>
    <ul>
      <li>
        <a><em>char</em>: typically used to represent a character</a>
      </li>
      <li>
        <a><em>int</em>: used to represent an integer</a>
      </li>  
    </ul>
  </li> 
  <li>
    <a>Floating point types:</a>
    <ul>
      <li>
        <a><em>float</em>: used to represent decimal numbers</a>
      </li>
      <li>
        <a><em>double</em>: used to represent decimal numbers</a>
      </li>
    </ul>
  </li>   
  <li>
    <a>SMALLEST --- char << int << float << double --- GREATEST</a> 
    <ul>
      <li>
        <a>You can store a smaller data type into a largest data type. For example, you can store an int into a float or a double</a>
      </li>
    </ul>     
  </li>  
  <li>
    <a>Type conversion:</a>
    <ul>
      <li>
        <a>Can use variable = dataType(variable); to change variable's type to dataType</a>
      </li>
      <li>
        <a>Can also use variable = static_cast</a><a><</a><a>dataType</a><a>></a><a>; to change variable type to dataType</a>
      </li>
      <li>
        <a>Converting any char into another type returns that value's ascii value</a>
      </li>  
      <li>
        <a>Examples of type conversion:</a>
        <details>
        <summary>Example Program</summary>
          <ul>
            <pre>
              <code>
                #include <iostream><br />
                using namespace std;<br />
                <br />
                int main()<br />
                {<br />
                &emsp;&emsp;double x = 1.1, y = 7.2;<br />
                &emsp;&emsp;x = int(x);<br />
                <br />
                &emsp;&emsp;cout << "The value of x is: " << x << '\n';<br />
                &emsp;&emsp;y = static_cast<int>(y);<br />
                &emsp;&emsp;cout << "The value of y is: " << y << '\n';<br />
                <br />
                &emsp;&emsp;return 0;<br />
                }<br />
              </code>
            </pre>  
            <details>
            <summary>Output</summary>
              <pre>
                <code>
                  The value of x is: 1<br />
                  The value of y is: 7<br />
                </code>
              </pre>  
            </details>
          </ul>  
        </details>
      </li>  
    </ul>
  </li>                 
</ul>   

## Constant Variables
<ul>
  <li>
    <a><em>Constant variable</em>: a variable whose value cannot change once it is declared and initialized</a>
    <ul>
      <li>
        <a>Muse use the keyword <em>const</em> or the define preprocessor</a>
      </li>
      <li>
        <a>Must declare and initialize the const variable on the same line</a>
      </li>
      <ul>
        <li>
          <a>const double SIZE = 3.14; //legal</a>
        </li>
        <li>
          <a>const double;<br />SIZE = 3.14; //illegal since variable declaration and initialization does not take place on the same line of code</a>  
        </li>
      </ul>
      <li>
        <a>The syntax for the define preprocessor statement is the following: #define identifier literal</a>
        <ul>
          <li>
            <a>#define PI 3.14159</a>
          </li>
        </ul>    
        <details>
        <summary>Example Program</summary>
          <ul>
            <pre>
              <code>
                #include <iostream><br />
                using namespace std;<br />
                <br />
                int main()<br />
                {<br />
                &emsp;&emsp;cout << "PI: " << PI << endl;
                &emsp;&emsp;return 0;<br />
                }<br />
              </code>
            </pre>  
            <details>
            <summary>Output</summary>
              <pre>
                <code>
                  PI: 3.14159<br /> 
                </code>
              </pre>  
            </details>
          </ul>  
        </details>
      </li> 
    </ul>
  </li>     
</ul>      

## Escape Sequences
<ul>
  <li>
    <a>The backslash / is the indicator of an escape sequence</a>
  </li>
  <li>
    <a>Some of the common escape sequences are listed below:</a>
    <ul>
      <li>
        <a>\n: newline</a>
      </li>
      <li>
        <a>\t: tab</a>
      </li>
    </ul>
  </li>
</ul>

## Arithmetic Operators
<ul>
  <li>
    <a><em>Addition operator</em>: adds the value on the left-hand side of the operator to the value on the right-hand side of the operator</a>
    <ul>
      <li>
        <a>x + y //sums the values x and y</a>
      </li>
    </ul>    
  </li>
  <li>
    <a><em>Subtraction operator<em>: subtracts the value on the right-hand side of the operator from the value on the left-hand side of the operator</a> 
    <ul>
      <li>
        <a>x - y; //subtracts the value y from the value x</a>
      </li>
    </ul>    
  </li>
  <li>
    <a><em>Multiplication operator</em>: multiplies the value on the right-hand side of the operator to the value on the left-hand side of the operator</a>
    <ul>
      <li>
        <a>x * y; //multiplies the values x and y</a>
      </li>
    </ul>    
  </li>
  <li>
    <a><em>Division operator</em>: divides the value on the left-hand side of the operator by the value on the right-hand side of the operator</a>
    <ul>
      <li>
        <a>x / y; //divides the x value by the value y</a>
      </li>
    </ul>    
  </li>
  <li>
    <a><em>Modulus operator</em>: divides the value on the left-hand side of the operator by the value on the right-hand side of the operator and returns the remainder</a>
    <ul>
      <li>
        <a>x % y; //finds the remainder of the value x divided by value y</a>
      </li>
    </ul>     
  </li>
  <li>
    <a><em>Pre-increment operator</em>: incrementing is done before the variable is used within the written line of code</a>
    <ul>
      <li>
        <a>++x; //increases the value of the variable by one integer</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Post-increment operator</em>: incrementing is done after the variable is used within the written line of code</a>
    <ul>
      <li>
        <a>x++; /increases the value of the variable by one integer</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Pre-decrement operator</em>: decrementing is done before the variable is used within the written line of code</a>
    <ul>
      <li>
        <a>--x; //decreases the value of the variable by one integer</a>  
      </li>
    </ul>
  </li>
  <li>
    <a><em>Post-decrement operator</em>: decrementing is done after the variable is used within the written line of code</a>  
    <ul>
      <li>
        <a>x--; //decreases the value of the variable by one integer</a> 
      </li>
    </ul>
  </li>
</ul>   

## Shorthand Assignment Operators
<ul>
  <li>
    <a><em>Addition assignment operator</em>: adds the value on the right-hand side of the operator to the value on the left-hand side</a>
    <ul>
      <li>
        <a>x += y; //means x equals the sum of x and y</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Subtraction assignment operator</em>: subtracts the value on the right-hand side of the operator from the value on the left-hand side</a>
    <ul>
      <li>
        <a>x -= y; //means x equals the subtraction of y from x</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Multiplication assignment operator</em>: multiplies the value on the right-hand side of the operator to the value on the left-hand side</a>
    <ul>
      <li>
        <a>x *= y; //means x equals the product of x and y</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Division assignment operator</em>: divides the value on the right-hand side of the operator to the value on the left-hand side</a>
    <ul>
      <li>
        <a>x /= y; //means x equals x divided by y</a>
      </li>
    </ul>
  </li>
  <li>
    <a><em>Modulo assignment operator</em>: finds the remainder of the value on the left-hand side of the operator divided by the value on the right-hand side</a>
    <ul>
      <li>
        <a>x %= y; //means x equals the remainder of x divided by y</a>
      </li>
    </ul>
  </li>                   
</ul>

## Header File
<ul>
  <li>
    <a>Header files are used to contain declarations of functions and classes</a>
  </li>
  <li>
    <a>There are a minimum of three files needed when implementing the header file: a main.cpp file, the header file, and the implementation file</a>
    <ul>
      <li>
        <a>The header and main files must be cpp files wheres the header file must end in .h</a>
      <li>
        <a>The name of the header file and the implementation file must be identical. If the name of the header file is Function.h, then the name of its implementation file must be Function.cpp</a>
      </li>
    </ul>
  </li>      
</ul>    
