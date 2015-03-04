//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Height of the threet is 3

#include <iostream>
#include <queue>

#include "simplebTree.h"

int heightOfTree(btree* root)
{
  if ( ! root )
    return 1;
  std::queue<btree*> dataQ;
  int height = 0;
  btree* temp;
  dataQ.push(root);
  dataQ.push(NULL); // indicate end of level
  while(!dataQ.empty())
    {
      temp = dataQ.front();
      dataQ.pop();
      
      if ( temp == NULL )
	{
	  if(!dataQ.empty())
	    dataQ.push(NULL);
	  height++;
	}
      else
	{
	  if ( temp->left )
	    dataQ.push(temp->left);
	  if ( temp->right )
	    dataQ.push(temp->right);	  
	}
    }
  return height;
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if (!root){
    std::cout<<"Error! Failed to create tree"<<std::endl;
    exit(10);
  }
  //  printTree(root);
  std::cout<<"Height of the Tree is : "<<heightOfTree(root)<<std::endl;
  deleteTree(root);
}

