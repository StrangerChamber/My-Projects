#include "RPNCalculator.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

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
  RPNCalculator calc;
  string input;
  int counter = 0;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(counter == 0)
  {
    cout << "#> ";
    getline(cin, input);
    if(isNumber(input) == true){
      calc.push(stof(input));      
    }
    else if (input == "="){
      counter++;
      break;
    }
    else{
      calc.compute(input);
    }
  }
  if(calc.isEmpty() == true){
    cout << "No operands: Nothing to evaluate"<< endl;
    return 0;
  }
  else{
    Operand* help = calc.peek();
    float helper = help->number;
    calc.pop();
    if(calc.isEmpty()== true){
      cout << setprecision(4) << helper << endl;
    }
    else{
      cout << "Invalid expression" << endl;
      return 0;
    }
  }
  return 0;
}