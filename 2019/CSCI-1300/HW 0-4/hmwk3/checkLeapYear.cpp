#include <iostream>
#include <math.h>
using namespace std;

int checkLeapYear(int year){
    if (year%4==0){
    return true;
    }
    if (year%400!= 0)
    return false;
}

int main(){
    return checkLeapYear(1700);
}