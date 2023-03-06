#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include "Trainers.h"
using namespace std;


class Map{
  private:
  string map[25][16];
  int playerIndex1;
  int playerIndex2;
  string mapChar;// stores the kind of tile 
  
  public:
  Map();
  string getMapTile(int, int); 
  int getPlayerIndex1();
  int getPlayerIndex2();
  void playerStart(int);
  void getPlayerLocation();
  void setPlayerLocation(int);// input the direction chosen by player as an int 1-4 (NSEW)
  bool canItLandHere(int, int);
  bool canP1moveHere(int,int);
  void sendtoPokeCenter(int, int);

};


#endif