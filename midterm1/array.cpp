#include<iostream>
#include<string>
using namespace std;

/*
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
	//Count the evens and odds
  for(int i = 0; i < size; i++){
    if(arr[i]%2 == 0){
      even_size++;
    } else {
      odd_size++;
    }
  }
  // Create the arrays of the proper size
  even_arr = new int[even_size];
  odd_arr = new int[odd_size];
  // Fill each arrays
  int e = 0;
  int o = 0;
  for(int i = 0; i < size; i++){
    if(arr[i]%2 == 0){
      even_arr[e] = arr[i];
      e++;
    } else {
      odd_arr[o] = arr[i];
      o++;
    }
  }
}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;

	// Call your function with new arrays:
  int *evenArr;
  int *oddArr;
  int evenSize = 0;
  int oddSize = 0;
	split(arr, evenArr, oddArr, stoi(argv[1]), evenSize, oddSize);

// Display even array
  if(evenSize == 0){
    cout << "No even items in the array";
  } else {
    cout << "Even array: " << endl;
    for(int i = 0; i<evenSize; i++)
    {
        cout<< evenArr[i];
        if(i < evenSize-1)
          cout << ", ";
    }
  }
  cout<<endl;

// Display odd array
  if(oddSize == 0){
    cout << "No odd items in the array";
  } else {
    cout << "Odd array: " << endl;
    for(int i = 0; i<oddSize; i++)
    {
        cout<< oddArr[i];
        if(i < oddSize-1)
          cout << ", ";
    }
  }
  cout<<endl;

	// Clean up (delete)
delete arr;
delete evenArr;
delete oddArr;
}
