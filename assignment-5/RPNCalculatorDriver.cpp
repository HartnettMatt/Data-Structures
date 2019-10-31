/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator calc;
  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;
  bool nonE = true;
  while(nonE)
  {
    cout << "#> ";
    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */
    string in;
    getline(cin, in);

    if(in.compare("=") == 0){
      nonE = false;
      if(calc.getStackHead() == NULL){
        cout << "No operands: Nothing to evaluate" << endl;
      } else if(calc.getStackHead()->next == NULL){
        cout << calc.peek()->number << endl;
      } else {
        cout << "Invalid expression" << endl;
      }
    } else if(in.compare("+") == 0 || in.compare("*") == 0){
        calc.compute(in);
    } else if(!isNumber(in)){
      cout << "Enter a valid operand" << endl;
    } else {
      calc.push(stof(in));
    }
  }

  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */

  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/

  return 0;
}
