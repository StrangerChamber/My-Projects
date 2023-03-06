#include <iostream> 
#include <math.h>
using namespace std;


char checkEqual(int one, int two, int three){
    if (one==two==three){
        cout << "All same";
    }
    else if (one!=two!=three){
        cout << "All Different";
    }
    else 
    cout << "Neither";
}

int main(){
    checkEqual(1,1,1);
}