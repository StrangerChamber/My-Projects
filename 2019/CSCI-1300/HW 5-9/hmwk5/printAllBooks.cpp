#include <iostream>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 5 - Problem 3

// function takes in a file
// opens it
// reads it line by line
// populates two arrays, one with authors names, and the other with titles of the authors books
// then it outputs the titles and authors 

void printAllBooks(string titles[], string authors[], int numOfBooks){ //my print all books function that hasa no return value and 3 parameters 
    string line = "";
    if (numOfBooks<=0){                          // edge case for if number of books is zero or negative
        cout << "No books are stored" << endl;
    }
    else{        
        int i = 0;
        cout << "Here is a list of books" << endl;     // this else statement reads a file, opens it, reads it line by line populating two arrays one with the authors and another with titles
        ifstream myFile;
        myFile.open(titles[i]);
        while (getline(myFile,line)){
            for (int j = 0; j<numOfBooks;j++){     
                titles[i]=line;
            }

        }
        while(i<numOfBooks){
            cout << titles[i] << " by " << authors[i] << endl;       // loop that makes sure to include all the books and authors not just the first one 
            i++;
        }
    }
    
}
    




int main(){      // test cases
    
    
   // no books stored with numBooks 0
string book_Titles[] = {};
string book_Authors[] = {};
printAllBooks(book_Titles, book_Authors, 0);
cout << endl;
   // print three books
string book_titles[] = {"Calculus", "Algebra", "Physics"};
string book_authors[] = {"Gottfried Leibniz", "Alan Turing", "Isaac Newton"};
printAllBooks(book_titles, book_authors, 3);
    
}