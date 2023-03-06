#include <iostream>
#include <vector>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 8 - Problem 2


class Player
{
  private: // private variables
  string name;  // variable for player name
  double points; // variable for player points
  public: // public member functions
  Player(); // constructor
  Player(string, double); // parameterized constructor
  string getName(); // get name
  double getPoints(); // get points
  void setName(string); // set name
  void setPoints(double); // set points
  
};




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
// checking default constructor
Player stella; 
cout << stella.getName() << endl;
cout << stella.getPoints() << endl;

// checking name setters and getters
Player Stella; 
Stella.setName("Stella");
cout << Stella.getName() << endl;

// checking points setters and getters
Player sTella;
sTella.setPoints(13.1);
cout << sTella.getPoints() << endl;

// checking parameterized constructor
Player hector("Hector", 6.2);
cout << hector.getName() << endl;
cout << hector.getPoints() << endl;
}