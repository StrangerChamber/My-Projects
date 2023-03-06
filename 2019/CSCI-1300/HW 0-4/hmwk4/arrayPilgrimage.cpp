#include <iostream>
#include <cmath>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: lucas Hayne
// Homework 4 - Problem 1 






int main(){
    double temps[10] = {-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67}; // declaring my first array and filling it
for (int i = 0; i < 10; i++){          //loop for outputting the contents of my array
    cout << temps[i] << endl;
}  
cout << endl;
    string colors[5] = {"Red", "Blue", "Green","Cyan","Magenta"};        // declaring and filling my next array then looping it to output the contents
    for (int j = 0; j<5;j++){
        cout << colors[j]<< endl;
    }
    cout << endl;
    int sequence[100];                           // 3rd array doing the same as the first two
    for (int k = 1; k<=100;k++){
        sequence[k]=k;
        cout << sequence[k]<< endl;
    }
    cout << endl;
    string letters[26]= {"A a", "B b", "C c", "D d", "E e", "F f", "G g", "H h", "I i", "J j", "K k", "L l", "M m", "N n", "O o", "P p", "Q q", "R r", "S s","T t", "U u", "V v", "W w", "X x", "Y y", "Z z"};
    for (int l = 0; l<26; l++){
        cout << letters[l] << endl;                // final array being called filled and finally output
    }
    cout << endl;
   
}