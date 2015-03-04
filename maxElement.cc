//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Maximum Element is 7

#include <iostream>
#include <queue>
#include "simplebTree.h"
int findMax(btree* root)
{
  btree* temp;
  int iMax = INT_MIN;
  std::queue<btree*> dataQ;
  
  if(!root){
    std::cout<<"Error! Tree is empty"<<std::endl;
    return 0;
  }
  dataQ.push(root);
  while(!dataQ.empty()){
    temp = dataQ.front();
    dataQ.pop();
    if ( temp->data > iMax )
      iMax = temp->data;
    if ( temp->left )
      dataQ.push(temp->left);
    if ( temp->right )
      dataQ.push(temp->right);
    // temp->right ? dataQ.push(temp->right) : void;
  }
  return iMax;
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if (!root){
    std::cout<<"Error! Failed to create tree"<<std::endl;
    exit(10);
  }
  std::cout<<"Maximum element is : "<<findMax(root)<<std::endl;
  deleteTree(root);
}
