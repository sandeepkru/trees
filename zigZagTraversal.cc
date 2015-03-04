#include <iostream>
#include <stack>
#include <stdbool.h>

#include "simplebTree.h"

void zigZagTraversal(btree* root)
{
  if ( !root ) return;
  bool LtoR = true;
  std::stack<btree*> currentLevel;
  std::stack<btree*> nextLevel;
  currentLevel.push(root);
  while ( !currentLevel.empty() )
    {
      btree* temp = currentLevel.top();
      currentLevel.pop();
      if ( temp ){
	std::cout<<temp->data<<"\t";
	if ( LtoR )
	  {
	    if(temp->left) nextLevel.push(temp->left);
	    if(temp->right) nextLevel.push(temp->right);
	  }
	else
	  {
	    if(temp->right) nextLevel.push(temp->right);
	    if(temp->left) nextLevel.push(temp->left);
	  }
      }
      if ( currentLevel.empty() )
	{
	  LtoR = (!LtoR);
	  swap(currentLevel,nextLevel);
	}
    }

}

int main(int argc,char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a tree"<<std::endl;
  zigZagTraversal(root);
  deleteTree(root);
}
