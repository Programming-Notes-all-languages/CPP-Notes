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