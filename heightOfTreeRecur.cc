//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Height of the threet is 3

#include <iostream>
#include "simplebTree.h"

int heightOfTree(btree* root)
{
  if ( ! root )
    return 0;
  else
    {
      int lh = heightOfTree(root->left);
      int rh = heightOfTree(root->right);
      if ( lh > rh )
	return (lh+1);
      else
	return (rh+1);
    }
}
int main(int argc, char** argv)
{
  btree* root = createTree();
  if (!root){
    std::cout<<"Error! Failed to create tree"<<std::endl;
    exit(10);
  }
  std::cout<<"Height of the Tree is : "<<heightOfTree(root)<<std::endl;
  deleteTree(root);
}
