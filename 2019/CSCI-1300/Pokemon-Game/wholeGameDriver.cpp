#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
#include <fstream>
#include <unistd.h>
#include <vector>
#include "Trainers.h"
#include "Map.h"
#include "Trainers.cpp"
#include "Map.cpp"
#include "Equations.h"
#include "Equations.cpp"
#include "Stats.h"
#include "Stats.cpp"
#include "Pokemon.h"
#include "Pokemon.cpp"
using namespace std;



int main(){
    Pokemon poke;
    Map maps;
    Trainers trainer;
    Equations EQ;
    Stats stat;
    int endgame = 0;
    while (endgame == 0){
    int num =0;
    int trainerfightopt;
    int endcenter = 0;
    int gym0count = 0;
    int gym1count = 0;
    int gym2count = 0;
    int gym3count = 0;
    int gym4count = 0;
    int gym5count = 0;
    int gym6count = 0;
    int gym7count = 0;
    int gym8count = 0;
    int gym9count = 0;
    int gym10count = 0;
    int gym11count = 0;
    int catchpoke = 0;
    int gym12count = 0;
    int gym13count = 0;
    int gym14count = 0;
    int gymIndex = 0;
    int pokedexchoice = -1;
    int choice = 0;
    int deadpoke = 0;
    int deadpokemon = 0;
    int pokeswitch = 0;
    int howmanyfainted =0 ;
    int winner = 0;
    int book = 0;
    int pokeSwitchChoice = 0;
    int pokefood = 0;
    int firstRound = 0;
    int trainerpokenum = 0;
    int pokecenterswitch = 0;
    int attacked = 0;
    int numOfRuns = 1;
    int fightCounter = 0;
    int direction = 0;
    int fightnum=0;
    int endFight = 0;
    int invalid = 0;
    string playerName = "";
    int pokeStartIndex = 0;
    cout << "Hello future Pokemon trainer, What is your name?" << endl;
    cin.ignore(0 ,' ');
    while(playerName == ""){
    getline(cin, playerName);
    }
    cout << "Hello " << playerName << ", which pokemon would you like to start with?" << endl;
    cout << "Enter 1 for Bulbasaur" << endl << "2 for Charmander" << endl << "3 for Squirtle" << endl << "4 for Pikachu" << endl;
    while(pokeStartIndex<1 || pokeStartIndex>4 ){
        cin >> pokeStartIndex;
        if(pokeStartIndex<1 || pokeStartIndex > 4){
            cout << "Invalid input please enter a number between 1-4 for your choice of Pokemon" << endl;
        }
    }
    if(pokeStartIndex==1){
        
        cout << "You have decided on the Mighty Bulbasuar"<< endl;
        poke.setActivePoke(0);
        poke.setPokeParty(0);
        poke.setPokedex(0);
        maps.playerStart(1);
        
    }
    if(pokeStartIndex==2){
        cout << "You have chosen the mighty Chamander" << endl;
        poke.setActivePoke(3);
        poke.setPokeParty(3);
        poke.setPokedex(3);
        maps.playerStart(2);
    }
    if (pokeStartIndex==3){
        cout << "You have chosen the mighty Squirtle"<< endl;
        poke.setActivePoke(6);
        poke.setPokeParty(6);
        poke.setPokedex(6);
        maps.playerStart(3);
    }
    if(pokeStartIndex==4){
        cout << "You have chosen the mighty Pikachu"<< endl;
        poke.setActivePoke(24);
        poke.setPokeParty(24);
        poke.setPokedex(24);
        maps.playerStart(4);
    }    
    cout << "You automatically recieve 10 pokeballs to start you on your adventure today." << endl << "Pokeballs allow you to capture new pokemon and heal your Pokemon" << endl;
    usleep(1000000);
    cout << "You beat this game by collecting pokemon of 8 different types or by collecting 6 gym badges" << endl;
    usleep(1000000);
    cout << "at every turn a mini map will be displayed to let you know where you are at all times" << endl;
    cout << "the tiles marked with a W denote a water tile. you cannot move onto those tiles" << endl;
    cout << "the tiles marked with a G denote a gym where you can battle the trainer housed at that gym" << endl;
    cout << "the tiles marked with a C denote a pokecenter where you can heal your pokemon and switch the pokemon in your active party" << endl;
    cout << "the tiles marked with a p denote a grass where the wild pokemon roam" << endl;
    cout << "the tile marked with a P1 is your current location" << endl;
    usleep(1000000);
    // set trainer location
    trainer.setTrainerGym();
    // set trainer pokes
    trainer.setTrainerPokes();
    // choose 20 pokemon
    poke.randomPokesChooser();
    // set pokemon location
    poke.setRandomPoke1stLocation();
    // display map and send player on their way
    cout << "At the start of each turn you have the option to move which moves your player one space of your choice," << endl << "try you luck which gives you a chance to catch a pokemon without losing a pokeball" << endl << "rest which raises your pokemons HP by 1, and finally to quit which ends the game" << endl;
    while (num!=4){
        maps.getPlayerLocation();
        cout << "You have " << stat.getPokeballs() << " Pokeballs left" << endl;
        // cout poke party 
        cout << "Your active poke is " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
        if(poke.getcounters() >= 2){
            cout << "The rest of your pokeparty is: " << endl << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
        }
        if(poke.getcounters() >= 3){
            cout <<  poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
        }
        if(poke.getcounters() >= 4){
            cout  << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
        }                    
        if(poke.getcounters() >= 5){
            cout  << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
        }  
        if(poke.getcounters() >= 6){
            cout  << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
        }
        if(book >= 1){
            cout << "It is now time for your next turn" << endl;
        }
        book++;
        cout << "enter 1 for moving" << endl;
        cout << "enter 2 for tyring your luck" << endl;
        cout << "enter 3 for resting" << endl;
        cout << "enter 4 for quitting" << endl;
        while(num<1 || num>4){
            cin>>num;
            if(num<1 || num > 4){
                cout << "Invalid input please enter a number between 1-4 for your choice of what to do next" << endl;
            }
        }    
        if(num ==4){// quit sequence
           break;
        }
        
        if(num == 1){// move 
            cout << "You have chosen to move, which direction do you want to go?" << endl << "Enter:" << endl << "1 for up" << endl << "2 for down" << endl << "3 for right" << endl << "4 for left" << endl;
            while(invalid == 0){
                while (direction<1 || direction>4){
                    cin >> direction;
                    if(direction<1 || direction>4){
                        cout << "Invalid number please enter a number 1-4" << endl;
                    }
                }    
                if(direction == 1){//up
                     if(maps.canP1moveHere(maps.getPlayerIndex1()-1, maps.getPlayerIndex2()) == 1){
                        // cout<< "hey jack you made it into the if statement" << endl;
                         maps.setPlayerLocation(direction);
                         cout << "You have moved up one tile" << endl;
                         invalid++;
                     }
                     else{
                         cout << "you cannot move to this tile please select another direction" << endl;
                     }
                }
                if(direction == 2){//down
                     if(maps.canP1moveHere(maps.getPlayerIndex1()+1, maps.getPlayerIndex2()) == 1){
                         maps.setPlayerLocation(direction);
                         cout << "You have moved one tile down" << endl;
                         invalid++;
                     }
                     else{
                         cout << "you cannot move to this tile please select another direction" << endl;
                     }
                    
                        
                }
                if(direction == 3){//right
                     if(maps.canP1moveHere(maps.getPlayerIndex1(), maps.getPlayerIndex2()+1) == 1){
                         maps.setPlayerLocation(direction);
                         cout << "You have moved one tile to the right" << endl;
                         invalid++;
                     }
                     else{
                         cout << "you cannot move to this tile please select another direction" << endl;
                     }
                        
                }
                if(direction == 4){// left
                     if(maps.canP1moveHere(maps.getPlayerIndex1(), maps.getPlayerIndex2()-1) == 1){
                         maps.setPlayerLocation(direction);
                         cout << "You have moved one tile to the left" << endl;
                         invalid++;
                     }
                     else{
                         cout << "you cannot move to this tile please select another direction" << endl;
                     }
                        
                }
                direction = 0;
            }
            invalid = 0;
            
        }  
        
        if(num == 2){ // try luck
            cout << "You've decided to try your luck!! If there are any pokemon in a 7X7 range of you you have a 50% chance of collecting that poke for free!! I wish you luck!!" << endl;
            if(poke.tryluck(maps.getPlayerIndex1(), maps.getPlayerIndex2())==1){
                srand(time(NULL));
                int num = rand()%2;
                if(num == 1){
                    cout << "Congratulations you have acquired " << poke.getunluckypoke() <<" without losing any pokeballs!!!" << endl;
                    poke.setTypeCount(poke.getunluckypokeindex());
                    string swarm = poke.getunluckypoke();
                    if(poke.setPokeParty(poke.getunluckypokeindex()) == 1){
                        poke.setPokedex(poke.getunluckypokeindex());
                        poke.replaceAndMoveRandomPoke(poke.unluckyPokeNum());
                    
                        cout << swarm <<" has been added to your poke party" << endl;
                    }
                    else{
                        poke.setPokedex(poke.getunluckypokeindex());  // add poke to pokedex
                    poke.replaceAndMoveRandomPoke(poke.unluckyPokeNum());
                        
                        cout << "Your Poke Party is full or there is another pokemon of the same name in your party already so " << swarm << " was added to your pokedex" << endl;
                    }
                }
                if(num == 0){
                    cout << "You're out of Luck:(" << endl;
                }
            }
            else{
                cout<< "There aren't any pokemon in range so I'm afraid you're out of Luck:(" << endl;
            }
            
        }
        
        if(num == 3){// rest
            stat.setPokeBalls();
            if(poke.getcounters()>= 0){
                stat.rest(poke.getPokeParty0thPoke());
            }
            if(poke.getcounters()>=1){
                stat.rest(poke.getPokeParty1stPoke());
            }
            if(poke.getcounters()>=2){
                stat.rest(poke.getPokeParty2ndPoke());
            }
            if(poke.getcounters()>=3){
                stat.rest(poke.getPokeParty3rdPoke());
            }            
            if(poke.getcounters()>=4){
                stat.rest(poke.getPokeParty4thPoke());
            }            
            if(poke.getcounters()>=5){
                stat.rest(poke.getPokeParty5thPoke());
            }            
            
            cout << "All the pokemon in your party gained 1 HP at a cost of 1 pokeball. You now have " << stat.getPokeballs() << " left" << endl;
        }
        
        num = 0;
        poke.moverandomPoke();
        // move the wild pokes one space
        if(poke.wannafightbro(maps.getPlayerIndex1(), maps.getPlayerIndex2())==1){ // check for poke in range for a battle
            cout << "You have stumbled upon a wild " << poke.getwannafightpokename() << " and initialized a battle" << endl;
            while(endFight == 0){
                if(fightCounter<2){
                    cout << "Since this is one of your first two encounters you automatically get " << poke.getwannafightpokename() << " without having to fight" << endl;
                    fightCounter++;
                    poke.setTypeCount(poke.getwannafightpokeindex());
                    //cout << poke.getrandompokechosen(poke.wannafightpokenum()) << " 1"<< endl << poke.getrandomPokelocationindex1(poke.wannafightpokenum()) << endl << poke.getrandomPokeLocationindex2(poke.wannafightpokenum()) << endl;
                    if(poke.setPokeParty(poke.getwannafightpokeindex())==1){
                        //cout << "hi jack" << endl;
                        poke.setPokedex(poke.getwannafightpokeindex());
                        poke.replaceAndMoveRandomPoke(poke.wannafightpokenum()); // replace that wild poke and send it to new random location
                        //cout << poke.getrandompokechosen(poke.wannafightpokenum()) << " 2"<< endl << poke.getrandomPokelocationindex1(poke.wannafightpokenum()) << endl << poke.getrandomPokeLocationindex2(poke.wannafightpokenum()) << endl;
                        endFight++;
                        break;
                    }
                    else{
                        poke.setPokedex(poke.getwannafightpokeindex());
                        poke.replaceAndMoveRandomPoke(poke.wannafightpokenum()); // replace that wild poke and send it to new random location
                        //cout << poke.getrandompokechosen(poke.wannafightpokenum()) << " 2"<< endl << poke.getrandomPokelocationindex1(poke.wannafightpokenum()) << endl << poke.getrandomPokeLocationindex2(poke.wannafightpokenum()) << endl;
                        endFight++;
                        break;
                    }

                    // add poke to party or pokedex 
                }

                if(firstRound == 0 && fightCounter>=2){
                    firstRound++;
                    srand(time(NULL));
                    int numero = rand()%10+1;
                    if(numero<=4){
                        cout << "Oh no " << poke.getwannafightpokename() << " escaped and ran away!!" << endl;
                        // set that pokes location to new random spot
                        poke.newpokelocation(poke.wannafightpokenum());
                        break;
                    }
                }
                cout << "Your active Pokemon is " << poke.getActivePokeName() << endl << "It's HP is: " << stat.getHP(poke.getActivePokeIndex()) << endl << "Attack is: " << stat.getAttack(poke.getActivePokeIndex()) << endl << "Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << endl << "Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "The wild pokemon is " << poke.getwannafightpokename() << endl << "It's HP is: " << stat.getHP(poke.getwannafightpokeindex()) << endl << "Attack is: " << stat.getAttack(poke.getwannafightpokeindex()) << endl << "Defense is: " << stat.getDefense(poke.getwannafightpokeindex())<< endl << "Speed is: " << stat.getSpeed(poke.getwannafightpokeindex()) << endl;
                cout << "You have the option to fight, switch your active pokemon, or run" << endl << "Enter:" << endl << "1 to fight" << endl << "2 to switch pokemon" << endl << "3 to run" << endl;
                while(fightnum<1 || fightnum>3){
                    cin >> fightnum;
                    if(fightnum<1|| fightnum>3){
                        cout << "Invalid entry please enter a number 1-3" << endl;
                    }
                }    
                if(fightnum == 1){// fight sequence
                cout<< "You have chosen to fight " << poke.getwannafightpokename() << endl << "The pokemon with the higher speed value attacks first" << endl;
                srand(time(NULL));
                while(attacked < 2){
                    if(stat.getSpeed(poke.getwannafightpokeindex())>=stat.getSpeed(poke.getActivePokeIndex())){
                        cout << poke.getwannafightpokename() << "'s speed is higher so they get to attack first" <<endl;
                        int att = rand()%stat.getAttack(poke.getwannafightpokeindex());
                        int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                        if(EQ.findDamage(att,def)>0){
                            cout << poke.getwannafightpokename() << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now" << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                        
                            attacked++;
                        }
                        else{
                            cout << "The attack did no damage" << endl;
                            attacked++;
                            
                        }
                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                            cout << poke.getActivePokeName() << " has fainted" << endl;
                            // leveling up the wild poke and resetting all stats to the new max
                            stat.setHP(poke.getwannafightpokeindex());
                            stat.setAttack(poke.getwannafightpokeindex());
                            stat.setDefense(poke.getwannafightpokeindex());
                            stat.setSpeed(poke.getwannafightpokeindex());
                            howmanyfainted++;// tracker to see if I have any poke left to fight with
                            if(howmanyfainted>=poke.getcounters()){
                                cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                poke.newpokelocation(poke.wannafightpokenum());
                                endFight++;// breaks my wild poke fight loop
                                break;// breaks the fight sequence loop
                            }
                            else{
                                cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                if(poke.getcounters() >= 2){
                                    cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                }
                                if(poke.getcounters() >= 3){
                                    cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                }
                                if(poke.getcounters() >= 4){
                                    cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                }                    
                                if(poke.getcounters() >= 5){
                                    cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                }  
                                if(poke.getcounters() >= 6){
                                    cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                }
                                while (deadpokemon == 0){
                                while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                    cin>>pokeSwitchChoice;
                                    if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                        cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                    }
                                    
                                }
                                if(pokeSwitchChoice == 2){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                    // swap active for 1st
                                    int swap  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty1stPoke());
                                    poke.setPokeParty1stPoke(swap);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }
                                if(pokeSwitchChoice == 3){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                    int swape  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty2ndPoke());
                                    poke.setPokeParty2ndPoke(swape);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }  
                                if(pokeSwitchChoice == 4){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                    int swaper  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty3rdPoke());
                                    poke.setPokeParty3rdPoke(swaper);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }          
                                if(pokeSwitchChoice == 5){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                    int sswap  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty4thPoke());
                                    poke.setPokeParty4thPoke(sswap);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }  
                                if(pokeSwitchChoice == 6){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                    int swapp  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty5thPoke());
                                    poke.setPokeParty5thPoke(swapp);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }  
                                if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                    cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                }
                                else{
                                    deadpokemon++;
                                }
                                pokeSwitchChoice = 0; 
                                }
                                deadpokemon =0;
                            }
                            
                        }
                        cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                         att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                         def = rand()%stat.getDefense(poke.getwannafightpokeindex());
                        if(EQ.findDamage(att,def)>0){
                            cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getwannafightpokename() << endl << poke.getwannafightpokename() << "'s HP is now" << stat.battleHP(poke.getwannafightpokeindex(), EQ.findDamage(att,def)) << endl;
                        
                            attacked++;
                        }
                        else{
                            cout << "The attack did no damage" << endl;
                            attacked++;
                            
                        }
                        if(stat.getHP(poke.getwannafightpokeindex()) == 0){
                            cout << "You have defeated " << poke.getwannafightpokename() << " and now they will join you and your active poke will level up" << endl;
                            poke.setTypeCount(poke.getwannafightpokeindex());
                            stat.resetHP(poke.getwannafightpokeindex());
                            if(poke.setPokeParty(poke.getwannafightpokeindex()) == 1){
                                poke.setPokedex(poke.getwannafightpokeindex());
                                cout << poke.getwannafightpokename() <<" has been added to your poke party" << endl;
                            }
                            else{
                                poke.setPokedex(poke.getwannafightpokeindex());  // add poke to pokedex
                                cout << "Your Poke Party is full so " << poke.getwannafightpokename() << " was added to your pokedex" << endl;
                            }
                            poke.replaceAndMoveRandomPoke(poke.wannafightpokenum());
                            stat.setPokeBalls();
                            cout << "You have gained 10 points for your win and lost one pokeball. You now have " << stat.getPokeballs()<<" left" << endl;
                            stat.setPoints(10);
                            stat.setHP(poke.getActivePokeIndex());
                            stat.setAttack(poke.getActivePokeIndex());
                            stat.setDefense(poke.getActivePokeIndex());
                            stat.setSpeed(poke.getActivePokeIndex());
                            endFight++;
                            break;
                        } 

                    }    
                    else{
                        cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                        int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                        int def = rand()%stat.getDefense(poke.getwannafightpokeindex());
                        if(EQ.findDamage(att,def)>0){
                            cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getwannafightpokename() << endl << poke.getwannafightpokename() << "'s HP is now" << stat.battleHP(poke.getwannafightpokeindex(), EQ.findDamage(att,def)) << endl;
                        
                            attacked++;
                        }
                        else{
                            cout << "The attack did no damage" << endl;
                            attacked++;
                            
                        }
                        if(stat.getHP(poke.getwannafightpokeindex()) == 0){
                            cout << "You have defeated " << poke.getwannafightpokename() << " and now they will join you and your active poke will level up" << endl;
                            poke.setTypeCount(poke.getwannafightpokeindex());
                            stat.resetHP(poke.getwannafightpokeindex());
                            if(poke.setPokeParty(poke.getwannafightpokeindex()) == 1){
                                poke.setPokedex(poke.getwannafightpokeindex());
                                cout << poke.getwannafightpokename() <<" has been added to your poke party" << endl;
                            }
                            else{
                                poke.setPokedex(poke.getwannafightpokeindex());  // add poke to pokedex
                                cout << "Your Poke Party is full so " << poke.getwannafightpokename() << " was added to your pokedex" << endl;
                            }
                            poke.replaceAndMoveRandomPoke(poke.wannafightpokenum());
                            stat.setPokeBalls();
                            cout << "You have gained 10 points for your win and lost one pokeball. You now have " << stat.getPokeballs()<<" left" << endl;
                            stat.setPoints(10);
                            stat.setHP(poke.getActivePokeIndex());
                            stat.setAttack(poke.getActivePokeIndex());
                            stat.setDefense(poke.getActivePokeIndex());
                            stat.setSpeed(poke.getActivePokeIndex());
                            endFight++;
                            break;
                        }              
                        cout << "It's now " << poke.getwannafightpokename() << "'s turn to attack" << endl;
                         att = rand()%stat.getAttack(poke.getwannafightpokeindex());
                         def = rand()%stat.getDefense(poke.getActivePokeIndex());
                        if(EQ.findDamage(att,def)>0){
                            cout << poke.getwannafightpokename() << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now" << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                        
                            attacked++;
                        }
                        else{
                            cout << "The attack did no damage" << endl;
                            attacked++;
                            
                        }
                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                            cout << poke.getActivePokeName() << " has fainted" << endl;
                            stat.setHP(poke.getwannafightpokeindex());
                            stat.setAttack(poke.getwannafightpokeindex());
                            stat.setDefense(poke.getwannafightpokeindex());
                            stat.setSpeed(poke.getwannafightpokeindex());
                            howmanyfainted++;
                            if(howmanyfainted>=poke.getcounters()){
                                cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                endFight++;
                                break;
                            }
                            else{
                                cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                if(poke.getcounters() >= 2){
                                    cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                }
                                if(poke.getcounters() >= 3){
                                    cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                }
                                if(poke.getcounters() >= 4){
                                    cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                }                    
                                if(poke.getcounters() >= 5){
                                    cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                }  
                                if(poke.getcounters() >= 6){
                                    cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                }
                                while(deadpokemon == 0){
                                while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                    cin>>pokeSwitchChoice;
                                    if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                        cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                    }
                                    
                                }
                                if(pokeSwitchChoice == 2){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                    // swap active for 1st
                                    int swap  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty1stPoke());
                                    poke.setPokeParty1stPoke(swap);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }
                                if(pokeSwitchChoice == 3){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                    int swape  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty2ndPoke());
                                    poke.setPokeParty2ndPoke(swape);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }  
                                if(pokeSwitchChoice == 4){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                    int swaper  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty3rdPoke());
                                    poke.setPokeParty3rdPoke(swaper);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }          
                                if(pokeSwitchChoice == 5){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                    int sswap  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty4thPoke());
                                    poke.setPokeParty4thPoke(sswap);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }  
                                if(pokeSwitchChoice == 6){
                                    cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                    int swapp  = poke.getActivePokeIndex();
                                    poke.setActivePoke(poke.getPokeParty5thPoke());
                                    poke.setPokeParty5thPoke(swapp);
                                    cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                }
                                if(stat.getHP(poke.getActivePokeIndex())==0){
                                    cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                }
                                else{
                                    deadpokemon++;
                                }
                                pokeSwitchChoice = 0;            
                            }
                            }
                            deadpokemon=0;
                            
                        }                        
                    }
                }
                 attacked = 0;   
                }
                if(fightnum == 2){// switch poke sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                deadpokemon=0;
                pokeSwitchChoice = 0;
                if(fightnum == 3){// run sequence
                    if(stat.getSpeed(poke.getActivePokeIndex())>stat.getSpeed(poke.getwannafightpokeindex())){
                        cout << "You have successfully escaped " << poke.getwannafightpokename() << " and fled to the nearest pokecenter" << endl;
                        // set player location to nearest poke center
                        maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                        poke.newpokelocation(poke.wannafightpokenum());
                        // end fight sequence
                        endFight++;
                    }
                    else{
                        if(EQ.canItRun(stat.getSpeed(poke.getActivePokeIndex()), stat.getSpeed(poke.getwannafightpokeindex()), numOfRuns) == 1){
                             cout << "You have successfully escaped " << poke.getwannafightpokename() << " and fled to the nearest pokecenter" << endl;
                             numOfRuns = 1;
                            maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                            poke.newpokelocation(poke.wannafightpokenum());
                             endFight++;
                        }
                        else{
                            cout << "You cannot run from " << poke.getwannafightpokename() << " just yet" << endl;
                            numOfRuns++;
                        }
                    }
                }
                fightnum = 0; // so my loop works right
            }
            endFight = 0;
            firstRound = 0;
        }
        // then check for pokes within two spaces 
        // after i catch a new poke I need to remove it from the random poke array and replace it and then move it to a new completely random spot
        // in fight sequnce with wild poke remember to replace it with another poke
        // give 10 points if they win and subtract a pokeball

        // remember to keep track of badge count and type count for a winner and point count
        if(maps.getMapTile(maps.getPlayerIndex1(), maps.getPlayerIndex2()) == "G"){//trainer fight situation
            for(int i = 0;i<15;i++){
                if(trainer.getTrainerGymindex1(i) == maps.getPlayerIndex1() && trainer.getTrainerGymindex2(i) == maps.getPlayerIndex2()){
                    cout << "You have landed on trainer "  << trainer.getTrainerName(i) <<"'s gym" << endl;
                    gymIndex = i;
                }
            }
            if(gym0count == 1 && gymIndex ==0){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym1count == 1&&gymIndex == 1){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym2count == 1&&gymIndex == 2){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym3count == 1&&gymIndex == 3){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym4count == 1&&gymIndex == 4){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym5count == 1&&gymIndex == 5){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym6count == 1&&gymIndex == 6){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym7count == 1&&gymIndex == 7){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym8count == 1&&gymIndex == 8){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym9count == 1&&gymIndex == 9){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym10count == 1&&gymIndex == 10){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym11count == 1&&gymIndex == 11){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym12count == 1&&gymIndex == 12){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym13count == 1&&gymIndex == 13){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            if(gym14count == 1&&gymIndex == 14){
                cout << "You have already battled against this trainer once and cannot battle them again" << endl;
            }
            
            if(gymIndex == 0 && gym0count == 0){
                gym0count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT1partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer1Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer1Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer1Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer1Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer1Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer1Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer1Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer1Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer1Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer1Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    trainerpokenum = 0;
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;
                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer1Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer1Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer1Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer1Pokesindex(trainerpokenum));
                                trainerpokenum++;
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                // only add to party/dex if trainers last poke has fainted
                                if(trainerpokenum >= trainer.getT1partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT1partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer1Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer1Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer1Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer1Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer1Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer1Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer1Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer1Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer1Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer1Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                // only add to party/dex if trainers last poke has fainted
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT1partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT1partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer1Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer1Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer1Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer1Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer1Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer1Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer1Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer1Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer1Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer1Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer1Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer1Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    trainerpokenum = 0;

                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;
                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;
                }
                
            if(gymIndex == 1&& gym1count == 0){
                gym1count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT2partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer2Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer2Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer2Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer2Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer2Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer2Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer2Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer2Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer2Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer2Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;
                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer2Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer2Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer2Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer2Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT2partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT2partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer2Pokesindex(i));
                                        
                                        if(poke.setPokeParty(trainer.getTrainer2Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer2Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer2Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer2Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer2Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer2Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer2Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer2Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer2Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                // only add to party/dex if trainers last poke has fainted
                                                                trainerpokenum++;
                                if(trainerpokenum >= trainer.getT2partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT2partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer2Pokesindex(i));
                                        
                                        if(poke.setPokeParty(trainer.getTrainer2Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer2Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer2Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer2Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer2Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer2Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer2Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer2Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer2Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer2Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer2Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;

            }            
            if(gymIndex == 2&& gym2count ==0){
                gym2count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT3partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer3Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer3Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer3Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer3Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer3Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer3Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer3Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer3Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer3Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer3Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;

                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer3Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer3Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer3Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer3Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT3partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT3partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer3Pokesindex(i));
                                        
                                        if(poke.setPokeParty(trainer.getTrainer3Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer3Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer3Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer3Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer3Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer3Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer3Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer3Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer3Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                trainerpokenum++;
                                if(trainerpokenum >= trainer.getT3partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT3partysize();i++){
                                            poke.setTypeCount(trainer.getTrainer3Pokesindex(i));
                                    
                                        if(poke.setPokeParty(trainer.getTrainer3Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer3Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer3Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer3Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer3Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer3Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer3Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer3Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer3Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer3Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer3Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;

                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;

                
            }            
            if(gymIndex == 3&& gym3count == 0){
                gym3count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                               cout << "trainer has " << trainer.getT4partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer4Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer4Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer4Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer4Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer4Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer4Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer4Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer4Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer4Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer4Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    trainerpokenum = 0;

                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer4Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer4Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer4Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer4Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT4partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT4partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer4Pokesindex(i));
                                        
                                        if(poke.setPokeParty(trainer.getTrainer4Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer4Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer4Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer4Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer4Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer4Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer4Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer4Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer4Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                // only add to party/dex if trainers last poke has fainted
                                if(trainerpokenum >= trainer.getT4partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT4partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer4Pokesindex(i));

                                        if(poke.setPokeParty(trainer.getTrainer4Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer4Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer4Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer4Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer4Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer4Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer4Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer4Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer4Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer4Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer4Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;

                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;

                
            }
            if(gymIndex == 4&& gym4count ==0 ){
                gym4count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT5partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer5Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer5Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer5Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer5Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer5Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer5Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer5Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer5Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer5Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer5Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;

                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer5Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer5Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer5Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer5Pokesindex(trainerpokenum));
                                                            stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());        
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT5partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT5partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer5Pokesindex(i));

                                        if(poke.setPokeParty(trainer.getTrainer5Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer5Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer5Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer5Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer5Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer5Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer5Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer5Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer5Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                // only add to party/dex if trainers last poke has fainted
                                if(trainerpokenum >= trainer.getT5partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT5partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer5Pokesindex(i));
                                        
                                        if(poke.setPokeParty(trainer.getTrainer5Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer5Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer5Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer5Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer5Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer5Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer5Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer5Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer5Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer5Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer5Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;

                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;

                
            } 
            if(gymIndex == 5&& gym5count == 0){
                gym5count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                            cout << "trainer has " << trainer.getT6partysize() << " pokes " << endl;
    
                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer6Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer6Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer6Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer6Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer6Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer6Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer6Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer6Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer6Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer6Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;

                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer6Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer6Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer6Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer6Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT6partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT6partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer6Pokesindex(i));

                                        if(poke.setPokeParty(trainer.getTrainer6Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer6Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer6Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer6Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer6Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer6Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer6Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer6Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer6Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                // only add to party/dex if trainers last poke has fainted
                                if(trainerpokenum >= trainer.getT6partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT6partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer6Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer6Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer6Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer6Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer6Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer6Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer6Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer6Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer6Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer6Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer6Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer6Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;
                
            }  
            if(gymIndex == 6&& gym6count == 0){
                gym6count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                cout << "trainer has " << trainer.getT7partysize() << " pokes " << endl;
                
                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer7Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer7Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer7Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer7Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer7Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer7Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer7Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer7Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer7Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer7Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer7Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer7Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer7Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer7Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT7partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT7partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer7Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer7Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer7Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer7Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer7Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer7Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer7Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer7Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer7Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer7Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                // only add to party/dex if trainers last poke has fainted
                                if(trainerpokenum >= trainer.getT7partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT7partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer7Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer7Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer7Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer7Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer7Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer7Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer7Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer7Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer7Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer7Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer7Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer7Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;

                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;

                
            } 
            if(gymIndex == 7&& gym7count == 0){
                gym7count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT8partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer8Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer8Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer8Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer8Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer8Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer8Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer8Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer8Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer8Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer8Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;

                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer8Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer8Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer8Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer8Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                // only add to party/dex if trainers last poke has fainted
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT8partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT8partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer8Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer8Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer8Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer8Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer8Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer8Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer8Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer8Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer8Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer8Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                // only add to party/dex if trainers last poke has fainted
                                if(trainerpokenum >= trainer.getT8partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT8partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer8Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer8Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer8Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer8Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer8Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer8Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer8Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer8Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer8Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer8Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer8Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer8Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;

                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;
                
            }            
            if(gymIndex == 8&& gym8count == 0){
                gym8count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                        cout << "trainer has " << trainer.getT9partysize() << " pokes " << endl;
        
                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer9Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer9Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer9Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer9Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer9Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer9Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer9Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer9Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer9Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer9Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer9Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer9Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer9Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer9Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT9partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT9partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer9Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer9Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer9Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer9Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer9Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer9Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer9Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer9Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer9Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer9Pokesindex(trainerpokenum));
                                // only add to party/dex if trainers last poke has fainted
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                if(trainerpokenum >= trainer.getT9partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT9partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer9Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer9Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer9Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer9Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer9Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer9Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer9Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer9Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer9Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer9Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer9Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer9Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;
                
            }   
            if(gymIndex == 9&& gym9count== 0){
                gym9count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                cout << "trainer has " << trainer.getT10partysize() << " pokes " << endl;
                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer10Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer10Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer10Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer10Pokesindex(trainerpokenum)) << endl;
               
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer10Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer10Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer10Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer10Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer10Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer10Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer10Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer10Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer10Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer10Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT10partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT10partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer10Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer10Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer10Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer10Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer10Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer10Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer10Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer10Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer10Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer10Pokesindex(trainerpokenum));
                                // only add to party/dex if trainers last poke has fainted
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                if(trainerpokenum >= trainer.getT10partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT10partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer10Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer10Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer10Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer10Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer10Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer10Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer10Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer10Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer10Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer10Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer10Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer10Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;                
            }            
            if(gymIndex == 10&& gym10count == 0){
                gym10count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT11partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer11Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer11Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer11Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer11Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer11Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer11Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer11Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer11Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer11Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer11Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer11Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer11Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer11Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer11Pokesindex(trainerpokenum));
                                trainerpokenum++;                         
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                if(trainerpokenum >= trainer.getT11partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT11partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer11Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer11Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer11Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer11Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer11Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer11Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer11Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer11Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer11Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer11Pokesindex(trainerpokenum));
                                // only add to party/dex if trainers last poke has fainted
                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());     
                                    trainerpokenum++;
                                if(trainerpokenum >= trainer.getT11partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT11partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer11Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer11Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer11Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer11Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer11Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer11Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer11Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer11Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer11Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer11Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer11Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer11Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;                
                
            }        
            if(gymIndex == 11&& gym11count ==0){
                gym11count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT12partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer12Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer12Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer12Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer12Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer12Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer12Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer12Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer12Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer12Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer12Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer12Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer12Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer12Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer12Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT12partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT12partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer12Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer12Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer12Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer12Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer12Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer12Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer12Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer12Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer12Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer12Pokesindex(trainerpokenum));
                                // only add to party/dex if trainers last poke has fainted
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                if(trainerpokenum >= trainer.getT12partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT12partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer12Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer12Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer12Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer12Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer12Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer12Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer12Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer12Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer12Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer12Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer12Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer12Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;  
                
            }      
            if(gymIndex == 12&& gym12count == 0){
                gym12count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT13partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer13Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer13Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer13Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer13Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer13Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer13Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer13Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer13Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer13Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer13Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer13Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer13Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer13Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer13Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT13partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT13partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer13Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer13Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer13Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer13Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer13Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer13Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer13Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer13Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer13Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer13Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                // only add to party/dex if trainers last poke has fainted
                                trainerpokenum++;
                                if(trainerpokenum >= trainer.getT13partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT13partysize();i++){
                                         poke.setTypeCount(trainer.getTrainer13Pokesindex(i));
                                       if(poke.setPokeParty(trainer.getTrainer13Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer13Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer13Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer13Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer13Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer13Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer13Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer13Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer13Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer13Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer13Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;                  
            }            
            if(gymIndex == 13&& gym13count == 0){
                gym13count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT14partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer14Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer14Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer14Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer14Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer14Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer14Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer14Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer14Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer14Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer14Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer14Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer14Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer14Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer14Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT14partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT14partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer14Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer14Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer14Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer14Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer14Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer14Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer14Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer14Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer14Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer14Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    trainerpokenum++;
                                // only add to party/dex if trainers last poke has fainted
                                if(trainerpokenum >= trainer.getT14partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT14partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer14Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer14Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer14Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer14Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer14Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer14Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer14Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer14Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer14Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer14Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer14Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer14Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;                 
            }           
            if(gymIndex == 14 && gym14count == 0){
                gym14count++;
                cout << "You will now battle " << trainer.getTrainerName(gymIndex) << endl;
                                cout << "trainer has " << trainer.getT15partysize() << " pokes " << endl;

                while(endFight==0){
                cout << trainer.getTrainerName(gymIndex) << "'s active pokemon is " << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << " HP: " << stat.getHP(trainer.getTrainer15Pokesindex(trainerpokenum)) << " A: " << stat.getAttack(trainer.getTrainer15Pokesindex(trainerpokenum)) << " D: " << stat.getDefense(trainer.getTrainer15Pokesindex(trainerpokenum)) << " S: " << stat.getSpeed(trainer.getTrainer15Pokesindex(trainerpokenum)) << endl;
                cout << "Your active poke is " << poke.getActivePokeName() << " HP: " << stat.getHP(poke.getActivePokeIndex()) << " A: " << stat.getAttack(poke.getActivePokeIndex()) << " D: " << stat.getDefense(poke.getActivePokeIndex()) << " S: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                cout << "When battling a trainer you only have 2 options: fight or switch Pokemon " << endl << "Enter: 1 for fighting" << endl << "2 for switching " << endl;
                while (trainerfightopt <1 || trainerfightopt>2){
                    cin>>trainerfightopt;
                    if(trainerfightopt <1 || trainerfightopt>2){
                        cout << "Invalid input please enter 1 or 2" << endl;
                    }
                }
                if(trainerfightopt == 1){// fight sequence
                    cout<< "You have chosen to fight " << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << endl << "The pokemon with the higher speed value attacks first" << endl;
                    srand(time(NULL));
                    while(attacked < 2){ 
                        if(stat.getSpeed(trainer.getTrainer15Pokesindex(trainerpokenum))>=stat.getSpeed(poke.getActivePokeIndex())){
                            cout << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << "'s speed is higher so they get to attack first" <<endl;
                            int att = rand()%stat.getAttack(trainer.getTrainer15Pokesindex(trainerpokenum));
                            int def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer15Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer15Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer15Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer15Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                        cin>>pokeSwitchChoice;
                                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                        }
                                        
                                    }
                                    if(pokeSwitchChoice == 2){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                        // swap active for 1st
                                        int swap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty1stPoke());
                                        poke.setPokeParty1stPoke(swap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }
                                    if(pokeSwitchChoice == 3){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                        int swape  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                                        poke.setPokeParty2ndPoke(swape);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 4){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                        int swaper  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                                        poke.setPokeParty3rdPoke(swaper);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }          
                                    if(pokeSwitchChoice == 5){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                        int sswap  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty4thPoke());
                                        poke.setPokeParty4thPoke(sswap);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(pokeSwitchChoice == 6){
                                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                        int swapp  = poke.getActivePokeIndex();
                                        poke.setActivePoke(poke.getPokeParty5thPoke());
                                        poke.setPokeParty5thPoke(swapp);
                                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                    }  
                                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                        cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                    }
                                    else{
                                        deadpokemon++;
                                    }
                                    pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            }
                            cout << "it is now "  << poke.getActivePokeName() << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(poke.getActivePokeIndex()); 
                             def = rand()%stat.getDefense(trainer.getTrainer15Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer15Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer15Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer15Pokesindex(trainerpokenum));
                                                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                trainerpokenum++;                                
                                if(trainerpokenum >= trainer.getT15partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated "  << trainer.getTrainerName(gymIndex) << " and acquired all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT15partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer15Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer15Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer15Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer15Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer15Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer15Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                            }
    
                        }    
                        else{
                            cout << poke.getActivePokeName() << " has a higher speed so it will attack first" << endl;
                            int att = rand()%stat.getAttack(poke.getActivePokeIndex());
                            int def = rand()%stat.getDefense(trainer.getTrainer15Pokesindex(trainerpokenum));
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getActivePokeName() << "'s attack was successful and took " << EQ.findDamage(att,def) << " HP from " << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum))<< endl << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << "'s HP is now" << stat.battleHP(trainer.getTrainer15Pokesindex(trainerpokenum), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(trainer.getTrainer15Pokesindex(trainerpokenum)) == 0){
                                cout << "You have defeated " << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << " and now your active poke will level up" << endl;
                                stat.resetHP(trainer.getTrainer15Pokesindex(trainerpokenum));
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());                                
                                // only add to party/dex if trainers last poke has fainted
                                                                trainerpokenum++;
                                if(trainerpokenum >= trainer.getT15partysize()){
                                    trainerpokenum = 0;
                                    cout << "You have defeated" << trainer.getTrainerName(gymIndex) << " and now you get all of their pokemon" << endl;
                                    for(int i = 0; i<trainer.getT15partysize();i++){
                                        poke.setTypeCount(trainer.getTrainer15Pokesindex(i));
                                        if(poke.setPokeParty(trainer.getTrainer15Pokesindex(i)) == 1){
                                            poke.setPokedex(trainer.getTrainer15Pokesindex(i));
                                            cout << poke.getPokeName(trainer.getTrainer15Pokesindex(i)) <<" has been added to your poke party" << endl;
                                        }
                                        else{
                                            poke.setPokedex(trainer.getTrainer15Pokesindex(i));  // add poke to pokedex
                                            cout << "Your Poke Party is full so " << poke.getPokeName(trainer.getTrainer15Pokesindex(i)) << " was added to your pokedex" << endl;
                                        }
                                    }    
                                    stat.addpokeballs(5);
                                    stat.addbadge();
                                    cout << "You have gained 60 points for your win, gained a gym badge, and gained 5 pokeballs. You now have " << stat.getPokeballs()<<" left, " << stat.getPoints() << " points and " << stat.getBadges() << " Badges" << endl;
                                    stat.setPoints(60);
                                    stat.setHP(poke.getActivePokeIndex());
                                    stat.setAttack(poke.getActivePokeIndex());
                                    stat.setDefense(poke.getActivePokeIndex());
                                    stat.setSpeed(poke.getActivePokeIndex());
                                    endFight++;
                                    break;
                                }
                                
                            }
                 
                            cout << "It's now " << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << "'s turn to attack" << endl;
                             att = rand()%stat.getAttack(trainer.getTrainer15Pokesindex(trainerpokenum));
                             def = rand()%stat.getDefense(poke.getActivePokeIndex());
                            if(EQ.findDamage(att,def)>0){
                                cout << poke.getPokeName(trainer.getTrainer15Pokesindex(trainerpokenum)) << "'s attack was successful and took" << EQ.findDamage(att,def) << "HP from " << poke.getActivePokeName() << endl << poke.getActivePokeName() << "'s HP is now " << stat.battleHP(poke.getActivePokeIndex(), EQ.findDamage(att,def)) << endl;
                            
                                attacked++;
                            }
                            else{
                                cout << "The attack did no damage" << endl;
                                attacked++;
                                
                            }
                            if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                cout << poke.getActivePokeName() << " has fainted" << endl;
                                // leveling up the wild poke and resetting all stats to the new max
                                stat.setHP(trainer.getTrainer15Pokesindex(trainerpokenum));
                                stat.setAttack(trainer.getTrainer15Pokesindex(trainerpokenum));
                                stat.setDefense(trainer.getTrainer15Pokesindex(trainerpokenum));
                                stat.setSpeed(trainer.getTrainer15Pokesindex(trainerpokenum));
                                howmanyfainted++;// tracker to see if I have any poke left to fight with
                                if(howmanyfainted>=poke.getcounters()){
                                    cout << "You are out of pokemon to fight with and will be sent to a pokecenter" << endl;
                                    trainerpokenum = 0;
                                    cout << "You have lost to " << trainer.getTrainerName(gymIndex) << " and will never be able to battle them again" << endl;

                                    maps.sendtoPokeCenter(maps.getPlayerIndex1(), maps.getPlayerIndex2());
                                    endFight++;// breaks my wild poke fight loop
                                    break;// breaks the fight sequence loop
                                }
                                else{
                                    cout << "Since your active poke has fainted you must replace it with another poke from your party " << endl;
                                    if(poke.getcounters() >= 2){
                                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 3){
                                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                                    }
                                    if(poke.getcounters() >= 4){
                                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                                    }                    
                                    if(poke.getcounters() >= 5){
                                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                                    }  
                                    if(poke.getcounters() >= 6){
                                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                                    }
                                    while (deadpokemon == 0){
                                        while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                                            cin>>pokeSwitchChoice;
                                            if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                                                cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                                            }
                                        }
                                        if(pokeSwitchChoice == 2){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                                            // swap active for 1st
                                            int swap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty1stPoke());
                                            poke.setPokeParty1stPoke(swap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }
                                        if(pokeSwitchChoice == 3){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                                            int swape  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty2ndPoke());
                                            poke.setPokeParty2ndPoke(swape);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 4){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                                            int swaper  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty3rdPoke());
                                            poke.setPokeParty3rdPoke(swaper);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }          
                                        if(pokeSwitchChoice == 5){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                                            int sswap  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty4thPoke());
                                            poke.setPokeParty4thPoke(sswap);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(pokeSwitchChoice == 6){
                                            cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                                            int swapp  = poke.getActivePokeIndex();
                                            poke.setActivePoke(poke.getPokeParty5thPoke());
                                            poke.setPokeParty5thPoke(swapp);
                                            cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                                        }  
                                        if(stat.getHP(poke.getActivePokeIndex()) == 0){
                                            cout << "This pokemon has already fainted and cannot battle please choose another pokemon" << endl;
                                        }
                                        else{
                                            deadpokemon++;
                                        }
                                        pokeSwitchChoice = 0; 
                                    }
                                    deadpokemon =0;
                                }
                                
                            
                        }
                    
                        
                    }
                    }
                    attacked = 0;
                }
                if(trainerfightopt == 2){// switch sequence
                    cout << "You have chosen to change your active poke from " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                    if(poke.getcounters()==1){
                        cout << "You don't have any other pokemon in your party to change to" << endl;
                    }
                    if(poke.getcounters() >= 2){
                        cout << "Enter 2 to change your poke to " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                    }
                    if(poke.getcounters() >= 3){
                        cout << "Enter 3 to change your poke to " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                    }
                    if(poke.getcounters() >= 4){
                        cout << "Enter 4 to change your poke to " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                    }                    
                    if(poke.getcounters() >= 5){
                        cout << "Enter 5 to change your poke to " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                    }  
                    if(poke.getcounters() >= 6){
                        cout << "Enter 6 to change your poke to " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                    }
                    while (deadpokemon==0){
                    while(pokeSwitchChoice<2 || pokeSwitchChoice>poke.getcounters()){    
                        cin>>pokeSwitchChoice;
                        if(pokeSwitchChoice>poke.getcounters() || pokeSwitchChoice<2){
                            cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                        }
                        
                    }
                    if(pokeSwitchChoice == 2){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                        // swap active for 1st
                        int swap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty1stPoke());
                        poke.setPokeParty1stPoke(swap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(pokeSwitchChoice == 3){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                        int swape  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty2ndPoke());
                        poke.setPokeParty2ndPoke(swape);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 4){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                        int swaper  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty3rdPoke());
                        poke.setPokeParty3rdPoke(swaper);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }          
                    if(pokeSwitchChoice == 5){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                        int sswap  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty4thPoke());
                        poke.setPokeParty4thPoke(sswap);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }  
                    if(pokeSwitchChoice == 6){
                        cout << "You have chosen to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                        int swapp  = poke.getActivePokeIndex();
                        poke.setActivePoke(poke.getPokeParty5thPoke());
                        poke.setPokeParty5thPoke(swapp);
                        cout << "Your active Pokemon is now " << poke.getActivePokeName() << endl;
                    }
                    if(stat.getHP(poke.getActivePokeIndex()) == 0){
                        cout << "This poke has fainted and cannot become your active pokemon please choose another" << endl;   
                    }
                    else{
                        deadpokemon++;
                    }
                }
                }
                trainerfightopt = 0;
                deadpokemon=0;
                pokeSwitchChoice = 0;                    
                }
                endFight = 0;                
            }            
            
        }    

        if(maps.getMapTile(maps.getPlayerIndex1(), maps.getPlayerIndex2()) == "C"){// pokecenter sequence
            cout << "You have arrived at a Pokecenter where all the pokemon in your party will have their HP restored and you have the option to reorganize your poke suite" << endl;
            howmanyfainted = 0;
            stat.resetHP(poke.getActivePokeIndex());
            if(poke.getcounters()>=2){
                stat.resetHP(poke.getPokeParty1stPoke());
            }
            if(poke.getcounters()>=3){
                stat.resetHP(poke.getPokeParty2ndPoke());
            }
            if(poke.getcounters()>=4){
                stat.resetHP(poke.getPokeParty3rdPoke());
            }
            if(poke.getcounters()>=5){
                stat.resetHP(poke.getPokeParty4thPoke());
            }
            if(poke.getcounters()>=6){
                stat.resetHP(poke.getPokeParty5thPoke());
            }
            cout << "All of your pokemon's HP is now fully restored" << endl << "Would you like to switch pokemon from your pokedex to your party?" << endl << "Enter 1 for Yes" << endl << "2 for no" << endl;
            while(choice>2 || choice<1){
                cin>>choice;
                if(choice>2 || choice<1){
                    cout << "Please enter 1 or 2" << endl;
                }
            }
            while (endcenter == 0){
            if(choice == 1){// change pokemon 
            cout << "You have chosen to change up your pokeparty" << endl;
                cout << "1: Your active poke is " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
            if(poke.getcounters() >= 2){
                cout << "The rest of your pokeparty is: " << endl << "2: " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
            }
            if(poke.getcounters() >= 3){
                cout <<  "3: " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
            }
            if(poke.getcounters() >= 4){
                cout  << "4: "<< poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
            }                    
            if(poke.getcounters() >= 5){
                cout  << "5: " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
            }  
            if(poke.getcounters() >= 6){
                cout  << "6: " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
            }
            cout << "The rest of these Pokemons are in your pokedex:" << endl;
            poke.getPokedex();
            cout << "To switch pokemon first enter the number next to the pokemon in your party you would like to replace" << endl;
            while(pokecenterswitch<1 || pokecenterswitch>poke.getcounters()){    
                cin>>pokecenterswitch;
                if(pokecenterswitch>poke.getcounters() || pokecenterswitch<1){
                    cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                }
            }
            cout << "Now enter the number next to the pokemon in the pokedex for which you want to be in your party" << endl;
            while(pokedexchoice<0 || pokedexchoice>poke.getPokedexSize()){
                cin>>pokedexchoice;
                if(pokedexchoice<0 || pokedexchoice>poke.getPokedexSize()){
                    cout <<"please enter a valid number" << endl;
                }
                if(poke.getActivePokeIndex() == poke.getsinglepokedexindex(pokedexchoice) || poke.getPokeParty1stPoke() == poke.getsinglepokedexindex(pokedexchoice) || poke.getPokeParty2ndPoke()==poke.getsinglepokedexindex(pokedexchoice) || poke.getPokeParty3rdPoke()== poke.getsinglepokedexindex(pokedexchoice)|| poke.getPokeParty4thPoke()== poke.getsinglepokedexindex(pokedexchoice)|| poke.getPokeParty5thPoke()== poke.getsinglepokedexindex(pokedexchoice)){
                    if(poke.getPokedexSize() == poke.getcounters()){
                        
                        cout << "There aren't any pokemon in your pokedex that aren't already in your pokedex" << endl;
                        pokedexchoice=1;
                        pokecenterswitch= 7;
                        endcenter++;
                        break;
                    }
                    cout << "This pokemon is already in your party please choose another not in your party" << endl;
                    pokedexchoice = -1;
                }
            }            
            if(pokecenterswitch == 1){
                cout << "You have decided to replace " << poke.getActivePokeName() << " for " << poke.getPokeName(poke.getsinglepokedexindex(pokedexchoice)) << endl;
            poke.setActivePoke(poke.getsinglepokedexindex(pokedexchoice));
                
            }
            if(pokecenterswitch == 2){
                cout << "You have decided to replace " << poke.getPokeName(poke.getPokeParty1stPoke())<< " for " << poke.getPokeName(poke.getsinglepokedexindex(pokedexchoice)) <<endl;
            
                poke.setPokeParty1stPoke(poke.getsinglepokedexindex(pokedexchoice));
            }
            if(pokecenterswitch == 3){
                cout << "You have decided to replace " << poke.getPokeName(poke.getPokeParty2ndPoke())<<" for " << poke.getPokeName(poke.getsinglepokedexindex(pokedexchoice)) << endl;
            
                poke.setPokeParty2ndPoke(poke.getsinglepokedexindex(pokedexchoice));

            }
            if(pokecenterswitch==4){
                cout <<"You have decided to replace " << poke.getPokeName(poke.getPokeParty3rdPoke())<< " for " << poke.getPokeName(poke.getsinglepokedexindex(pokedexchoice)) <<endl;
                poke.setPokeParty3rdPoke(poke.getsinglepokedexindex(pokedexchoice));
            
                
            }
            if(pokecenterswitch == 5){
                cout <<"You have decided to replace " << poke.getPokeName(poke.getPokeParty4thPoke()) << " for " << poke.getPokeName(poke.getsinglepokedexindex(pokedexchoice)) <<endl;
            
                poke.setPokeParty4thPoke(poke.getsinglepokedexindex(pokedexchoice));
                
            }
            if(pokecenterswitch == 6){
                cout <<"You have decided to replace "<< poke.getPokeName(poke.getPokeParty5thPoke())<< " for " << poke.getPokeName(poke.getsinglepokedexindex(pokedexchoice)) <<endl;
                poke.setPokeParty5thPoke(poke.getsinglepokedexindex(pokedexchoice));
           
            }
            cout << "Your pokeparty is now comprised of:" << endl;
            cout << "1: Your active poke is " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
            if(poke.getcounters() >= 2){
                cout << "The rest of your pokeparty is: " << endl << "2: " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
            }
            if(poke.getcounters() >= 3){
                cout <<  "3: " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
            }
            if(poke.getcounters() >= 4){
                cout  << "4: "<< poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
            }                    
            if(poke.getcounters() >= 5){
                cout  << "5: " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
            }  
            if(poke.getcounters() >= 6){
                cout  << "6: " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
            }
            cout << "Would you like to switch another poke?" << endl << "1 for yes" << endl << "2 for no" << endl;
            while(pokeswitch<1 || pokeswitch>2){    
                cin>>pokeswitch;
                if(pokeswitch<1 || pokeswitch>2){
                    cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                }
            }
            if(pokeswitch == 1){
                cout << "You have chosen to switch another pokemon" << endl;
            }
            if(pokeswitch == 2){
                endcenter++;
            }
            pokeswitch = 0;

            }
        
            if(choice == 2){
                cout << "You have chosen not to change your pokemon. Now we will send you back into your adventure. Good luck:)" << endl;
                endcenter++;
            }
        pokecenterswitch = 0;
        pokedexchoice = -1;
            }
            endcenter = 0;
            choice = 0;            

        }
        srand(time(NULL));
        int catchNew = rand()%10;
        if(catchNew<=2){
            cout << "Another Poke has stumbled in your lap would you like to catch it for one pokeball or release it?" << endl << "Enter 1 to catch or 2 to release" << endl;
            while(catchpoke<1 || catchpoke>2){
                cin>>catchpoke;
                if(catchpoke<1 || catchpoke>2){
                    cout << "Invalid input please enter 1 or 2" <<endl;
                }
            }
            if(catchpoke == 1){
                srand(time(NULL));
                int moneypoke = rand()%151;
                poke.setTypeCount(moneypoke);
                stat.setPokeBalls();
                cout << "You have decided to catch " << poke.getPokeName(moneypoke) << " for one pokeball. you now have " << stat.getPokeballs() << " left" << endl;
                if(poke.setPokeParty(moneypoke) == 1){
                    poke.setPokedex(moneypoke);
                    cout << poke.getPokeName(moneypoke) <<" has been added to your poke party" << endl;
                }
                else{
                    poke.setPokedex(moneypoke);  // add poke to pokedex
                    cout << "Your Poke Party is full so " << poke.getPokeName(moneypoke) << " was added to your pokedex" << endl;
                }
            }
            if(catchpoke==2){
                cout << "You have decided not to get a new pokemon" << endl;
            }
            catchpoke = 0;
        }
        int treasure = rand()%100;
        if(treasure<25){
            int whichT = rand()%2;
            if(whichT==0){
                stat.addpokeballs(2);
                cout << "You have discovered 2 pokeballs. You now have " << stat.getPokeballs() << " left" << endl; 
            }
            if(whichT == 1){
                cout << "You have stumbled upon some Magic food for which you can give to one of your pokemon for them to level up." << endl << "Which Poke would you like to give it to?" << endl;
                cout << "Enter the number next to the pokemon to give them the food" << endl;
                cout << "1: Your active poke is " << poke.getActivePokeName() << " It's HP is: " << stat.getHP(poke.getActivePokeIndex())  << " Attack is: " << stat.getAttack(poke.getActivePokeIndex())  << " Defense is: " << stat.getDefense(poke.getActivePokeIndex()) << " Speed is: " << stat.getSpeed(poke.getActivePokeIndex()) << endl;
                if(poke.getcounters() >= 2){
                    cout << "The rest of your pokeparty is: " << endl << "2: " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                }
                if(poke.getcounters() >= 3){
                    cout <<  "3: " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                }
                if(poke.getcounters() >= 4){
                    cout  << "4: "<< poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                }                    
                if(poke.getcounters() >= 5){
                    cout  << "5: " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                }  
                if(poke.getcounters() >= 6){
                    cout  << "6: " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                }
                while(pokefood<1 || pokefood>poke.getcounters()){    
                    cin>>pokefood;
                    if(pokefood>poke.getcounters() || pokefood<1){
                        cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                    }
                }
                if(pokefood == 1){
                    cout << "You have chosen to level up " << poke.getActivePokeName() << endl;
                    stat.setHP(poke.getActivePokeIndex());
                    stat.setAttack(poke.getActivePokeIndex());
                    stat.setDefense(poke.getActivePokeIndex());
                    stat.setSpeed(poke.getActivePokeIndex());
                }
                if(pokefood == 2){
                    cout << "You have chosen to level up " << poke.getPokeName(poke.getPokeParty1stPoke()) << endl;
                    stat.setHP(poke.getPokeParty1stPoke());
                    stat.setAttack(poke.getPokeParty1stPoke());
                    stat.setDefense(poke.getPokeParty1stPoke());
                    stat.setSpeed(poke.getPokeParty1stPoke());
                }                
                if(pokefood == 3){
                    cout << "You have chosen to level up " << poke.getPokeName(poke.getPokeParty2ndPoke()) << endl;
                    stat.setHP(poke.getPokeParty2ndPoke());
                    stat.setAttack(poke.getPokeParty2ndPoke());
                    stat.setDefense(poke.getPokeParty2ndPoke());
                    stat.setSpeed(poke.getPokeParty2ndPoke());
                }
                if(pokefood == 4){
                    cout << "You have chosen to level up " << poke.getPokeName(poke.getPokeParty3rdPoke()) << endl;
                    stat.setHP(poke.getPokeParty3rdPoke());
                    stat.setAttack(poke.getPokeParty3rdPoke());
                    stat.setDefense(poke.getPokeParty3rdPoke());
                    stat.setSpeed(poke.getPokeParty3rdPoke());
                }   
                if(pokefood == 5){
                    cout << "You have chosen to level up " << poke.getPokeName(poke.getPokeParty4thPoke()) << endl;
                    stat.setHP(poke.getPokeParty4thPoke());
                    stat.setAttack(poke.getPokeParty4thPoke());
                    stat.setDefense(poke.getPokeParty4thPoke());
                    stat.setSpeed(poke.getPokeParty4thPoke());
                }                
                if(pokefood == 6){
                    cout << "You have chosen to level up " << poke.getPokeName(poke.getPokeParty5thPoke()) << endl;
                    stat.setHP(poke.getPokeParty5thPoke());
                    stat.setAttack(poke.getPokeParty5thPoke());
                    stat.setDefense(poke.getPokeParty5thPoke());
                    stat.setSpeed(poke.getPokeParty5thPoke());
                }
                pokefood=0;
            }
        }
        int wannadie= rand()%5;
        if(wannadie == 0){
            int deadB = rand()%poke.getcounters();
            if(deadB == 0){
                cout << "OH NO " << poke.getActivePokeName() << " Has passed away from old age!!! What a shame;( " << endl;
                cout << " Enter the number next to the pokemon you wish to replace it with " << endl;
                if(poke.getcounters()>=2){   
                    cout << "2: " << poke.getPokeName(poke.getPokeParty1stPoke()) << " HP: " << stat.getHP(poke.getPokeParty1stPoke()) << ", A: " << stat.getAttack(poke.getPokeParty1stPoke()) << ", D: " << stat.getDefense(poke.getPokeParty1stPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty1stPoke()) << endl;
                }
                if(poke.getcounters() >= 3){
                    cout <<  "3: " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " HP: " << stat.getHP(poke.getPokeParty2ndPoke()) << ", A: " << stat.getAttack(poke.getPokeParty2ndPoke()) << ", D: " << stat.getDefense(poke.getPokeParty2ndPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty2ndPoke()) << endl;
                }
                if(poke.getcounters() >= 4){
                    cout  << "4: "<< poke.getPokeName(poke.getPokeParty3rdPoke()) << " HP: " << stat.getHP(poke.getPokeParty3rdPoke()) << ", A: " << stat.getAttack(poke.getPokeParty3rdPoke()) << ", D: " << stat.getDefense(poke.getPokeParty3rdPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty3rdPoke()) << endl;
                }                    
                if(poke.getcounters() >= 5){
                    cout  << "5: " << poke.getPokeName(poke.getPokeParty4thPoke()) << " HP: " << stat.getHP(poke.getPokeParty4thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty4thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty4thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty4thPoke()) << endl;
                }  
                if(poke.getcounters() >= 6){
                    cout  << "6: " << poke.getPokeName(poke.getPokeParty5thPoke()) << " HP: " << stat.getHP(poke.getPokeParty5thPoke()) << ", A: " << stat.getAttack(poke.getPokeParty5thPoke()) << ", D: " << stat.getDefense(poke.getPokeParty5thPoke()) << ", S: " << stat.getSpeed(poke.getPokeParty5thPoke()) << endl;
                }
                while(deadpoke<2 || deadpoke>poke.getcounters()){    
                    cin>>deadpoke;
                    if(deadpoke>poke.getcounters() || deadpoke<2){
                        cout << "Invalid input please enter a number corresponding to one of the above choices" << endl;
                    }
                }
                poke.removePokefromDex(poke.getActivePokeIndex());// removed from dex
                if(deadpoke == 2){
                    cout << "you have chosen " << poke.getPokeName(poke.getPokeParty1stPoke()) << " to be your new active pokemon " << endl;
                    poke.setActivePoke(poke.getPokeParty1stPoke());
                    poke.setPokeParty0thPoke(poke.getPokeParty1stPoke());
                    if(poke.getcounters() == 2){
                        poke.lowercounters();   
                    }    
                    if(poke.getcounters()>=3){
                        poke.setPokeParty1stPoke(poke.getPokeParty2ndPoke());
                        if(poke.getcounters() == 3){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=4){
                        poke.setPokeParty2ndPoke(poke.getPokeParty3rdPoke());
                        if(poke.getcounters()==4){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=5){
                        poke.setPokeParty3rdPoke(poke.getPokeParty4thPoke());
                        if(poke.getcounters()==5){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }
                    cout << "Your active Poke is now" << poke.getActivePokeName() << endl;
                    
                }
                if(deadpoke == 3){
                    cout << "you have chosen " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " to be your new active pokemon " << endl;
                    poke.setActivePoke(poke.getPokeParty2ndPoke());
                    poke.setPokeParty0thPoke(poke.getPokeParty2ndPoke());
                    
                    if(poke.getcounters() == 3){
                        poke.lowercounters();
                    }
                    if(poke.getcounters()>=4){
                        poke.setPokeParty2ndPoke(poke.getPokeParty3rdPoke());
                        if(poke.getcounters()==4){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=5){
                        poke.setPokeParty3rdPoke(poke.getPokeParty4thPoke());
                        if(poke.getcounters()==5){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }

                    cout << "Your active pokemon is now " << poke.getActivePokeName() << endl;
                }
                if(deadpoke == 4){
                    cout << "you have chosen " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " to be your new active pokemon " << endl;
                    poke.setActivePoke(poke.getPokeParty3rdPoke());
                    poke.setPokeParty0thPoke(poke.getPokeParty3rdPoke());
                    
                    if(poke.getcounters()==4){
                        poke.lowercounters();
                    }
                    if(poke.getcounters()>=5){
                        poke.setPokeParty3rdPoke(poke.getPokeParty4thPoke());
                        if(poke.getcounters()==5){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }
                }
                if(deadpoke == 5){
                    cout << "you have chosen " << poke.getPokeName(poke.getPokeParty4thPoke()) << " to be your new active pokemon " << endl;
                    poke.setActivePoke(poke.getPokeParty4thPoke());
                    poke.setPokeParty0thPoke(poke.getPokeParty4thPoke());
                    
                    if(poke.getcounters()==5){
                        poke.lowercounters();
                    }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }
                }
                if(deadpoke == 6){
                    cout << "you have chosen " << poke.getPokeName(poke.getPokeParty5thPoke()) << " to be your new active pokemon " << endl;
                    poke.setActivePoke(poke.getPokeParty5thPoke());
                    poke.setPokeParty0thPoke(poke.getPokeParty5thPoke());
                    poke.lowercounters();
                }
            }    
            if(deadB == 1){
                cout << "OH NO " << poke.getPokeName(poke.getPokeParty1stPoke()) << " Has passed away from old age!!! What a shame;( " << endl;
                cout << "Your poke party will now be one spot smaller" << endl;
                poke.removePokefromDex(poke.getPokeParty1stPoke());// removed from dex
                    if(poke.getcounters()==2){
                        poke.lowercounters();
                    }
                    if(poke.getcounters()>=3){
                        poke.setPokeParty1stPoke(poke.getPokeParty2ndPoke());
                        if(poke.getcounters() == 3){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=4){
                        poke.setPokeParty2ndPoke(poke.getPokeParty3rdPoke());
                        if(poke.getcounters()==4){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=5){
                        poke.setPokeParty3rdPoke(poke.getPokeParty4thPoke());
                        if(poke.getcounters()==5){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }                
                
                
            }
            if(deadB == 2){
                cout << "OH NO " << poke.getPokeName(poke.getPokeParty2ndPoke()) << " Has passed away from old age!!! What a shame;( " << endl;
                poke.removePokefromDex(poke.getPokeParty2ndPoke());
                if(poke.getcounters()==3){
                    poke.lowercounters();
                }
                    if(poke.getcounters()>=4){
                        poke.setPokeParty2ndPoke(poke.getPokeParty3rdPoke());
                        if(poke.getcounters()==4){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=5){
                        poke.setPokeParty3rdPoke(poke.getPokeParty4thPoke());
                        if(poke.getcounters()==5){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }                
                                
            }
            if(deadB == 3){
                cout << "OH NO " << poke.getPokeName(poke.getPokeParty3rdPoke()) << " Has passed away from old age!!! What a shame;( " << endl;
                poke.removePokefromDex(poke.getPokeParty3rdPoke());
                if(poke.getcounters() == 4){
                    poke.lowercounters();
                }
                    if(poke.getcounters()>=5){
                        poke.setPokeParty3rdPoke(poke.getPokeParty4thPoke());
                        if(poke.getcounters()==5){
                            poke.lowercounters();
                        }
                    }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }                  
                
            }
            if(deadB == 4){
                cout << "OH NO " << poke.getPokeName(poke.getPokeParty4thPoke()) << " Has passed away from old age!!! What a shame;( " << endl;
                poke.removePokefromDex(poke.getPokeParty4thPoke());
                if(poke.getcounters() == 5){
                    poke.lowercounters();
                }
                    if(poke.getcounters()>=6){
                        poke.setPokeParty4thPoke(poke.getPokeParty5thPoke());
                        poke.lowercounters();
                    }                 
                
            }
            if(deadB == 5){
                cout << "OH NO " << poke.getPokeName(poke.getPokeParty5thPoke()) << " Has passed away from old age!!! What a shame;( " << endl;
                poke.removePokefromDex(poke.getPokeParty5thPoke());
                poke.lowercounters();
            
                
            }

        }
        cout << "you have caught pokemon of " << poke.getTypeCount() << " types" << endl;
        if(stat.getBadges() >= 6){
            winner = 2;
            cout << "Congratulations you have acquired 6 Gym Badges and won the game!!!! You are a master pokemon trainer" << endl; 
            break;
        }
        if (poke.getTypeCount() >= 8){
            winner = 1;
            cout << "Congratulations you have acquired pokemon of 8 different types and won the game!!!!" << endl;
            break;
        }
   
    }
    int playagain = 0;
    if(winner == 0){
        cout << "You have chosen to quit and therefore lost the Game:(((" << endl;
        ofstream outfile;
        outfile.open("resultsPokemon.txt");
        outfile<< playerName << " Lost and had " << stat.getPoints() << " points"; 
        cout << "Would you like to play again?" << endl << "Enter 1 for yes 2 for no " << endl;
        while(playagain<1||playagain>2){
            cin>>playagain;
            if(playagain<1||playagain>2){
                cout << "Invalid input enter 1 or 2" << endl;
            }
        }
        if(playagain==1){
            cout << "You have chosen to play again. Good Luck, you have more experience now, make it count" << endl;
            stat.resetPoints();
            playerName = "";
            poke.resetcounters();       
        }
        if(playagain ==2){
            cout << "You have chosen not to play again farewell pokemon trainer just think of what could have been:((" << endl;
            break;
        }
        playagain =0;
    }
    if(winner>0){
        cout << "Congratulations!!!!!! you have beaten my very complex game. Beating this game means you most definetly have an IQ of over 200 so well done smarty!!!" << endl;
        cout << "You will now go down in the history books as a winner Congrats!!!" << endl;
        ofstream winner;
        winner.open("resultsPokemon.txt");
        winner << playerName << " won and had " << stat.getPoints() << " points" << endl;
        cout << "Would you like to play again?" << endl << "Enter 1 for yes 2 for no " << endl;
        while(playagain<1||playagain>2){
            cin>>playagain;
            if(playagain<1||playagain>2){
                cout << "Invalid input enter 1 or 2" << endl;
            }
        }
        if(playagain==1){
            cout << "You have chosen to play again. Good Luck, you have more experience now, make it count" << endl;
            stat.resetPoints();
            poke.resetcounters();
            playerName = "";
        }
        if(playagain ==2){
            cout << "You have chosen not to play again farewell pokemon trainer just think of what could have been:((" << endl;
            break;
        }
        playagain =0;
    }
    
    
    
}
    
    
}