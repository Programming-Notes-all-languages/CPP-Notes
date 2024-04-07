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
        <a><em>Single-line comments</em>: are denoted with the double forward slash characters, //, and tell the compiler to ignore all code from the two forward slashes to end of the line of code</a>
      </li>
      <details>
      <summary>Example Program</summary>
        <ul>
          <pre>
            <code>
              #include <<a>iostream</a>><br />
              using namespace std;<br /><br />
              int main()<br />
              {<br />
                  cout << "Hello world!" << endl;<br />
                  //Everything here is ignored<br />
                  <br />return 0;<br />
              }<br />
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
              /*This is a multi-line comment.<br />
              This line will be ignored.<br />
              So will this one.*/<br />
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
