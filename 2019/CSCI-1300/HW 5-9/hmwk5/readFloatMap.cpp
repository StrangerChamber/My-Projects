#include <iostream>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 5 - Problem 6


// Algorithm: first the function takes in 3 parameters
// opens a file
// then populates a 2d array based on the split function
// returns the number of rows input

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
} // split function recycled


double readFloatMap(string fileName, double array[][4], int rows){
    ifstream infile;        // input file
    infile.open(fileName);   //opens file
    string line = "";    // dummy string for getline function
    int total=0;  //this is used to count the rows of my 2d array
    string arr[4]; // dummy array for split function
    
    if(infile.is_open()){ // if the file opens
        while(getline(infile,line)){ // while the file is being read line by line
            if (line!= ""){ // if the line isn't empty
                split(line,',',arr, 4);            // split the line by commas into 4 pieces
                for (int i = 0; i<4; i++){   // for loop to populate my 2d array
                   array[total][i] = stod(arr[i]);
               }
               total++; // increment rows
           }
           else { // if the line is empty
               return 0;
           }
        }
    }
    else {  // if the file doesnt open
        return -1;
    }
    return rows;     // returning whatever is input into rows
}    






int main(){
double floatMap[2][4];
int x = readFloatMap("readFloatMaptestcase.txt", floatMap, 2);
cout << "Function returned: " << x << "\n";
for(int i = 0; i < 2; i++){
    cout << floatMap[i][0] << ", " << floatMap[i][1] << ", " << floatMap[i][2] << ", " << floatMap[i][3] << "\n";
}

cout  << endl;

cout << "Function returned: 2" << endl << "23.5, 34.3, 1.3, 0.23" << endl ;
cout << "203.5, 134.3, 1.33, 11.23";
}