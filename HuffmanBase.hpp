#ifndef HUFFMANBASE_H
#define HUFFMANBASE_H

#include <cstddef>
#include <string>
#include <iostream>

//HuffmanNode class which is a node in the tree
class HuffmanNode {
public:
  //constructor initializing instance
  HuffmanNode(char c, size_t f, HuffmanNode *p, HuffmanNode *l, HuffmanNode *r) : character(c), frequency(f), parent(p), left(l), right(r) {};
  //constructor initializing instance
  HuffmanNode(char c, size_t f) : HuffmanNode(c, f, nullptr, nullptr, nullptr) {};

  //getter which returns the character stored in the current node
  char getCharacter() const;
  //getter which returns the frequency stored in the current node
  size_t getFrequency() const;

  //method which determines if the current node is a leaf
  bool isLeaf() const;
  //method which determines if the current node is a branch
  bool isBranch() const;
  //method which determines if the current node is a root
  bool isRoot() const;

  //Compare class definition
  class Compare {
  public:
    //constructor initializing Compare
    Compare(bool lessThan = true) : lessThan(lessThan) {};
    //boolean method which compares two HuffmanNodes by their frequency 
    bool operator()(const HuffmanNode &n1, const HuffmanNode &n2) const;
    bool operator()(const HuffmanNode *n1, const HuffmanNode *n2) const;
  private:
    bool lessThan;
  };

private:
  //public attributes for the map indicating its value and key
  char character;
  size_t frequency;

public: 
  //public attributes the tree node indicating that a node can either be a parent, left, or a right node
  HuffmanNode *parent;
  HuffmanNode *left;
  HuffmanNode *right;
};

class HuffmanTreeBase {
  public:
  //compress method definition which turns the input string into a binary string using Huffman encoding
  virtual std::string compress(const std::string inputStr) = 0;
  //serializeTree method which converts the Huffman tree into its string form
  virtual std::string serializeTree() const = 0;
  //decompress method which transforms the Huffman tree into a serialized string. Then the method decodes the string in binary form back to the original string
  virtual std::string decompress(const std::string inputCode, const std::string serializedTree) = 0;
};

#endif /* HUFFMANBASE_H */