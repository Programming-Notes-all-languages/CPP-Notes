#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.hpp"
#include <iostream>
#include <map>
using namespace std;

//child class of HuffmanTree inherited from the abstract HuffmanTreeBase class
class HuffmanTree : public HuffmanTreeBase
{
    //private member attributes regarding the root of the tree and the map
    HuffmanNode *root;
    map<char, string> code;

    public:
        //HuffmanTree default constructor
        HuffmanTree ()
            : root(nullptr) {}
        //compress method definition which turns the input string into a binary string using Huffman encoding
        string compress(string) override;
        //serializeTree method which converts the Huffman tree into its string form
        string serializeTree() const override;
        //decompress method which transforms the Huffman tree into a serialized string. Then the method decodes the string in binary form back to the original string
        string decompress(const string, const string) override; 
        //serialize method to turn the contents of the Huffman tree into a singular string
        void serialize(HuffmanNode *, string &) const;
        //deserialize method for constructing a Huffman tree from the previously created serialized string
        HuffmanNode *deserialize(const string &, int &);
        //buildMap method which builds the map based on each character of the input string passed as a parameter
        void buildMap(HuffmanNode *, string);
        //helper method for freeing the Huffman tree from memory
        void destroy(HuffmanNode *);
        //HuffmanTree destructor for freeing the tree from memory
        ~HuffmanTree();
};

#endif