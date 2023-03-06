#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "Book.h"
#include "Book.cpp"

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 4



int main(){
    // Test if you have read in the titles correctly
int numbooks = readBooks("minitest1.txt", books, 0, 50);

cout << "Function returned value: " << numbooks << endl;

// checking the elements in the arr
if(numbooks == 3)
{
     printArrTitle(books, numbooks);
}
else
{
     cout << "make sure your book count is correct" << endl;
}




// Test if you have read in the authors correctly
int numbooks = readBooks("minitest1.txt", books, 0, 50);

cout << "Function returned value: " << numbooks << endl;

// checking the elements in the arr
if(numbooks == 3){
     printArrAuthor(books, numbooks);
} else {
     cout << "make sure your book count is correct" << endl;
}
}