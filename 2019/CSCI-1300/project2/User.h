#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 7 - 1


class User{               // my user class
    private:     // private variables
   
    int size;         
    string userName;
    int numRatings;
    int ratings[50];

    public: // member functions
   
    User();      //constructor
    User(string newUserName, int newRatings[], int newNumRatings);      // parameterized constructor
    
    string getUsername();           // get username function
    int getNumRatings();         // get numratings function
    int getSize();            // get size
    int getRatingAt(int);       // get rating at a location
    
    void setUsername(string);      // mutator for username
    bool setRatingAt(int,int);    // mutator for ratings
    void setNumRatings(int);     // mutator for num ratings
};
#endif