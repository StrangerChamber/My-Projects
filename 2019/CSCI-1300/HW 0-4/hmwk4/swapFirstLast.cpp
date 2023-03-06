#include <iostream>
#include <cmath>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: lucas Hayne
// Homework 4 - Problem 4



void swapFirstLast(int array[], int length){     // this function returns the array with the first and last values flipped
int i =0;
int j = length-1;
int temp = array[i];
array[i]=array[j];
array[j]= temp;
}



int main(){
    int arr1[3] = {10, 20, 30};
swapFirstLast(arr1, 3);
int printArray(arr1, 3);

int arr2[5] = {5, 4, 3, 2, 1};
swapFirstLast(arr2, 5);
int printArray(arr2, 5);
    
}