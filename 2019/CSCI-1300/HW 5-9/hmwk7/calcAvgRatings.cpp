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
// Homework 7 - problem 5

//algorithm
// input title
// lowercase the title
// find match for title
// find ratings for that book
// find average of those ratings 
// return the average


double calcAverageRating(User users[], Book books[],int currentNumOfUsers, int currentNumOfBooks, string title){
    if(currentNumOfUsers == 0 || currentNumOfBooks == 0){
        return -3;
    }
    int bookIndex = 0;
    int rating = 0;
    double ratingTotal = 0;
    int amountOfRatings = 0;
    int bookCounter = 0;
    int notReadCounter = 0;
    for (int i = 0; i < title.length(); i++){ //lowercase the title
        title[i]=tolower(title[i]);
    }
    for (int i = 0; i < currentNumOfBooks; i++){
        string currentBook = books[i].getTitle();
        for (int j = 0; j < currentBook.length(); j++){ // lowercase the title in the array
            currentBook[j]=tolower(currentBook[j]);
        }
        if (currentBook == title){  // find a match
            bookIndex = i;
            bookCounter++;
            for (int i = 0; i < currentNumOfUsers; i++){
                if(users[i].getRatingAt(bookIndex)>0 && users[i].getRatingAt(bookIndex)<=5){ // if they rated the books
                    rating = users[i].getRatingAt(bookIndex);
                    ratingTotal = ratingTotal + rating; // add that rating to the total
                    rating = 0;
                    amountOfRatings++;
                }
                if (users[i].getRatingAt(bookIndex)==0){
                    notReadCounter++;
                    if (notReadCounter == currentNumOfUsers - 1){   // if no one read the book return 0
                        return 0;
                    }
                }
            }
        }
    }

    double average = ratingTotal/ amountOfRatings; // find average of the ratings and return the average
    if(bookCounter>0 && amountOfRatings>0){
    return average;
    }
    else {
        return -3;
    }
    

}





int main(){
    User users[100];
    Book books[50];
    string title = "jack";
int option1 = calcAverageRating(users,books, 0,0, title);
cout << option1 << endl;
int test2 = calcAverageRating(users,books,50,0,title);
cout << test2;
    
}