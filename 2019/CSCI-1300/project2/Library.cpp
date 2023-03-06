#include <iostream>
#include <cmath>
#include <fstream>
#include<string>
using namespace std;
#include "Library.h"
#include "User.h"
#include "Book.h"

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




Library::Library(){
    numBooks = 0;
    numUsers = 0;
    sizeBook = 50;
    sizeUser = 100;
}

int Library:: getSizeBook(){
    return sizeBook;
}

int Library:: getSizeUser(){
    return sizeUser;
}

int Library:: getNumBooks(){
    return numBooks;
}

int Library:: getNumUsers(){
    return numUsers;
}
int split(string str, char c, string array[], int sizes){
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
}  /// this is my split function that I am recycling from the last hw

int Library:: readBooks(string fileName){
    ifstream myFile;
    if (numBooks == 50){ //if the number of books stored is equal to size the fuinction returns -2
        return -2;
    }
    int i = numBooks;    // this variable is my counter and it starts at whatever the numBpokStored variable is
    myFile.open(fileName);     // opening my file
    string line ="";      
    string arr[2];    // dummy array used in my split function
    if(myFile.is_open()){     // this if is important for the edge case of an unexistent file
        while(getline(myFile,line)){     // while the function is reading the file
            if (line != "" && i<50){    // this if is for splitting the line and then filling my arrays until i reaches size
                split(line,',', arr ,2);
                books[i].setAuthor(arr[0]);       // this is where the book class comes into play; Im using my set author function to store the author name from arr 0 into books 0
                books[i].setTitle(arr[1]);         // using set title function to store arr 1 into my books array
                i++;
            }
        }
        numBooks = i;
    }
    else {      // this is for if my file cannot be opened 
        return -1;
    }
    return i;   // returning the amount of arrays filled
}

void Library:: printAllBooks(){
        string line = "";
    if (numBooks<=0){                          // edge case for if number of books is zero or negative
        cout << "No books are stored" << endl;
    }
    else{        
        int i = 0;
        cout << "Here is a list of books" << endl;     // this else statement reads a file, opens it, reads it line by line populating two arrays one with the authors and another with titles
        while(i<numBooks){
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;;       // loop that makes sure to include all the books and authors not just the first one 
            i++;
        }
    }

}

void Library:: printBooksByAuthor(string authorName){
    int counter = 0;
    int i = 0;
    while (i<numBooks){
        if(books[i].getAuthor()==authorName){        // this while loop is for the edge case that there are no books by the authorName
            counter++;
            i++;
        }
        else{
            i++;
        }
    }
    if (counter == 0 && numBooks>0){       // this if statement uses the counter from the previous loop to determine if the author has 0 books matching their name
        cout << "There are no books by " << authorName << endl;
    }
    else {                   // this else statement matches the author and books 
        if (numBooks<=0){
            cout << "No books are stored" << endl;      // if the number of books is zero or negative the function prints no books
        }
        else{
            int i = 0;
            int matches = 0;
            cout << "Here is a list of books by " << authorName << endl;   
            while (i< numBooks){
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

int Library:: readRatings(string filename){
    ifstream inFile;
    inFile.open(filename);  // open file
    string line = ""; // dummy string for getline
    int i = numUsers; // my increment for number of rows used within the while loop
    string array[101]; // dummy array for split function
    if (numUsers>=100){ // edge case for if number of users is equal to maximum number of rows
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
            if (i == 100){
                numUsers = i;
                return i;
            }

        }    
    }
    else {// for if the file cannot be open
        return -1;
    }
    numUsers = i;
    return i; // return my incremental variable

}

int Library:: getRating(string userName, string title){
        if (numUsers>0 &&numBooks>0){  // set username to lowercase
    for (int i = 0; i < userName.length(); i++){
        userName[i]=tolower(userName[i]);
    }
    for (int i = 0; i < title.length(); i++){      // set title to lowercase
        title[i]=tolower(title[i]);
    }
    int userNameIndex = 0;
    int bookIndex = 0;
    int userCounter = 0;
    int bookCounter = 0;
    for (int i = 0; i < numUsers;i++){
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){    // set user in array to lowercase
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName ){    // find match
             userNameIndex = i;       // store index
             userCounter++;
            break;
        }
        if (i ==numUsers){
            return -3;
         }    
    }
    
    for (int i = 0; i < numBooks; i++){       // set title in array to lowercase
        string currentBook = books[i].getTitle();
        for (int j = 0; j < currentBook.length(); j++){
            currentBook[j]=tolower(currentBook[j]);
        }
        if(currentBook == title){    // find match
             bookIndex = i ;      // store index
            bookCounter++;
            break;
        }
        if (i==numBooks){
            return -3;
        }
        
    }
        if(userCounter>0 && bookCounter > 0){     // if user and title exist return the users rating for that book
            return users[userNameIndex].getRatingAt(bookIndex);
        }
        else {
            return -3;
        }
    }
    else{
        return -3;
    }

}

int Library:: getCountReadBooks(string userName){
    if(numBooks == 0 || numUsers == 0){
        return -3;
    }   
    int userNameIndex = 0;
    int counter = 0;
    int userNameCounter = 0;
    for (int i = 0; i < userName.length(); i++){       // this for loop makes everything in the username string lowercase
        userName[i]=tolower(userName[i]);
    }
    for (int i = 0; i < numUsers+1;i++){          // this makes the users in the array lowercase as well
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName){   // finding a match of username to a user 
            userNameIndex = i;     // storing the index location
            userNameCounter++;
            break;
        }
    }
    for (int i = 0; i < numBooks; i++){
        if(users[userNameIndex].getRatingAt(i)>0 && users[userNameIndex].getRatingAt(i)<=5){   // counting how many books the user has rated
            counter++;
        }
    }
    if(userNameCounter>0){
    return counter;     // returning the amoung of books the user has rated if its more than 0
    }
    else {
        return -3;
    }
    
}

void Library:: viewRatings(string userName, int minRating){
    int counter = 0;
    string oldUsername = userName;
    int counter2 =0;
    int userNameIndex = 0;
    for(int i = 0; i<userName.length();i++){
        userName[i] = tolower(userName[i]);
    }
    for(int i = 0; i<numUsers;i++){
        string currentUser= users[i].getUsername();
        for(int j = 0; j<currentUser.length();j++){
            if(currentUser == userName){
                userNameIndex = i;
                counter++;
            }
        }
    }
    if (counter == 0){
        cout << userName << " does not exist." << endl;
    }
    else{
            for (int j = 0; j<numBooks;j++){
                if(users[userNameIndex].getRatingAt(j)>=minRating){
                    if (counter2 == 0){
                        counter2++;
                        cout<< "Here are the books that "<< oldUsername << " rated" << endl;
                    }
                        cout << "Title : " << books[j].getTitle() << endl;
                        cout << "Rating : " << users[userNameIndex].getRatingAt(j) << endl;
                        cout << "-----" << endl;                        
                }
            }
        if (counter2 == 0){
            cout << oldUsername << " has not rated any books yet." << endl;
        }
    }
}

double Library:: calcAvgRating(string title){
        if(numUsers == 0 || numBooks == 0){
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
    for (int i = 0; i < numBooks; i++){
        string currentBook = books[i].getTitle();
        for (int j = 0; j < currentBook.length(); j++){ // lowercase the title in the array
            currentBook[j]=tolower(currentBook[j]);
        }
        if (currentBook == title){  // find a match
            bookIndex = i;
            bookCounter++;
            for (int i = 0; i < numUsers; i++){
                if(users[i].getRatingAt(bookIndex)>0 && users[i].getRatingAt(bookIndex)<=5){ // if they rated the books
                    rating = users[i].getRatingAt(bookIndex);
                    ratingTotal = ratingTotal + rating; // add that rating to the total
                    rating = 0;
                    amountOfRatings++;
                }
                if (users[i].getRatingAt(bookIndex)==0){
                    notReadCounter++;
                    if (notReadCounter == numUsers - 1){   // if no one read the book return 0
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

double Library:: calcAvgRatingByAuthor(string author){
    if(numUsers<=0){
        return -3;
    }
    for (int i = 0; i< author.length();i++){
        author[i]=tolower(author[i]);
    }
    int authorIndex = 0;
    int authorMatch = 0;
    double ratingTotal = 0;
    int amountOfRatings = 0;
    double rating = 0;
    for(int i = 0;i<numBooks; i++){
        string currentAuthor = books[i].getAuthor();
        for (int j = 0; j<currentAuthor.length();j++){
            currentAuthor[j]=tolower(currentAuthor[j]);
        }
        if (currentAuthor == author){
            authorIndex = i;
            authorMatch++;
            for(int k = 0; k<numUsers;k++){
                if (users[k].getRatingAt(authorIndex)>0 && users[k].getRatingAt(authorIndex)<=5){
                    amountOfRatings++;
                    rating = users[k].getRatingAt(authorIndex);
                    ratingTotal = ratingTotal + rating;
                    rating = 0;
                }
            }
        }    
    }
    if(authorMatch == 0){
        return -3;
    }
    if(amountOfRatings == 0){
        return 0;
    }
    double ratingAverage = ratingTotal/amountOfRatings;
    return ratingAverage;
}

int Library:: addUser(string userName){
    if(numUsers == sizeUser){
        return -2;
    }
    for(int i = 0; i<userName.length();i++){
        userName[i] = tolower(userName[i]);
    }
    for(int i = 0; i<numUsers; i++){
        string currentUser = users[i].getUsername();
        for (int j = 0; j<currentUser.length();j++){
            currentUser[i]=tolower(currentUser[i]);
        }
        if(currentUser == userName){
            return 0;
        }
    }
    if(numUsers<sizeUser){
        numUsers = numUsers +1 ;
        users[numUsers-1].setUsername(userName);
        return 1;
    }
    
    
}

int Library:: checkOutBook(string userName, string title, int newRating){
    for (int i = 0; i < userName.length(); i++){
        userName[i]=tolower(userName[i]);
    }
    for (int i = 0; i < title.length(); i++){      // set title to lowercase
        title[i]=tolower(title[i]);
    }
    int userNameIndex = 0;
    int bookIndex = 0;
    int userCounter = 0;
    int bookCounter = 0;
    for (int i = 0; i < numUsers;i++){
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){    // set user in array to lowercase
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName ){    // find match
             userNameIndex = i;       // store index
             userCounter++;
            break;
        }
    }
    
    for (int i = 0; i < numBooks; i++){       // set title in array to lowercase
        string currentBook = books[i].getTitle();
        for (int j = 0; j < currentBook.length(); j++){
            currentBook[j]=tolower(currentBook[j]);
        }
        if(currentBook == title){    // find match
            bookIndex = i ;      // store index
            bookCounter++;
            break;
        }
    }
    if(newRating<0 || newRating>5){
        return -4;
    }
    if(bookCounter == 0 || userCounter == 0){
        return -3;
    }
    if(newRating>=0 && newRating<=5){
        users[userNameIndex].setRatingAt(bookIndex, newRating);
        return 1;
    }
}

void Library:: getRecommendations(string userName){
    for (int i = 0; i < userName.length(); i++){
        userName[i]=tolower(userName[i]);
    }
    int userCounter = 0;
    int inputUserIndex = 0;
    int ssd = 0;
    int partOfSsd = 0;
    int lowestSsd = 1250;
    int userIndexWithLowestssd = 0;
    for (int i = 0; i < numUsers;i++){
        string currentUser = users[i].getUsername();
        for (int j = 0; j < currentUser.length();j++){    // set user in array to lowercase
            currentUser[j]=tolower(currentUser[j]);
        }
        if(currentUser == userName){
            userCounter++;
            inputUserIndex = i;
        }
    }
    if(userCounter == 0){
        cout << userName << " does not exist." << endl;
    }
    else{
        for(int i = 0;i<numUsers;i++){
            ssd=0;
            for(int j = 0;j<numBooks ; j++){
                if(inputUserIndex!= i && getCountReadBooks(users[i].getUsername()) != 0){
                    partOfSsd = pow(users[inputUserIndex].getRatingAt(j)-users[i].getRatingAt(j),2);
                    ssd = ssd + partOfSsd;
                    partOfSsd = 0;
                    if(j == numBooks-1){
                        if (ssd<lowestSsd){
                            lowestSsd = ssd;
                            userIndexWithLowestssd = i;
                        }
                    }
                }    
            }
        }
        int counter3=0;
        int bookCounter = 0;
        for(int i = 0; i<numBooks;i++){
            if(users[userIndexWithLowestssd].getRatingAt(i) >=3 && users[userIndexWithLowestssd].getRatingAt(i)<=5 && users[inputUserIndex].getRatingAt(i)==0 && bookCounter<=5){
                if(counter3 == 0){
                    counter3++;
                    cout << "Here is the list of recommendations" << endl;
                }
                cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
                bookCounter++;
            }
        }
        if (counter3 == 0){
            cout << "There are no recommendations for "<< userName << " at present." << endl;
        }
    }    
    
}


int main(){
//addUser : success
Library l15 = Library();
int numBooks = l15.readBooks("books.txt");
int numUsers = l15.readRatings("ratings.txt");
cout << "numUsers(before) = " << l15.getNumUsers() << endl;

// checking the num users
int rv =  l15.addUser("newUser");
cout << "addUser returned: " << rv << endl;
cout << "numUsers (after)= " << l15.getNumUsers() << endl;

// check if we can find the newUser
int count = l15.getCountReadBooks("newUser");
cout << "getCountReadBooks returned: " << count << endl;
}