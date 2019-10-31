#include "RPNCalculator.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

RPNCalculator::RPNCalculator(){
  stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){
  stackHead = NULL;
}

bool RPNCalculator::isEmpty(){
  if(stackHead == NULL){
    return true;
  }
  return false;
}

void RPNCalculator::push(float num){
  Operand *temp = new Operand;
  temp->number = num;
  temp->next = stackHead;
  stackHead = temp;
}

void RPNCalculator::pop(){
  if(isEmpty()){
    cout << "Stack empty, cannot pop an item." << endl;
    return;
  } else {
    Operand *temp = stackHead;
    stackHead = stackHead->next;
    delete temp;
  }
}

Operand* RPNCalculator::peek(){
  if(stackHead == NULL){
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }
  return stackHead;
}

bool RPNCalculator::compute(std::string symbol){
  if(symbol.compare("*") != 0 && symbol.compare("+") !=0){
    cout << "err: invalid operation" << endl;
  } else if(stackHead != NULL && stackHead->next != NULL) {
    float x = peek()->number;
    pop();
    float y = peek()->number;
    pop();
    if(symbol.compare("*")==0){
      push(x*y);
    } else {
      push(x+y);
    }
  } else {
    cout << "err: not enough operands" << endl;
  }
}
