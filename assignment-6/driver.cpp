#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void menu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;
}

void doS(MovieTree &mT){
  menu();
  int in;
	cin >> in;
  cin.ignore();
	if(in == 1){
    cout << "Enter title:" << endl;
    string s;
    getline(cin, s);
    mT.findMovie(s);
    doS(mT);
  } else if (in == 2){
    cout << "Enter minimum rating:" << endl;
    float r;
    cin >> r;
    cin.ignore();
    cout << "Enter minimum year:" << endl;
    int y;
    cin >> y;
    cin.ignore();
    mT.queryMovies(r, y);
    doS(mT);
  } else if (in == 3){
    mT.printMovieInventory();
    doS(mT);
  } else if (in == 4){
    mT.averageRating();
    doS(mT);
  } else if (in == 5){
    cout << "Goodbye!" << endl;
    return;
  } else {
    cout << "Bad Monkey, try again" << endl;
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
        mT.addMovieNode(stoi(arr[0]), arr[1], stoi(arr[2]), stof(str));
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
