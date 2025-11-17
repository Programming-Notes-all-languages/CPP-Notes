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
  <li>
    <a href='#graph-searching'>Graph Searching</a>
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

### Undirected Graphs
Edges go both ways where the connection between A-B is the same as the connection between B-A

### Directed Graphs
Edges have a direction where the connection between A-B is not the same as the connection between B-A

### Cycles
A <em>cycle</em> is when one starts at a vertex, follow edges, and eventually come back to the same vertex without repeating an edge

#### Simple Cycle
A <em>simple cycle</em> is a cycle with no repeated vertices except for the starting and ending vertex

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

## Graph Searching
### Subgraphs
A graph $S$ is a <em>subgraph</em> of $G$ if
<ul>
  <li>
  
  Vertices($S$) ⊆ Vertices($G$)</li>
  <li>
  
  Edges($S$) ⊆ Edges($G$)</li>
</ul>

#### Spanning Subgraph
A subgraph that contains all vertices of $G$ where edges may be fewer

### Connectivity
#### Connected Graph
A graph is <em>connected</em> if every pair of vertices has a path between them

A connected component of a graph $G$ is a <em>maximal</em> connected subgraph of $G$

### Trees and Forest
#### Trees
An undirected graph $T$ such that it is connected and acyclic

The number of vertices in a tree graph with n vertices has n - 1 edges 

#### Forests
Is a collection of disconnected trees. An undirected graph with no cycles and each connected component of a <em>forest</em> is a tree

### Spanning Trees and Spanning Forests
#### Spanning Trees
A spanning subgraph that is a tree:
<ul>
<li>Contains all vertices</li>
<li>Is connected</li>
<li>Has no cycles</li>
<li>n vertices --> n-1 edges</li>
</ul>

#### Spanning Forests
If the graph is not connected, a <em>spanning forest</em> contains one spanning tree per component

### Depth-First Search
A DFS traversal visits all vertices and edges; determines if $G$ is connected; computes connected components; computes a spanning forest.l It is not used for finding the shortest path

Explore as far as possible along each branch before backtracking using a stack

#### Time Complexity
O(V + E)

#### S-ace Complexity
O(V)

#### Breadth-First Search
Explore a graph level by level and finds the shortest path in edges between vertices in an unweighted graph using a queue

#### Time Complexity
O(V + E)

#### Space Complexity
O(V)

### Dijkstra's Algorithm
Finds the shortest weighted paths from a starting vertex to all other vertices

#### Time Complexities
| Data Structure for Priority Queue | Time Complexity      |
| --------------------------------- | -------------------- |
| Array                             | O(V²)                |
| Binary Heap                       | **O((V + E) log V)** |
| Fibonacci Heap                    | O(E + V log V)       |

#### Space Complexity
O(V)

### Prim's Algorithm
Starting from any vertex, add the minimum-weight edge from the tree to any new vertex. Continue adding the cheapest valid edge until all vertices are included

This is Dijkstra-like, but it uses a priority queue

<details>
    <summary>Example program</summary>
Given the following graph, perform Prim's algorithm

<pre>
  (2)
A ---- B
| \    |
|3 \5  | 1
|    \ |
C ---- D
   (4)
</pre>
<ul>  
  <details>
    <summary>Solution</summary>

Minimum spanning tree result:
<pre>
  (2)
A ---- B
|      |
|3     | 1
|      |
C      D
</pre>

Total weight: 1 + 2 + 3 = 6
</details> 
</ul>  
</details>

### Kruskal's Algorithm
Start with picking the edge that has the smallest weight and continue to sort all edges by weight, ascending. For each edge in sorted order: add it if it does not create a cycle and skip it if it would create a cycle. Continue until there are n - 1 edges

<details>
    <summary>Example program</summary>
Given the following graph, perform Prim's algorithm

<pre>
  (2)
A ---- B
| \    |
|3 \5  | 1
|    \ |
C ---- D
   (4)
</pre>
<ul>  
  <details>
    <summary>Solution</summary>

Minimum spanning tree result:
<pre>
  (2)
A ---- B
|      |
|3     | 1
|      |
C      D
   
</pre>

Total weight: 1 + 2 + 3 = 6
</details> 
</ul>  
</details>

### Prim's and Kruskal's Algorithm Comparisons
Both algorithms produce the same total weight minimum spanning tree; however, they do not always produce the same exact set of edges