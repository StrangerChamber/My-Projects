#include "Maze.h"
#include <iostream>

Maze::Maze(){// don't need my constructor here to do anything
    
}

void Maze::welcome(){// only time i use this class is to print rules in the beginning of each game
    std::cout << "Welcome Prospective Maze Runner!!! Can you escape my maze?!?!?! Only the strongest survive, enter at your own risk..." << std::endl;
    std::cout << "There are a few rules you should know about: First are the symbols that make up the maze They are as follows:"<< std::endl;
    std::cout << "P is the spot your player currently resides on" << std::endl << "E is the exit square. Make it here and you win." << std::endl << "W's are the walls of the maze. You cannot move onto these spots" << std::endl << "G represents the spots that are empty. You can move onto these spots" << std::endl <<  "B's represents the enemies roaming the maze. If you and an enemy end up on the same square that's game over for you. Every time you make a move the enemies make their own moves as well" << std::endl<< "T means a spot that has treasure on it. If you land on one of these spots you get 100 points" << std::endl;
}