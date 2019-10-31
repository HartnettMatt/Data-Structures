#include <fstream>
#include <iostream>
using namespace std ;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
  if(numEntries == 0){
    myArray[0] = newValue;
    return 1;
  } 
  for(int i = 0; i < numEntries; i++){
    if(myArray[i] > newValue){
      for(int j = numEntries; j > i; j--){
        myArray[j] = myArray[j-1];
      }
      myArray[i] = newValue;
      return numEntries+1;
    }
  }
  myArray[numEntries] = newValue;
  return numEntries+1;
}

int main ()
{
  int listsize=6;
  int list[listsize] = {29,44,35,16,9,200};
  int arr[listsize];
  for(int j = 0; j < 6; j++){
    cout << list[j] << " ";
  }
  cout << endl;
  for(int i = 0; i < 6; i++){
    insertIntoSortedArray(arr, i, list[i]);
    for(int k = 0; k < i; k++){
      cout <<arr[k] << ", ";
    }
    cout << endl;
  }
}
