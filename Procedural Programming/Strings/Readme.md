<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#string-literals'>String Literals</a>
  </li> 
  <li>
    <a href='#string-variables'>String Variables</a>
  </li> 
  <li>
    <a href='#reading-and-writing-strings'>Reading and Writing Strings</a>
  </li> 
  <li>
    <a href='#accessing-the-characters-in-a-string'>Accessing the Characters in a Strings</a>
  </li> 
  <li>
    <a href='#command-line-arguments'>Command Line Arguments</a>
  </li> 
</ol>
</details>

## String Literals
<ul>
  <li><em>String literals</em> are a sequence a characters that are declared such as the following that are enclosed within double quotes: <code>char *string = "Garrett";</code></li>
  <li>Strings are essentially character arrays. Each character within a string is stored into an index of the char array. The name of the string is the char array</li>
  <li>When the compiler encounters a string literal of length size, the program sets aside size + 1 amount of memory for the string
    <ul>
      <li>A string literal contains all the characters within string, plus a single \0 character called the <em>null character</em>, which is an escape sequence, is appended after the end of the last character</li>
      <li>For example, the string literal "abc" is stored into an array of type char in four characters in the following order: 'a', 'b', 'c', and '\0'</li>   
    </ul>
  </li>   
</ul>  

### Operations on String Literals
<ul>
  <li>Like with arrays, string literals can be pointed to by pointers. Pointers that point to string literals are of type char * and can only point to one index, one character, within the string literal</li>
  <li>Unlike with arrays, string literals following declarations cannot be modified. Any attempt to modify a string variable will result in undefined behavior</li>  
  <li><code>const char *string = "Garrett";</code> cannot be modified whereas <code>char string[] = "Garrett";</code> can be modified</li>
</ul>   

### String Literals versus Character Constants
<ul>
  <li>The difference between a string literal and a character constant is the following: a string literal is represented by a pointer where the content of the string is stored in memory and a character constant is where a character is represented by an integer</li>
</ul>    

## String Variables
### Initializing a String Variable
<ul>
  <li>In C++, there is a definition for a string defined within the standard library unlike in C</li>
  <li>There are benefits to both C and C++ strings. The main difference being that with C strings, there is absolute control over memory allocation and with C++ strings is that they are easier to use</li>
  <li>Here is the syntax for creating a string variable:

```c
int length = 12;
char variableName[length + 1] = "Garrett Ellis";
```
  </li>    
  <li>If the length of the char array is longer than the string literal assigned to the character array, then the remaining indices of the array are simply assigned a null character</li>
  <li>The size of the char array can be omitted, just like with any other arrays that are initialized. The array's size will be one greater than the number of elements within the char array because the last element of a character array must be a null character</li>    
</ul>   

<details>
    <summary>Example program</summary>

What are the contents of string <code>s1</code> after executing the following statements?

<div align="center">

```cpp
string s1 = "hello"
string s2 = "students"
s1 += s1 + s2[0] + s1
```
</div>

<ul>  
  <details>
    <summary>Output</summary>

```cpp
//s1 = s1 + s1 + s2[0] + s1
//s1 = "hello" + "hello" + "s" + "hello"
//s1 = "hellohelloshello"
```
</details>
  </ul>  
</details>  

### Character Arrays versus Character Pointers
<ul>
  <li>There are a few key differences between character arrays and character pointers:
    <ul>
      <li>Character arrays can have its contents be modified just like any other array</li>
      <li>Character pointers that point to a string literal cannot modify the string literal</li>
      <li>Regarding character arrays, the declared character array is simply the name of the array whereas a character pointer can point to an indefinite number of string literals</li>
    </ul>
  </li>
</ul>   

## Reading and Writing Strings
### Writing Strings Using printf and puts
<ul>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;

int main()
{
    //variable declarations and initialization
    string str = "Garrett is amazing!";
    
    cout << str << endl;
    
    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
Garrett is amazing!
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
</ul>

## Accessing the Characters in a String
<ul>
  <li>Since strings are essentially character arrays, strings can be accessed using subscripting to access each element of the string</li>
  <li>Unlike with arrays previously in this course, character arrays, when passed to a function via an argument, do not need to include an additional argument that defines the size of the string. Instead, the program can test for the null character, '\0', which will determine that the end of the character array has been reached</li>
  <details>
    <summary>Example program</summary>

```cpp
#include <iostream>
using namespace std;
//What is the return value of f("cabd", "acad")?

//function prototype for f
int f(char *s, char *t)
{
    //variable declarations
    char *p1, *p2;
    
    //nested for loops
    for(p1 = s; *p1 != '\0'; p1++) {
        for(p2 = t; *p2 != '\0'; p2++)
            if (*p1 == *p2) break;
        if(*p2 == '\0') break;
    }
    
    return p1 – s;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
2
        </code>
      </pre>  
    </details>
  </ul>
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//What does the following read_lines function do, assuming that n is larger than the size of the input string?

int read_line(char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) == ' ');
    *str++ = ch;
    i++;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *str++ = ch;
            i++;
        }    
    }
    *str = '\0';
    return i;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
This function appends on to an existing string. It will first skip over all white spaces. Once a non-white space character is entered by the user, it will continue to store the remainder of characters to the string. Once the user enters a new-line character, the while loop terminates and the null character is appended to the end of the string. No spaces are added between the existing string and the new characters within the char array
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

void change(char *s) {
    while (*s) {
        *s = (*s == 'a') ? 'x' : *s;
        s++;
    }
}

int main() {
    char str[] = "banana";

    change(str);
    cout << str;

    return 0;
}
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
bxnxnx
        </code>
      </pre>  
    </details>
  </ul>
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Complete the function is_all_uppercase so that it checks if all letters in an input string str are uppercase letters. The string str is composed of letters only. It must return 1 if all letters in str are uppercase, and 0 otherwise

int is_all_uppercase(char str[]) {
    int flag = 1;

    return flag;
}  
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
int is_all_uppercase(char str[]) {
    int flag = 1;

    for (char *ptr = str; *ptr != '\0'; ptr++)
        if (*ptr >= 'a' && *ptr <= 'z')
            flag = 0;

    return flag;
}  
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write the function that shifts a message. The function expects message to point to a string containing the message to be shifted; shift represents the amount by which each letter in the message to be shifted. Lower-case letters remain lower-case when shifted, and upper-case remain upper-case

void shift(char *message, int shift) {
    
} 
```
<ul>  
  <details>
    <summary>Output</summary>

```c
void shift(char *message, int shift) {
    for (; shift >= 26;)
        shift -= 26;
        
    for (; *message != '\0'; message++) {
        if (*message >= 'a' && *message <= 'z') {
            *message += shift;
            if (*message > 'z')
                *message = 'a' + (*message - 'z' - 1);
        }        

        else if (*message >= 'A' && *message <= 'Z') {
            *message += shift;
            if (*message > 'Z')
                *message = 'A' + (*message - 'Z' - 1);
        }        
    }    
}
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Complete the following function that replaces every occurrence of a character x with another character y in a given string, without using the standard library function

void replace_char(char *, char, char) {
    
} 
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
using namespace std;

void replace_char(char *, char, char);

int main()
{
    char string[] = "Garrett";

    replace_char(string, 'r', 's');

    cout << string;

    return 0;
}

void replace_char(char *str, char x, char y) {
    for (char *ptr = str; *ptr != '\0'; ptr++)
        if (*ptr == x)
            *ptr = y;
}
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a function reverse_string that reverses a given string in place

void reverse(char *str) {

}
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
using namespace std;

void r(char *str) {
    int characters = 0;

    for (char *ptr = str; *ptr != '\0'; ptr++)
        characters++;

    for (char *ptr = str, *ptrE = str + characters - 1; ptr < ptrE; ptr++, ptrE--) {
        char temp = *ptr;
        *ptr = *ptrE;
        *ptrE = temp;
    }    
}

int main()
{
    char string[100] = "Garrett";

    r(string);

    cout << string;

    return 0;
}
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a function is_palindrome to check if a string is palindrome

int is_palindrome(const char *str) {

}
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int is_palindrome(char *str) {
    int strLength = strlen(str);
    int flag = 1;

    for (char *ptr = str, *ptrEnd = str + strLength - 1; ptr <= ptrEnd; ptr++, ptrEnd--)
        if (*ptr != *ptrEnd)
            flag = 0;

    return flag;        
}

int main()
{
    char string[100] = "GaGaG";
    int flag = is_palindrome(string);

    (flag == 1) ? (cout << string << " is a palindrome\n") : (cout << string << " is not a palindrome\n");

    return 0;
}
```
  </details>
  </ul>  
  </details> 
</ul>   

## Using the C String Library
<ul>
  <li>There is a C++ library with the header name <code><string.h></code> that is used for comparing and manipulating strings</li>
</ul>    

### The strcpy (String Copy) Function
<ul>
  <li>The strcpy function takes advantage of the fact that a string cannot be reassigned using the assignment operator. What the strcpy function does it that it redeclares a string by passing two string into the function where the contents of the second argument are assigned to the string variable passed in the first parameter</li>
  <li>Here is the syntax for strcpy:

```cpp
strcpy(str1, str2);
```
  </li>
  <details>
    <summary>Example program</summary>

```cpp
//Complete the program below so it calls the swap function and prints the words in the array w in alphabetical order

#include <iostream>
using namespace std;

void swap(char *a, char *b)
{
    char tmp[4];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

int main()
{
    char w[3][4] = {"dog", "rat", "cat"};


    for (int i = 0; i < 3; i++)
        cout << w[i] << endl;

    return 0;    
}
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <string.h>
using namespace std;

void swap(char *a, char *b)
{
    char tmp[4];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

int main()
{
    char w[3][4] = {"dog", "rat", "cat"};

    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++)
            if (strcmp(w[i], w[j]) > 0)
                swap(w[i], w[j]);

    for (int i = 0; i < 3; i++)
        cout << w[i] << endl;

    return 0;    
}
```
  </details>
  </ul>
  </details> 
</ul>    

### The strlen (String Length) Function
<ul>
  <li>The strlen function returns the length of a string, not including the null character(s) appended to the end of the string</li>
  <li>Here is the syntax for strlen:

```c
strlen(strVariable);
```
  </li>
  <details>
    <summary>Example program</summary>

```cpp
//Write a program that finds the length of the longest word in an array of strings such as the following: char w[5][20] = {"apple", "banana", "kiwi", "grape", "mango"};
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    //variable declarations and initialization
    char w[5][20] = {"apple", "banana", "kiwi", "grape", "mango"};
    int longest = strlen(w[4]);

    //for loop which iterates through the array of strings and compares the length of each string to the length of the longest string thus far
    for (int i = 0; i < 5; i++)
        if (strlen(w[i]) > longest)
            longest = strlen(w[i]);

    cout << "The longest word in the array is " << longest << " characters long" << endl;        
}
```
  </details>
  </ul>
  </details> 
</ul>    

### The strcat (String Concatenation) Function
<ul>
  <li>The strcat function appends one string onto another. The strcat function takes in two arguments: the first argument is the string that will have more characters appended to it and the second argument is the string that will be appended to the first string</li>
  <li>The strcat function modifies only the first argument that is passed to its function call. The second argument that is passed to strcat is not modified by the strcat function</li>
  <li>Here is the syntax for strcat:

```cpp
strcat(str1, str2);
```
  </li>
</ul>    

### The strcmp (String Comparison) Function
<ul>
  <li>The strcmp function compares two strings together and returns a value either less than, greater than, or equal to 0. This function compares to strings lexicographically, meaning it compares two strings based on the order in which the string's characters appear in the dictionary
    <ul>
      <li>The strcmp function returns a value of type integer
        <ul>
          <li>If the function returns zero, then both functions have the exact same string</li>
          <li>If the function returns a negative integer, then the first string has a lower ascii value at an index closer index zero. For instance, if strcmp("ab", "aa") where to be written, it would return a value less than one since the second string has a lower ascii value for its second character compared to the first string</li>
          <li>if the function returns a positive integer, then the second strings has a lower ascii value at an index closer to index zero</li>
        </ul>
      </li>
    </ul>        
  </li> 
  <li>Here is the syntax for strcmp:

```cpp
if (strcmp(str1, str2) == 0)
```
  </li>
  <details>
    <summary>Example program</summary>

```cpp
//What will be the value of string s2 after the following statements have been executed?
strcpy(s1, "Program");
strcpy(s2, "Design");
if strcmp(s1, s2) < 0
    strcat(s1, s2);
else
    strcat(s2, s1);
```
<ul>  
  <details>
    <summary>Output</summary>
      <pre>
        <code>
"DesignProgram"
        </code>
      </pre>  
    </details>
  </ul>  
  </details> 
</ul>    

## Arrays of Strings
<ul>
  <li>The way to create an array of strings is to use a two-dimensional array of characters</li>
  <li>Here is the syntax for creating an array of strings:

```cpp
char arrayName[][] = {"str1", "str2", "str3"};
```
  </li>
</ul>    

## Command Line arguments
<ul>
  <li>Programs written in C++ can accept command line arguments. To do so, the main function of the C++ file needs to contain these two arguments: int argc and char *argv[]</li>
  <li>Here is the syntax for this type of main function:

```cpp
int main(int argc, char *argv[])
{
    return 0;
} 
```
  <ul>
      <li>The first argument, argc, defines the total number of command line arguments given, including the name of the program itself</li>
      <li>The second argument, *argv[], is a string of pointers where each index of the pointer array stores a character array, a string, beginning with the name of the program itself</li>
    </ul>    
  </li>    
  <details>
    <summary>Example program</summary>

```cpp
//Write a program which will echo its command-line argument in reverse order. Running the program by typing, ./a.out today and tomorrow, should produce the following output: tomorrow and today
```
<ul>  
  <details>
    <summary>Output</summary>
      
```cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{
    char **ptrB = argv + 1, **ptrE = argv + argc - 1;

    for (; ptrB < ptrE; ++ptrB, --ptrE) {
        char temp[100];
        strcpy(temp, *ptrB);
        strcpy(*ptrB, *ptrE);
        strcpy(*ptrE, temp);
    }

    for (char **ptr = argv + 1; ptr < argv + argc; ++ptr)
        cout << *ptr << endl;

    return 0;
}
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a program where the user provides command line-arguments and the program will check if the user's arguments are palindromic. For instance, the command-line ./a.out 1 20 5 20 1 has palindromic arguments, but the command-line ./a.out 1 20 5 20 2 does not have palindromic arguments
```
<ul>  
  <details>
    <summary>Output</summary>  

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) 
{
    char **ptrB = argv + 1, **ptrE = argv + argc - 1;
    int palindrome = 1;

    for (; ptrB <= ptrE; ptrB++, ptrE--) 
        if (strcmp(*ptrB, *ptrE) != 0) 
            palindrome = 0;

    (palindrome) ? (cout << "Palindrome") : (cout << "Not Palindrome");        

    return 0;
}
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a program that takes a series of strings as command-line arguments, reverses each string, and concatenates them into a single string. The output should be printed as a single line. For example, if the command is ./program_name hello world, the output should be olleh dlrow.
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    char **ptr = argv + 1, final[argc], *finalPtr = final;
    
    for (; ptr < argv + argc; ptr++) {
        for (char *charPtr = *ptr + strlen(*ptr) - 1, *begin = *ptr; charPtr > begin; charPtr--, begin++) {
            char temp = *begin;
            *begin = *charPtr;
            *charPtr = temp;
        }    
        strcat(final, " ");
        strcat(final, *ptr);
    }    
    
    cout << final << endl;

    return 0;
}
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a program that removes all vowels (both uppercase and lowercase) from a given string. Use only pointer manipulation--no indexing with [] or standard library functions.
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) 
{
    char **ptr = argv + 1;

    for (; ptr < argv + argc; ptr++) 
        for (char *charPtr = *ptr; *charPtr != '\0'; charPtr++)
            if (*charPtr == 'a' || *charPtr == 'e' || *charPtr == 'i' || *charPtr == 'o' || *charPtr == 'u' || *charPtr == 'A' || *charPtr == 'E' || *charPtr == 'I' || *charPtr == 'O' || *charPtr == 'U') {
                for (char *copyPtr = charPtr; *copyPtr != '\0'; copyPtr++)
                    *copyPtr = *(copyPtr + 1);

                charPtr--;    
            }

    for (char **ptr = argv + 1; ptr < argv + argc; ptr++)
        cout << *ptr << endl;        

    return 0;
}     
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a function that extracts the file extension from a given file name. If no extension exists, store an empty string in extension. Complete the following function:

void extract_extension(char *filename, char *extension) {
  
}
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <string.h>
using namespace std;

void extract_extension(char *filename, char *extension) {
    char *tempPtr = extension;
    for (char *ptr = filename; *ptr != '\0'; ptr++)
        if (*ptr == '.')
            for (char *newPtr = ptr; *newPtr != '\0'; newPtr++)
                *tempPtr++ = *newPtr;
}

int main(int argc, char *argv[]) 
{
    char **ptr = argv + 1, extension[100] = {'\0'};

    extract_extension(*ptr, extension);    

    cout << extension << endl; 

    return 0;
}
```
  </details>
  </ul>  
  </details> 
  <details>
    <summary>Example program</summary>

```cpp
//Write a program that takes multiple strings as command-line arguments and counts the total number of vowels and consonants across all strings. Print the results to the console. The following function definition can be used to help

int count_vowels(char *str) {
  
}
```
<ul>  
  <details>
    <summary>Output</summary>

```cpp
#include <iostream>
#include <string.h>
using namespace std;

int count_vowels(char *str) {
    char *charPtr = str;
    int count = 0;

    for (; *charPtr != '\0'; charPtr++)
        if (*charPtr == 'a' || *charPtr == 'e' || *charPtr == 'i' || *charPtr == 'o' || *charPtr == 'u' || *charPtr == 'A' || *charPtr == 'E' || *charPtr == 'I' || *charPtr == 'O' || *charPtr == 'U')
            count++;

    return count;        
}

int main(int argc, char *argv[]) 
{
    char **ptr = argv + 1;
    int vowels = 0, consonants = 0;

    for (; ptr < argv + argc; ptr++) {
        vowels += count_vowels(*ptr);
        consonants += strlen(*ptr) - vowels;
    }    

    cout << "Vowels: " << vowels << "\nConsonants: " << consonants << endl;

    return 0;
}
```
  </details>
  </ul>  
  </details> 
</ul>    
