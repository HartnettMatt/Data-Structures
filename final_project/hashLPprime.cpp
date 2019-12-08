#include "hashLP.hpp"
#include <math.h>
using namespace std;

hashLPprime::hashLPprime(){
  tableSize = 10009;
  table = new int[tableSize];
}

// inserts a key into hash table
bool hashLPprime::insertItem(int key){
  int index = hashFunction(key);
  for(int i = index; i < tableSize; i++){
    if(table[i] == 0){
      table[i] = key;
      return true;
    }
  }
  for(int i = 0; i < index; i++){
    if(table[i] == 0){
      table[i] = key;
      return true;
    }
  }
  return false;
}
// hash function to map values to key
unsigned int hashLPprime::hashFunction(int key)
{
    return (int)floor((key*1.0)/ tableSize)%tableSize;
}

void hashLPprime::printTable(){
  for (int i = 0; i < tableSize; i++) {
    cout << i <<" || " << table[i] << endl;;
  }
}
void hashLPprime::print100(){
  for (int i = 0; i < 100; i++) {
    cout << i <<" || " << table[i] << endl;;
  }
}

int hashLPprime::searchItem(int key){
  int index = hashFunction(key);
  if(table[index] == key){
    return index;
  } else {
    for(int i = index+1; i != index; i++){
      if(i == tableSize){
        i = 0;
      }
      if(table[i] == key){
        return i;
      }
    }
  }
  return -1;
}

bool hashLPprime::deleteItem(int key){
  int index = hashFunction(key);
  if(table[index] == key){
    table[index] = -1;
    return true;
  } else {
    for(int i = index+1; i != index; i++){
      if(i == tableSize){
        i = 0;
      }
      if(table[i] == key){
        table[i] = -1;
        return true;
      }
    }
  }
  return false;
}
