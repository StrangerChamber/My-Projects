#include <iostream>
#include <cmath>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: lucas Hayne
// Homework 4 - Problem 5 




int getWordCount(string sentence){      // function counts the words in a given array
    if (sentence == ""){
        return 0;
    }
    int match = 0;
    for (int i = 0; i<sentence.length();i++){       // everytime a space is found in the string a word is added
        if (sentence.substr(i,1) == " "){
            match++;
        }
    }
    return match + 1;
}



int main(){
    getWordCount("");
    
getWordCount("I cannot take this anymore");
}