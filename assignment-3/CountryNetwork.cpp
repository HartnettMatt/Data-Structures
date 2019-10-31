/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
  head = nullptr;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */

void CountryNetwork::insertCountry(Country* previous, string countryName)
{
  cout << "adding: " << countryName<< " (";
  if(head == nullptr){
    head = new Country;
    head->name = countryName;
    head->next = nullptr;
    cout << "HEAD)" << endl;
  } else if(previous == nullptr){
    Country *nC = new Country;
    nC->name = countryName;
    nC->next = head;
    head = nC;
    cout << "HEAD)" << endl;
  } else {
    Country *nC= new Country;
    nC->name = countryName;
    nC->next = previous->next;
    previous->next = nC;
    cout << "prev: " << previous->name << ")" << endl;
  }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
  insertCountry(nullptr, "United States");
  insertCountry(searchNetwork("United States"), "Canada");
  insertCountry(searchNetwork("Canada"), "Brazil");
  insertCountry(searchNetwork("Brazil"), "India");
  insertCountry(searchNetwork("India"), "China");
  insertCountry(searchNetwork("China"), "Australia");
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
  Country* crawler = head;
  while(crawler != nullptr && crawler->name.compare(countryName) != 0){
    crawler = crawler->next;
  }
  return crawler;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
  if(head == nullptr){
    cout << "Empty list\n" << endl;
    return;
  }
  if(searchNetwork(receiver) == NULL){
    cout << "Country not found" << endl;
    return;
  }
  Country *crawler = new Country;
  crawler = head;
  while(crawler != nullptr && crawler->name.compare(receiver) != 0){
    crawler->numberMessages++;
    crawler->message = message;
    cout << crawler->name << " [# messages received: " <<
    crawler->numberMessages << "] received: " << crawler->message << endl;
    crawler = crawler->next;
  }
  if(crawler != nullptr && crawler->name.compare(receiver) == 0){
    crawler->numberMessages++;
    crawler->message = message;
    cout << crawler->name << " [# messages received: " <<
    crawler->numberMessages << "] received: " << crawler->message << endl;
    return;
  }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  cout << "== CURRENT PATH ==" << endl;
  if(head != nullptr){
    Country* crawler = head;
    while(crawler != nullptr){
      cout << crawler->name << " -> ";
      crawler = crawler->next;
    }
    cout << "NULL" << endl;
  } else {
    cout << "nothing in path" << endl;
  }

  cout <<"===" << endl;
}
