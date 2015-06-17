//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Leaf Nodes = 4 (4,5,6,7)
#include <iostream>
#include <queue>

#include "simplebTree.h"

void countLeaves(btree* root, int& count)
{
  if ( !root )
  {
	  return;
  }
  if ( !root->left && !root->right )
	  ++count;
  countLeaves(root->left, count);
  countLeaves(root->right, count);
  return;
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Faied to create a new tree"<<std::endl;
  int count  = 0;
  countLeaves(root, count);
  std::cout<<"Number of Leaf nodes : "<< count << std::endl;
  deleteTree(root);
}

