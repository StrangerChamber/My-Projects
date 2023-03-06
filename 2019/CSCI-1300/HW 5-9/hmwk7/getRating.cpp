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
// Homework 7 - problem 3


//algorithm
// input title and user
// find match for user and title
// return users rating for that title


int getRating(string userName, string title, User users[], Book books[], int currentNumOfUsers, int currentNumOfBooks){
    if (currentNumOfUsers>0 &&currentNumOfBooks>0){  // set username to lowercase
    for (int i = 0; i < userName.length(); i++){
        userName[i]=tolower(userName[i]);
    }
    for (int i = 0; i < title.length(); i++){      // set title to lowercase
        title[i]=tolower(title[i]);
    }
    int userNameIndex = 0;
    int bookIndex = 0;
    int userCounter = 0;
    int bookCounter = 0;
    for (int i = 0; i < currentNumOfUsers;i++){
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){    // set user in array to lowercase
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName ){    // find match
             userNameIndex = i;       // store index
             userCounter++;
            break;
        }
        if (i == currentNumOfUsers){
            return -3;
         }    
    }
    
    for (int i = 0; i < currentNumOfBooks; i++){       // set title in array to lowercase
        string currentBook = books[i].getTitle();
        for (int j = 0; j < currentBook.length(); j++){
            currentBook[j]=tolower(currentBook[j]);
        }
        if(currentBook == title){    // find match
             bookIndex = i ;      // store index
            bookCounter++;
            break;
        }
        if (i==currentNumOfBooks){
            return -3;
        }
        
    }
        if(userCounter>0 && bookCounter > 0){     // if user and title exist return the users rating for that book
            return users[userNameIndex].getRatingAt(bookIndex);
        }
        else {
            return -3;
        }
    }
    else{
        return -3;
    }
}

int main(){       // test cases
    User users[100];
    Book books[50];
    string userName = "jack";
    string title = "jack";
    int option1 = getRating(userName, title, users, books, 0,0);
    cout << option1 << endl;
    int option2 = getRating(userName, title, users, books, 45,0);
    cout << option2;
}