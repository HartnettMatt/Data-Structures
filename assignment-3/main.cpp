/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

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
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
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
    cout << "Enter name of the country to receive the message:" << endl;
    string c;
    cin.ignore();
    getline(cin, c);

    cout << "Enter the message to send:"<< endl;
    string msg;
    getline(cin, msg);

    CountryNet.transmitMsg(c, msg);
  } else if (in == 4){
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

  } else if (in == 5){
    cout << "Quitting...\nGoodbye!" << endl;
    return;
  } else {
    cout << "Chose a valid option" << endl;
  }
  doShit(CountryNet);
}
