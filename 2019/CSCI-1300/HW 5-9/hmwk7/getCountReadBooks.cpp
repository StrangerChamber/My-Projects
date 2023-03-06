#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#include "User.h"
#include "Book.h"
#include "User.cpp"

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 7 - problem 4

// algorithm
// input a username
// find a match to a user in the array
// determine how many books that user has rated
// return that number

int getCountReadBooks(string userName, User users[],int currentNumOfUsers, int currentNumOfBooks){
    if(currentNumOfBooks == 0 || currentNumOfUsers == 0){
        return -3;
    }   
    int userNameIndex = 0;
    int counter = 0;
    int userNameCounter = 0;
    for (int i = 0; i < userName.length(); i++){       // this for loop makes everything in the username string lowercase
        userName[i]=tolower(userName[i]);
    }
    for (int i = 0; i < currentNumOfUsers;i++){          // this makes the users in the array lowercase as well
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName){   // finding a match of username to a user 
            userNameIndex = i;     // storing the index location
            userNameCounter++;
            break;
        }
    }
    for (int i = 0; i < currentNumOfBooks; i++){
        if(users[userNameIndex].getRatingAt(i)>0 && users[userNameIndex].getRatingAt(i)<=5){   // counting how many books the user has rated
            counter++;
        }
    }
    if(userNameCounter>0){
    return counter;     // returning the amoung of books the user has rated if its more than 0
    }
    else {
        return -3;
    }
}










int main(){ // test cases 
    
    string userName = "jack";
    User users[100];
    int option1 = getCountReadBooks(userName,users, 0, 0);
    cout << option1 << endl;
    int option2 = getCountReadBooks(userName,users,50,0);
    cout << option2;
}