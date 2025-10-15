#include "HuffmanTree.hpp"
#include "HeapQueue.hpp"
#include <iostream>
#include <map>
using namespace std;

void destroy(HuffmanNode *root)
{
    if (root == nullptr)
        return;

    destroy(root->left);
    destroy(root->right);

    delete root;
}

string HuffmanTree::compress(string input)
{
    map<char, int> frequency;
    auto it = frequency.begin();
    HeapQueue<char, int> *root = new HeapQueue<char, int>();

    for (int i = 0; i < input.size(); i++)
        frequency[input[i]]++;
    
    for (; it != frequency.end(); it++)
    {
        HuffmanNode *newNode = new HuffmanNode(it->first, it->second);
        root->insert(newNode);
    }
}

HuffmanTree::~HuffmanTree()
{
    destroy(root);

    root = nullptr;
}