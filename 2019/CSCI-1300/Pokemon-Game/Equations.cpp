#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
using namespace std;
#include "Equations.h"



Equations:: Equations(){
    F = 0;
    damage = 0;
    mapPosition = 0;
}

void Equations:: setMapPosition(int newPosition){
    mapPosition= newPosition;
}

bool Equations:: canItRun(int speedOfRunner, int speedOfActive, int numOfEscapeTries){
    int A = speedOfRunner * 32;
    int B = (speedOfActive/4)%256;
    int C = numOfEscapeTries*30;
    F = (A/B)+C;
    if(F>255){
        return true;
    }
    else{
        srand (time(NULL));
        int num = rand()%255 +1;
        if(num>F){
            return true;
        }
        else{
            return false;
        }
    }
}

int Equations:: findDamage(int A, int D){
    if(A-D>0){
        return A-D;
    }
    else{
        return 0;
    }
}

bool Equations:: inRange(int position){ // for this I'm going to use an array to represent the map and where the scattered pokemon are 
            return true;                            // and determine whether there are any pokes within the range of wherever our player is at to trigger a battle 
    
}
