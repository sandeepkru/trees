#include "simplebTree.h"

int main(int argc,char** argv)
{
  // Create a random size for a binary tree
   btree *root = createTree();
  if (!root)
    printf("No tree has been created\n");
  printTree(root);
  deleteTree(root);
}
