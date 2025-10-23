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

Complexity is O(n) because one must search through the whole list to see if the key already exists

If a map is implemented with a list and one is determining time complexity, the following is needed:

<ul>
  <li>To insert a new key-value pair, one must check if the key already exists, since maps cannot have duplicates. That requires scanning through the entire list which is O(n)</li>
  <li>Then if the key exists, one would have to search through all the values associated with that key, which again is O(n)</li>
  <li>This makes the entire process O(n<sup>2</sup>)
</ul>

#### <code>find(key)</code>
Looks for a key and returns its value

Complexity is O(n) because one might need to check every element to find the key

#### <code>erase(key)</code>
Removes a key-value pair from the map

Complexity is O(n) because one must find the key first

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

### Hash Map
A <em>hash map</em> is a data structure that stores key-value pairs using their hash code to decide where to put them in an array

A hash function will generate an integer that corresponds to the key in which the value will be stored in the map

#### Method Complexity
<code>put(key, value)</code>: O(1)

<code>find(key)</code>: O(1)

<code>erase(key)</code>: O(1)

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