#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#include "User.h"
#include "User.cpp"
#include "Book.h"



// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 7 - problem 2



int main(){ //test cases
    
    string fileName = "ratings.txt";
    User users[100];
    int option1 = readRatings(fileName, users, 0,100,50);
    cout << option1<<endl;
    int option2 = readRatings(fileName, users, 50, 100, 50);
    cout << option2;
}
