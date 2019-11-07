// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

//function to search
node* HashTable::searchItem(int key)
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
bool HashTable::insertItem(int key)
{
  if(searchItem(key) != nullptr && searchItem(key)->key == key){
    cout<<"duplicate entry: "<<key<<endl;
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
void HashTable::printTable()
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
