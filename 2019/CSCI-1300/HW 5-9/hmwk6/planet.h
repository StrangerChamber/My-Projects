#ifndef PLANET_H
#define PLANET_H
#include <iostream>
#include <string>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Haynes
// Homework 6 - Problem 1, 2


class Planet
{
    private:
        string planetName;   // name of the planet
        double planetRadius; // radius of the planet
    
    public:
        Planet();
        Planet(string, double);
        //---------------------------------------------
        string getName(); // returns planetName as a string
        double getRadius(); // Returns planetRadius as a double
        double getVolume(); //Calculates and returns the volume of the planet as a double
        //---------------------------------------------
        void setName(string); // Assigns planetName the value of the input string
        void setRadius(double); // Assigns planetRadius the value of the input double

};

#endif
