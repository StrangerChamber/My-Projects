#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 9 - Problem 1

// algorithm
// input number
// if input number is 1 or 0 return a string of 1 or 0 respectively
// if num isn't 1 or 0 we go into a loop
// the loop runs until num is equal to 0
// the input num is divided by 2 and the remainder is stored
// then the number is split in half
// then the remainder is input into a string 
// this continues until the number is equal to zero
// then returns the string of the stored remainders in order from the last remainder to the first
string decimalToBinaryIterative(int num){
    int remain;     // remainder variable
    string together = ""; // string that will create my binary number
    if (num == 1){  // checking if the input number is one
        return "1";
    }
    if (num==0){ // cjecking if the input number is zero
        return "0";
    }
    while(num!=0){ // loop to translate the input number into binary form
        remain = num%2; // remainder equation
        num = num/2; // splitting the number
        together = to_string(remain) + together; // storing the remainders as a string
    }
   return together; // returning my string of remainders which is also the number input in binary
}


int main(){
    cout << decimalToBinaryIterative(8) << endl; // test case 1
    cout << decimalToBinaryIterative(9); // test case 2
}