#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }

bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
    if (n == 0) {
        Node *temp = head->next;
        delete head;
        head = temp;
        return true;
    }

  Node *crawler = head;

  for(int i = 0; i < n-1; i++){
    crawler = crawler->next;
  }
  Node *ptr = crawler->next;
  crawler->next = crawler->next->next;
  delete ptr;
  return true;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    // TODO
    Node *crawler = head;
    Node *last;
    Node *temp;
    Node *secondTolast;
    int counter = 0;

    // Find final node:
    while(crawler->next != nullptr){
      crawler = crawler->next;
      counter++;
    }
    last = crawler;

    // Find the secondTolast Node:
    secondTolast = head;
    for(int i = 0; i < counter-1; i++){
      secondTolast = secondTolast->next;
    }

    // Swap the first and last node:
    crawler = head;
    temp = head->next;
    head = last;
    last = crawler;

    // Swapped, now repairing:

    head->next = temp;
    last->next = nullptr;
    secondTolast->next = last;
    isSwapped = true;
    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
