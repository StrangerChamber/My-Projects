#include <iostream>
#include <math.h>
using namespace std;



int countHours(int months){
    switch(months){
    case 1 : return 744; break;
    case 2 : return 672; break;
    case 3 : return 744; break;
    case 4 : return 720    ; break;
    case 5 : return 744    ; break;
    case 6 : return 720    ; break;
    case 7 : return 744    ; break;
    case 8 : return 744    ; break;
    case 9 : return 720    ; break;
    case 10 : return 744    ; break;
    case 11 : return 720    ; break;
    case 12 : return 744    ; break;
    default : return 0;
    }
}

int main(){
    countHours(2);
}