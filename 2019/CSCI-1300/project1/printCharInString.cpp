#include <iostream>
#include <math.h>
using namespace std;

// CS1300 Fall 2019
// Author: JAck Blackburn
// Recitation: f19 – Lucas Haynes
// Project 1 - Problem 1 


int printCharInString(string s){               // this is my function 
    if (s==""){                            // condition for an empty string to output "given string is empty"
    cout << "Given string is empty!"; 
    }
    for (int i = 0; i< s.length() ; i++){    // this sets up a loop that will print each character one by one on their own line 
        cout << s[i]<< endl;
    }
    
}

string mon;                // declaring my string for the test case

int main(){
  cout <<  printCharInString(mon);  // test case for my function
}