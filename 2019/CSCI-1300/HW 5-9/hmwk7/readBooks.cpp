#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 5 - Problem 2


//algorithm: first the function intakes 5 parameters
// opens an input file
// reads the file line by line
// if the line isn't empty it populates two arrays that are split using my split function 
// the function returns however many times the arrays were populated

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

int readBooks(string filename, string titles[], string authors[], int numBookStored, int size){         
    ifstream myFile;
    int i =numBookStored;    // this variable is my counter and it starts at whatever the numBpokStored variable is
    myFile.open(filename);     // opening my file
    string line ="";      
    string arr[2];     // dummy array used in my split function
    if(myFile.is_open()){     // this if is important for the edge case of an unexistent file
        while(getline(myFile,line)){     // while the function is reading the file
            if (line != "" && i<size){    // this if is for splitting the line and then filling my arrays until i reaches size
                split(line,',', arr ,2);
                titles[i]= arr[1];
                authors[i]= arr[0];
                i++;
            }


            if (numBookStored == size){ //if the number of books stored is equal to size the fuinction returns -2
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



int main(){
// return -2 if the arr is already full

int numbooks = 3;
string std_titles[3] = {"title1", "title2", "title3"};
string std_authors[3] = {"author1", "author2", "author3"};

int rv = readBooks("minitest1.txt", std_titles, std_authors, numbooks, 3);
cout << "Function returned value: "<< rv << endl;



}