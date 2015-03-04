//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// True if element is found, False if it is not
#include <iostream>
#include <queue>
#include "simplebTree.h"
#include <stdbool.h>

bool findElement(btree* root, int data)
{
  if (!root)
    return false;
  std::queue<btree*> dataQ;
  btree* temp;
  dataQ.push(root);
  while(!dataQ.empty())
    {
      temp = dataQ.front();
      dataQ.pop();
      if ( temp->data == data )
	return true;
      if ( temp->left )
	dataQ.push(temp->left);
      if ( temp->right )
	dataQ.push(temp->right);
    }
  return false; 
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  std::cout<<"Elemnet 2 exists in tree : "<<(findElement(root,2)? "True" : "False")<<std::endl;
  std::cout<<"Elemnet 12 exists in tree : "<<(findElement(root,12)? "True" : "False")<<std::endl;
  std::cout<<"Elemnet 1 exists in tree : "<<(findElement(root,1)? "True" : "False")<<std::endl;
  deleteTree(root);
}
