/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu() {
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
  cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
void doS(ProducerConsumer pC) {
	menu();
	int in;
	cin >> in;
	if(in == 1){
		cout << "Enter the number of items to be produced:" << endl;
		int g;
		string s;
		cin >> g;
		cin.ignore();
		for(int i = 1; i <= g; i++){
			cout << "Item" << i << ":" << endl;
			getline(cin, s);
			pC.enqueue(s);
		}
		doS(pC);
	} else if(in == 2){
		cout << "Enter the number of items to be consumed:" << endl;
		int g;
		cin >> g;
		for(int i = 0; i < g; i++){
			if(pC.queueSize() != 0){
				cout << "Consumed: " << pC.peek() << endl;
				pC.dequeue();
			} else {
				cout << "No more items to consume from queue" << endl;
				i = g;
			}
		}
		doS(pC);
	} else if(in == 3){
		cout << "Number of items in the queue:" << pC.queueSize() << endl;
	}
}

int main(int argc, char const *argv[]) {
	ProducerConsumer pC;
	doS(pC);
}
