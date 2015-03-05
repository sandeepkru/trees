#ifndef __SIMPLEBTREE_H_
#define __SIMPLEBTREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <limits.h>
/* Simple binary tree stucture */
typedef struct binarytree
{
  int data;
  struct binarytree* left;
  struct binarytree* right;
}btree;

btree* createNode(int data);
btree* createTree();
void printTree(btree*);
void   deleteTree();
btree* createNode(int num)
{
  btree* node = (btree*)malloc(sizeof(btree));
  if (!node) 
    return NULL;
  node->data  = num;
  node->left  = NULL;
  node->right = NULL;
  return node;
}
btree* createTree()
{
  // Create a tree for provided size
  // 1. Create a node first, assign its left and right to NULL, then
  // decide where to insert 
  btree* node = createNode(1);
  btree* root = node;

  node->left  = createNode(2);
  node->right = createNode(3);  
  if (node->left)
    {
      node->left->left  = createNode(4);
      node->left->right = createNode(5);
    }
  if (node->right)
    {
      node->right->left  = createNode(6);
      node->right->right = createNode(7);
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
#endif /* for __SIMPLEBTREE_H_ */
