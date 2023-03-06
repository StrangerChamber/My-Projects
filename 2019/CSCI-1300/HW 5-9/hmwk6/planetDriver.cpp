#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "planet.h"
#include "planet.cpp"

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 1



int main(){
    //check volume
string name = "Nebraska";
double radius = 866.23;
Planet p5 = Planet(name, radius);
cout << "Planet Name: " << p5.getName() << endl;
cout << "Planet Radius: " << p5.getRadius() << endl;
cout << "Planet Volume: " << p5.getVolume() << endl;

//check volume
string name = "Flarbellon-7";
double radius = 600;
Planet p6 = Planet(name, radius);
cout << "Planet Name: " << p6.getName() << endl;
cout << "Planet Radius: " << p6.getRadius() << endl;
cout << "Planet Volume: " << p6.getVolume() << endl;
}