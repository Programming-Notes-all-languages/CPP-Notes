<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#general-trees'>General Trees</a>
  </li> 
  <li>
    <a href='#binary-trees'>Binary Trees</a>
  </li> 
  <li>
    <a href='#priority-queues'>Priority Queues</a>
  </li> 
  <li>
    <a href='heaps'>Heaps</a>
  </li>
  <li>
    <a href='binary-search-trees'>Binary Search Trees</a>
  </li>
  <li>
    <a href='avl-trees'>AVL Trees</a>
  </li>
</ol>
</details>

## General Trees
The <em>tree data structure</em> is used to represent data in the form of parent and child relationship

The top most node of the tree is called the root and the nodes below the root are called the child nodes. Each node can have multiple child nodes where those nodes can have their own child nodes

Here is the representation of a node in a tree data structure:

```cpp
class Node
{
    public:
        int data;
        Node *child1;
        Node *child2;
        Node *child3;
        Node *childN;
}
```

<details>
    <summary>Example problem</summary>
Count the number of nodes in a tree
  <details>
    <summary>Solution</summary>

```cpp
int countNodes(Node *root) {
	if (root == nullptr)
		return 0;
	
	return 1 + countNodes(root->left) + countNodes(root->right);
}
```

Time complexity: O(n)

Space complexity: O(n)
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
Count the number of leaf nodes in a tree
  <details>
    <summary>Solution</summary>

```cpp
int countLeaves(Node *root) {
    if (root == nullptr)
        return 0;
    
    else if (root->left == nullptr && root->right == nullptr)
        return 1;
    
    return countLeaves(root->left) + countLeaves(root->right);
}
```

Time complexity: O(n)

Space complexity: O(n)
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
Count the number of non-leaf nodes in a tree
  <details>
    <summary>Solution</summary>

```cpp
int count(Node *root)
{
    if (root == nullptr)
        return 0;
    
    if (root->left == nullptr && root->right == nullptr)
        return 0;
    
    return 1 + count(root->left) + count(root->right);
}
```
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
Write a function to free a binary tree from memory
  <details>
    <summary>Solution</summary>

```cpp
void destroy(Node *root)
{
    if (root == nullptr)
        return;
    
    destroy(root->left);
    destroy(root->right);
    delete root;
}
```
</details> 
</ul>  
</details>

### Height and Depth
#### Height
The height measures the distance from a node to its deepest leaf

<details>
    <summary>Example problem</summary>
Write a function to compute the height of a binary tree
  <details>
    <summary>Solution</summary>

```cpp
int height(Node *root)
{
    int leftHeight, rightHeight;

    if (root == nullptr)
        return -1;
    
    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
```
</details> 
</ul>  
</details>

#### Depth
The depth measures the distance from the root of the tree to a node

<details>
    <summary>Example problem</summary>
Write a function to compute the sum of all the elements in a binary tree
  <details>
    <summary>Solution</summary>

```cpp
int sum(Node *root)
{
    if (root == nullptr)
        return 0;
    
    return root->data + sum(root->left) + sum(root->right);
}
```
</details> 
</ul>  
</details>

### Preorder
Preorder traversal starts at the root, then goes left to right. Visit the current node first, then recursively visit the left subtree, then the right subtree

               1
           /       \
         2           3
       /   \       /   \
      4     5     6     7
     /           / \
    8           9  10

So, the preorder traversal here is: 1, 2, 4, 8, 5, 3, 6, 9, 10, 7

#### C++ Implementation
```cpp
void preorder(Node *root)
{
    if (root == nullptr)
        return;
  
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```

### Inorder
Inorder traversal starts that the left, then goes to the root, then finally the right

               1
           /       \
         2           3
       /   \       /   \
      4     5     6     7
     /           / \
    8           9  10

So, the inorder traversal here is: 8, 4, 2, 5, 1, 9, 6, 10, 3, 7

#### C++ Implementation
```cpp
void preorder(Node *root)
{
    if (root == nullptr)
        return;
  
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}
```

### Postorder
Postorder traversal starts that the left, then goes to the right, then finally the root. Visit the children first, then visit the current node last

               1
           /       \
         2           3
       /   \       /   \
      4     5     6     7
     /           / \
    8           9  10

So, the postorder traversal here is: 8, 4, 5, 2, 9, 10, 6, 7, 3, 1

```cpp
void postorder(Node *root)
{
    if (root == nullptr)
        return;

    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}
```

<details>
    <summary>Example problem</summary>
Given the following tree, find the preorder, postorder, and inorder traversal, along with the depth of the node "Canada" and the height of the tree
<img src="Images/Problem 1.png" alt="Problem 1">
<ul>  
  <details>
    <summary>Solution</summary>

Preorder: Electronics R' Us, R&D, Sales, Domestic, International, Canada, S. America, Overseas, Africa, Europe, Asia, Australia, Purchasing, Manufacturing, TV, CD, Tuner<br />

Inorder: R&D, Electronics R' Us, Domestic, Sales, Canada, International, S. America, Africa, Overseas, Europe, Asia, Australia, Purchasing, TV, Manufacturing, CD, Tuner<br />

Postorder: R&D, Domestic, Canada, S. America, Africa, Europe, Asia, Australia, Overseas, International, Sales, Purchasing, TV, CD, Tuner, Manufacturing, Electronics R' Us

Depth of Canada: 3
Height: 4
</details> 
</ul>  
</details>

<details>
    <summary>Example problem</summary>
Draw a single binary tree T, such that:
<ul>
  <li>Each node of T stores a single character</li>
  <li>A preorder traversal of T yields EXAMFUN</li>
  <li>An inorder traversal of T yields MAFXUEN</li>
<ul>  
  <details>
    <summary>Solution</summary>

             E
            / \
           X   N
          / \
         A   U
        / \
       M   F
</details> 
</ul>  
</details>

## Binary Trees
Binary trees is a data structure where each node has at most two children: one child is referred to as the left child and the other as the right child

The topmost node is called the rood node and the nodes at the bottom of the tree that have no children are called the leaf nodes

To represent a binary tree in C++, one needs to declare a <code>class</code> Node that will consist of data and the pointers that point to the left and right children

```cpp
class Node
{
    public;
        int data;
        Node *left;
        Node *right;
}
```

To create a binary tree, the following can be done:

```cpp
Node *create(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;

    return newNode;
}
```

### Traversing a Binary Tree
```cpp
void traverseTree(Node *root)
{
    if (root == nullptr)
        return
    
    traverseTree(root->left);
    traverseTree(root->right);
}
```

<details>
    <summary>Example program</summary>
Draw an arithmetic expression tree that has four external nodes, storing the number 1,3,5, and 8 (with each number stored in a distinct external node, but not necessary in this order) and has three internal nodes, each storing an operator from the set {+, -, x, or /}, so that the value of the root is 20. The operators may return and act on fractions, and operator may be used more than once.
<ul>  
  <details>
    <summary>Solution</summary>

               +
           /       \
         *           -
       /   \       /   \
      8     3     5     1
</details> 
</ul>  
</details>

<details>
    <summary>Example program</summary>
Draw the binary tree representation of the following arithmetic expression: (((5 + 4) / (2 + 1)) * (((3 + 6) - 7) / (9 - 7)) * 8)
<ul>  
  <details>
    <summary>Solution</summary>

                 *
           /          \
         /              /
       /   \          /   \
      +     +        -     *
    /  \   / \      / \    | \
   5    4 2   1    +   7   8  -
                  / \        / \
                 3   6      9   7
</details> 
</ul>  
</details>

## Priority Queues
A priority queue is a special type of queue in which each elements has a priority associated with it, and elements with higher priority are served before those with lower priority, regardless of order in which they were inserted

Unlike a regular queue which is first-in-first-out, a priority queue dequeues elements based on priority, not position. Highest-priority elements are removed first

A priority queue can be implemented using an array or linked list, but a heap is the most common and most efficient data structure used to implement this ADT

<details>
    <summary>Example program</summary>
Show the output from the following sequence of priority queue ADT operations. The entries are key-element pairs, where sorting is based on the key value: insert(5, a), insert(4, b), insert(7, i), insert(1, d), removeMin(), insert(3, j), insert(6, c),
removeMin(), removeMin(), insert(8, g), removeMin(), insert(2,h), removeMin(),
removeMin()
<ul>  
  <details>
    <summary>Solution</summary>

(5, a)<br />
(4, b), (5, a)<br />
(4, b), (5, a), (7, i)<br />
(1, d), (4, b), (5, a), (7, i)<br />
(4, b), (5, a), (7, i)<br />
(3, j), (4, b), (5, a), (7, i)<br />
(3, j), (4, b), (5, a), (6, c), (7, i)<br />
(4, b), (5, a), (6, c), (7, i)<br />
(5, a), (6, c), (7, i)<br />
(5, a), (6, c), (7, i), (8, g)<br />
(6, c), (7, i), (8, g)<br />
(2, h), (6, c), (7, i), (8, g)<br />
(6, c), (7, i), (8, g)<br />
(7, i), (8, g)<br />
</details> 
</ul>  
</details>

<details>
    <summary>Example program</summary>
Show how to implement a stack ADT using only a priority queue and one additional member variable
<ul>  
  <details>
    <summary>Solution</summary>
So there can be a member simulating a count that starts at zero. With each push to the queue, the counter increments. Then you can pop the item with the highest count as this is the last item to be entered in the priority queue
</details> 
</ul>  
</details>

<details>
    <summary>Example program</summary>
Show how to implement a queue ADT using only a priority queue and one additional member variable
<ul>  
  <details>
    <summary>Solution</summary>
So there can be a member simulating a count that starts at zero. With each push to the queue, the counter increments. Then you can pop the item with the lowest count as this is the first item to be entered in the priority queue
</details> 
</ul>  
</details>

### List-Based Priority Queues
A list-based priority queues uses a linked list or a dynamic array to store items

Assume each element in a queue is a pair:

```cpp
struct Node {
    int data, priority;
    Node *next;
}
```

There are two common approaches to creating a priority queue using linked lists: using an unsorted list or using a sorted list

#### Unsorted List
Inserting a new element at the end of the queue is O(1), but dequeueing requires scanning the entire list for the highest-priority element, O(n)

#### Sorted List
A sorted list keeps the list sorted by priority at all times. Enqueueing must find the correct place, O(n). Dequeueing is O(1) as one needs to only remove the element at the front of the list, if the highest priority element is at the front of the list

## Heaps
There are two main types of heaps: max-heaps and min-heaps. The data structure to implement a binary heap is an array

Space complexity is O(n)

### Max-Heaps
<em>Max-heaps</em> are where every parent node is larger than, or equal to, its children. The root is the maximum element

### Min-Heaps
<em>Min-heaps</em> are where every parent node is smaller than, or equal to, its children. The root is the minimum element

### Heap Declaration
```cpp
struct MinHeap {
    int array[MAX];
    int size;
};
```

### <code>parent(i)</code>
<code>int parent(int i) { return (i - 2) / 2; }</code>
This function takes in an integer <code>i</code>, which represents the index of a node in the heap's array representation, and returns the index of that node's parent

### <code>left(i)</code>
<code>int left(int i) { return 2 * i + 1; }</code>
This function takes in an integer <code>i</code>, which represents the index of a parent node in the heap's array representation, and returns the index of the parent's left child

### <code>right(i)</code>
<code>int right(int i) { return 2 * i + 2; }</code>
This function takes in an integer <code>i</code>, which represents the index of a parent node in the heap's array, and returns the index of its right child

### <code>swap(int *a, int *b)</code>
The purpose of this function is to swap two elements in the heap array

```cpp
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### Time Complexities
#### Peek
Returns the root element, O(1)

#### Enqueue (heapifyUp())
Adds a new value to the heap and heapifies up until the heap property is restored, O(log n)

To insert into the max-heap:
<ol>
  <li>Put the new node in the last index of the array, which means the rightmost child node in the tree</li>
  <li>Repeatedly swap that node with its parents until the parent is smaller</li>
</ol>

<details>
    <summary>Example program</summary>
Given the following array, [2, 4, 6, 8, 10, 12, 14, 16], enqueue 3 into the min-heap
<ul>  
  <details>
    <summary>Solution</summary>
<pre><code>
         2
       /   \
      4     6
     / \   / \
    8  10 12 14
   / \
  16  3
</code></pre>
First swap:
<pre><code>
         2
       /   \
      4     6
     / \   / \
    3  10 12 14
   / \
  16  8
</code></pre>
Final swap:
<pre><code>
         2
       /   \
      3     6
     / \   / \
    4  10 12 14
   / \
 16   8
</code></pre>
</details> 
</ul>  
</details>

#### Dequeue (heapifyDown())
Removes and returns the root element, then moves the last element to the root and heapifies down, O(log n)

To remove from a max-heap:
<ol>
  <li>Remove the maximum element, the root</li>
  <li>Replace root with last element in heap</li>
  <li>Remove the last element so that the heap size decreases by one</li>
  <li>Heapify from the root. Swap repeatedly the new root with its largest child</li>
</ol> 

<details>
    <summary>Example program</summary>
Given the following array, [2, 3, 6, 4, 10, 12, 14, 16, 8], dequeue 2 from the min-heap
<ul>  
  <details>
    <summary>Solution</summary>
<pre><code>
         2
       /   \
      3     6
     / \   / \
    4  10 12 14
   / \
 16   8
</code></pre>
Remove root and replace with last element in heap:
<pre><code>
         8
       /   \
      3     6
     / \   / \
    4  10 12 14
   /
  16
</code></pre>
Swap:
<pre><code>
         3
       /   \
      8     6
     / \   / \
    4  10 12 14
   /
  16
</code></pre>
Final swap:

         3
       /   \
      4     6
     / \   / \
    8  10 12 14
   /
  16
</code></pre>
</details> 
</ul>  
</details>

<details>
    <summary>Example program</summary>
Given the following array, [1, 3, 2, 6, 7, 8, 9, 10, 14, 16], dequeue 1 from the min-heap
<ul>  
  <details>
    <summary>Solution</summary>
<pre><code>
          1
        /   \
       3     2
      / \   / \
     6  7  8  9
    / \  /
   10 14 16
</code></pre>
Remove root and replace with last element in heap:
<pre><code>
          16
        /   \
       3     2
      / \   / \
     6  7  8  9
    / \ 
   10 14
</code></pre>
Swap:
 <pre><code>
          2
        /   \
       3     16
      / \   / \
     6  7  8  9
    / \ 
   10 14
</code></pre>
Final swap:
<pre><code>
          2
        /   \
       3     8
      / \   / \
     6  7  16  9
    / \ 
   10 14
</code></pre>
</details> 
</ul>  
</details>

### Search
Finds a specific value anywhere in the heap, O(n)

### Delete
Removes an element from inside the heap, O(n)

## Binary Search Trees
A <em>binary search tree</em> is a type of binary tree with the following properties:

For every node <code>N</code>:
<ul>
  <li>All values in the left subtree of <code>N</code> are less than <code>N->data</code></li>
  <li>All values in the right subtree of <code>N</code> are greater than <code>N->data</code>
</ul>

This property allows efficient searching, insertion, and deletion operations

### Basic Structure
```cpp
struct Node {
    int data;
    Node *left, *right;
};
```

### Number of Different Binary Search Trees given a Key
The number of possible binary search trees that can be formed with n distinct keys is given in the n-th Catalan number:

<div align="center">

$C = (2n)! / ((n + 1)! * n!)$
</div>

<details>
    <summary>Example program</summary>
How mand different binary search trees can store the keys: {1, 2, 3}?
<ul>  
  <details>
    <summary>Solution</summary>

$C = (2 * 3)! / ((3 + 1)! * 3!)$

$C = 6! / (4! * 3!)$

$C = 6 * 5 * 4! / (4! * 3!)$

$C = 30 / (3 * 2 * 1)$

$C = 5$
</details> 
</ul>  
</details>

### Operations

<details>
    <summary>Example problem</summary>
Write a function to find the minimum value in a binary search tree
  <details>
    <summary>Solution</summary>

```cpp
int findMin(Node *root) {
	  if (root == nullptr)
		    return 0;
		
	  if (root->left == nullptr)
		    return root->data;
	
	    return findMin(root->left);
}
```
</details> 
</ul>  
</details>

#### Searching a Binary Tree
```cpp
Node *search(Node *root, int key)
{
    if (root == nullptr || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
```

Average time complexity: O(log n)

Worst-case: O(n)

<details>
    <summary>Example problem</summary>
Write a function that returns a boolean value indicating if a node in the tree is found
  <details>
    <summary>Solution</summary>

```cpp
bool search(Node *root, int key) {
	  if (root == nullptr)
	    	return false;
	
	  if (key < root->data)
	    	return search(root->left, key);
	  else if (key > root->data)
	    	return search(root->right, key);
	
	  return true;
}
```
</details> 
</ul>  
</details>

#### Insertion
```cpp
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        Node *newNode = new Node{val, nullptr, nullptr};
        return newNode;
    }

    if (val < root ->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}
```

Average time complexity: O(log n)

Worst: O(n)

#### Deletion
```cpp
Node *delete(Node *root, int key)
{
  if (root == nullptr)
      return root;
  if (key < root->data)
      root->left = delete(root->left, key);
  else if (key > root ->data)
      root->right = delete(root->right, key);
  else 
  {
        
      if (!root->left) {
          Node* temp = root->right;
          delete root;
          return temp;
      }

      else if (!root->right) {
          Node* temp = root->left;
          delete root;
          return temp;
      }

      Node* temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

Node* findMin(Node* root) 
{
    while (root && root->left)
        root = root->left;

    return root;
}
```

Average time complexity: O(log n)

Worst: O(n)

#### Traversal
Traversing a binary search tree can be done using preorder traversal, inorder traversal, and postorder traversal

Time complexity is O(n)

## AVL Trees
An <em>AVL</em> is a self-balancing binary search tree. It maintains the BST property and ensures that for every node in the tree, the height difference between its left and right subtrees is at most 1

### Why Balance Matters
In a normal binary search tree, the worst case for search time is O(n) time complexity. In an AVL tree, the tree stays balance and all operations are O(log n), except for traversal. Space complexity is O(n)

### Node Structure
```cpp
struct Node
{
    int data, height;
    Node *left, *right;
}
```