#include <iostream>
#include <math.h>
using namespace std;

int printGrid(int number){
   
   switch(number){
    case 1 : cout << "+--+
                      |  |
                      +--+" ; break;
    case 2 : cout << "+--+--+
                      |  |  |
                      +--+--+
                      |  |  |
                      +--+--+
                      "; break;
    case 3 : return 744; break;
    case 4 : return 720    ; break;
    case 5 : return 744    ; break;
    default : cout << "The grid can only have a positive number of rows and columns." ;
}