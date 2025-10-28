<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#maps'>Maps</a>
  </li> 
  <li>
    <a href='#hashes'>Hashes</a>
  </li> 
</ol>
</details>

## Maps
A <em>map</em>, also known as a dictionary, is a data structure that stores key-value pairs like this:

<table border="1">
  <tr>
    <th>Key</th>
    <th>Value</th>
  </tr>
  <tr>
    <td>"apple"</td>
    <td>3</td>
  </tr>
  <tr>
    <td>"banana"</td>
    <td>5</td>
  </tr>
  <tr>
    <td>"orange"</td>
    <td>2</td>
  </tr>
</table>

The key is unique and if another <code>"apple"</code> is inserted, it replaces the old value. Maps are used whenever one needs fast lookup by key, not by index

### Methods
#### <code>put(key, value)</code>
Adds a key-value pair or updates an existing one

#### <code>find(key)</code>
Looks for a key and returns its value

#### <code>erase(key)</code>
Removes a key-value pair from the map

<details>
    <summary>Example problem</summary>
Given the following code snippet:

```cpp
int main() {
    map<int, string> m;
    m[5] = "apple";
    m[2] = "banana";
    m[8] = "cherry";
    m[2] = "grape";
    m[10] = "pear";

    for (auto p : m)
        cout << p.first << ": " << p.second << endl;
}
```

<ol type="a">
  <li>How many elements are in the map at the end?</li>
  <li>In what order will the keys print?</li>
  <li>What value is stored in key 2?</li>
  <li>What is the time complexity of each insertion?</li>
</ol>
  <details>
    <summary>Solution</summary>

<ol type ="a">
  <li>4</li>
  <li>"grape", "apple", "cherry", "pear"</li>
  <li>"grape"</li>
  <li>O(log n) if implemented with a AVL</li>
</ol>
</details> 
</ul>  
</details>

<table>
  <thead>
    <tr>
      <th>Implementation</th>
      <th>Insertion</th>
      <th>Search</th>
      <th>Deletion</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Linked List</td>
      <td>O(n)</td>
      <td>O(n)</td>
      <td>O(n)</td>
      <td>Linear scan; simple but slow</td>
    </tr>
    <tr>
      <td>Unbalanced BST</td>
      <td>O(h) (worst O(n))</td>
      <td>O(h) (worst O(n))</td>
      <td>O(h) (worst O(n))</td>
      <td>Performance depends on tree shape</td>
    </tr>
    <tr>
      <td>Balanced BST (e.g., Red-Black / AVL) — <code>std::map</code></td>
      <td>O(log n)</td>
      <td>O(log n)</td>
      <td>O(log n)</td>
      <td>Keys kept in sorted order</td>
    </tr>
    <tr>
       <td>Hash Table — <code>std::unordered_map</code></td>
      <td>O(1) average (worst O(n))</td>
      <td>O(1) average (worst O(n))</td>
      <td>O(1) average (worst O(n))</td>
      <td>No ordering; depends on good hashing/load factor</td>
    </tr>
  </tbody>
</table>


## Hashes
A <em>hash</em> is a number of code generated from data, that represents a key

For example, if one feeds a key, like <code>"apple"</code> into a hash function, and it outputs an integer, the hash code:

<table border="1">
  <tr>
    <th>Key</th>
    <th>Hash Code</th>
  </tr>
  <tr>
    <td>"apple"</td>
    <td>102</td>
  </tr>
  <tr>
    <td>"banana"</td>
    <td>305</td>
  </tr>
  <tr>
    <td>"orange"</td>
    <td>207</td>
  </tr>
</table>

A hash function always gives the same results for the same input

### Iterating through a Map using an Iterator
An iterator is like a pointer that lets one move through the elements of a container, such as a map or hash map, one bu one--without knowing how the container is implemented internally

<ul>
  <li>Moving forward through the map is done with <code>++it</code></li>
  <li>Accessing the key with <code>it->first</code> and value with <code>it->second</code>
  <li>Comparing with the another iterator <code>it == map.end()</code></li>
</ul>

```cpp
map<int, string> m;
m[5] = "five";
m[1] = "one";
m[3] = "three";

for (auto it = m.begin(); it != m.end(); ++it)
    cout << it->first << ": " << it->second << endl;

```

### Load Factor
The <em>load factor</em> measures how full a hash table is where

<div align="center">

$LF$ = number of elements / number of buckets
</div>

A higher load factor means the table is more crowded, which increases the chance of collisions

### Hash Map
A <em>hash map</em> is a data structure that stores key-value pairs using their hash code to decide where to put them in an array

A hash function will generate an integer that corresponds to the key in which the value will be stored in the map

#### Method Complexity
<code>put(key, value)</code>: O(1)

<code>find(key)</code>: O(1)

<code>traverse()</code>:O(n)

<code>erase(key)</code>: O(1)

For the worse case scenario, the four methods above have complexity of O(n) if collisions cause chains

<details>
    <summary>Example problem</summary>
Given a hash table of size 7, using linear probing for collision resolution

The function is: $h = k$ mod 7

Insert the following keys in order: 10, 17, 24, 6, 31

  <details>
    <summary>Solution</summary>

h(10) = 3<br />
h(17) = 3 -> 4<br />
h(24) = 3 -> 4 -> 5<br />
h(6) = 6<br />
h(31) = 3 -> 4 -> 5 -> 6 -> 0<br />

Answer: [31, x, x, 10, 17, 24, 6]
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
Given a hash table of size 5 using chaining for collision resolution

The hash function is: $h(k) = k$ mod 5

Insert the following keys in order: 12, 7, 22, 17, 32
  <details>
    <summary>Solution</summary>

h(12) = 2<br />
h(7) = 2<br />
h(22) = 2<br />
h(17) = 2<br />
h(32) = 2<br />

Answer: [x, x, 12->7->22->17->32, x, x]
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
Given a hash table of size 7 using chaining for quadratic probing

The hash function is: $h(k) = k$ mod 7

Insert the following keys in order: 10, 17, 24, 31
  <details>
    <summary>Solution</summary>

h(10) = 3<br />
h(17) = 3 -> (3 + 1^2) mod 7 = 4<br />
h(24) = 3 -> (3 + 1^2) mod 7 = 4 -> (3 + 2^2) mod 7 = 0<br />
h(31) = 3 -> (3 + 1^2) mod 7 = 4 -> (3 + 2^2) mod 7 = 0 -> (3 + 3^3) mod 7 = 5<br />

Answer: [24, x, x, 10, 17, 31, x]
</details> 
</ul>  
</details>


<details>
    <summary>Example problem</summary>
Given a hash table of size 7 using two hash functions:

$h1(k) = k$ mod 7<br />
$h2(k)$ 5 - ($k$ mod 5)

Insert the following keys in order: 50, 700, 76, 85, 92, 73, 101
  <details>
    <summary>Solution</summary>

index = $(h1(k) + i * h2(k))$ mod $m$, where $m$ is the size of the hash table

h1(50) = 1<br />
h1(700) = 0<br />
h1(76) = 6<br />
h1(85) = 1<br />
h2(85) = 5 - (85 mod 5) = 5<br />
index = (1 + 0 * 5) mod 7 = 1 -> (1 + 1 * 5) mod 7 = 6 -> (1 + 2 * 5) mod 7 = 4<br />
h1(92) = 1<br />
h2(92) = 5 - (92 mod 5) = 3<br />
index = (1 + 0 * 3) mod 7 = 1 -> (1 + 1 * 3) mod 7 = 4 -> (1 + 2 * 3) mod 7 = 0 -> (1 + 3 * 3) = 3<br />
h1(73) = 3<br />
h2(73) = 5 - (73 mod 5) = 2<br />
index = (3 + 0 * 2) mod 7 = 3 -> (3 + 1 * 2) mod 7 = 5<br />
h1(101) = 3<br />x
h2(101) = 5 - (101 mod 5) = 4<br />
index = (3 + 0 * 4) mod 7 = 3 -> (3 + 1 * 4) mod 7 = 0 -> (3 + 2 * 4) mod 7 = 4 -> (3 + 3 * 4) mod 7 = 1 -> (3 + 4 * 4) mod 7 = 5 -> (3 + 5 * 4) mod 7 = 2<br />

Answer: [700, 50, 101, 02, 85, 73, 76]
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
Draw the 11-entry hash table that results from using the hash function, h(k) = (3k + 3) mod 11, to hash keys: 12, 44, 13, 88, 23, 94, 11, 39, 5, 20, and 16

<ol type-"a">
  <li>Collisions are handled by chaining</li>
  <li>Collisions are handled by linear probing</li>
  <li>Collisions are handled by quadratic probing, up to the point where the method fails</li>
</ol>
  <details>
    <summary>Solution</summary>

| Key | 3k+3 | (3k+3) mod 11 | h(k) |
| --- | ---- | ------------- | ---- |
| 12  | 39   | 6             | 6    |
| 44  | 135  | 3             | 3    |
| 13  | 42   | 9             | 9    |
| 88  | 267  | 3             | 3    |
| 23  | 72   | 6             | 6    |
| 94  | 285  | 10            | 10   |
| 11  | 36   | 3             | 3    |
| 39  | 120  | 10            | 10   |
| 5   | 18   | 7             | 7    |
| 20  | 63   | 8             | 8    |
| 16  | 51   | 7             | 7    |

| Key | Hash |
| --- | ---- |
| 12  | 6    |
| 44  | 3    |
| 13  | 9    |
| 88  | 3    |
| 23  | 6    |
| 94  | 10   |
| 11  | 3    |
| 39  | 10   |
| 5   | 7    |
| 20  | 8    |
| 16  | 7    |

<ol type="a">
  <li>

| Index | Keys (chain) |
| ----- | ------------ |
| 0     |              |
| 1     |              |
| 2     |              |
| 3     | 44 → 88 → 11 |
| 4     |              |
| 5     |              |
| 6     | 12 → 23      |
| 7     | 5 → 16       |
| 8     | 20           |
| 9     | 13           |
| 10    | 94 → 39      |

  </li>
  <li>

| Step | Key | h(k) | Action                                                                      |
| ---- | --- | ---- | --------------------------------------------------------------------------- |
| 1    | 12  | 6    | Place at 6                                                                  |
| 2    | 44  | 3    | Place at 3                                                                  |
| 3    | 13  | 9    | Place at 9                                                                  |
| 4    | 88  | 3    | 3 is full → try 4 → empty → place at 4                                      |
| 5    | 23  | 6    | 6 full → try 7 → empty → place at 7                                         |
| 6    | 94  | 10   | Place at 10                                                                 |
| 7    | 11  | 3    | 3 full → 4 full → 5 empty → place at 5                                      |
| 8    | 39  | 10   | 10 full → 0 empty → place at 0                                              |
| 9    | 5   | 7    | 7 full → 8 empty → place at 8                                               |
| 10   | 20  | 8    | 8 full → 9 full → 10 full → 0 full → 1 empty → place at 1                   |
| 11   | 16  | 7    | 7 full → 8 full → 9 full → 10 full → 0 full → 1 full → 2 empty → place at 2 |

| Index | Key |
| ----- | --- |
| 0     | 39  |
| 1     | 20  |
| 2     | 16  |
| 3     | 44  |
| 4     | 88  |
| 5     | 11  |
| 6     | 12  |
| 7     | 23  |
| 8     | 5   |
| 9     | 13  |
| 10    | 94  |

</li>
<li>

| Step | Key | h(k) | Probe sequence                              | Final index                    |
| ---- | --- | ---- | ------------------------------------------- | ------------------------------ |
| 1    | 12  | 6    | 6                                           | 6                              |
| 2    | 44  | 3    | 3                                           | 3                              |
| 3    | 13  | 9    | 9                                           | 9                              |
| 4    | 88  | 3    | 3→4 (1²=1)                                  | 4                              |
| 5    | 23  | 6    | 6→7 (1²=1)                                  | 7                              |
| 6    | 94  | 10   | 10                                          | 10                             |
| 7    | 11  | 3    | 3→4→6 (1²=1, 2²=4, 3+4=7→7 full?) check → 8 | Wait, let’s compute carefully. |

3 full (44)

4 full (88)

(3 + 4) % 11 = 7 → 7 full (23)

(3 + 9) % 11 = 1 → empty → place at 1 |

| 8 | 39 | 10 | 10 full → (10+1)%11=0 → empty → 0 |

| 9 | 5 | 7 | 7 full → (7+1)%11=8 → empty → 8 |

| 10 | 20 | 8 | 8 full → (8+1)%11=9 full → (8+4)%11=1 full → (8+9)%11=6 full → (8+16)%11=2 empty → 2 |

| 11 | 16 | 7 | 7 full → (7+1)%11=8 full → (7+4)%11=0 full → (7+9)%11=5 empty → 5 |

| Index | Key |
| ----- | --- |
| 0     | 39  |
| 1     | 11  |
| 2     | 20  |
| 3     | 44  |
| 4     | 88  |
| 5     | 16  |
| 6     | 12  |
| 7     | 23  |
| 8     | 5   |
| 9     | 13  |
| 10    | 94  |

</li>
</ol>
</details> 
</ul>  
</details>

### Space Complexity
| Implementation                             | Explanation                                                           | Space Complexity                   | Notes                                   |
| ------------------------------------------ | --------------------------------------------------------------------- | ---------------------------------- | --------------------------------------- |
| **Hash Table (with chaining)**             | Uses an array of buckets; each bucket holds a linked list of entries. | **O(n)**                           | n = total key–value pairs.              |
| **Hash Table (open addressing / probing)** | Stores all entries directly in the array.                             | **O(n)**                           | Still linear in the number of elements. |
| **Auxiliary structures**                   | Temporary memory used for insert, search, etc.                        | **O(1)**                           | Operations are in-place.                |
| **Resizing / rehashing**                   | Table doubles in size when load factor is exceeded.                   | **O(2n)** → simplifies to **O(n)** | Temporary extra array during resize.    |
