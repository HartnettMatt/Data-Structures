#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
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



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n){
  if(n <= 0){
    cout << "You said this wouldn't happen!";
    return;
  }
  Node* temp = head;
  Node* prev;
  int c = 0;
  // Count the number of items in the array in order to properly iterate to the correct node to delete
  while(temp != nullptr){
    c++;
    temp = temp->next;
  }
// Reset the temperary pointer so as it re-use it, and create a prev pointer to repair the LL after deletion
  temp = head;
  prev = nullptr;
// If c-n == 0, then the user is deleting the head node, which is a special case and needs to be handled differently
  if(c-n == 0){
    head = head->next;
    delete temp;
    return;
  }
  // Iterate to the correct node so that temp is the node to delete and prev is the node before it
  for(int i = 0; i < c-n; i++){
    prev = temp;
    temp = temp->next;
  }
  // Repair and delete
  prev->next = temp->next;
  delete temp;
}
