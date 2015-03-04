#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <limits.h>
typedef struct binarytree
{
  int data;
  struct binarytree* left;
  struct binarytree* right;
}btree;

btree* createNode()
{
  time_t t;
  btree* node = (btree*)malloc(sizeof(btree));
  if (!node) 
    return NULL;
  srand((unsigned)time(&t));
  node->data  = rand() % 80;
  node->left  = NULL;
  node->right = NULL;
  return node;
}

btree* createTree(int size)
{
  // Create a tree for provided size
  // 1. Create a node first, assign its left and right to NULL, then
  // decide where to insert 
  btree* node = (btree*)malloc(sizeof(btree));
  if (!node) 
    return NULL;
  node->data  = size % 99;
  node->left  = NULL;
  node->right = NULL;
  btree* root = node;

  node->left  = createNode();
  node->right = createNode();  
  if (node->left)
    {
      node->left->left  = createNode();
      node->left->right = createNode();
    }
  if (node->right)
    {
      node->right->left  = createNode();
      node->right->right = createNode();
    }
  return root;
}
void printTree(btree* root)
{
  btree *current = root;
  if(current){
    printf("%d\n",current->data);
    printTree(current->left);
    printTree(current->right);
  }
}
void deleteTree(btree* root)
{
  if (root!=NULL)
    {
      //     printf("In delete tree\n");
      deleteTree(root->left);
      deleteTree(root->right);
      printf("deleting %d\n",root->data);
      free(root);
    }
}
int findMax(btree* root)
{
  int root_val, left_max, right_max, max=INT_MIN;
  if(root!=NULL)
    {
      root_val  = root->data;
      left_max  = findMax(root->left);
      right_max = findMax(root->right);
      if (left_max > right_max)
	max = left_max;
      else 
	max = right_max;
      if (root_val > max )
	max = root_val;
    }
  return max;
}
int main(int argc,char** argv)
{
  // Create a random size for a binary tree
  srand(time(NULL));
  int size = rand() % 99;
  btree *root = createTree(size);
  if (!root)
    printf("No tree has been created\n");
  printTree(root);
  printf("Maximum element in tree is %d\n",findMax(root));
  deleteTree(root);
}
