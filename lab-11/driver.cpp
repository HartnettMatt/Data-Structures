// Driver program
#include<iostream>
#include "hash.hpp"
using namespace std;

// GOLD TODO Complete this function
void printPairs(int* arr, int size, int sum, HashTable ht){

  for(int i = 0; i < size; i++){
    if(sum >= arr[i] && ht.searchItem(sum-arr[i]) != nullptr){
      cout << ht.searchItem(sum-arr[i])->key  << " + " << arr[i] << " = " << sum << endl;
      return;
    }
  }
  cout << "pair not found" << endl;
}

int main()
{
    int a[] = {15, 11, 27, 8, 12, 7, 18};
    int n = 7;

    // 7 is count of buckets in hash table
    HashTable ht(7);
    // insert the keys into the hash table.
    for (int i = 0; i < n; i++) {
        ht.insertItem(a[i]);
    }

    cout<< "Contents of the hash table are"<<endl;
    ht.printTable();

    cout<<endl;

    int searchFor = 15;
    if(ht.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }
    cout<<"------------------------------------"<<endl;

    int sum = 19;
    //
    // // GOLD TODO Complete printPairs() function
    printPairs(a,n,sum,ht);

    return 0;
}
