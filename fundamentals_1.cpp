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
    float prev;
    float temp = newValue;
    for (int k = location; k++; k < numElements+1){
      prev = sortedArray[i];
      sortedArray[i] = temp;
      temp = sortedArray[i+1];
      sortedArray[i+1] = prev;
    }
  }
  return arraysize;
}
