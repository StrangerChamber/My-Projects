#include <iostream>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 5 - Problem 7


// algorithm: function intakes 6 parameters
// opens a file
// reads it line by line
// fills two arrays with the info from the file
// returns the number of users input

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



int readRatings(string filename, string users[], int ratings[][50],int numUsers, int maxRows, int maxColumns){
    ifstream inFile;
    inFile.open(filename);  // open file
    string line = ""; // dummy string for getline
    int i = numUsers; // my increment for number of rows used within the while loop
    string array[51]; // dummy array for split function
    if (numUsers==maxRows){ // edge case for if number of users is equal to maximum number of rows
        return -2;
    }    
    
    if(inFile.is_open()){ // if the file is open
        while(getline(inFile,line)){ //while the function is reading the file line by line
            if (line != "" ){ // if the line isnt epmty
                split(line, ',', array, 51); // split the line by comma
                users[i]=array[0];// users of my incremental variable is equal to the first value of the array
                i++;// increment
                for (int j =1 ; j < split(line, ',', array, 51); j++){ // for loop to fill each column of each row one row at a time
                    ratings[i-1][j-1]= stoi(array[j]); // storing my ratings
                }
            }
            if (i == maxRows){ // edge case if i reaches the maximum number of rows the function returns i
                return i;
            }

        }    
    }
    else {// for if the file cannot be open
        return -1;
    }
    return i; // return my incremental variable
}






int main(){
    string users[100] = {};
    int ratings[100][50] = {{0}};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    int numBooks = 5; // (we know it's 5 books)
    numUsers = readRatings("ratings.txt", users, ratings, numUsers, maxRows, maxColumns);
    for (int i = 0; i<86; i++){
        for (int j = 0; j<50; j++){
    cout << ratings[i][j];
            
        }
        cout << endl;
    }
}