#include <iostream>
#include <stack>

#include "simplebTree.h"

void preOrder (btree*);
void inOrder  (btree*);

void preOrder(btree* root)
{
   if ( !root ) return; 
   std::stack<btree*> lStack;
 
   lStack.push(root);
   while ( !lStack.empty() )
   {
     btree* current = lStack.top();
     lStack.pop();
     std::cout << current->data <<'\t';
     if ( current->right ) lStack.push(current->right);
     if ( current->left ) lStack.push(current->left);
   }
   return;
}

void inOrder(btree* root)
{
    if ( !root ) return;
    bool _term = false;
    btree* current = root;
    std::stack<btree*> auxStack;
    while ( !_term )
    {
       if ( current != NULL )
       {
         auxStack.push(current);
         current = current->left;
       }
       else 
	 {
          if ( !auxStack.empty() )
          {
             btree* temp = auxStack.top();
             auxStack.pop();
             std::cout << temp->data << '\t';
             current = temp->right;
          }
          else _term = true;
         }
    }
    return;
}

int main(int argc, char* argv[])
{
btree* root = createTree();
if ( !root )
  std::cout<<"Error! Failed to create a new tree"<<std::endl;
std::cout<<" Pre order "<<std::endl;
preOrder(root);
std::cout<<"\n In order "<<std::endl;
inOrder(root);
deleteTree(root);
}
