#include <iostream>
#include "simplebTree.h"

void printArray(int path[],int len)
{
  for ( int i=0;i<len;i++ )
    std::cout<<path[i]<<"\t";
  std::cout<<"\n";
}
void printPaths(btree* root, int path[], int pathLength)
{
  if ( !root )
    return;
  path[pathLength] = root->data;
  pathLength++;
  if ( !root->left && !root->right )
    printArray(path,pathLength);
  else
    {
      printPaths(root->left,path,pathLength);
      printPaths(root->right,path,pathLength);
    }
}

int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<" Error! Failed to create new tree "<<std::endl;
  int path[20];
  printPaths(root,path,0);
  deleteTree(root);
}
