#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 8 - Problem 2

//algorithm
// set points equal to 0
// set name to an empty string
Player:: Player(){ // constructor setting name to an empty string and points to 0
    points = 0;
    name = "";
}
// algorithm
// input string and double
// set string equal to name
// double equal to points
Player:: Player(string newName, double newPoints){   // parameterized constructor setting name and points to whatever is input
    name = newName;
    points = newPoints;
}
//algorithm
// return name
string Player:: getName(){ // getting the name of the player
    return name;
}
// algorithm
// return points
double Player:: getPoints(){ // getting the player points
    return points;
}
//algorithm
// input string
// set that string equal to the player name
void Player::setName(string newName){ // setting the name to whats input
    name = newName;
}


// algorithm
// input a double
// that input value now equal to points
void Player:: setPoints(double newPoints){ // setting points to the input value
    points = newPoints;
}

int main(){
    
}    