#include "HuffmanTree.hpp"
#include "HeapQueue.hpp"
#include <iostream>
#include <map>
#include <stack>
using namespace std;

//compress method definition which turns the input string into a binary string using Huffman encoding
string HuffmanTree::compress(const string input)
{
    //variable declarations
    map<char, int> frequency;
    HeapQueue<HuffmanNode *, HuffmanNode::Compare> priorityQ;
    string output;

    //for loop which iterates through the entire input stirng an increments the frequency of each character found
    for (int i = 0; i < input.size(); i++)
        frequency[input[i]]++;
    
    //for loop which iterates over the frequency map and creates a new Huffman node which will then be inserted into the priority queue
    for (auto it = frequency.begin(); it != frequency.end(); it++)
    {
        HuffmanNode *newNode = new HuffmanNode(it->first, it->second);
        priorityQ.insert(newNode);
    }

    //while loop needed to combind the Huffman nodes to build a Huffman tree
    while (priorityQ.size() > 1)
    {
        //pointing left to the minimum value of the queue, then removing that value
        HuffmanNode *left = priorityQ.min();
        priorityQ.removeMin();
        //pointing right to the minimum value of the queue, then removing that value
        HuffmanNode *right = priorityQ.min();
        priorityQ.removeMin();

        //creating a parent Huffman node
        HuffmanNode *parent = new HuffmanNode('\0', left->getFrequency() + right->getFrequency());

        //assigning left and parent to parent and left nodes
        parent->left = left;
        left->parent = parent;

        //assigning right and parent to parent and right nodes
        parent->right = right;
        right->parent = parent;

        //finally inserting the parent node to the priority queue
        priorityQ.insert(parent);
    }

    //creating map and assigning the root of the tree to the minimum value of the priority queue
    root = priorityQ.min();
    buildMap(root, "");

    for (auto it2 = input.begin(); it2 != input.end(); it2++)
        output += code[*it2];

    return output;
}

//serializeTree method which converts the Huffman tree into its string form
string HuffmanTree::serializeTree() const
{
    //variable declaration
    string serialized;

    //calling serializeTree function to serialize the serialized stirng
    serialize(root, serialized);
    
    return serialized;
}

//decompress method which transforms the Huffman tree into a serialized string. Then the method decodes the string in binary form back to the original string
string HuffmanTree::decompress(const string input, const string serialized)
{
    //variable declarations and initialization
    string output;
    int index = 0;

    //deserialize the root node and then create a pointer called current which points to the root
    root = this->deserialize(serialized, index);
    HuffmanNode *current = root;

    //for loop which iterates through the input string, the encoded bits
    for (int i = 0; i < input.size(); i++)
    {
        //checking if the current character is a 0
        if (input[i] == '0')
            current = current->left;
        //checking if the current character is a 1
        else if (input[i] == '1')
            current = current->right;
        
        //if a leaf node is currently being pointed to, output its character value
        if (current->isLeaf())
        {
            output += current->getCharacter();
            current = root;
        }
    }

    return output;

}

//buildMap method which builds the map based on each character of the input string passed as a parameter
void HuffmanTree::buildMap(HuffmanNode *node, string output)
{
    //if the current node points to nothing, exit the function
    if (node == nullptr)
        return;
    
    //if the current node is a leaf, assign the code
    if (node->isLeaf())
        code[node->getCharacter()] = output;
    //otherwise, traverse left and add 0 to the output or traverse right and add 1 to the output
    else
    {
        buildMap(node->left, output + "0");
        buildMap(node->right, output + "1");
    }
}

//destroy method which clears the Huffman tree from memory
void HuffmanTree::destroy(HuffmanNode *node)
{
    //if the current node is pointing to nothing, exit from the function
    if (node == nullptr)
        return;
    
    //destroy the current node's left child
    destroy(node->left);
    //destroy the current node's right child
    destroy(node->right);
    
    //free the current node from memory
    delete node;
}

//HuffmanTree destructor needed to free the Huffman tree from memory
HuffmanTree::~HuffmanTree()
{
    //call the destroy method to remove each node from the tree
    destroy(root);

    //have the root of the tree point to nothing to avoid dangling pointer
    root = nullptr;
}

//serialize method to turn the contents of the Huffman tree into a singular string
void HuffmanTree::serialize(HuffmanNode *node, string &output) const
{
    //if the current node points to nothing, exit the function
    if (node == nullptr)
        return;
    
    //visit the tree in postorder form using recursion
    this->serialize(node->left, output);
    this->serialize(node->right, output);
    
    //if the current node is a leaf, append the character L to the output stirng along with the current node's character attribute
    if (node->isLeaf())
    {
        output += 'L';
        output += node->getCharacter();
    }

    //otherwise if the current node is a branch, append the character B to the output string
    else if (node->isBranch())
        output += 'B';
}

//deserialize method for constructing a Huffman tree from the previously created serialized string
HuffmanNode *HuffmanTree::deserialize(const string &serialized, int &index)
{
    char token, ch;
    stack<HuffmanNode *> stk;

    for (int i = 0; i < (int)serialized.size();)
    {
        token = serialized[i++];

        //if the current character in the serialized string is L, indicating a leaf node, the next character is stored. The index is then advanced by two positions skipping L and the newly stored character
        if (token == 'L')
        {
            ch = serialized[i++];

            HuffmanNode *node = new HuffmanNode(ch, 0);
            stk.push(node);
        }

        //otherwise, if the current character in the serialized string is B, indicating a branch node
        else if (token == 'B')
        {
            if (stk.size() < 2) break;
            
            HuffmanNode *right = stk.top(); 
            stk.pop();
            HuffmanNode *left  = stk.top(); 
            stk.pop();

            //create the parent node with the two children pointer nodes from above
            HuffmanNode *parent = new HuffmanNode('\0', 0);
            parent->left = left;
            parent->right = right;

            left->parent = parent;
            right->parent = parent;

            stk.push(parent);
        }
    }

    index = serialized.size();  

    return stk.empty() ? nullptr : stk.top();
}