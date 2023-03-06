#include <iostream>
#include <math.h>
using namespace std;

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: f19- Lucas
// Project 1 - Problem 2 


int countMatches(string s, string p){                 // setting up the parameters for my finction with two strings
    
   int matches = 0;
   
     for (int i = 0; i<= s.length()-p.length(); i++){              // a for loop that will give me my matches 
         if (s.substr(i,p.length())== p) matches ++;
    }
    if (p == "" || s == ""){                            // if statement that returns -1 if either string is empty
    return -1;
    }
    return matches;
     }





int main(){
    cout << countMatches(,);
}