<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#streams'>Streams</a>
  </li>   
  <li>
    <a href='#file-operations'>File Operations</a>
  </li>  
  <li>
    <a href='#formatted-input-and-output'>Formatted Input and Output</a>
  </li>  
</ol>
</details>

## Streams
<ul>
  <li>In C++, file input and output are managed within the <code><fstream></code> library using file streams</li>
  <li>This header provides the necessary classes and functions for file input and output in C++<code>#include <fstream></code></li>
  <li><code>ifstream</code> is the input file stream which reads from a file</li>
  <li><code>ofstream</code> is the output file stream which writes to a file</li>
  <li><code>fstream</code> is a combination of <code>ifstream</code> and <code>ofstream</code> and provides a single interface for both input and output operations</li>
</ul>  

## File Operations
### Opening a File
<ul>
  <li>Opening a file is done by creating a file stream object and by using the .open() method<li>
  <li>Here is an example of how to open a file using the ifstream (stream for reading information from a file):
  
```cpp
ifstream myFile;
myFile.open("example.txt");
```
  </li>
  <li>To test if a file opened successfully, a call to the is_open()method enacted on a file stream object can be done like the following:

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myFile;
    myFile.open("example.txt");

    if (!myFile.is_open()) 
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    return 0;
}    
```
  </li>
  <li>To open up a file upon the creation of a file stream object, the following can be done: <code>ifstream inFile("input.txt");</code></li>
  <details>
    <summary>Example program</summary>

```cpp
//Write a program that copies the contents of one file into another
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    string line;

    if (!inFile)
    {
        cerr << "Error opening files." << endl;
        return 1;
    }

    while (!inFile.eof())
    {
        getline(inFile, line);
        outFile << line << "\n";
    }

    inFile.close();
    outFile.close();

    return 0;
}    
```
</details>
  </ul>  
  </details> 
</ul>  

### Modes
<ul>
  <li>Here are the default open modes:
<table>
  <tr>
    <td>ifstream</td>
    <td>ios::in</td>
  </tr>
  <tr>
    <td>ofstream</td>
    <td>ios::out</td>
  </tr>
  <tr>
    <td>fstream</td>
    <td>ios::in | ios::out</td>
  </tr>    
</table>
  </li>
  <li>Here are some additional open modes in C++:

<table>
  <tr>
    <td>ios::ate</td>
    <td>The output position starts at the end of the file</td>
  </tr>
  <tr>
    <td>ios::app</td>
    <td>All output operations happen at the end of the file</td>
  </tr>
  <tr>
    <td>ios::trunc</td>
    <td>Any contents that existed on the file once it is opened are wiped</td>
  </tr>    
  <tr>
    <td>ios::nocreate</td>
    <td>Does not create a new file if it does not already exist</td>
  </tr>    
</table>
  </li>
</ul>

### Closing a File
<ul>
  <li>A file must always be closed after a file is opened in any mode</li>
  <li>Here is the syntax for the fclose function:

```cpp
fileObject.close();
```
  </li>
</ul>  

## Formatted Input and Output
### The >> Operator
<ul>
  <li>To read in information from a file, a string variable can be declared where the contents of the line in the file are stored in a string</li>
  <li>Here is one way to read information from a file and to store it in a string within the program:

```cpp
string line;
inFile >> line;
```
  </li>
  <li>To read a whole line from a file, the getline function can be used such as in the following:

```cpp
string line;
getline(inFile, line);
```
  </li>
  <li>Here is the syntax for the getline function that is defined withing the <code><string></code>library:

```cpp
istream& getline(istream &is, string &str, char delim);
```
  <ul>
    <li>The getline function takes characters from an input string and appends them to a string object until the delim character is encountered; once it is encountered, the getline function terminates and control moves to the next line in the program
      <ul>
        <li>is: is an object of type istream class which tells getline function which stream to read information from</li>
        <li>str: is the string object where the input is stored</li>
        <li>delim: is the character that tells the function to stop reading further input</li>
      </ul>
    </li>    
  </ul>
  </li>
</ul>      

### The << Operator
<ul>
  <li>Similar to the >> operator, the << operator can be overloaded to write information to a file</li>
  <li>Here is the syntax for the writing a string to a file:

```c
outFile << "Hello, file!" << endl;
```
  </li>
</ul>          

### Detecting End-of-File
<ul>
  <li>To check whether the control has reached the end of a file, the eof() method can be used</li>
  <li>Here is the syntax for the eof() method:

```cpp
fileStream.eof();
```
  </li>
  <li>Here is an example of a while loop which loops through a file until the end of the file is reached:

```cpp
while (!inFile.eof())
{
    inFile >> word;
}
```
  </li>
  <details>
    <summary>Example program</summary>

```cpp
//Write a program that reads the contents of a csv and writes each word to a new-line within a different file
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    string line;

    if (!inFile)
    {
        cerr << "Error opening files." << endl;
        return 1;
    }

    while (!inFile.eof())
    {
        getline(inFile, line);
        outFile << line << "\n";
    }

    inFile.close();
    outFile.close();

    return 0;
}    
```
</details>
  </ul>  
  </details> 
</ul>      
