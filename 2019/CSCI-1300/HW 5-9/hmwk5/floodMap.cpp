#include <iostream>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 5 - Problem 5

// function has a 2d array with 4 columns and a variable amount of rows
// using a nested for loop the function fills each array row and prints it based on whether it is below or above the waterlevel



void floodMap (double array[][4],int rows, double waterLevel){
   for (int j = 0; j<rows; j++){      // for loop for the rows of the array
        for (int i = 0; i< 4; i++){     // loop to populate the rows of the array one at a time 
            if(array[j][i]>waterLevel){ // above water level gives a _ below gives a *
                cout<<'_';
            }
            else {
                cout<<'*';
            }
        }    
            cout << endl;    // end the line after each row is populated
    }
}



int main(){
    double map[4][4] = {{5.9064, 15.7541, 6.11483, 11.3928}, 
{16.8498, 5.736, 9.33342, 6.36095}, 
{3.18645, 16.935, 4.7506, 9.63635}, 
{2.22407, 0.815145, 0.298158, 13.466}};
floodMap(map, 4, 9.3);


cout << endl;

double Map[1][4] = {0, 0, 0, 0};
floodMap(Map, 1, 1);
}