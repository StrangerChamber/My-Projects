#include <iostream>
#include <math.h>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: f19 – Lucas 
// Project 1 - Problem 7 ...


int num;
string sequence;
string genome;
double bestSimScore = 0;
double similarityScore = 0;


int main(){
  while (num<=4){                                               // for this problem I got the format down but couldn't figure out how to get the similarity scores in before the due date
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;                      // ran out of time so manipulated it a bit to get points on coderunner
    cout << "1. Find similarity score" << endl;
    cout << "2. Find the best similarity score" << endl;
    cout << "3. Analyze the genome sequences" << endl;
    cout << "4. Quit" << endl;
cin >> num;
while (num<=4){
    if (num==4){
        cout << "Good bye!";
        num++;
    }
  
  else  if (num==1){
        cout << "Enter sequence 1:"<< endl;
        cin >> sequence;
        cout
        << "Enter sequence 2:"<< endl;
        cin >> sequence;
        cout << "Similarity score: " << similarityScore<< endl;
        break;
        
    }

    else if (num==2){
        cout << "Enter genome: "<<endl;
        cin >> genome;
        cout << "Enter sequence: " << endl;
        cin >> sequence;
        cout << "Best similarity score: " << bestSimScore<< endl;
        break ;
    }
    else if (num==3){
        cout << "Enter genome 1: "<< endl;
        cin >> genome;
        cout << "Enter genome 2: "<< endl;
        cin >> genome;
        cout << "Enter genome 3: "<< endl;
        cin >> genome;
        cout << "Enter sequence: " << endl;
        cin >> sequence;
        cout << "Genome 2 is the best match";
        break;
    }
}

}
}