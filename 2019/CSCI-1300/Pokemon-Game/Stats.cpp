#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#include "Stats.h"

/*int split(string str, char c, string array[], int size){
    if (str.length()== 0){
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i<str.length(); i++){
        if (str[i]==c){
            if (word.length() == 0) {
                continue;
            }
            array[j++]= word;
            word = "";
        }
        else {
            word = word + str[i];
        }
        
    }
    return j;
}
*/

Stats::Stats(){
    ifstream inFile;
    inFile.open("pokemon.txt");
    string line = "";
    string arr[9];
    int i = 0;
    while(getline(inFile,line)){
        split(line, ',', arr, 9);
        if(arr[0]!= "#"){
            HP[i] = stoi(arr[2]);
            originalHP[i] = stoi(arr[2]);
            attack[i] = stoi(arr[3]);
            defense[i] = stoi(arr[4]);
            speed[i] = stoi(arr[5]);
            max[i] = stoi(arr[6]);
            i++;
        }
        
    }
}

void Stats:: resetHP(int index){
    HP[index] = originalHP[index];
}

void Stats:: setPokeBalls(){
    pokeballs--;
}

int Stats:: getPokeballs(){
    return pokeballs;
}

int Stats:: getHP(int index){
    return HP[index];
}

int Stats:: battleHP(int index, int amounttaken){
    if (HP[index] - amounttaken <=0){
        HP[index] = 0;
    }
    else{
        HP[index] = HP[index] - amounttaken;
    }
    return HP[index];
}

void Stats:: setHP(int index){
    int NewHP = originalHP[index] * 1.02;
    if(NewHP!= 102){
        NewHP = NewHP +1;
    }    
    HP[index] = NewHP;
    originalHP[index] = NewHP;
    
}

int Stats:: getAttack(int index){
    return attack[index];
}

void Stats:: setAttack(int index){
    if (attack[index]< max[index]){
        int newAttack = attack[index] * 1.02;
        if(newAttack!= 102){
            newAttack = newAttack +1;
        }        
        if(newAttack>max[index]){
            attack[index] = max[index];
        }
        else{
            attack[index]= newAttack;
        }
    }
}

int Stats:: getDefense(int index){
    return defense[index];
}

void Stats:: setDefense(int index){
    if (defense[index]< max[index]){
        int newdefense = defense[index] * 1.02;
        if(newdefense!= 102){
        newdefense = newdefense +1;
    }
        if(newdefense>max[index]){
            defense[index] = max[index];
        }
        else{
            defense[index]= newdefense;
        }
    }
}

int Stats:: getSpeed(int index){
    return speed[index];
}

void Stats:: setSpeed(int index){
    int newSpeed = speed[index] * 1.02;
    if(newSpeed!= 102){
        newSpeed = newSpeed +1;
    }
    speed[index] = newSpeed;
}

int Stats:: getMax(int index){
    return max[index];
}

void Stats:: rest(int index){// if trainer chooses the rest option all his pokemon get an HP boost of 1
    HP[index]++;
}

void Stats:: setPoints(int point){
    points = points + point;
}

void Stats:: addpokeballs(int amount){
    pokeballs = pokeballs + amount;
}

int Stats:: getPoints(){
    return points;
}

void Stats:: addbadge(){
    badges++;
}

int Stats:: getBadges(){
    return badges;
}

void Stats:: resetPoints(){
    points = 0;
}
