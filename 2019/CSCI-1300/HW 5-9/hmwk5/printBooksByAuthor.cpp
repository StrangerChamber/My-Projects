#include <iostream>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 5 - Problem 4

// this function takes in a file
// determines whether an author name matches any books given in a string 
// prints the book title if the author name matches the title 

void printBooksByAuthor(string titles[], string authors[], int numofbooks, string authorName){      //function with no return value and 4 parameters
    ifstream file;
    int counter = 0;
    int i = 0;
    while (i<numofbooks){
        if(authors[i]==authorName){        // this while loop is for the edge case that there are no books by the authorName
            counter++;
            i++;
        }
        else{
            i++;
        }
    }
    if (counter == 0 && titles[i]!= ""){       // this if statement uses the counter from the previous loop to determine if the author has 0 books matching their name
        cout << "There are no books by " << authorName;
    }
    
    else {                   // this else statement matches the author and books 
    if (numofbooks<=0){
        cout << "No books are stored" << endl;      // if the number of books is zero or negative the function prints no books
    }
    else{
    string line = "";
    int i = 0;
    int matches = 0;
    cout << "Here is a list of books by " << authorName << endl;   
    while (i< numofbooks){
    if (authors[i]== authorName){       // this loop finds and prints the titles that match the author
    cout << titles[i] << endl;
    i++;
    }
    else {
        i++;
    }
    }
}
}
}


int main(){            // test cases
    // two books by author A
string book_titles[] = {"Book 1", "Book 2", "Book 3", "Book 4"};
string book_authors[] = {"Author A", "Author B", "Author C", "Author A"};;
int numberOfBooks = 4;
string author = "Author A";
printBooksByAuthor(book_titles, book_authors, numberOfBooks, author);
cout << endl;

// All the books by author A
string Book_titles[] = {"Book 1", "Book 2", "Book 3"};
string Book_authors[] = {"Author A", "Author A", "Author A"};
int NumberOfBooks = 3;
string Author = "Author A";
printBooksByAuthor(Book_titles, Book_authors, NumberOfBooks, Author);


}