#include <iostream>
#include <cmath>
using namespace std;
#include "planet.h"

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 1, 2



Planet::Planet(){        // here is my constructor initializing my private variables as empty and 0
    planetName = "";
    planetRadius = 0.0;
}
Planet::Planet(string name, double radius){      // this is my parameterized constructor where my private variables are now changedto whatever is put into this function
    planetName= name;
    planetRadius = radius;
}

string Planet::getName(){      // my accessor function for the name of the planet
    return planetName;
}

double Planet::getRadius(){   // accessor function returning the planet radius
    return planetRadius;
}

double Planet::getVolume(){ // accessor function giving volume of the planet based on the input of the planet radius
    double volume = (4*M_PI*planetRadius*planetRadius*planetRadius)/3;
    return volume;
}

void Planet::setName(string name){    // mutator function used to set the planet name
    planetName = name;
}

void Planet::setRadius(double radius){     // mutator used to change my planet radius
    planetRadius = radius;
}




int maxRadius(Planet planet[], int size){  // this is my function I used for problem 2; it finds the planet with the biggest radius and returns the index number of the biggest radius
    double radius[size];
    int biggestRadiusIndex = -1; 
    double biggestRadius=-1.0;
    if(size<=0){      // edge case check for if size is 0 or negative and if so returning 0
        return -1;
    }
    for (int i = 0; i< size; i++){        // for loop that uses the planet class to determine the largest radius of given planets
           if(planet[i].getRadius() > biggestRadius)
           {
               biggestRadius = planet[i].getRadius();  // using the getradius function to store the biggest radius 
               biggestRadiusIndex = i;
           }
            
        }
    return biggestRadiusIndex;    // returning the index of biggest radius 
}



int main(){

}