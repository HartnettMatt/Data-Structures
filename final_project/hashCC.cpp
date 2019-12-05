#include "hashCC.hpp"

using namespace std;

hashCC::hashCC(){
  tableSize = 10009;
  table = new int[tableSize];
  rehashCount = 0;
}

// Rehash function if a loop is encountered:
bool hashCC::rehash(){
  int oldTableSize = tableSize;
  cout << "rehashing..." << endl;
  if(rehashCount == 0){
    tableSize = 20021;
  } else if(rehashCount == 1){
    tableSize = 40039;
  } else if(rehashCount == 2){
    tableSize = 80077;
  } else {
    cout << "can't rehash: too large" << endl;
    return false;
  }
  int *temp = table;
  table = new int[tableSize];
  for(int i = 0; i < oldTableSize; i++){
    insertItem(temp[i]);
  }
  delete temp;
  rehashCount++;
  cout << "rehashed!";
  return true;
}
// inserts a key into hash table
bool hashCC::insertHelper(int key, int first){
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
    if(temp == first){
      if(rehash()){
        insertHelper(key, first);
      } else {
        cout << "Can't add value" << endl;
        return false;
      }
    } else {
      table[index] = key;
      insertHelper(temp, first);
    }
  }
}
bool hashCC::insertItem(int key){
  return insertHelper(key, key);
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
