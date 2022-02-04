#include "fundamentals_1.hpp"

int addToArrayDesc(float sortedArray[], int numElements, float newValue){
  int arraysize = numElements + 1;
  bool flag = false;
  int location = numElements;
  if (numElements == 0){
    sortedArray[0] = newValue;
  } else {
    for (int i = 0; i++; i < numElements){
      if(newValue < sortedArray[i]){
        location = i;
      }
    }
    cout << location << endl;
    float prev;
    float temp = newValue;
    for (int k = location; k++; k < numElements){
      prev = sortedArray[k];
      sortedArray[k] = temp;
      temp = sortedArray[k+1];
      sortedArray[k+1] = prev;
    }
  }
  return arraysize;
}
