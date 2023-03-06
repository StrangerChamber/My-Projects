#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#include "Book.h"

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 3,4,5,6



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
}    // this is my split function I've recycled from previous homeworks it is totally unchanged

int readBooks(string filename, Book books[], int numBooksStored, int booksArrSize){      // my read books function largely unchanged except for where i'm storing the information that is split          
    ifstream myFile;
    int i = numBooksStored;    // this variable is my counter and it starts at whatever the numBpokStored variable is
    myFile.open(filename);     // opening my file
    string line ="";      
    string arr[2];    // dummy array used in my split function
    if(myFile.is_open()){     // this if is important for the edge case of an unexistent file
        while(getline(myFile,line)){     // while the function is reading the file
            if (line != "" && i<booksArrSize){    // this if is for splitting the line and then filling my arrays until i reaches size
                split(line,',', arr ,2);
                books[i].setAuthor(arr[0]);       // this is where the book class comes into play; Im using my set author function to store the author name from arr 0 into books 0
                books[i].setTitle(arr[1]);         // using set title function to store arr 1 into my books array
                i++;
            }


            if (numBooksStored == booksArrSize){ //if the number of books stored is equal to size the fuinction returns -2
                return -2;
            }
        
            else {
                continue;
            }

        }
    }
    else {      // this is for if my file cannot be opened 
        return -1;
    }
    return i;   // returning the amount of arrays filled
}


void printAllBooks(Book books[], int numOfBooks){ //my print all books function that has no return value and 2 parameters an array books and numofbooks stored
    string line = "";
    if (numOfBooks<=0){                          // edge case for if number of books is zero or negative
        cout << "No books are stored" << endl;
    }
    else{        
        int i = 0;
        cout << "Here is a list of books" << endl;     // this else statement reads a file, opens it, reads it line by line populating two arrays one with the authors and another with titles
        ifstream myFile;
        myFile.open("i");
        while (getline(myFile,line)){
            for (int j = 0; j<numOfBooks;j++){     
                books[j].setTitle(line);        // this is a set title function being used to fill books with the information of each line of the file
            }

        }
        while(i<numOfBooks){
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;;       // loop that makes sure to include all the books and authors not just the first one 
            i++;
        }
    }
    
}


void printBooksByAuthor(Book books[], int numofbooks, string authorName){      //function with no return value and 4 parameters
    ifstream file;
    int counter = 0;
    int i = 0;
    while (i<numofbooks){
        if(books[i].getAuthor()==authorName){        // this while loop is for the edge case that there are no books by the authorName
            counter++;
            i++;
        }
        else{
            i++;
        }
    }
    if (counter == 0 && numofbooks>0){       // this if statement uses the counter from the previous loop to determine if the author has 0 books matching their name
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
                if (books[i].getAuthor()== authorName){       // this loop finds and prints the titles that match the author
                    cout << books[i].getTitle() << endl;
                    i++;
                }
                else {
                    i++;
                }
            }
        }
    }
}






int main(){
    
}


