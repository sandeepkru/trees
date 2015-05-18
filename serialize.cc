#include <iostream>
#include <fstream>
#include "simplebTree.h"
void serialize(root);
void deserialize(root);

int main(int argc, char** argv)
{
    btree* root = createTree();
  if ( !root )
    std::cout<<"Error! Failed to create a new tree"<<std::endl;
  ofstream myfile;
  serialize(root, );
  deserialize(root);
}
