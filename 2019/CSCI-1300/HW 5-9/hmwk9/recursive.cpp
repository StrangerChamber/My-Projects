#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 9 - Problem 2


//algorithm
// input a number(integer)
// check if number is equal to zero
// if so return the string "0"
//otherwise return as a string the number modulated by 2 plus 10 multiplied by the function with the number divided by 2 in the parameters
// this continues until the input number is zero
// then it returns the input number in binary as a string
string decimalToBinaryRecursive(int num){
    if (num == 0){// check if zero this is the only way the function ends
        return "0";
    }
    else{
        return to_string(num % 2 + 10*stoi(decimalToBinaryRecursive(num/2))); // recursion used to return a string that represents the input number in binary
    }
}


int main(){
    cout << decimalToBinaryRecursive(1);// test case 1
    cout << endl << decimalToBinaryRecursive(37); // test case 2
}