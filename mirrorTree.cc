#include <iostream>
#include "simplebTree.h"

btree* mirrorTree(btree* root)
{

  btree* temp;
  if ( root )
    {
      mirrorTree(root->left);
      mirrorTree(root->right);
      temp = root->left;
      root->left = root->right;
      root->right = temp;
    }
  return root;
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error Failed to create a new tree "<<std::endl;
  printTree(root);
  btree* root2 = mirrorTree(root);
  printTree(root2);
  deleteTree(root);
}
