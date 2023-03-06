#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
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
#endif