#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.hpp"
#include <iostream>
using namespace std;

class HuffmanTree : public HuffmanTreeBase
{
    HuffmanNode *root;
    map<char, string> code;

    public:
        HuffmanTree ()
            : root(nullptr) {}
        string compress(string input) override;
        ~HuffmanTree();
};

void destroy(HuffmanNode *);

#endif