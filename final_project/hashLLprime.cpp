#include "hashLL.hpp"
#include <math.h>
using namespace std;

hashLLprime::hashLLprime()
{
    tableSize = 10009;
    table = new node*[10009];
    for(int i=0;i<10009;i++)
        table[i] = nullptr;
}

node* hashLLprime::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

//function to calculate hash function
unsigned int hashLLprime::hashFunction(int key)
{
    return (int)floor((key*1.0)/ tableSize)%tableSize;
}

//function to search
node* hashLLprime::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    node *crawler = table[index];
    while(crawler != nullptr){
      if(crawler->key == key){
        return crawler;
      }
      crawler = crawler->next;
    }
    return nullptr;
}

//function to insert
bool hashLLprime::insertItem(int key)
{
  if(searchItem(key) != nullptr && searchItem(key)->key == key){
    // cout<<"duplicate entry: "<<key<<endl;
    return false;
  } else {
    int index = hashFunction(key);
    node* newNode = createNode(key, nullptr);
    if(table[index] == nullptr){
      table[index] = newNode;
    } else {
      newNode->next = table[index];
      table[index] = newNode;
    }
  }
  return true;
}

// function to display hash table
void hashLLprime::printTable()
{
  for (int i = 0; i < tableSize; i++) {
    cout << i <<" || ";
    node *crawler = table[i];
    while(crawler != nullptr){
      cout << crawler->key << "->";
      crawler = crawler->next;
    }
    cout << "NULL" << endl;
  }
 }

// function to display first 100 values for testing purpose
void hashLLprime::print100()
{
  for (int i = 0; i < 100; i++) {
    cout << i <<" || ";
    node *crawler = table[i];
    while(crawler != nullptr){
      cout << crawler->key << "->";
      crawler = crawler->next;
    }
    cout << "NULL" << endl;
  }
}

// function to delete item from hash table
bool hashLLprime::deleteItem(int key)
{
  int index = hashFunction(key);
  node *crawler = table[index];
  if(crawler->key == key){
    node *temp = crawler;
    table[index] = nullptr;
    delete temp;
    return true;
  }
  while(crawler->next != nullptr){
    if(crawler->next->key == key){
      node *temp = crawler->next;
      crawler->next = crawler->next->next;
      delete temp;
      return true;
    }
    crawler = crawler->next;
  }
  return false;
}
