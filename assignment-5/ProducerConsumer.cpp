#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

ProducerConsumer::ProducerConsumer(){
  queueFront = 0;
  queueEnd= 0;
}

bool ProducerConsumer::isEmpty(){
  return queueFront == queueEnd;
}

bool ProducerConsumer::isFull(){
  return ((queueEnd == 20 && queueFront == 0) || (queueEnd == queueFront-1));
}

void ProducerConsumer::enqueue(std::string item){
  if(!isFull()){
    if(queueEnd == 20){
      queueEnd = 0;
    }
    queue[queueEnd] = item;
    queueEnd++;
  } else {
    cout << "Queue full, cannot add new item" << endl;
  }

}

void ProducerConsumer::dequeue(){
  if(isEmpty()){
    cout << "Queue empty, cannot dequeue an item" << endl;
  } else {
    queueFront++;
    if(queueFront == 20){
      queueFront = 0;
    }
  }
}

string ProducerConsumer::peek(){
  if(isEmpty()){
    cout << "Queue empty, cannot peek" << endl;
  }
  return queue[queueFront];
}

int ProducerConsumer::queueSize(){
  if(queueEnd-queueFront >= 0){
    return queueEnd-queueFront;
  } else {
    return 20 + queueEnd-queueFront;
  }
}
