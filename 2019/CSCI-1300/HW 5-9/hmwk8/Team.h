#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 8 - Problem 3


class Team
{
    private:// private variables
    string teamName; // string for team name
    vector<Player> players; // vector object of type player
    public: // public member functions
    Team();// constructor
    Team(string);// parameterized constructor
    int getNumPlayers();// get number of players
    string getTeamName(); // get team name
    void setTeamName(string); // set team name
    void readRoster(string); // read the roster of players and points
    string getPlayerName(int i); // get player name
    double getPlayerPoints(int i); // get player points
    
};
#endif