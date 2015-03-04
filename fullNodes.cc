//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Full Nodes = 3 (1,2,3)
#include <iostream>
#include <queue>

#include "simplebTree.h"

int fullNodes(btree* root)
{
  if ( !root )
    return 0;
  std::queue<btree*> dataQ;
  int count = 0;
  btree* temp;
  dataQ.push(root);
  while(!dataQ.empty())
    {
      temp = dataQ.front();
      dataQ.pop();
      
      if ( temp->right && temp->left )
	count++;
      if ( temp->left )
	dataQ.push(temp->left);
      if ( temp->right )
	dataQ.push(temp->right);
    }
  return count;
}


int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  std::cout<<"Number of full nodes : "<<fullNodes(root)<<std::endl;
  deleteTree(root);
}
