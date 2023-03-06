#include <iostream>
#include <cmath>
using namespace std;

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: lucas Hayne
// Homework 4 - Problem 2 


void printArrReverse(int arr[], int length){            // function that gives me an input array in reverse order
    for (int i = length -1; i>=0;i--){
        cout<< arr[i]<< endl;
    }
    
}







int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
int len = 10;
printArrReverse(arr, len);

int arra[] = {1, 9, 7};
int lenn = 3;
printArrReverse(arra, lenn);
}