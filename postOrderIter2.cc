#include <iostream>
#include <stack>
#include <assert.h>
#include "simplebTree.h"

void postOrder(btree*);

// Print post Order iteratively
void postOrder( btree* root )
{
  if ( !root ) return;
  std::stack<btree*> stk1;
  std::stack<btree*> stk2;
  // std::cout << root->data <<std::endl; // return;
  stk1.push(root);
  while( !stk1.empty() )
    {
      btree* temp = stk1.top();
      stk2.push(temp);
      stk1.pop();
      if ( temp->left ) stk1.push(temp->left);
      if ( temp->right ) stk1.push(temp->right);
    }
  while ( !stk2.empty() )
    {
      std::cout << stk2.top()->data << '\t';
      stk2.pop();
    }
  std::cout << std::endl;
  return;
}

// Main
int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  postOrder(root);
  //std::cout<<"Number of full nodes : "<<postOder(root)<<std::endl;
  deleteTree(root);
}
