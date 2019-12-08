#include<iostream>

using namespace std;


class hashLP
{
    int tableSize;

    // Pointer to an array containing buckets
    int *table;

public:
    hashLP();  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    void print100();

    // Returns the index of the key
    int searchItem(int key);

    bool deleteItem(int key);
};

class hashLPprime
{
    int tableSize;

    // Pointer to an array containing buckets
    int *table;

public:
    hashLPprime();  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    void print100();

    // Returns the index of the key
    int searchItem(int key);

    bool deleteItem(int key);
};
