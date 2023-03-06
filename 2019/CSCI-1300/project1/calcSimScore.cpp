#include <iostream>
#include <math.h>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: f19 – Lucas
// Project 1 - Problem 4 ...


double calcSimScore (string sequence1, string sequence2){              // function that is a double that calculates how similar each sequence is
if (sequence1.length()!=sequence2.length()){       // if statements for my extraneous cases
return 0 ;
}
else if (sequence1==""){
    return 0;
}


double similarity_score;        //    declaring variables
double hamming_distance = 0;
for (int i =0; i<= sequence1.length();i++){       // this for loop checks and matches each charater of the sequence and adds one to hamming distance each time it gets a match
if (sequence1[i]!=sequence2[i]){
    hamming_distance++;
    


}
similarity_score = (sequence1.length()-hamming_distance)/(double) sequence1.length();    // the formula for my similarity score 
}
return similarity_score;          // returning the sim score
}




int main(){
    cout << calcSimScore("rdr","rtr")<< endl;
   
}