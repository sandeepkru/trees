#include <iostream>
#include "simplebTree.h"

int findMax(btree* root)
{
  int root_val,left,right,maxVal=INT_MIN;
  if ( root != NULL)
    {
      root_val = root->data;
      left  = findMax(root->left);
      right = findMax(root->right);
      if ( left > right )
	maxVal = left;
      else
	maxVal = right;
      if ( root_val > maxVal )
	maxVal = root_val;
    }
  return maxVal;
}

int main(int argc, char** argv)
{
  btree* root = createTree();

  if ( !root )
    std::cout<<"Error! Failed to create tree"<<std::endl;

  std::cout<<"Maximum Element in tree : " <<findMax(root)<<std::endl;
  
  deleteTree(root);
}
