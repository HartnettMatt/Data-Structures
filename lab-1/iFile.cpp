#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;
int main ()
{
  char str[ 10 ];
  ifstream iFile;
  iFile.open("filename.txt");
  string str1;
  if (!iFile) {
        cout << "Unable to open file" << endl;;
        exit(1); // terminate with error
    }

    while (iFile >> str1) {
        cout << str1 << endl;
    }
  // iFile>> str;
  // cout << str << "\n" ;
  // cin.get();
  iFile.close();
  return 0;
}
