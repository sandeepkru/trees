//                       1
//                      / \
//                     2   3
//                    / \ / \
//                   4  5 6  7

// Level Order Traversal 1->2->3->4->5->6->7

#include <iostream>
#include <queue>
#include "simplebTree.h"
void levelOrderTraversal(btree* root)
{
  btree* temp;
  std::queue<btree*> dataQ;
  if (!root)
    return;
  dataQ.push(root);
  while(!dataQ.empty()){
    temp = dataQ.front();
    dataQ.pop();
    std::cout<<temp->data<<"\t";
    if (temp->left)
      dataQ.push(temp->left);
    if (temp->right)
      dataQ.push(temp->right);
  }
}

int main(int argc,char** argv)
{
  btree* root = createTree();
  if (!root){
    std::cout<<" Error! Failed to create tree"<<std::endl;
    exit(10);
  }
  levelOrderTraversal(root);
  deleteTree(root);
}
