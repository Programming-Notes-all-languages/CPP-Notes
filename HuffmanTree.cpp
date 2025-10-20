#include "HuffmanTree.hpp"
#include "HeapQueue.hpp"
#include <iostream>
#include <map>
using namespace std;

string HuffmanTree::compress(const string input)
{
    map<char, int> frequency;
    HeapQueue<HuffmanNode *, HuffmanNode::Compare> priorityQ;
    string output;

    for (int i = 0; i < input.size(); i++)
        frequency[input[i]]++;
    
    for (auto it = frequency.begin(); it != frequency.end(); it++)
    {
        HuffmanNode *newNode = new HuffmanNode(it->first, it->second);
        priorityQ.insert(newNode);
    }

    while (priorityQ.size() > 1)
    {
        HuffmanNode *left = priorityQ.min();
        priorityQ.removeMin();
        HuffmanNode *right = priorityQ.min();
        priorityQ.removeMin();

        HuffmanNode *parent = new HuffmanNode('\0', left->getFrequency() + right->getFrequency());

        parent->left = left;
        left->parent = parent;

        parent->right = right;
        right->parent = parent;

        priorityQ.insert(parent);
    }

    root = priorityQ.min();
    buildMap(root, "");

    for (auto it2 = input.begin(); it2 != input.end(); it2++)
        output += code[*it2];

    return output;
}

string HuffmanTree::serializeTree() const
{
    string serialized;

    serialize(root, serialized);
    
    return serialized;
}

string HuffmanTree::decompress(const string input, const string serialized)
{
    string output;
    int index = 0;

    root = this->deserialize(serialized, index);
    HuffmanNode *current = root;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '0')
            current = current->left;
        else if (input[i] == '1')
            current = current->right;
        
        if (current->isLeaf())
        {
            output += current->getCharacter();
            current = root;
        }
    }

    return output;

}

void HuffmanTree::buildMap(HuffmanNode *node, string output)
{
    if (node == nullptr)
        return;
    
    if (node->isLeaf())
        code[node->getCharacter()] = output;
    else
    {
        buildMap(node->left, output + "0");
        buildMap(node->right, output + "1");
    }
}

void HuffmanTree::destroy(HuffmanNode *node)
{
    if (node == nullptr)
        return;
    
    destroy(node->left);
    destroy(node->right);
    
    delete node;
}

HuffmanTree::~HuffmanTree()
{
    destroy(root);

    root = nullptr;
}

void HuffmanTree::serialize(HuffmanNode *node, string &output) const
{
    if (node == nullptr)
        return;
    
    this->serialize(node->left, output);
    this->serialize(node->right, output);
    
    if (node->isLeaf())
    {
        output += 'L';
        output += node->getCharacter();
    }

    else if (node->isBranch())
        output += 'B';
}

HuffmanNode *HuffmanTree::deserialize(const string &serialized, int &index)
{
    if (index >= serialized.size())
        return nullptr;

    if (serialized[index] == 'L')
    {
        HuffmanNode *node = new HuffmanNode(serialized[index + 1], 0);
        index += 2;
        return node;
    }

    else if (serialized[index] == 'B')
    {
        index++;
        
        HuffmanNode *right = this->deserialize(serialized, index);
        HuffmanNode *left = this->deserialize(serialized, index);

        HuffmanNode *parent = new HuffmanNode('\0', 0);
        parent->left = left;
        parent->right = right;

        return parent;
    }

    return nullptr;
}