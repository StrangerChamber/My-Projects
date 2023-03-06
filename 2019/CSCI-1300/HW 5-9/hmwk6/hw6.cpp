#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 7


class Book
{
    private:
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


Book::Book(){
    title = "";
    author = "";
}

Book::Book(string newTitle, string newAuthor){
    title = newTitle;
    author = newAuthor;
}

string Book::getTitle(){
    return title;
}

string Book::getAuthor(){
    return author;
}

void Book::setTitle(string newTitle){
    title = newTitle;
}

void Book::setAuthor(string newAuthor){
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
} // split function

int readBooks(string filename, Book books[], int numBooksStored, int booksArrSize){         
    ifstream myFile;
    int i = numBooksStored;    // this variable is my counter and it starts at whatever the numBpokStored variable is
    myFile.open(filename);     // opening my file
    string line ="";      
    string arr[2];    // dummy array used in my split function
    if(myFile.is_open()){     // this if is important for the edge case of an unexistent file
        while(getline(myFile,line)){     // while the function is reading the file
            if (line != "" && i<booksArrSize){    // this if is for splitting the line and then filling my arrays until i reaches size
                split(line,',', arr ,2);
                books[i].setAuthor(arr[0]);
                books[i].setTitle(arr[1]);
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
}   // modified read books function


void printAllBooks(Book books[], int numOfBooks){ //my print all books function that has no return value and 3 parameters 
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
                books[j].setTitle(line);
            }

        }
        while(i<numOfBooks){
            if (books[i].getTitle()!=""){
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;       // loop that makes sure to include all the books and authors not just the first one 
            i++;
            }
            else{
                break;
            }
        }
    }
}   // modded print all books


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
        cout << "There are no books by " << authorName << endl;
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
}   // modded print books by author








int main(){
    int num = 0;
    int booksStored = 0;
    string fileName = "";
    string AuthorName = "";
    Book books[50];
    while(num!=4){
	    cout<<"======Main Menu====="<<endl;
	    cout<<"1. Read books"<<endl;
	    cout<<"2. Print all books"<<endl;
	    cout<<"3. Print books by author"<<endl;
	    cout<<"4. Quit"<< endl;
        cin >> num ;

    if (num == 4){       // quit option
        cout << "Good bye!";
        break;
    }
    if (num>4 || num<1){
        cout << "Invalid input." << endl;
        
    } //invalid input option
    if (num == 1){      // read books option
        cout << "Enter a book file name: ";
        cin >> fileName;    // entering filename
        cout << endl;
        int option1 = readBooks(fileName, books, booksStored, 50);  // calling the read books function and storing the return value into a variable
        booksStored = option1;    // making another variable for return  value of read books 
        if (booksStored == -1){     // if no books are in the file
            cout << "No books saved to the database." << endl;
        }
        if (booksStored == -2){ // books stored already fills the array
            cout << "Database is already full. No books were added" << endl;
        }
        if(booksStored >= 50){ // capping the array
            cout << "Database is full. Some books may have not been added." << endl;
        }
        if ( booksStored!= -1 && booksStored!= -2 && booksStored < 50){ // this is for outputting the amount of books stored if the array doesn't need an edge case
            cout << "Total books in the database: " << option1 << endl;
        }
    }
    if (num == 2){    // print all books option
        printAllBooks(books, 50); // calling the function
    }
    if (num == 3){    // print books by author option
        cout << "Enter name of author: ";
        cin.ignore(); // ignores spaces in cin 
        getline(cin,AuthorName);
        cout << endl;
        printBooksByAuthor(books, 50, AuthorName);//calling the function with the input author name
    }
    }
}
