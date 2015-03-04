#include <iostream>
#include <queue>

#include "simplebTree.h"

int maxSumLevel(btree* root)
{
  if ( !root )
    return -1;
  std::queue<btree*> dataQ;
  int curlevel=0,maxlevel=0, maxSum = INT_MIN, curSum = INT_MIN;
  btree* temp;
  dataQ.push(root);
  dataQ.push(NULL);
  while(!dataQ.empty())
    {
      temp = dataQ.front();
      dataQ.pop();
      if ( temp == NULL )
	{
	  if ( curSum > maxSum )
	    {
	      maxSum   = curSum;
	      maxlevel = curlevel;
	    }
	  if ( !dataQ.empty())
	    dataQ.push(NULL);
	  curlevel++;
	  curSum = 0;
	}
      else
	{
	  curSum += temp->data;
	  if ( temp->left )
	    dataQ.push(temp->left);
	  if ( temp->right )
	    dataQ.push(temp->right);
	}
    }
  return maxlevel;
}


int main(int argc, char** argv)
{
  btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  std::cout<<"Maximum sum found in level  "<<maxSumLevel(root)<<std::endl;
  deleteTree(root);
}
