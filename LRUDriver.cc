#include <iostream>
#include "LRUCache.h"

int main(int argc, char** argv)
{
  size_t size = 20;
  LRUCache<int,int>* lru = new LRUCache<int,int>(size);
  LRUCache<int,int>* lru2;
  new (lru) LRUCache<int,int>(size);
  //  lru2 = lru;
  for ( int i = 0; i< 20; i++ )
    {
      lru->put(i,i);
    }
  lru->showMap();
  delete lru;
  return 0;
}
