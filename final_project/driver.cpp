// Driver program
#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h>
#include <chrono>
#include <vector>
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
  bool testingLL = true;
  if(testingLL){
    ofstream oFA;
    oFA.open("outputfile.txt");
    int *counts[40000];
    for(int i = 0; i < 40000; i++){
      counts[i] = 0;
    }
    hashLL htLL;
    htLL.insertItem(searchFor);
    // Fill hash table with data set
    while(getline(iFA, s, ',')){
      htLL.insertItem(stoi(s));
      counts[htLL.hashFunction(stoi(s))]++;
    }
    for(int i = 0; i < 40000; i++){
      oFA << i << "\t" << counts[i] << endl;
    }
    cout<< "The first 100 elements of the LL hash table are:"<<endl;
    // htLL.print100();

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
  bool testingLP = false;
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
    float load = .6;
    int dataCount;
    while(dataCount < load*10009 && getline(iFA, s, ',')){
      htCC.insertItem(stoi(s));
      dataCount++;
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

  // Code to time the hash tables
  bool timing = false;
  if(timing){

    // Loop to test different load factors
    for(float load = 0.1; load < 1.0; load += .1){
      iFA.close();
      iFA.open("dataSetA.csv");
      // build a full array out of the test values
      vector <int> arr;
      int i = 0;
      while(getline(iFA, s, ',')){
        arr.push_back(stoi(s));
        i++;
      }
      // These arrays are needed for timing of insert search and delete
      vector<int> insertArr, searchArr, deleteArr;
      hashLL htLL;

      // Loop to fill the hash table with random values from the test data
      for(int j = 0; j < (int)(10009*load)+100; j++){
        int index, item, counter;

        // Loop to find random values that haven't been used yet
        if(arr.size() == 0){
          cout << "empty array" << endl;
        }
        do{
          index = rand()%(arr.size()-1);
          item = arr[index];
        } while (item == -1);


        // After random value is found, add to the main array or add to the insert array
        if(j < (int)(10009*load)){
          htLL.insertItem(item);
          arr[index] = -1;
          // Add 100 values to the search and delete arrays
          if(counter < 100){
            searchArr.push_back(item);
            deleteArr.push_back(item);
            counter++;
          }
        } else {
          insertArr.push_back(item);
        }
      }

      // Output file for moving the data into google sheets
      ofstream oFS;
      oFS.open("outputfile.txt");
      float outArr[9][100];
      // Now that the hash table has the load factors worth of values, can actually test the three methods:
      float timeTotal = 0;
      std::chrono::time_point<std::chrono::system_clock> startTime, endTime;

      cout << "\n" << "Load factor: " << load << endl;

      // Test 100 of specific function
      for(int k = 0; k < 100; k++){
        typedef std::chrono::high_resolution_clock Time;
        typedef std::chrono::nanoseconds ns;
        typedef std::chrono::duration<float> fsec;
        htLL.insertItem(insertArr[k]);
        auto t0 = Time::now();
        // This is the actual function being tested:
        htLL.deleteItem(insertArr[k]);
        auto t1 = Time::now();
        fsec fs = t1 - t0;
        ns d = std::chrono::duration_cast<ns>(fs);
        // std::cout << fs.count() << "\n";
        timeTotal += fs.count();
        // Add to the output array
        outArr[(int)(load*10)-1][k] = fs.count();
      }
      cout << "Average time: " << timeTotal/100 << endl;
      // Send output array to output File
      for(int f = 0; f < 100; f++){
        for(int y = 0; y < 9; y++){
          oFS << outArr[y][f] << "\t";
        }
        oFS << "\n";
      }
    }
    cout << endl;
  }

  iFA.close();

  return 0;
}
