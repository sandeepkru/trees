#include "LRUCache.h"

template<class K,class T>
LRUCache<K,T>::LRUCache(size_t size)
{
  itemList = new LRUCacheEntry<K,T>[size];
  for ( int i = 0; i < size ; i++ )
    {
      _freelist.push_back(itemList+i);
    }
  head = new LRUCacheEntry<K,T>;
  tail = new LRUCacheEntry<K,T>;
  head->prev = NULL;
  head->next = tail;
  tail->prev = head;
  tail->next = NULL;
}

template<class K,class T>
LRUCache<K,T>::~LRUCache()
{
  delete head;
  delete tail;
  delete []itemList;
}

template<class K, class T>
void
LRUCache<K,T>::detach(LRUCacheEntry<K,T>* node)
{
  node->next->prev = node->prev;
  node->prev->next = node->next;
}

template<class K, class T>
void
LRUCache<K,T>::attach(LRUCacheEntry<K,T>* node)
{
  node->next = head->next;
  node->prev = head;
  head->next = node;
  node->next->prev = node;
}

template<class K, class T>
T
LRUCache<K,T>::get(K key)
{
  LRUCacheEntry<K,T>* item = _hashTable[key];
  
  if ( item )
    {
      detach(item);
      attach(item);
      return item->data;
    }
  else
    return NULL;
}

template<class K, class T>
void
LRUCache<K,T>::put(K key, T data)
{
  LRUCacheEntry<K,T>* node = _hashTable[key];
  // Check if Key already exists in hash 
  if ( node )
    {
      detach(node);
      node->data = data;
      attach(node);
    }
  else 
    {
      if ( _freelist.empty() )
	{
	  node = tail->prev;
	  detach(node);
	  _hashTable.erase(node->key);
	  node->data = data;
	  node->key  = key;
	  _hashTable[key] = data;
	  attach(node);
	}
      else
	{
	  node = _freelist.back();
	  _freelist.pop_back();
	  node->key = key;
	  node->data = data;
	  _hashTable[key] = node;
	  attach(node);
	}
    }
}

template<class K, class T>
void
LRUCache<K,T>::showMap()
{
  typename std::map<K,LRUCacheEntry<K,T>*>::iterator it;
  std::cout<<"Key  "<<"\t"<<"Value"<<std::endl;
  std::cout<<"====="<<"\t"<<"====="<<std::endl;
  for ( it = _hashTable.begin(); it != _hashTable.end(); ++it)
    {
      std::cout<<it->first<<std::endl;
    }
}
