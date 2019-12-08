#include "hashBST.hpp"
#include <math.h>
using namespace std;

hashBSTprime::hashBSTprime()
{
    tableSize = 10009;
    table = new Node*[10009];
    for(int i=0;i<10009;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int hashBSTprime::hashFunction(int key)
{
return (int)floor((key*1.0)/ tableSize)%tableSize;
}


// functions to search
Node* hashBSTprime::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}
Node* hashBSTprime::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    Node *treeHead = table[index];
    return searchKeyHelper(treeHead, key);
}

//functions to insert
Node* hashBSTprime::addNodeHelper(Node* currNode, int data)
{
  if(currNode == NULL){
    Node *nw = new Node;
    nw->key = data;
    nw->left = nullptr;
    nw->right = nullptr;
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
bool hashBSTprime::insertItem(int key)
{
  int index = hashFunction(key);
  table[index] = addNodeHelper(table[index], key);
  return true;
}

// functions to display hash table
void hashBSTprime::printHelper(Node * node)
{
  if(node != nullptr){
    printHelper(node->left);
    cout << " "<< node->key;
    printHelper(node->right);
  }

}
void hashBSTprime::printTable()
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
void hashBSTprime::print100()
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

// helper function to delete item from hash table
bool hashBSTprime::deleteNode(Node * currNode, int key){
  if(key < currNode->key){
    deleteNode(currNode->left, key);
  } else if(key > currNode->key){
    deleteNode(currNode->right, key);
  }
  // We found the node with the value
  else {
    //Case : No child
    if(currNode->left == NULL && currNode->right == NULL)
    {
      currNode = nullptr;
      delete currNode;
      return true;
    }
    //Case : Only right child
    else if(currNode->left == NULL)
    {
      Node *temp = currNode;
      currNode = currNode->right;
      delete currNode;
      return true;
    }
    //Case : Only left child
    else if(currNode->right == NULL)
    {
      Node *temp = currNode;
      currNode = currNode->left;
      delete currNode;
      return true;
    }
    //Case: Both left and right child
    else
    {
      ///Replace with Minimum from right subtree
      Node *min = getMinValueNode(currNode->right);
      currNode->key = min->key;
      deleteNode(currNode->left, min->key);
    }
  }
}

// function to delete item from hash table
bool hashBSTprime::deleteItem(int key)
{
  int index = hashFunction(key);
  if(table[index] == nullptr){
    return false;
  } else if(table[index]->key == key){
    Node *temp = table[index];
    table[index] == nullptr;
    delete temp;
    return true;
  } else {
    return deleteNode(table[index], key);
  }
}

// function to find smallest value from tree with root currNode
Node* hashBSTprime::getMinValueNode(Node* currNode){
    if(currNode->left == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->left);
}
