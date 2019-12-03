#include<iostream>

using namespace std;

struct Node{
    int key;
    Node* left ;
    Node* right;
};

class hashBST
{
  private:

    int tableSize;

    // Pointer to an array containing buckets
    Node* *table;


  public:
    Node* addNodeHelper(Node* currNode, int data);
    hashBST();  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);
    // Node* createNode(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);
    void printHelper(Node* node);
    void printTable();
    void print100();
    bool deleteItem(int key);
    bool deleteNode(Node *currNode, int key);
    Node* getMinValueNode(Node* currNode);
    Node* searchItem(int key);
};
