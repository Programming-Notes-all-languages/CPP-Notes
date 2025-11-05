<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#the-seven-functions'>The Seven Functions</a>
  </li> 
  <li>
    <a href='#abstract-data-type-vs-data-structures'>Abstract Data Type vs Data Structures</a>
  </li> 
  <li>
    <a href='#quick-sort'>Quick Sort</a>
  </li> 
  <li>
    <a href='#merge-sort'>Merge Sort</a>
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

O($n$) because the recursive function runs $n$ times throughout the entire list
  </details>
  </ul>  
</details> 

## Abstract Data Type vs Data Structures
### Abstract Data Type
Is the logical model of a data collection and the operations that can be performed on the data. It defines the behavior of the operations. It also hides the implementation details using encapsulation

### Data Structure
Is the physical implementation of an ABT model in memory. It specifies how data is actually stored in memory which does not necessarily hide the details

## Quick Sort
<em>Quick sort</em> is done by partitioning an array around a pivot. A <em>pivot</em> is picked by selecting an element in the array

Always choosing the last element in a partition as the pivot results in poor performance O(n<sup>2</sup>) on arrays that are sorted and that contain identical elements. The problem is easily solved by choosing either a random index for the pivot or choosing the middle index of the partition 

Partition the elements so that:
<ul>
  <li>Elements smaller than the pivot are on the left</li>
  <li>Elements greater than the pivot are on the right</li>
</ul>

Then recursively quick wort the left and right sub arrays

Array: <code>[8,2,5,1,9,3]</code>
<ol>
  <li>Pick pivot = <code>3</code></li>
  <li>Partition: <code>[2,1], [3], [8,5,9]</code></li>
  <li>Sort each side recursively:
    <ul>
      <li><code>[2,1] -> [1,2]</code></li>
      <li><code>[8,5,9] -> [5,8,9]</code></li>
    </ul>
  </li>
  <li>Combine: <code>[1,2,3,5,8,9]</code></li>
</ol>

### Time and Space Complexities
| Case    | Time                    | Space    |
| ------- | ----------------------- | -------- |
| Best    | O(n log n)              | O(log n) |
| Average | O(n log n)              | O(log n) |
| Worst   | O(n²) (if pivot is bad) | O(log n) |

<details>
    <summary>Example program</summary>
Given the array <code>[6, 3, 8, 5, 2]
</code>, show the array after each merge step
<ul>  
  <details>
    <summary>Solution</summary>

<code>[6, 3, 8, 5, 2]</code>

Pivot: 8

<code>[6,3,5,2] [8]</code>

Pivot: 3

<code>[2] [3] [5, 6] [8]</code>

Pivot: 5

<code>[2] [3] [5] [6] [8]</code>

<code>[2,3,5,6,8]</code>
</details> 
</ul>  
</details>

## Merge Sort
<em>Merge sort</em> uses the divide and conquer strategy where the array is divided into halves until there are only single-element arrays. The conquer part is to sort those halves back together in sorted order

### Steps
<ol>
  <li>If the array has 1 or fewer elements, it is already sorted</li>
  <li>Split the array into two halves</li>
  <li>Recursively sort each half</li>
  <li>Merge to two sorted halves together</li>
</ol>

Array: <code>[5, 2, 9, 1, 6, 3]</code>

Divide:<code>
[5, 2, 9]   [1, 6, 3]<br />
[5] [2,9]   [1] [6,3]<br />
[5] [2] [9] [1] [6] [3]
</code>

Merge:<code>
[2,5,9]   [1,3,6]<br />
→ [1,2,3,5,6,9]
</code>

### Time and Space Complexities
| Case    | Time       | Space |
| ------- | ---------- | ----- |
| Best    | O(n log n) | O(n)  |
| Average | O(n log n) | O(n)  |
| Worst   | O(n log n) | O(n)  |

<details>
    <summary>Example program</summary>
Given the array <code>[7, 3, 9, 1, 6, 2]
</code>, show the array after each merge step
<ul>  
  <details>
    <summary>Solution</summary>

<code>[7, 3, 9, 1, 6, 2]</code>

<code>[7,3,9] [1,6,2]</code>

<code>[7,3] [9] [1,6] [2]</code>

<code>[7] [3] [9] [1] [6] [2]</code>

<code>[3,7] [9] [1] [6] [2]</code>

<code>[3,7,9] [1] [6] [2]</code>

<code>[3,7,9] [1,6] [2]</code>

<code>[3,7,9] [1,2,6]</code>

<code>[1,2,3,6,7,9]</code>
</details> 
</ul>  
</details>

<details>
    <summary>Example program</summary>
Given the array <code>[8,4,2,9,5]</code>, show the array after each merge step
<ul>  
  <details>
    <summary>Solution</summary>

<code>[8,4,2,9,5]</code>

<code>[8,4,2] [9,5]</code>

<code>[8,4] [2] [9] [5]</code>

<code>[8] [4] [2] [9] [5]</code>

Compare 8 and 4. 4 is smaller so it goes first. Then append the greater element, 8, to the end of the array

<code>[4, 8] [2] [9] [5]</code>

Compare [4, 8] and [2]. Now we compare the first elements of each. Compare 4 vs 2 and 2 is smaller. Right now the list is empty so copy [4, 8] into the array

<code>[2, 4, 8] [9, 5]</code>

Compare [9] and [5]

<code>[2, 4, 8] [5, 9]</code>

<code>[2, 4, 5, 8, 9]</code>
</details> 
</ul>  
</details>

| **Basis for Comparison**                   | **Quick Sort**                                                                             | **Merge Sort**                                                    |
| ------------------------------------------ | ------------------------------------------------------------------------------------------ | ----------------------------------------------------------------- |
| **The partition of elements in the array** | The splitting (partitioning) of elements is in **any ratio**, not necessarily into halves. | The array is always **divided into two equal halves** (n/2 each). |
| **Additional storage space requirement**   | **Less** (In-place)                                                                        | **More** (Not In-place)                                           |
| **Efficiency**                             | **Inefficient for very large arrays** due to poor worst-case performance (O(n²)).          | **More efficient for large datasets**, guaranteed O(n log n).     |
| **Sorting method**                         | **Internal sorting** (works entirely in main memory).                                      | **External sorting** (preferred when data doesn’t fit in memory). |
| **Stability**                              | **Not stable** — equal elements may change order.                                          | **Stable** — equal elements retain their original order.          |
| **Preferred for**                          | **Arrays** (in-memory data).                                                               | **Linked Lists** (easy to split and merge).                       |
| **Locality of reference**                  | **Good** (better cache performance).                                                       | **Poor** (frequent memory accesses across arrays).                |
