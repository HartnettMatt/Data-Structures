/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed
using namespace std;
// declarations for main helper-functions
void displayMenu();
void doShit(CountryNetwork CountryNet);
string getS();

int main()
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    doShit(CountryNet);
}

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network " << endl;
    cout << " 6. Rotate Network " << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

string getS(){
  string str;
  cin.ignore();
  getline(cin, str);
  return str;
}

void doShit(CountryNetwork CountryNet){
  displayMenu();
  bool flag = true;
  int in;
  cin >> in;
  if(in == 1){
    CountryNet.loadDefaultSetup();
    CountryNet.printPath();
  } else if (in == 2){
    CountryNet.printPath();
  } else if (in == 3){
    cout << "Enter a new country name:" << endl;
    string c = getS();

    cout << "Enter the previous country name (or First):" << endl;
    string p;
    getline(cin, p);

    while(flag){
      if(p.compare("First") == 0){
        flag = false;
        CountryNet.insertCountry(nullptr, c);
        CountryNet.printPath();

      }
      else {
        Country *pPtr;
        if(CountryNet.searchNetwork(p) != NULL){
          flag = false;
          pPtr = CountryNet.searchNetwork(p);
          CountryNet.insertCountry(pPtr, c);
          CountryNet.printPath();
        }
      }
      if(flag){
        cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
        getline(cin, p);
      }
    }
  } else if (in == 4){
    cout << "Enter a country name:" << endl;
    string c = getS();
    CountryNet.deleteCountry(c);
    CountryNet.printPath();
  }  else if (in == 5){
    CountryNet.reverseEntireNetwork();
    CountryNet.printPath();
  }  else if (in == 6){
    cout << "Enter the count of values to be rotated:" << endl;
    string c = getS();
    CountryNet.rotateNetwork(stoi(c));
    CountryNet.printPath();
  }  else if (in == 7){
    cout << "Network before deletion" << endl;
    CountryNet.printPath();
    CountryNet.deleteEntireNetwork();
    cout << "Network after deletion" << endl;
    CountryNet.printPath();
  } else if (in == 8){
    cout << "Quitting... cleaning up path: " << endl;
    CountryNet.printPath();
    CountryNet.deleteEntireNetwork();
    if(CountryNet.isEmpty()){
      cout << "Path cleaned" << endl;
    } else {
      cout << "Error: Path NOT cleaned" << endl;
    }
    cout << "Goodbye!" << endl;
    return;
  } else {
    cout << "Chose a valid option" << endl;
  }
  doShit(CountryNet);
}
