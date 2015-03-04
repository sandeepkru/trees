//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// True if element is found, False if it is not
#include <iostream>
#include <stdbool.h>
#include "simplebTree.h"

bool findElement(btree* root,int data)
{
  if ( !root )
    return false;
  // if ( data == root->data )
  //   return true;
  else
    return ( ( data == root->data ) || findElement(root->left,data) || findElement(root->right,data) );
  //  return false;
}


int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<" Error! Failed to create tree "<<std::endl;
  std::cout<<"Elemnet 2 exists in tree : "<<(findElement(root,2)? "True" : "False")<<std::endl;
  std::cout<<"Elemnet 12 exists in tree : "<<(findElement(root,12)? "True" : "False")<<std::endl;
  std::cout<<"Elemnet 1 exists in tree : "<<(findElement(root,1)? "True" : "False")<<std::endl;
  deleteTree(root);
}
