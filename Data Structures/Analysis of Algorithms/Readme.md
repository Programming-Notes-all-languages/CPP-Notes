<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#the-seven-functions'>The Seven Functions</a>
  </li> 
  <li>
    <a href='#queues'>Queues</a>
  </li> 
  <li>
    <a href='#deques'>Deques</a>
  </li> 
</ol>
</details>

## The Seven Functions
### The Constant Function
The algorithm takes the same amount of time no matter how big the input is

<div align="center">

O(1)
</div>

Algorithms with O(1) complexity are remarkably efficient since they perform a fixed number of operations. This makes them highly suitable for tasks where performance is crucial in real time systems

### The Logarithm Function
Each step of the algorithm reduces the problem size by half (or a fraction)

<div align="center">

O(log n)
</div>

### Linear Time
The algorithm looks at each element once, so the time grows linearly with input size

<div align="center">

O(n)
</div>

### Linearithmic Time
A mixture of linear and logarithmic. Usually comes from divide and conquer algorithms

<div align="center">

O(n log n)
</div>

### Quadratic Time
Common in nested loops where every element interacts with every other element

<div align="center">

O(n<sup>2</sup>)
</div>

### Cubic Time
Common in three nested loops

<div align="center">

O(n<sup>3</sup>)
</div>

### Exponential Time
Time doubles (or more) with each additional input element. Often seen in recursive brute-force solutions

<div align="center">

O(2<sup>n</sup>)
</div>

<details>
    <summary>Example program</summary>
Determine Big-O runtime

```cpp
int s = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i*i; j++) {
        s = s + A[j];
    }
}
```

<ul>  
  <details>
    <summary>Output</summary>

$n$ = 3:<br />
i = 1 and inner runs 1<br />
i = 2 and inner runs 4<br />
i = 3 and inner runs 9<br />

1<sup>2</sup> + 2<sup>2</sup> + 3<sup>2</sup> + n<sup>2</sup> = 1/6[n(n + 1)(2n + 1)]<br />

O($n$) = $n$<sup>3</sup>
  </details>
  </ul>  
</details> 

<details>
    <summary>Example program</summary>

Find $n$<sub>0</sub> such that A is better than B for all $n$ $\leq$ $n$<sub>0</sub><br />

Algorithm A: 5 $n$ log<sub>2</sub> $n$<br />
Algorithm B: $n$ <sup>2</sup>

<ul>  
  <details>
    <summary>Output</summary>

5 $n$ log<sub>2</sub> $n$ $\leq$ $n$<sup>2</sup><br />
5 log<sub>2</sub> $n$ $\leq$ $n$<br />

Test: $n$ = 32<br />
25 $\leq$ 32 is true, $\therefore$ $n$<sub>0</sub> = 32

  </details>
  </ul>  
</details> 

<details>
    <summary>Example program</summary>

Determine for which $n$ algorithm B is better

Algorithm A: 2 $n$<sup>2</sup> + 3 $n$<br />
Algorithm B: 50 $n$

<ul>  
  <details>
    <summary>Output</summary>

2 $n$<sup>2</sup> + 3 $n$ $\geq$ 50 $n$<br />
2 $n$ + 3 $\geq$ 50<br />
2 $n$ $\geq$ 47<br />
$n$ $\geq$ 23.5

Algorithm B is better for the following $n$: $n$ $\geq$ 24

  </details>
  </ul>  
</details> 

<details>
    <summary>Example program</summary>

Determine Big-O runtime

```cpp
template <typename T>
int count(Node<T> *head) {
    if (head != nullptr)
        return 0;
    
    return 1 + count(head->next);
}
```

<ul>  
  <details>
    <summary>Output</summary>

O($n$) because the recursive function runs $n$ times throughout the entire list6
  </details>
  </ul>  
</details> 