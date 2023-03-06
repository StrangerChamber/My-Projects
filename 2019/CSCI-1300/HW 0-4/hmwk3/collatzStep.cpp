#include <iostream> 
#include <math.h>
using namespace std;

int collatzStep(int number){
    if (number<0){
        return 0;
    }
    if ( number%2==0 && number>=0){
        return number/2 ;
        }
     
    else {
        return 3*number + 1 ;
    }
    
}


int main(){
  collatzStep(6);
}