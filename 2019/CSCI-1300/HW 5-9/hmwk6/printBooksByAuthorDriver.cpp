#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "Book.h"
#include "Book.cpp"

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 6




int main(){
 // All the books by author A
Book book1 = Book("Book 1", "Author A");
Book book2 = Book("Book 2", "Author A");
Book book3 = Book("Book 3", "Author A");
Book listOfBooks[] = {book1, book2, book3};
int numberOfBooks = 3;
string author = "Author A";
printBooksByAuthor(listOfBooks, numberOfBooks, author);

// No books by author A
Book book1 = Book("Book 1", "Author B");
Book book2 = Book("Book 2", "Author C");
Book book3 = Book("Book 3", "Author D");
Book listOfBooks[] = {book1, book2, book3};
int numberOfBooks = 3;
string author = "Author A";
printBooksByAuthor(listOfBooks, numberOfBooks, author);
}