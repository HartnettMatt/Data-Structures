#include "hashCC.hpp"

using namespace std;

hashCC::hashCC(){
  tableSize = 10009;
  table = new int[tableSize];
}
// inserts a key into hash table
bool hashCC::insertItem(int key){
  // Insert into first hash location if empty
  int index = hashFunction(key);
  if(table[index] == 0){
    table[index] = key;
    return true;
  }
  // Insert into second hash location and rehash if second location is occupied
  index = hashFunctionPrime(key);
  if(table[index] == 0){
    table[index] = key;
    return true;
  } else {
    int temp = table[index];
    table[index] = key;
    insertItem(temp);
  }
}

// hash function to map values to key
unsigned int hashCC::hashFunction(int key){
  return (key % tableSize);
}
// secondary hash function for cuckcoo hashing
unsigned int hashCC::hashFunctionPrime(int key){
  return (int)floor((key*1.0)/ tableSize)%tableSize;
}

void hashCC::printTable(){
  for (int i = 0; i < tableSize; i++) {
    cout << i <<" || " << table[i] << endl;;
  }
}
void hashCC::print100(){
  for (int i = 0; i < 100; i++) {
    cout << i <<" || " << table[i] << endl;;
  }
}

// Returns the index of the key
int hashCC::searchItem(int key){
  int index = hashFunction(key);
  if(table[index] == key){
    return index;
  }
  // Check second hash location
  index = hashFunctionPrime(key);
  if(table[index] == key){
    return index;
  }
  return -1;
}

bool hashCC::deleteItem(int key){
  int index = hashFunction(key);
  if(table[index] == key){
    table[index] = 0;
    return true;
  }
  // Check second hash location
  index = hashFunctionPrime(key);
  if(table[index] == key){
    table[index] = 0;
    return true;
  }
  return false;
}
