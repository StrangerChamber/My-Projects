#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#include "User.h"
#include "Book.h"


// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 7 - 1


Book::Book(){     // this is my constructor for the books class; it initializes my private variables as empty strings
    title = "";
    author = "";
}

Book::Book(string newTitle, string newAuthor){     // parameterized constructor that takes the initialization of my varaibles and sets them to whatever is input into the function
    title = newTitle;
    author = newAuthor;
}

string Book::getTitle(){      // accessor function returning title
    return title;
}

string Book::getAuthor(){        // accessor returning author
    return author;
}

void Book::setTitle(string newTitle){        // mutator function setting a new title
    title = newTitle;
}

void Book::setAuthor(string newAuthor){      // mutator setting the new author 
    author = newAuthor;
}





User::User(){      /// constructor setting my variables to 0
    const int size = 50;
    string userName = "";
    int numRatings = 0;
    int i = 0;
    for(int i = 0;i<50; i++){
     ratings[i] = 0;
    }
    
}

User:: User(string newUserName, int newRatings[], int newNumRatings){     //parameterized constructor to input values into the variables
    userName = newUserName;
    if (newNumRatings<=50){
        numRatings = newNumRatings;
    }
    for (int i = 0;i<numRatings;i++){
    ratings[i] = newRatings[i];
    }
    for(int i = numRatings; i<50; i++){
        ratings[i]=0;
    }
}

string User:: getUsername(){   // get username function
    return userName;
}

int User:: getNumRatings(){  // get num ratings
    return numRatings;
}

int User:: getSize(){    // get size
    return size;
}

int User:: getRatingAt(int indexLocation){      // get ratings at function
    if(indexLocation<0 || indexLocation>=50){
        return -1;
    }
    else{
    return ratings[indexLocation];
    }
}

void User:: setUsername(string newUser){ //set a new username
    userName = newUser;
}

void User:: setNumRatings(int newNum){ // set a numrating
    numRatings = newNum;
}

bool User:: setRatingAt(int index, int value){  // set rating at
    if(value>=0 && value<=5 && index<50){    
    ratings[index] = value;

        return 1;
    }
    else {
        return 0;
    }
}

int split(string str, char c, string array[], int size){
    if (str.length()== 0){
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i<str.length(); i++){
        if (str[i]==c){
            if (word.length() == 0) {
                continue;
            }
            array[j++]= word;
            word = "";
        }
        else {
            word = word + str[i];
        }
        
    }
    return j;
}     //split function recycled

//algorithm
//input a file
// split the file into users and ratings 
// fill an array with usernames and ratings based on the file input
// return number of rows filled 
int readRatings(string filename, User users[],int numUsersStored, int UsersArrSize, int maxColumns){
    ifstream inFile;
    inFile.open(filename);  // open file
    string line = ""; // dummy string for getline
    int i = numUsersStored; // my increment for number of rows used within the while loop
    string array[101]; // dummy array for split function
    if (numUsersStored==UsersArrSize){ // edge case for if number of users is equal to maximum number of rows
        return -2;
    }    
    
    if(inFile.is_open()){ // if the file is open
        while(getline(inFile,line)){ //while the function is reading the file line by line
            if (line != "" ){ // if the line isnt epmty
                int num = split(line, ',', array, 101); // split the line by comma
                users[i].setUsername(array[0]);// users of my incremental variable is equal to the first value of the array
                for (int j = 1 ; j < num; j++){ // for loop to fill each column of each row one row at a time
                    users[i].setRatingAt(j-1,stoi(array[j])); // storing my ratings
                }
                i++;
            }
            if (i == UsersArrSize){ // edge case if i reaches the maximum number of rows the function returns i
                return i;
            }

        }    
    }
    else {// for if the file cannot be open
        return -1;
    }
    return i; // return my incremental variable
}





