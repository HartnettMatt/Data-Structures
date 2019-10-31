#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Enqueue 20 things, dequeue 10, enqeue 10" << endl;
  ProducerConsumer pc;
  for(int i=0; i<20; i++)
      pc.enqueue("aaa");
  cout << "here1" << endl;
  for(int i=0; i<10; i++)
      pc.dequeue();
  cout << "here2" << endl;
  for(int i=0; i<10; i++)
      pc.enqueue("bbb");
  cout << "here3" << endl;
  cout << "Queue front index: " << pc.getQueueFront() << endl;
  cout << "Queue back index: " << pc.getQueueEnd() << endl;
  string full = pc.isFull() ? "true" : "false";
  cout << "Queue is full? " << full << endl;
}
