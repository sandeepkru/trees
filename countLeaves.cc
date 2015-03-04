//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Leaf Nodes = 4 (4,5,6,7)
#include <iostream>
#include <queue>

#include "simplebTree.h"

int countLeaves(btree* root)
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
      if ( !temp->left && !temp->right )
	count++;
      else
	{
	  if ( temp->left )
	    dataQ.push(temp->left);
	  if ( temp->right )
	    dataQ.push(temp->right);
	}
    }
  return count;
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  std::cout<<"Number of Leaf nodes : "<<countLeaves(root)<<std::endl;
  deleteTree(root);
}

