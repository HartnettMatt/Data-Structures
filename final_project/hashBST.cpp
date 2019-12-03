#include "hashBST.hpp"
using namespace std;

hashBST::hashBST()
{
    tableSize = 10009;
    table = new Node*[10009];
    for(int i=0;i<10009;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int hashBST::hashFunction(int key)
{
    return (key % tableSize);
}


//function to search
Node* searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}
Node* hashBST::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    Node *treeHead = table[index];
    return searchKeyHelper(treeHead, key);
    // node *crawler = table[index];
    // while(crawler != nullptr){
    //   if(crawler->key == key){
    //     return crawler;
    //   }
    //   crawler = crawler->next;
    // }
}

//function to insert
Node* hashBST::addNodeHelper(Node* currNode, int data)
{
  if(currNode == NULL){
    Node *nw = new Node;
    nw->key = data;
    return nw;
  }
  else if(currNode->key < data){
    currNode->right = addNodeHelper(currNode->right,data);
  }
  else if(currNode->key > data){
    currNode->left = addNodeHelper(currNode->left,data);
  }
  return currNode;

}
bool hashBST::insertItem(int key)
{
  int index = hashFunction(key);
  if(table[index] == nullptr){
    Node* nw = new Node;
    nw->key = key;
    nw->right = nullptr;
    nw->left = nullptr;
    table[index] = nw;
  } else {
    addNodeHelper(table[index], key);
  }
  return true;
}

// function to display hash table
void hashBST::printHelper(Node * node)
{
  if(node != nullptr){
    printHelper(node->left);
    cout << " "<< node->key;
    printHelper(node->right);
  }

}
void hashBST::printTable()
{
  for (int i = 0; i < tableSize; i++) {
    cout << i <<" || ";
    if(table[i] != nullptr)
    {
       printHelper( table[i]->left);
       cout << " "<< table[i]->key;
       printHelper( table[i]->right);
    } else {
      cout << "NULL";
    }
    cout << endl;
  }
 }

// function to display first 100 values for testing purpose
void hashBST::print100()
{
  for (int i = 0; i < 100; i++) {
    cout << i <<" || ";
    if(table[i] != nullptr)
    {
       printHelper( table[i]->left);
       cout << " "<< table[i]->key;
       printHelper( table[i]->right);
    } else {
      cout << "NULL";
    }
    cout << endl;
  }
}
