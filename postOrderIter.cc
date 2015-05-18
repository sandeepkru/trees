#include <iostream>
#include <stack>

#include "simplebTree.h"

void postOrder(btree*);

// Print post Order iteratively
void postOrder( btree* root )
{
if ( !root ) return ;
std::stack<btree*> dataStack;
do
  {
   while(  root )
     {
       if ( root->right )
	 dataStack.push(root->right);
       dataStack.push(root);
       root = root->left;
     }
   root = dataStack.top();
   dataStack.pop();
   if ( root->right && !dataStack.empty() && dataStack.top() == root->right )
     {
       dataStack.pop();
       dataStack.push(root);
       root = root->right;
     }
   else
     {
       std::cout<<root->data<<"  ";
       root = NULL;
     }
  }while(!dataStack.empty());  
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
