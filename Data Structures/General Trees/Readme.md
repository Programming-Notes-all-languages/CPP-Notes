<details>
<summary>Table of Contents</summary>
<ol>
  <li>
    <a href='#general-trees'>General Trees</a>
  </li> 
  <li>
    <a href='#binary-trees'>Binary Trees</a>
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
