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

G

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
