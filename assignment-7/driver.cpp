#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void menu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Print the inventory" << endl;
  cout << "2. Delete a movie" << endl;
  cout << "3. Quit" << endl;
}

void doS(MovieTree &mT){
  menu();
  int in;
	cin >> in;
  cin.ignore();
	if(in == 1){
    mT.printMovieInventory();
    doS(mT);
  } else if (in == 2){
    cout << "Enter a movie title:" << endl;
    string str;
    getline(cin, str);
    mT.deleteMovie(str);
    doS(mT);
  } else if (in == 3){
    cout << "Goodbye!" << endl;
    return;
  } else {
    cout << "Bad Monkey, try again" << endl;
    doS(mT);
  }
}

int main(int argc, char const *argv[])
{
  MovieTree mT;
  ifstream iF;
  iF.open(argv[1]);
  string s1;
  string arr[4];
  string str;
  int counter = 0;
  while(getline(iF, s1)){
    stringstream ss;
    ss << s1;
    while(getline(ss, str, ',')){
      arr[counter] = str;
      if(counter == 3){
        mT.addMovie(stoi(arr[0]), arr[1], stoi(arr[2]), stof(str));
        counter = 0;
      } else {
        counter++;
      }
    }
  }
  iF.close();
  doS(mT);
  return 0;
}
