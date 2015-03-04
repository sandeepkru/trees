#include <iostream>
#include "simplebTree.h"

btree* lcaOfNodes(btree* root, btree* node1, btree* node2)
{
  if ( root == NULL ) return root;
  if ( (root == node1) || ( root == node2) ) return root;
  btree* left  = lcaOfNodes(root->left, node1,node2);
  btree* right = lcaOfNodes(root->right,node1,node2);
  if ( left && right )
    return root;
  else
    return (left?left:right);
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error Failed to create a new tree "<<std::endl;
  btree* temp = lcaOfNodes(root,root->left,root->right);
  std::cout<<"LCA is   "<<temp<< " Data is "<<temp->data<<std::endl;
  temp = lcaOfNodes(root,root->left->left,root->left->right);
  std::cout<<"LCA is   "<<temp<< " Data is "<<temp->data<<std::endl;
  deleteTree(root);
}


