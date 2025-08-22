<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#function-templates'>Function Templates</a>
  </li> 
  <li>
    <a href='#class-templates'>Class Templates</a>
  </li> 
</ol>
</details>

## Function Templates
C++ provides an automatic mechanism, called the <em>function templates</em>, to produce a generic function for an arbitrary type <code>T</code>.

Here is the syntax for creating a template function:

```cpp
template <typename T>
T functionName(T variableName)
    return variableName;
```

<details>
    <summary>Example program</summary>

Write a template function that swaps two variables

<ul>  
  <details>
    <summary>Output</summary>

```cpp
template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
```
    
</details>
  </ul>  
</details>  

## Class Templates
In addition to function templates, C++ allows classes to be templated. A class template is a blueprint for a class that works with any data type

Here is the syntax for creating a template class:

```cpp
template <typename T>
class ClassName
{
    private:
        T data;
    
    public:
        ClassName(T variable) : data(variable) {}
}
```