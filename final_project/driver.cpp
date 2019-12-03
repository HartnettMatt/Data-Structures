// Driver program
#include<iostream>
#include <stdlib.h>
#include "hashLL.hpp"
#include "hashBST.hpp"
#include "hashLP.hpp"
using namespace std;

int main()
{
  // Simple test code for the linked list implementation
  bool testingLL = false;
  if(testingLL){
    hashLL htLL;
    int searchFor = 15;
    htLL.insertItem(searchFor);
    for(int i = 0; i < 10109; i++){
      htLL.insertItem(rand());
    }
    cout<< "The first 100 elements of the LL hash table are:"<<endl;
    htLL.print100();

    cout<<endl;
    // Search test code:
    if(htLL.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }

    // Delete test code:
    if(htLL.deleteItem(searchFor)){
      cout<<searchFor<<" deleted from the hash table"<<endl;
      if(htLL.searchItem(searchFor))
       {
         cout<<searchFor<<" found in the hash table"<<endl;
       }
      else{
        cout<<searchFor<<" not found in the hash table"<<endl;
      }
    } else {
      cout<<searchFor<<" not deleted from the hash table"<<endl;
    }
    cout << endl;
    cout << "============================\n" << endl;
  }

  // Simple test code for the BST implementation
  bool testingBST = false;
  if(testingBST){
    hashBST htBST;
    htBST.insertItem(15);
    for(int i = 0; i < 10109; i++){
      htBST.insertItem(rand());
    }
    cout<< "The first 100 elements of the BST hash table are:"<<endl;
    htBST.print100();

    cout<<endl;
    // Search test code:
    if(htBST.searchItem(15) != nullptr){
      cout << "Found 15 in BST Hash Table" << endl;
    } else {
      cout << "15 not found in BST Hash Table" << endl;
    }

    // Delete test code:
    if(htBST.deleteItem(15)){
      cout<<"15 deleted from the hash table"<<endl;
      if(htBST.searchItem(15))
       {
         cout<<"15 found in the hash table"<<endl;
         htBST.print100();
       }
      else{
        cout<<"15 not found in the hash table"<<endl;
      }
    } else {
      cout<<"15 not deleted from the hash table"<<endl;
    }
    cout << endl;
    cout << "============================\n" << endl;
  }

  // Simple test code for the linear probing
  bool testingLP = false;
  if(testingLP){
    hashLP htLP;
    // Linear probing test:
    htLP.insertItem(15);
    htLP.insertItem(16);
    htLP.insertItem(16);
    htLP.insertItem(17);
    // Fill the array with random integers
    for(int i = 0; i < 10005; i++){
      htLP.insertItem(rand());
    }
    cout<< "The first 100 elements of the LL hash table are:"<<endl;
    htLP.print100();

    cout << endl;
    // Search test code:
    if(htLP.searchItem(15) != -1){
      cout << "Found 15 in LP Hash Table" << endl;
    } else {
      cout << "15 not found in LP Hash Table" << endl;
    }

    // Delete test code:
    if(htLP.deleteItem(15)){
      cout<<"15 deleted from the hash table"<<endl;
      if(htLP.searchItem(15) != -1)
       {
         cout<<"15 found in the hash table"<<endl;
         htLP.print100();
       }
      else{
        cout<<"15 not found in the hash table"<<endl;
      }
    } else {
      cout<<"15 not deleted from the hash table"<<endl;
    }
    cout << endl;
    cout << "============================\n" << endl;
  }
  return 0;
}
