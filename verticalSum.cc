#include <iostream>
#include <map>
#include "simplebTree.h"
std::map<int,int> hMap;
void verticalSum(btree* root, int colNum)
{
#if 0
  printf("Hello World\n");
#endif
  if ( !root ) return;
  verticalSum(root->left,colNum-1);
  hMap[colNum] += root->data;
  verticalSum(root->right,colNum+1);
}

int main(int argc,char** argv)
{
  btree* root = createTree();
  if ( !root ) {
    std::cout<<"Error! Failed to create a tree" <<std::endl;
    return 1;
  }
  verticalSum(root,0);
  std::map<int,int>::iterator itr;
  for(itr=hMap.begin(); itr!=hMap.end(); ++itr)
    std::cout<<"Column: "<< itr->first <<" sum is : "<<itr->second<<std::endl;
  deleteTree(root);
}
