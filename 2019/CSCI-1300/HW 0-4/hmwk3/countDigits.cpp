#include <iostream>
#include <math.h>
using namespace std;

int countDigits(int number){
    if (number >=0 && number<10 || number < 0 && number > -10){
        return (int) (number/10)+1;
    }
    else if (number >= 10 && number < 100 || number <=-10 && number > -100){
    return (int) (number*0)+2;
}
else if (number >= 100 && number < 1000 || number <=-100 && number > -1000){
    return (int) (number*0)+3;
}
else if (number >= 1000 && number < 10000 || number <=-1000 && number > -10000){
    return (int) (number*0)+4;
}
else if (number >= 10000 && number < 100000 || number <=-10000 && number > -100000){
    return (int) (number*0)+5;
}
else if (number >= 100000 && number < 1000000 || number <=-100000 && number > -1000000){
    return (int) (number*0)+6;
}
else if (number >= 100000000 && number < 1000000000 || number <=-100000000 && number > -1000000000){
    return (int) (number*0)+9;
}
    else {
        return 0;
    }
}

int main(){
    countDigits(5);
}