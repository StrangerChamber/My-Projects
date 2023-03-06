#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 3,4,5,6,7



class Book              //heres my class Books
{
    private:    // private variables
    string title;
    string author;
    public:
    Book();          //Sets both title and author to empty strings
    Book(string, string);    // Takes two strings for initializing title and author, in this order
   //-----------------------
    string getTitle();       // Returns title as a string
    string getAuthor();       // Returns author as a string
    //------------------------
    void setTitle(string);   // Assigns title the value of the input string
    void setAuthor(string);   // Assigns author the value of the input string
    
};

#endif