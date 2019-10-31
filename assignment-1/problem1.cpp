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

int main (int argc, char const *argv[])
{
  if(argc != 2){
    cout << "Include one filename"<<endl;
    return 0;
  }

  ifstream iF;
  iF.open(argv[1]);
  string s;
  int b = 0;
  while(getline(iF, s)){
    b++;
  }
  iF.close();

  ifstream iFile;
  iFile.open(argv[1]);
  string str;
  int i = 0;

  int arr[b];
  while(getline(iFile, str)){
    i = insertIntoSortedArray(arr, i, stoi(str));
    for(int j = 0; j < i; j++){
      if(j == i-1){
        cout << arr[j];
      } else {
        cout << arr[j] << ",";
      }
    }
    cout<< endl;
  }

  iFile.close();

  if(i == 0){
    cout << "Failed to open the file." <<endl;
  }
  return 1;
}
