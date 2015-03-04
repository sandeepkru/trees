//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Deepest node any of last level 4 or 5 or 6 or 7
#include <iostream>
#include <queue>

#include "simplebTree.h"

btree* deepestNode(btree* root)
{
  btree* temp = NULL;
  if ( !root )
    return temp;
  std::queue<btree*> dataQ;
  dataQ.push(root);
  while(!dataQ.empty())
    {
      temp = dataQ.front();
      dataQ.pop();
      if ( temp->left )
	dataQ.push(temp->left);
      if ( temp->right )
	dataQ.push(temp->right);
    }
  return temp;
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  std::cout<<"Deepest node is "<<deepestNode(root)<<" and Value is "<<(deepestNode(root)->data)<<std::endl;
  deleteTree(root);
}
