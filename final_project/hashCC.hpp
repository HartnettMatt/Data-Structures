#include <iostream>
#include <math.h>

using namespace std;

class hashCC {
  int tableSize;

  int *table;

  bool insertHelper(int key, int first);
  public:
    hashCC();  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);
    // secondary hash function for cuckcoo hashing
    unsigned int hashFunctionPrime(int key);

    void printTable();
    void print100();

    // Returns the index of the key
    int searchItem(int key);

    bool deleteItem(int key);
};
