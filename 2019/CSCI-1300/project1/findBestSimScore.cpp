#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;
// CS1300 Fall 2019
// Author: JacK Blackburn
// Recitation: f19 – Jack Blackburn
// Project 1 - Problem 5 ...




double getmatch(string a, string b){                      // function for checking string characters and matching them just like from the previous problem
    int matches = 0;
    for (int j=0;j<a.length();j++){
        if(a[j]==b[j])
        matches++;
    }
    return matches/((double)a.length());
}
 

double findBestSimScore(string genome, string sequence){                    // my functtion that deals with extraneous cases 
    if (sequence.length()>genome.length()){
    return 0;
    }
  double bestmatch = 0;
  double match=0;
 
    for(int i=0;i<=genome.length()-sequence.length();i++){              // for loop to to find the sim score of the sequences
        
   match = getmatch(genome.substr(i,sequence.length()),sequence);
  
    if (match>bestmatch){
        bestmatch=match;
    }
}
return bestmatch;

}


int main(){
     cout << findBestSimScore("acttttt","actttttttt")<< " should be 0"<< endl;
    cout << findBestSimScore("acttttt","act")<< " should be 1"<< endl;                // test cases 

}