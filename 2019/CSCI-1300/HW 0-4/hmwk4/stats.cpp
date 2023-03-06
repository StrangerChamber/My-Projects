#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: lucas Hayne
// Homework 4 - Problem 3




void stats(double array[], int length){
double largest = array[0];
double minimum = array[0];
double sum = 0;
for (int j = 1; j<length; j++){          /// this for loop finds the minimum number in the array
    if (array[j]<minimum){
        minimum = array[j];
    }
}
cout << "Min: " << fixed << setprecision(2) << minimum << endl;
for (int i =1;i<length; i++){      // this loop finds the largest number in the array
    if(array[i]>largest){
        largest = array[i];
    }
}
cout << "Max: " << fixed << setprecision(2) << largest << endl;
for (int k = 0; k < length; k++){        // this finds the sum of all the numbers in the array
        sum = sum + array[k];
        }
double avg = sum/length;
cout << "Avg: " << fixed << setprecision(2) << avg;
}



int main(){
    stats(0,5);
    stats(1.4);
    
}