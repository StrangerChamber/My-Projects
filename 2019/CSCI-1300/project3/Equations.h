#ifndef EQUATIONS_H
#define EQUATIONS_H
#include <iostream>
#include <string>
using namespace std;

class Equations{
  private:
  int F; 
  int damage; 
  int mapPosition; // position of player
  public:
  Equations();
  void setMapPosition(int);
  bool canItRun(int, int, int);// determining whether the pokemon can run or not 
  int findDamage(int, int);// determines how much damage an attack will do
  bool inRange(int);// determines whether a poke is in range of the player to induce a battle
};

#endif