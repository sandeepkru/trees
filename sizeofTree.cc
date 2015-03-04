//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Size of Tree is 7
#include <iostream>
#include <queue>
#include "simplebTree.h"

int sizeOfTree(btree* root)
{
  if ( !root )
    return 0;
  int size = 0;
  std::queue<btree*> dataQ;
  btree* temp;
  dataQ.push(root);
  while(!dataQ.empty())
    {
      temp = dataQ.front();
      dataQ.pop();
      size++;
      if ( temp->left )
	dataQ.push(temp->left);
      if ( temp->right )
	dataQ.push(temp->right);	  
    }
  return size;
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<" Error! Failed to create tree "<<std::endl;

  std::cout<<"Size of the tree is : "<<sizeOfTree(root)<<std::endl;
  deleteTree(root);
}

  
