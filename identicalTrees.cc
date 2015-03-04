#include <iostream>
#include <stdbool.h>

#include "simplebTree.h"

bool areTreesIdentical(btree* root1, btree* root2)
{
  if ( !root1 && !root2 )
    return true;
  if ( !root1 || !root2 )
    return false;
  else return ( (root1->data == root2->data) && areTreesIdentical(root1->left, root2->left) && areTreesIdentical(root1->right,root2->right));
}


int main(int argc, char** argv)
{
  btree* root1 = createTree();
  btree* root2 = createTree();
  if ( !root1 || !root2)
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  std::cout<<"Are Trees Identical  "<<(areTreesIdentical(root1,root2)? "True" : "False")<<std::endl;
  std::cout<<"Are Trees Identical  "<<(areTreesIdentical(NULL,root2)? "True" : "False")<<std::endl;
  deleteTree(root1);
  deleteTree(root2);
}
