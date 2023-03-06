#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 7 - problem 6



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

class User{
    private:
   
    int size;
    string userName;
    int numRatings;
    int ratings[50];

    public:
   
    User();
    User(string newUserName, int newRatings[], int newNumRatings);
    string getUsername();
    int getNumRatings();
    int getSize();
    int getRatingAt(int);
    
    void setUsername(string);
    bool setRatingAt(int,int);
    void setNumRatings(int);
};
// impplementation of user class 

User::User(){
    const int size = 50;
    string userName = "";
    int numRatings = 0;
    int i = 0;
    for(int i = 0;i<50; i++){
     ratings[i] = 0;
    }
    
}

User:: User(string newUserName, int newRatings[], int newNumRatings){
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

string User:: getUsername(){
    return userName;
}

int User:: getNumRatings(){
    return numRatings;
}

int User:: getSize(){
    return size;
}

int User:: getRatingAt(int indexLocation){
    if(indexLocation<0 || indexLocation>=50){
        return -1;
    }
    else{
    return ratings[indexLocation];
    }
}

void User:: setUsername(string newUser){
    userName = newUser;
}

void User:: setNumRatings(int newNum){
    numRatings = newNum;
}

bool User:: setRatingAt(int index, int value){
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


            if (numBooksStored >= booksArrSize){ //if the number of books stored is equal to size the fuinction returns -2
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


int readRatings(string filename, User users[],int numUsersStored, int UsersArrSize, int maxColumns){
    if (numUsersStored>=UsersArrSize){ // edge case for if number of users is equal to maximum number of rows
        return -2;
    }    
    ifstream inFile;
    inFile.open(filename);  // open file
    string line = ""; // dummy string for getline
    int i = numUsersStored; // my increment for number of rows used within the while loop
    string array[51]; // dummy array for split function

    if(inFile.is_open()){ // if the file is open
        while(getline(inFile,line)){ //while the function is reading the file line by line
            if (line != "" ){ // if the line isnt epmty
                int num = split(line, ',', array, 51); // split the line by comma
                users[i].setUsername(array[0]);// users of my incremental variable is equal to the first value of the array
                for (int j = 1 ; j < 51; j++){ // for loop to fill each column of each row one row at a time
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
}// read ratings from earlier


int getRating(string userName, string title, User users[], Book books[], int currentNumOfUsers, int currentNumOfBooks){
    if (currentNumOfUsers>0 && currentNumOfBooks>0){
    for (int i = 0; i < userName.length(); i++){
        userName[i]=tolower(userName[i]);
    }
    for (int i = 0; i < title.length(); i++){
        title[i]=tolower(title[i]);
    }
    int userNameIndex = 0;
    int bookIndex = 0;
    int userCounter = 0;
    int bookCounter = 0;
    for (int i = 0; i < currentNumOfUsers;i++){
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName ){
             userNameIndex = i;
             userCounter++;
            break;
        }
        if (i == currentNumOfUsers){
            return -3;
         }    
    }
    
    for (int i = 0; i < currentNumOfBooks; i++){
        string currentBook = books[i].getTitle();
        for (int j = 0; j < currentBook.length(); j++){
            currentBook[j]=tolower(currentBook[j]);
        }
        if(currentBook == title){
             bookIndex = i ;
            bookCounter++;
            break;
        }
        if (i==currentNumOfBooks){
            return -3;
        }
        
    }
        if(userCounter>0 && bookCounter > 0){
            return users[userNameIndex].getRatingAt(bookIndex);
        }
        else {
            return -3;
        }
    }
    else{
        return -3;
    }
} // pasted get rating function

int getCountReadBooks(string userName, User users[],int currentNumOfUsers, int currentNumOfBooks){
    if(currentNumOfBooks == 0 || currentNumOfUsers == 0){
        return -3;
    }   
    int userNameIndex = 0;
    int counter = 0;
    int userNameCounter = 0;
    for (int i = 0; i < userName.length(); i++){
        userName[i]=tolower(userName[i]);
    }
    for (int i = 0; i < currentNumOfUsers;i++){
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName){
            userNameIndex = i;
            userNameCounter++;
            break;
        }
    }
    for (int i = 0; i < currentNumOfBooks; i++){
        if(users[userNameIndex].getRatingAt(i)>0 && users[userNameIndex].getRatingAt(i)<=5){
            counter++;
        }
    }
    if(userNameCounter>0){
    return counter;
    }
    else {
        return -3;
    }
} // get count funciton


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
    for (int i = 0; i < title.length(); i++){
        title[i]=tolower(title[i]);
    }
    for (int i = 0; i < currentNumOfBooks; i++){
        string currentBook = books[i].getTitle();
        for (int j = 0; j < currentBook.length(); j++){
            currentBook[j]=tolower(currentBook[j]);
        }
        if (currentBook == title){
            bookIndex = i;
            bookCounter++;
            for (int i = 0; i < currentNumOfUsers; i++){
                if(users[i].getRatingAt(bookIndex)>0 && users[i].getRatingAt(bookIndex)<=5){
                    rating = users[i].getRatingAt(bookIndex);
                    ratingTotal = ratingTotal + rating;
                    rating = 0;
                    amountOfRatings++;
                }
                if (users[i].getRatingAt(bookIndex)==0){
                    notReadCounter++;
                    if (notReadCounter == currentNumOfUsers - 1){
                        return 0;
                    }
                }
            }
        }
    }

    double average = ratingTotal/ amountOfRatings;
    if(bookCounter>0 && amountOfRatings>0){
    return average;
    }
    else {
        return -3;
    }
    

} // avaerage function

int main(){
    int num = 0;
    int bookStored = 0;
    int booksStored = 0;
    int booksArrSize =50 ;
    int readRatingsValue = 0;
    int getRatingResult = 0;
    int number = 0;
    int currentNumOfBooks = 0;
    int currentNumOfUsers = 0;
    int UsersArrSize = 100;
    double average = 0.0;
    string fileName = "";
    string title = "";
    string userName = "";
    Book books[50];
    User users[100];


    while(num!=6){
	    cout<<"======Main Menu====="<<endl;
	    cout<<"1. Read books"<<endl;
	    cout<<"2. Read ratings"<<endl;
	    cout<<"3. Get rating"<<endl;
	    cout<<"4. Find number of books user rated"<< endl;
	    cout<<"5. Get average rating"<< endl;
	    cout<<"6. Quit"<< endl;
        cin >> num ;

        if (num == 1){      // read books option
            cout << "Enter a book file name: ";
            cin >> fileName;    // entering filename
            cout << endl;
            int option1 = readBooks(fileName, books, booksStored, 50);  // calling the read books function and storing the return value into a variable
            bookStored = option1;    // making another variable for return  value of read books 
            if ( bookStored!= -1 && bookStored!= -2 && bookStored < 50){ // this is for outputting the amount of books stored if the array doesn't need an edge case
                cout << "Total books in the database: " << bookStored << endl;
            }
            if (bookStored == -1){     // if no books are in the file
                cout << "No books saved to the database." << endl;
            }
            if (bookStored == -2){ // books stored already fills the array
                cout << "Database is already full. No books were added." << endl;
            }
            if(bookStored >= 50){ // capping the array
                cout << "Database is full. Some books may have not been added." << endl;
            }
            if(bookStored!= -1){
            booksStored = booksStored + option1;
            }
        }
        if (num == 2){ //option 2
            cout << "Enter a user file name:";
            cin >> fileName;    // entering filename
            cout << endl;
            int option2 = readRatings(fileName, users, currentNumOfUsers, UsersArrSize, 50);
            readRatingsValue = option2;
            if (readRatingsValue == -1){
                cout << "No users saved to the database."<< endl;
            }
            if (readRatingsValue == -2){
                cout << "Database is already full. No users were added." << endl;
            }
            if (readRatingsValue >= UsersArrSize){
                cout << "Database is full. Some users may have not been added." << endl;
            }
            if(readRatingsValue!= -1 && readRatingsValue != -2 && readRatingsValue < UsersArrSize){
                cout << "Total users in the database: " << readRatingsValue << endl;
            }
            if(readRatingsValue!=-1){
                if (currentNumOfUsers + option2 >=100){
                    currentNumOfUsers = 100;
                }
                else{
                    currentNumOfUsers = currentNumOfUsers + option2;
                }
                if(currentNumOfUsers>=50){
                    currentNumOfBooks = 50;
                }
                else{
                    currentNumOfBooks = currentNumOfUsers;
                }
            }
        }
        if (num == 3){     //option 3
            cout << "Enter a user name: " << endl;
            cin>>userName;
            cout << "Enter a book title: "<< endl;
            cin.ignore();
            getline(cin, title);
            int option3 = myLibrary.getRating(userName);
            if (option3 == 0){
                cout << userName << " has not rated "<< title<< endl;
            }
            if (option3 == -3){
                cout << userName << " or " << title << " does not exist." << endl;
            }
            if(option3!= 0 && option3!= -3){
                cout << userName << " rated " << title << " with " << option3 << endl;
            }
        }
        if (num == 4){ // option 4
            cout << "Enter a user name: " << endl;
            cin>> userName;
            int option4 = getCountReadBooks( userName, users, currentNumOfUsers, currentNumOfBooks);
            number = option4;
            if (number == 0){
                cout << userName << " has not rated any books." << endl;
            }
            if (number == -3){
                cout << userName << " does not exist." << endl;
            }
            if(number!= -3 && number != 0){
                cout << userName << " rated " << number << " books." << endl;
            }
            
        }
        if (num == 5){ // option 5
            cout << "Enter a book title: "<< endl;
            cin.ignore();
            getline(cin, title);
            double option5 = calcAverageRating(users, books, currentNumOfUsers, currentNumOfBooks, title);
            double average = option5;
            if (average == -3){
                cout << title << " does not exist." << endl;
            }
            else {
                cout << "The average rating for " << title << " is " << average << endl;
            }
            
        }
        if (num == 6){ // option 6 
            cout << "Good bye!" << endl;
            break;
        }
        if (num>6 || num<1){   // invlaid option
            cout << "Invalid input." << endl;
            
        } //invalid input option
        
    }
    
    

}
