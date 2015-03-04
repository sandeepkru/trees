#include <iostream>
#include <stdbool.h>
#include "simplebTree.h"

bool hasPathSum(btree* root, int sum)
{
  if ( !root ) return ( sum == 0 );
  else {
    int remainsum = sum - root->data;
    if ( (root->left && root->right) || (!root->left && !root->right) )
      return (hasPathSum(root->left,remainsum) || hasPathSum(root->right,remainsum));
    else if (root->left)
      return hasPathSum(root->left,remainsum);
    else
      return hasPathSum(root->right,remainsum);
  }
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree "<<std::endl;
  std::cout<<"Does tree has path sum of 20 : "<<(hasPathSum(root,20) ? "True" : "Flase")<<std::endl;
  std::cout<<"Does tree has path sum of 9  : "<<(hasPathSum(root,9)  ? "True" : "Flase")<<std::endl;
  std::cout<<"Does tree has path sum of 11 : "<<(hasPathSum(root,11) ? "True" : "Flase")<<std::endl;
  std::cout<<"Does tree has path sum of 7  : "<<(hasPathSum(root,7)  ? "True" : "Flase")<<std::endl;
  deleteTree(root);
}
