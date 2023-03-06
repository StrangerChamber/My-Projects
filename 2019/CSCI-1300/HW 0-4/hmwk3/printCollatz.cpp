#include <iostream>
#include <math.h>
using namespace std;


int printCollatz(int number){
if (number <= 0){
    cout << "invalid number";
}
else if (number >=0){
cout << number;
}
while (number>1){

if (number%2==0){
 
    cout << " " << number/2;

     number =number/2;
 }
else if (number%2!=0){
    cout << " " << number*3+1;
    number = number*3+1;
}
}
}
int main(){
    
}