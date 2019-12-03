// Driver program
#include<iostream>
#include <stdlib.h>
#include "hashLL.hpp"
#include "hashBST.hpp"
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

    if(htLL.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }

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
  bool testingBST = true;
  if(testingBST){
    hashBST htBST;
    htBST.insertItem(15);
    for(int i = 0; i < 10109; i++){
      htBST.insertItem(rand());
    }
    cout<< "The first 100 elements of the BST hash table are:"<<endl;
    htBST.print100();

    cout<<endl;

    if(htBST.searchItem(15) != nullptr){
      cout << "Found 15 in BST Hash Table" << endl;
    } else {
      cout << "15 not found in BST Hash Table" << endl;
    }
  }
}
