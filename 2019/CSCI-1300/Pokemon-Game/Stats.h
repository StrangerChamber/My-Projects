#ifndef STATS_H
#define STATS_H
#include <iostream>
#include <string>
using namespace std;


class Stats{
  private:
  int HP[151];  // health of pokemon
  int originalHP[151];
  int attack[151]; // strength of attacks
  int defense[151]; // resistance against attacks
  int max[151];    // max value of the attack and defense values
  int speed[151]; // speed of poke 
  int pokeballs = 10;
  int points = 0;
  int badges = 0;

  public:
  Stats();
  void setPokeBalls();
  int getPokeballs();
  int getHP(int);
  void setHP(int);
  int getAttack(int);
  void setAttack(int);
  int getDefense(int);
  void setDefense(int);
  int getMax(int);
  int getSpeed(int);
  void setSpeed(int);
  void rest(int);
  void resetHP(int);
  int battleHP(int, int);
  void setPoints(int);
  int getPoints();  
  void addpokeballs(int);
  void addbadge();
  int getBadges();
  void resetPoints();
};
#endif