#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Park {
  string parkname;
  string state;
  int area;
};

void addPark(Park parks[], string pn, string s, int a, int length){
  Park newPark;
  newPark.parkname = pn;
  newPark.state = s;
  newPark.area = a;
  parks[length] = newPark;
}

void printList(const Park parks[], int length){
  for(int i = 0; i < length; i++){
    cout << parks[i].parkname <<" [" << parks[i].state << "] area: "<< parks[i].area << endl;
  }
}

string strPark(Park p){
  return p.parkname + " [" + p.state + "] area: "+ to_string(p.area) + "\n";
}

int main(int argc, char const *argv[]){
    if(argc != 4){
      cout << "Please provide input file, output file, and a minimum area" << endl;
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

    int arrSize = b;
    Park arr[arrSize];
    Park nP;
    Park minPark[arrSize];
    int mArea = stoi(argv[3]);

    ifstream iFile;
    iFile.open(argv[1]);
    string str;
    int counter = 0;
    int c = 0;
    while(getline(iFile, str)){
      istringstream s(str);
      string tempArr[3];
      int k = 0;
      string token;
      while(getline(s, token, ',')) {
        tempArr[k] = token;
        k++;
      }
      addPark(arr, tempArr[0], tempArr[1], stoi(tempArr[2]), counter);
      if(stoi(tempArr[2]) >= mArea){
        addPark(minPark, tempArr[0], tempArr[1], stoi(tempArr[2]), c);
        c++;
      }
      counter++;
    }
    printList(arr, arrSize);

    ofstream oFile (argv[2]);
    for(int i = 0; i < c; i++){
        oFile << minPark[i].parkname << "," + minPark[i].state << "," << minPark[i].area <<"\n";
    }

    oFile.close();
    iFile.close();
    return 0;
	}
