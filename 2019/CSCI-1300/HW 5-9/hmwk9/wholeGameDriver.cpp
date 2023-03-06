#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
using namespace std;


// this is where I will place the finished classes and their implementations



int main(){
    // this is where most of the magic is going into happen and where most of my code will be written
    // first off we will print the options of starting pokemon
    // the user will input their name and their choice of pokemon as an int 1-4
    // then we call my player start function and take whatever was input to place my player at the indicated start for the chosen pokemon
    // then we print out that the player now has 10 pokeballs and explain what the pokeballs are for
    // then we call all my functions that assign trainers to gyms, pokemon to trainers, random poke to index's 
    // next we print the 7x7 map with the player location right in the middle 
    // next I create a giant while loop that will run as long as 4 isn't input 
    // next we print out the options for the player travel, rest, try luck, or quit
    // if travel it will then give the player an option of NSEW and whatever is chosen we update the players location by calling my setplayerlocation function
    // if rest we call my rest function and add 1 HP to all the poke in his party 
    // if try luck check to see if any poke are located within the 7x7 map and if so 50% chance of catching it without losing a pokeball 
    // if quit we break the while loop and output the losers stats
    // after the player has chosen an option and that options functions have been carried out 
    // we move all wild pokemon by one spot with a setrandompokelocation function (that i have yet to create)
    // then check to see if any poke are within range of the player to cause a battle using my inrange function
    // if yes then we start a battle sequence for fighting a random poke which goes like:
    // print active poke with a getactivepoke function that has yet to be created
    // and print the info for the poke that we encountered
    // then print 3 options for the encounter: fight, switch, or run
    // if fight then: if first or second fight the poke auto joins your party without any battling needed
    // otherwise the wild poke will try to run 40% of the time
    // if it tries to run then call my F function to determine if it can run
    // if run is successful the battle ends
    // if run isn't successful or the poke chooses to fight:
    // poke with larger value for speed goes first
    // that poke will get a random value between 0 and its attack value for the turn
    // then i call my A-d function to determine how much damage will be done to the opposing poke 
    // if damage is greater than 0 we subtract that from the defending pokes hp
    // then we do the same sequence but the attacker becomes the defender and vice versa
    // after they both attack the options are given again
    // the switch option allows the player to switch their active poke using a setactivepoke function
    // the run option is the same as above for the wild poke (call f function)
    // we repeat these options until someone successfully runs or the wild pokes hp hits zero or all the poke in the players party hit zero HP
    // if the wild poke HP hits zero then we add that poke to our party and lose one pokeball
    // if all the players pokes hit zero HP then we are trsansported to the nearest pokecenter using 
}