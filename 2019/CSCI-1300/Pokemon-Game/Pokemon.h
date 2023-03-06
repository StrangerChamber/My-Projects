#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include "Map.h"
#include "Stats.h"
using namespace std;



class Pokemon
{
  private:
  string pokeType1[151];
  string pokeType2[151];
  string pokeName[151];
  int pokeParty[6];
  int typeCount;
  vector<string> types;
  int counters = 0;
  vector<int> pokedex;
  int randomPokesChosen[20];
  int randomPokeLocationIndex1[20];
  int randomPokeLocationIndex2[20];
  int unluckypoke;
  int wannafightpoke;
  Map maps;
  Stats stat;
  int activePokeIndex;
  public:
  Pokemon();
  void randomPokesChooser();
  string getunluckypoke();
  int getunluckypokeindex();
  void setPokedex(int);
  bool setPokeParty(int);
  int getPokeParty0thPoke();
  int getPokeParty1stPoke();
  int getPokeParty2ndPoke();
  int getPokeParty3rdPoke();
  int getPokeParty4thPoke();
  int getPokeParty5thPoke();  
  void setPokeParty0thPoke(int);
  void setPokeParty1stPoke(int);
  void setPokeParty2ndPoke(int);
  void setPokeParty3rdPoke(int);
  void setPokeParty4thPoke(int);
  void setPokeParty5thPoke(int);  
  void setRandomPoke1stLocation();
  string getType(int);
  string getPokeName(int);
  int getrandomPokelocationindex1(int);
  int getrandomPokeLocationindex2(int);
  void setActivePoke(int);
  void getPokedex();
  string getActivePokeName();
  int getActivePokeIndex();
  bool tryluck(int, int);
  int getcounters();
  void replaceAndMoveRandomPoke(int);
  int getrandompokechosen(int);
  void moverandomPoke();
  bool wannafightbro(int, int);
  int getwannafightpokeindex();
  string getwannafightpokename();
  void newpokelocation(int);
  int unluckyPokeNum();
  int wannafightpokenum();
  int getPokedexSize();
  int getsinglepokedexindex(int);
  void setTypeCount(int);
  int getTypeCount();
  void removePokefromDex(int);
  void lowercounters();
  void resetcounters();
    
};

#endif