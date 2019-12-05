#include<iostream>

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class hashLL
{
    int tableSize;

    // Pointer to an array containing buckets
    node* *table;

    node* createNode(int key, node* next);
public:
    hashLL();  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    void print100();

    node* searchItem(int key);

    bool deleteItem(int key);
};

class hashLLprime
{
    int tableSize;

    // Pointer to an array containing buckets
    node* *table;

    node* createNode(int key, node* next);
public:
    hashLLprime();  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    void print100();

    node* searchItem(int key);

    bool deleteItem(int key);
};
