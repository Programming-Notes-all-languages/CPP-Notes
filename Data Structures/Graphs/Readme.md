<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#what-is-a-graph'>What is a Graph</a>
  </li> 
  <li>
    <a href='#adjacency-list'>Adjacency List</a>
  </li> 
  <li>
    <a href='#adjacency-matrix'>Adjacency Matrix</a>
  </li> 
  <li>
    <a href='#incidence-matrix'>Incidence Matrix</a>
  </li> 
</ol>
</details>

## What is a Graph
A <em>graph</em> is a collection of:
<ul>
  <li><em>Vertices</em> (known as nodes)</li>
  <li><em>Edges</em> which are the connections between the vertices</li>
</ul>

### Terminology
#### Endpoints
Every edge in a graph connects two vertices. Those two vertices are the endpoints of the edge

```css
A —— B
```

Here A and B are the endpoints of that edge

#### Incident
An edge is said to be incident to the vertices it connects

```css
A —— B —— C
```

Edges sharing a vertex are incident, hence vertex B has incident edges (A, B) and (B, C)

#### Adjacent
Two vertices are adjacent if there is an edge directly connecting them

```css
A —— B —— C
```

<ul>
  <li>A and B are adjacent</li>
  <li>B and C are adjacent</li>
  <li>A and C are not adjacent</li>
</ul>

#### Degree
The degree of a vertex equals the number of edges incident to it

#### Parallel Edges
Two or more edges that connect the same pair of vertices are parallel edges

#### Self Loop
A self loop is an edge that connects a vertex to itself

A single self loop adds two degrees to a vertex

### Undirected Graphs
Edges go both ways where the connection between A-B is the same as the connection between B-A

### Directed Graphs
Edges have a direction where the connection between A-B is not the same as the connection between B-A

## Adjacency List
One way to store the connections between vertices in a graph is by using an <em>adjacency list</em> which uses vectors of neighbors

Each vertex stores a list (or vector) of its neighbors. Let's say that the given edges exists: A-B, A-C, B-A, C-A

```css
A → B, C  
B → A  
C → A
```

Only the existing edges are stored so there is no wasted space

### Time Complexities
| **Operation**                   | **Time Complexity** | **Explanation**                                             |
| ------------------------------- | ------------------- | ----------------------------------------------------------- |
| **Add Vertex**                  | **O(1)**            | Just create a new entry (e.g., in a map or vector).         |
| **Add Edge (u, v)**             | **O(1)**            | Append v to u’s neighbor list (and u to v’s if undirected). |
| **Remove Edge (u, v)**          | **O(deg(u))**       | Must search u’s adjacency list to find v.                   |
| **Remove Vertex (u)**           | **O(E)**            | Must remove all edges incident to u from other vertices.    |
| **Check if Edge (u, v) Exists** | **O(deg(u))**       | Must search u’s list for v.                                 |
| **Iterate Over Neighbors of u** | **O(deg(u))**       | You simply walk through u’s neighbor list.                  |
| **Iterate Over All Vertices**   | **O(V)**            | One visit per vertex.                                       |
| **Iterate Over All Edges**      | **O(V + E)**        | Each edge visited once (twice if undirected).               |

## Adjacency Matrix
One way to store the connections between vertices in a graph is by using an <em>adjacency matrix</em> which uses a 2D array

It is a square 2D matrix of size V * V (where V is the number of vertices). Each cell <code>[i][j]</code> tells you if there is an edge between the vertex i and j

```css
   A  B  C
A [0, 1, 1]
B [1, 0, 0]
C [1, 0, 0]
```

This means that A-B and A-C exists, while B-C does not exist

### Time Complexities
| **Operation**                   | **Time Complexity** | **Explanation**                                      |
| ------------------------------- | ------------------- | ---------------------------------------------------- |
| **Add Vertex**                  | **O(V²)**           | You must create a new larger matrix (copy & resize). |
| **Add Edge (u, v)**             | **O(1)**            | Directly set `matrix[u][v] = 1`.                     |
| **Remove Edge (u, v)**          | **O(1)**            | Just set `matrix[u][v] = 0`.                         |
| **Remove Vertex (u)**           | **O(V²)**           | Requires removing row *u* and column *u*.            |
| **Check if Edge (u, v) Exists** | **O(1)**            | Lookup `matrix[u][v]` directly.                      |
| **Iterate Over Neighbors of u** | **O(V)**            | Must scan entire row *u*.                            |
| **Iterate Over All Vertices**   | **O(V)**            | One per vertex.                                      |
| **Iterate Over All Edges**      | **O(V²)**           | Must scan all cells in the matrix.                   |


## Incidence Matrix
One way to store the connections between vertices in a graph is by using an <em>incidence matrix</em> which uses a 2D array

Given the sample graph:

```css
A —— B
|    /
|   /
C——
```

Vertices: A, B, C<br />
Edges:
<ul>
  <li>e1 = (A, B)</li>
  <li>e2 = (A, C)</li>
  <li>e3 = (B, C)</li>
</ul>

```css
   e1 e2 e3
A [1, 1, 0]
B [1, 0, 1]
C [0, 1, 1]
```

### Space Complexities
<table border="1" cellpadding="6" cellspacing="0">
  <tr>
    <th>Operation / Property</th>
    <th>Adjacency List</th>
    <th>Adjacency Matrix</th>
    <th>Incidence Matrix</th>
  </tr>
  <tr>
    <td><b>Memory</b></td>
    <td>O(|V| + |E|)</td>
    <td>O(|V|²)</td>
    <td>O(|V| × |E|)</td>
  </tr>
  <tr>
    <td><b>Adding Vertex</b></td>
    <td>O(1)</td>
    <td>O(|V|²)</td>
    <td>O(|V| × |E|)</td>
  </tr>
  <tr>
    <td><b>Adding Edge</b></td>
    <td>O(1)</td>
    <td>O(1)</td>
    <td>O(|V| × |E|)</td>
  </tr>
  <tr>
    <td><b>Removing Vertex</b></td>
    <td>O(|E|)</td>
    <td>O(|V|²)</td>
    <td>O(|V| × |E|)</td>
  </tr>
  <tr>
    <td><b>Removing Edge</b></td>
    <td>O(|V|)</td>
    <td>O(1)</td>
    <td>O(|V| × |E|)</td>
  </tr>
  <tr>
    <td><b>V is adjacent to U</b></td>
    <td>O(|E|)</td>
    <td>O(1)</td>
    <td>O(|V|)</td>
  </tr>
  <tr>
    <td><b>Pros</b></td>
    <td>Constant time additions</td>
    <td>Constant lookup times, constant edge addition</td>
    <td>Ease of incidence calculations, interesting math qualities</td>
  </tr>
  <tr>
    <td><b>Cons</b></td>
    <td>Slow removal for list search times</td>
    <td>Slow to add/remove vertices for matrix resize/copy</td>
    <td>Slow add/remove vertices/edges for matrix resize/copy</td>
  </tr>
</table>

<details>
    <summary>Example problem</summary>
Of the three data structures (Adjacency List, Adjacency Matrix, and Incidence Matrix),
what would have the smallest memory footprint for a simple undirected graph with:

6 vertices and 4 edges50 vertices and 60 edges

  <details>
    <summary>Solution</summary>

Space Complexities:<br />
Adjacency list: O(V + E)<br />
Adjacency Matrix: O(V<sup>2</sup>)<br />
Incidence Matrix: O(V x E)<br />

Space Complexities:<br />
Adjacency list: 6 + 4 = 10 ✅<br />
Adjacency Matrix: 6<sup>2</sup> = 36<br />
Incidence Matrix: 6 * 4 = 24<br />
</details> 
</ul>  
</details>

### Maximum Number of Edges in a Graph
#### Undirected Graph
$E = V(V - 1) / 2$

#### Directed Graph
$E = V(V - 1)$

<details>
    <summary>Example problem</summary>
Can the worst-case memory footprint of an Adjacency Matrix be smaller than an Adjacency List

<ol type="a">
<li>For a simple undirected graph?</li>
<li>For a simple directed graph?</li>
</ol>

  <details>
    <summary>Solution</summary>

<ol type="a">
<li>

Matrix space: $O(V$<sup>2</sup>$)$<br />

List space: $O(V + E)$<br />

Maximum number of edges for undirected graph: $E = V(V - 1) / 2$<br />

$V$<sup>2</sup> $< V + E$<br />

$V$<sup>2</sup> $< V + V(V - 1) / 2$<br />

$V$<sup>2</sup> $< V + V$<sup>2</sup>$ / 2 - V / 2$<br />

$V$<sup>2</sup> $< V$<sup>2</sup>$ / 2 + V / 2$<br />

This is impossible so no the adjacency matrix is never smaller for an undirected graph
</li>
<li>

Matrix space: $O(V$<sup>2</sup>$)$<br />

List space: $O(V + E)$<br />

Maximum number of edges for directed graph: $E = V(V - 1)$<br />

$V$<sup>2</sup> $< V + E$<br />

$V$<sup>2</sup> $< V + V(V - 1)$<br />

$V$<sup>2</sup> $< V + V$<sup>2</sup>$ - V$<br />

$V$<sup>2</sup> $< V$<sup>2</sup><br />

This is impossible so no the adjacency matrix is never smaller for an directed graph graph
</li>
</ol>
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
A complete directed graph has every possible edge (including direction).
If it has n vertices, how many entries (cells) would exist in the adjacency matrix?

  <details>
    <summary>Solution</summary>

Maximum number of edges for directed graph: $E = n(n - 1)$<br />

There would be $n$ <sup>2</sup> edges
</details> 
</ul>  
</details>