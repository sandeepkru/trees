//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Level Order reverse 4 5 6 7 2 3 1

#include <iostream>
#include <queue>
#include <stack>

#include "simplebTree.h"

void reversePrint(btree* root)
{
  if (!root)
    std::cout<<"nothing to print - Empty tree"<<std::endl;
  btree* temp = NULL;
  std::queue<btree*> dataQ;
  std::stack<int> printOrder;
  dataQ.push(root);
  while(!dataQ.empty())
    {
      temp = dataQ.front();
      dataQ.pop();
      printOrder.push(temp->data);
      // Insert right first
      if ( temp->right )
	dataQ.push(temp->right);
      if ( temp->left )
	dataQ.push(temp->left);
    }
  while(!printOrder.empty())
    {
      std::cout<<printOrder.top()<<" \t";
      printOrder.pop();
    }
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<" Error! Failed to create tree "<<std::endl;

  reversePrint(root);
  deleteTree(root);
}
