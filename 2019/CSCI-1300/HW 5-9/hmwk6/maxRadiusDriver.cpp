#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "planet.h"
#include "planet.cpp"



// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 2



int main(){
    Planet planets[5];
planets[0] = Planet(“On A Cob Planet”,1234);
planets[1] = Planet(“Bird World”,4321);
int idx = maxRadius(planets, 2);
cout << planets[idx].getName() << endl;
cout << planets[idx].getRadius() << endl;
cout << planets[idx].getVolume() << endl;


Planet planets[3];
planets[0] = Planet("Planet Squanch",6.8);
planets[1] = Planet("Delphi 6",8.6);
planets[2] = Planet("Cronenberg World",8.6);
int idx = maxRadius(planets, 3);
cout << planets[idx].getName() << endl;
cout << planets[idx].getRadius() << endl;
cout << planets[idx].getVolume() << endl;
}