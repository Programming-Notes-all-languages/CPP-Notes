#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.hpp"
#include <iostream>
#include <map>
using namespace std;

class HuffmanTree : public HuffmanTreeBase
{
    HuffmanNode *root;
    map<char, string> code;

    public:
        HuffmanTree ()
            : root(nullptr) {}
        string compress(string) override;
        string serializeTree() const override;
        string decompress(const string, const string) override; 
        void serialize(HuffmanNode *, string &) const;
        HuffmanNode *deserialize(const string &, int &);
        void buildMap(HuffmanNode *, string);
        void destroy(HuffmanNode *);
        ~HuffmanTree();
};

#endif