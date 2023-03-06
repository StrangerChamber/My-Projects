#include <iostream>
#include <math.h>
using namespace std;

void convertSeconds(int seconds){
   
   int minutes = seconds/60;
   int hour = minutes/60;
    cout << hour << " hour(s) " << minutes%60 << " minute(s) " << seconds%60 << " second(s)" << endl;
    
    
}

int main(){
    convertSeconds(8567);
}