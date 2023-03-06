#include<iostream>
#include <cmath>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 5 - Problem 1



// taking a file and reading it line by line and populating that file into arrays if the line is a number
// we declare an input file
// open the file 
// read the line of the file and if it satisfies the conditions it goes into the array
// then we return the amount of lines that were put into the array

int getLinesFromFile(string fileName, int array[], int arrayLength){       // my function to read lines of a file and fill them into an array 
    ifstream myFile;                               // input file statement
    myFile.open(fileName);                          //opening the file
    string line = "";
    int i = 0;
    if(myFile.is_open()){
        while(getline(myFile, line) && i<arrayLength){       // reading the file line by line
            if (line != "")
            {
                array[i]= stoi(line);        // filling my array with the lines and turning the lines into integers from strings
                i++;
            }
        }
    }    
    else{
        return -1;
    }
    return i;                        // returning the amount of lines that the array stored
    myFile.close();
}




int main(){                       // test cases
    int numArray[4];
int x = getLinesFromFile("textFile.txt", numArray, 4);
cout << "Function returned: " << x << "\n";
for(int i = 0; i < 4; i++){
    cout << numArray[i] << "\n";
}
cout << endl;
int NumArray[4];
int y = getLinesFromFile("zeroFile.txt", NumArray, 4);
cout << "Function returned: " << y << "\n";
for(int i = 0; i < y; i++){
    cout << NumArray[i] << endl;
}
}