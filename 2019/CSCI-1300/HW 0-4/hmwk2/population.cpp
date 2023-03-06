#include <iostream>
#include <math.h>
using namespace std;


int population(int initialPop){
    cin >> initialPop;
    int SIY = 31536000; // Seconds in a year
    int population = initialPop + (SIY/8) - (SIY/12) + (SIY/27);
    
}

int main (){
    population(0);
  
}