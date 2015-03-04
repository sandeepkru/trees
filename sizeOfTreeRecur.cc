//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Size of Tree is 7
#include <iostream>
#include "simplebTree.h"

int sizeOfTree(btree* root)
{
  if ( !root )
    return 0;
  else return ( sizeOfTree(root->left) + 1 + sizeOfTree(root->right) );
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<" Error! Failed to create tree "<<std::endl;

  std::cout<<"Size of the tree is : "<<sizeOfTree(root)<<std::endl;
  deleteTree(root);
}
