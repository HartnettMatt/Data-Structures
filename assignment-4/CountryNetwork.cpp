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

void CountryNetwork::deleteEntireNetwork(){
  if(head == nullptr){
    return;
  }
  Country* crawler = head;
  Country* temp;
  while(crawler != nullptr){
    cout << "deleting: " << crawler->name << endl;
    temp = crawler;
    crawler = crawler->next;
    delete temp;
  }
  head = nullptr;
  cout << "Deleted network" << endl;
}

bool CountryNetwork::isEmpty(){
  if(head == nullptr){
    return true;
  } else {
    return false;
  }
}

void CountryNetwork::rotateNetwork(int n){
  Country* crawl = head;
  int c = 0;
  while(crawl != nullptr){
    c++;
    crawl = crawl->next;
  }
  if(head == nullptr){
    cout << "Linked List is Empty" << endl;
    return;
  } else if(n < 1 || n > c){
    cout << "Rotate not possible" << endl;
    return;
  } else {
    for(int i = 0; i < n; i++){
      Country *temp = head->next;
      Country* crawler = head;
      while(crawler->next != nullptr){
        crawler = crawler->next;
      }
      crawler->next = head;
      head->next = nullptr;
      head = temp;
    }
    cout << "Rotate Complete" << endl;
  }
}

void CountryNetwork::deleteCountry(string countryName){
  if(searchNetwork(countryName) == nullptr){
    cout << "Country does not exist." << endl;
    return;
  }
  if(head->name.compare(countryName) == 0){
    Country *temp = head->next;
    delete head;
    head = temp;
    return;
  }
  Country* crawler = head;
  while(crawler != nullptr && crawler->next->name.compare(countryName) != 0){
    crawler = crawler->next;
  }
  if(crawler != nullptr){
    Country *temp = crawler->next;
    crawler->next = crawler->next->next;
    delete temp;
  }
}

void CountryNetwork::reverseEntireNetwork(){
  if(head == nullptr){
    return;
  }
  Country *crawl = head;
  Country *next = head -> next;
  Country *prev = nullptr;
  while(next != nullptr){
    crawl->next = prev;
    prev = crawl;
    crawl = next;
    next = crawl->next;
  }
  crawl->next = prev;
  head = crawl;
}
