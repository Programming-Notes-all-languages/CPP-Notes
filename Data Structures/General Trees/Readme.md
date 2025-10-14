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

### Height and Depth
#### Height
The height measures the distance from a node to its deepest leaf

#### Depth
The depth measures the distance from the root of the tree to a node

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
    preorder(root-right);
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
    preorder(root-right);
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

So, the postorder traversal here is: 8, 4, 2, 5, 9, 10, 6, 7, 3, 1

```cpp
void postorder(Node *root)
{
    if (root == nullptr)
        return;

    preorder(root->left);
    preorder(root-right);

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

Unlike a regular queue which is first-in-first-out, a priority queue dequeues elements based on priority, not position

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

## Heaps
There are two main types of heaps: max-heaps and min-heaps

### Max-Heaps