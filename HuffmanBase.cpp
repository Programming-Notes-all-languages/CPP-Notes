#include "HuffmanBase.hpp"

//getting the character value that is stored in the current node
char HuffmanNode::getCharacter() const
{
  return character;
}

//getting the frequency of the current map item
size_t HuffmanNode::getFrequency() const
{
  return frequency;
}

//boolean method returning a value depending on if the current node in the tree is a leaf
bool HuffmanNode::isLeaf() const
{
  return (left == nullptr && right == nullptr);
}

//boolean method returning a value depending on if the current node in the tree is a branch
bool HuffmanNode::isBranch() const
{
  return (left != nullptr || right != nullptr);
};

//boolean method returning a value depending on if the current node in the tree is a root
bool HuffmanNode::isRoot() const
{
  return (parent == nullptr);
};

//boolean method which compares two HuffmanNodes by their frequency 
bool HuffmanNode::Compare::operator()(const HuffmanNode &n1, const HuffmanNode &n2) const
{
  if (n1.frequency == n2.frequency) {
    return lessThan ? n1.character < n2.character : n1.character >= n2.character;
  } else {
    return lessThan ? n1.frequency < n2.frequency : n1.frequency >= n2.frequency;
  }
  
}


//boolean method which compares two HuffmanNodes by their frequency
bool HuffmanNode::Compare::operator()(const HuffmanNode *n1, const HuffmanNode *n2) const
{
  return operator()(*n1, *n2);
}