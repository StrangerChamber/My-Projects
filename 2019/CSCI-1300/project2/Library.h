#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn   
// Recitation: Lucas Hayne
// Project 2 - Problem 1

class Library      // library class
{
    private:          // private variables
    int sizeBook;
    int sizeUser;
    Book books[50];
    User users[100];
    int numBooks;
    int numUsers;
    
    public:          // public member functions
    Library();
    int getSizeBook();
    int getSizeUser();
    int getNumBooks();
    int getNumUsers();
    
    int readBooks(string);
    void printAllBooks();
    void printBooksByAuthor(string);
    int readRatings(string);
    int getRating(string, string);
    int getCountReadBooks(string);
    void viewRatings(string, int);
    double calcAvgRating(string);
    double calcAvgRatingByAuthor(string);
    int addUser(string);
    int checkOutBook(string, string, int);
    void getRecommendations(string);
    
    
};
#endif