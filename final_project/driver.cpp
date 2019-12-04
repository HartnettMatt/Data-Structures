// Driver program
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include "hashLL.hpp"
#include "hashBST.hpp"
#include "hashLP.hpp"
#include "hashCC.hpp"
using namespace std;

int main()
{
  // File stream for data set A
  ifstream iFA;
  iFA.open("dataSetA.csv");
  string s;

  // Number to test with (gotten from data set A):
  int searchFor = 34047189;
  // Simple test code for the linked list implementation
  bool testingLL = false;
  if(testingLL){
    hashLL htLL;
    htLL.insertItem(searchFor);
    // Fill hash table with data set
    while(getline(iFA, s, ',')){
      htLL.insertItem(stoi(s));
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
    while(getline(iFA, s, ',')){
      htBST.insertItem(stoi(s));
    }
    cout<< "The first 100 elements of the BST hash table are:"<<endl;
    htBST.print100();

    cout<<endl;
    // Search test code:
    if(htBST.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }

    // Delete test code:
    if(htBST.deleteItem(searchFor)){
      cout<<searchFor<<" deleted from the hash table"<<endl;
      if(htBST.searchItem(searchFor))
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

  // Simple test code for the linear probing
  bool testingLP = true;
  if(testingLP){
    hashLP htLP;
    // Fill the array with data
    while(getline(iFA, s, ',')){
      htLP.insertItem(stoi(s));
    }
    cout<< "The first 100 elements of the LP hash table are:"<<endl;
    htLP.print100();

    cout << endl;
    // Search test code:
    if(htLP.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }

    // Delete test code:
    if(htLP.deleteItem(searchFor)){
      cout<<searchFor<<" deleted from the hash table"<<endl;
      if(htLP.searchItem(searchFor))
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

  // Simple test code for the cuckcoo collision resolving
  bool testingCC = false;
  if(testingCC){
    hashCC htCC;
    // Fill with data:
    while(getline(iFA, s, ',')){
      htCC.insertItem(stoi(s));
    }
    cout<< "The first 100 elements of the CC hash table are:"<<endl;
    htCC.print100();

    cout << endl;
    // Search test code:
    if(htCC.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }

    // Delete test code:
    if(htCC.deleteItem(searchFor)){
      cout<<searchFor<<" deleted from the hash table"<<endl;
      if(htCC.searchItem(searchFor))
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

  iFA.close();
  return 0;
}
