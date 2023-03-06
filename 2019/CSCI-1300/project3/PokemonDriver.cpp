#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;


int split(string str, char c, string array[], int size){
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
};

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

void Stats:: addpokeballs(int amount){
    pokeballs = pokeballs + amount;
}

void Stats:: addbadge(){
    badges++;
}

int Stats:: getBadges(){
    return badges;
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

int Stats:: getPoints(){
    return points;
}

class Map{
  private:
  string map[25][16];
  int playerIndex1;
  int playerIndex2;
  string mapChar;// stores the kind of tile 
  
  public:
  Map();
  string getMapTile(int, int); 
  void playerStart(int);
  void getPlayerLocation();
  void setPlayerLocation(int);// input the direction chosen by player as an int 1-4 (NSEW)
  bool canItLandHere(int, int);

};

Map:: Map(){
    mapChar = "";
    playerIndex1 = 0;
    playerIndex2 = 0;
    
    ifstream inFile;
    inFile.open("mapPoke.txt");
    string line = "";
    string arr[16];
    int i = 0;
    while(getline(inFile, line)){
        split(line, ',', arr, 16);
        for(int j = 0; j<16;j++){
            map[i][j] = arr[j];
        }
        i++;
    }
}

string Map:: getMapTile(int index1, int index2){ // use this to determine what's at the input tile index 
    mapChar = map[index1][index2];    
    return mapChar;
}

void Map:: playerStart(int chosenPoke){// the input will be 1-4 based on whichever pokemon is chosen by the player in the very start
    if(chosenPoke == 1){
        playerIndex1 = 13;
        playerIndex2 = 7;
    }
    if (chosenPoke == 2){
        playerIndex1 = 13;
        playerIndex2 = 8;
    }
    if (chosenPoke == 3){
        playerIndex1 = 13;
        playerIndex2 = 9;
    }
    if(chosenPoke == 4){
        playerIndex1 = 13;
        playerIndex2 = 10;
    }
}

void Map:: getPlayerLocation(){
    map[playerIndex1][playerIndex2] = "P1"; 
    if(playerIndex1>=3 && playerIndex1<=21 && playerIndex2>=3 && playerIndex2<=12){
        cout << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< endl;     
    }
    if(playerIndex1 == 2 && playerIndex2>=3 && playerIndex2<=12){
        cout << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< endl;     

    }
    if(playerIndex1 == 1 && playerIndex2>=3 && playerIndex2<=12){
        cout << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< endl;
        cout << map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< endl;     

    }
    if(playerIndex1 == 0 && playerIndex2>=3 && playerIndex2<=12){
        cout << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< endl;
        cout << map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+6][playerIndex2-3]<< " , " << map[playerIndex1+6][playerIndex2-2]<< " , " << map[playerIndex1+6][playerIndex2-1]<< " , " << map[playerIndex1+6][playerIndex2]<< " , " << map[playerIndex1+6][playerIndex2+1]<< " , " << map[playerIndex1+6][playerIndex2+2]<< " , " << map[playerIndex1+6][playerIndex2+3]<< endl;     
    
        
    }
    if(playerIndex1 == 22 && playerIndex2>=3 && playerIndex2<=12){
        cout << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< endl;     

    }
    if(playerIndex1 == 23 && playerIndex2>=3 && playerIndex2<=12){
        cout << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< endl;     
    }
    if(playerIndex1 == 24 && playerIndex2>=3 && playerIndex2<=12){
        cout << map[playerIndex1-6][playerIndex2-3]<< " , " << map[playerIndex1-6][playerIndex2-2]<< " , " << map[playerIndex1-6][playerIndex2-1]<< " , " << map[playerIndex1-6][playerIndex2]<< " , " << map[playerIndex1-6][playerIndex2+1]<< " , " << map[playerIndex1-6][playerIndex2+2]<< " , " << map[playerIndex1-6][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< endl;     
        cout << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< endl;  
    }
    if(playerIndex2 == 2 && playerIndex1>=3 && playerIndex1<=21){
        cout <<  map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;  
        cout <<  map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     

    }
    if(playerIndex2 == 1 && playerIndex1>=3 && playerIndex1<=21){
        cout <<   map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;  
        cout <<   map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        
    }
    if(playerIndex2 == 0 && playerIndex1>=3 && playerIndex1<=21){
        cout <<    map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;  
        cout <<    map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        
    }
    if(playerIndex2 == 13 && playerIndex1>=3 && playerIndex1<=21){
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< endl;     
        cout <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  
        cout <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< endl;     
        
    }
    if(playerIndex2 == 14 && playerIndex1>=3 && playerIndex1<=21){
        cout <<  map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< endl;     
        
    }
    if(playerIndex2 == 15 && playerIndex1>=3 && playerIndex1<=21){
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< endl;     
        
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 2){
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 1){
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 0){
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 2){
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 1){
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 0){
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 2){
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 1){
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 0){
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 13){
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 14){
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 15){
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 15){
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 14){
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 13){
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 15){
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 14){
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 13){
        
    }
    if(playerIndex1 == 22 && playerIndex2 == 2){
        
    }
    if(playerIndex1 == 22 && playerIndex2 == 1){
        
    }
    if(playerIndex1 == 22 && playerIndex2 == 0){
        
    }
    if(playerIndex1 == 23 && playerIndex2 == 2){
        
    }
    if(playerIndex1 == 23 && playerIndex2 == 1){
        
    }
    if(playerIndex1 == 23 && playerIndex2 == 0){
        
    }
    if(playerIndex1 == 24 && playerIndex2 == 2){
        
    }
    if(playerIndex1 == 24 && playerIndex2 == 1){
        
    }
    if(playerIndex1 == 24 && playerIndex2 == 0){
        
    }
    if(playerIndex1 == 22 && playerIndex2 == 13){
        
    }
    if(playerIndex1 == 22 && playerIndex2 == 14){
        
    }
    if(playerIndex1 == 22 && playerIndex2 == 15){
        
    }
    if(playerIndex1 == 23 && playerIndex2 == 15){
        
    }
    if(playerIndex1 == 23 && playerIndex2 == 14){
        
    }
    if(playerIndex1 == 23 && playerIndex2 == 13){
        
    }
    if(playerIndex1 == 24 && playerIndex2 == 15){
        
    }
    if(playerIndex1 == 24 && playerIndex2 == 14){
        
    }
    if(playerIndex1 == 24 && playerIndex2 == 13){
        
    }

    

    

    
    
    


}// this is my function that handles printing out the 7x7 map at each turn 

void Map:: setPlayerLocation(int ){// this function will move the player based on an input of 1-4 which in the game will be NSEW
    
}

bool Map:: canItLandHere(int index1, int index2){
    if(index1<0 || index1>24 || index2 <0 || index2 >15){
        return false;
    }
    if(map[index1][index2]== "w" || map[index1][index2]== "C" || map[index1][index2]=="G"){
        return false;
    }
    else{
        return true;
    }
}



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
  void newpokelocation(int);
  int getrandompokechosen(int);
  void moverandomPoke();
  bool wannafightbro(int, int);
  int getwannafightpokeindex();
  string getwannafightpokename();
  int unluckyPokeNum();
  int getPokedexSize();
  int wannafightpokenum();
  int getsinglepokedexindex(int);
  void setTypeCount(int);
  int getTypeCount();
};



Pokemon:: Pokemon(){
    ifstream inFile;
    inFile.open("pokemon.txt");
    string line = "";
    string myarr[9];
    int i = 0;
    while(getline(inFile,line)){
        split(line, ',', myarr, 9);
        if(myarr[0]!= "#"){
            pokeName[i] = myarr[1];
            pokeType1[i] = myarr[7];
            if(myarr[8]!=""){
            pokeType2[i] = myarr[8];
            }
            else{
                pokeType2[i] = "";
            }
            myarr[8]="";
            i++;
        }
    }
}

int Pokemon:: getunluckypokeindex(){
    return randomPokesChosen[unluckypoke];
}

string Pokemon:: getunluckypoke(){
    return getPokeName(randomPokesChosen[unluckypoke]);
}

void Pokemon:: setActivePoke(int index){
    activePokeIndex = index;
}

string Pokemon:: getActivePokeName(){
    return pokeName[activePokeIndex];
}

int Pokemon:: getActivePokeIndex(){
    return activePokeIndex;
}

void Pokemon:: setRandomPoke1stLocation(){
    srand(time(NULL));
    for(int i = 0;i<20;i++){
        int index1 = rand()%25;
        int index2 = rand()%16;
        int counter = 0;
        if(i>0){
            for(int j = 1;j<20;j++){
                if(j<=i){
                    if(index1 == randomPokeLocationIndex1[j] && index2 == randomPokeLocationIndex2[j]){
                        counter++;
                    }
                }    
            }
        }
        if(counter == 0){
             if(index1== 13 && index2 == 7){
                counter++;
            }
             if(index1 == 13 && index2 == 8){
                counter++;
            }
             if(index1 ==13 && index2 ==9){
                counter++;
            }
             if(index1 == 13 && index2 ==10){
                counter++;
            }
             if(maps.canItLandHere(index1, index2) == 0){
                counter++;
            }
            if(counter == 0){
                randomPokeLocationIndex1[i] = index1;
                randomPokeLocationIndex2[i] = index2;

            } 


        }
        if(counter>0){
            i--;
        }
        

    }
}

string Pokemon:: getType(int index){
    if(pokeType2[index]== ""){
        return pokeType1[index];
    }
    else{
        string type1 = pokeType1[index];
        string type2 = pokeType2[index];
        string typeCombo = type1 + " and " + type2;
        return typeCombo;
    }
}

string Pokemon:: getPokeName(int index){
    return pokeName[index];
}

void Pokemon::randomPokesChooser(){
    srand(time(NULL));
    for(int i = 0;i<20;i++){
        int num = rand()%151+1;
        randomPokesChosen[i]= num;
        num = 0;
    }    
    
}

bool Pokemon:: setPokeParty(int index){
    for(int i = 0;i<counters;i++){
        if(index == pokeParty[i]){
            return false;
        }    
    }
    if(counters == 0){
        pokeParty[0] = index;
    }
    if(counters == 1){
        pokeParty[1]= index;
    }
    if(counters == 2){
        pokeParty[2]= index;
    }
    if(counters == 3){
        pokeParty[3] = index;
    }
    if(counters == 4){
        pokeParty[4] = index;
    }
    if(counters == 5){
        pokeParty[5] = index;
    }
    if(counters<=5){
        counters++;
        return true;
    }
    if(counters>5){
        return false;
    }
}

int Pokemon:: getrandomPokelocationindex1(int pokeindex){
    return randomPokeLocationIndex1[pokeindex];
}

int Pokemon:: getrandomPokeLocationindex2(int pokeindex){
    return randomPokeLocationIndex2[pokeindex];
}

bool Pokemon:: tryluck(int index1, int index2){
    int j = 0;
    for(int i = 0;i<20;i++){
        if(index1 == getrandomPokelocationindex1(i) || index1 - 1 == getrandomPokelocationindex1(i) || index1 -2 == getrandomPokelocationindex1(i) || index1 - 3 == getrandomPokelocationindex1(i) || index1+1==getrandomPokelocationindex1(i) || index1 +2 ==getrandomPokelocationindex1(i) || index1 + 3== getrandomPokelocationindex1(i)){
            if(index2 == getrandomPokeLocationindex2(i) || index2 - 1 == getrandomPokeLocationindex2(i) || index2 -2 == getrandomPokeLocationindex2(i) || index2 - 3 == getrandomPokeLocationindex2(i) || index2+1==getrandomPokeLocationindex2(i) || index2 +2 ==getrandomPokeLocationindex2(i) || index2 + 3== getrandomPokeLocationindex2(i)){
                j++;
                unluckypoke = i;
                return true;
                break;
            }
        }
    }
    if(j == 0){
       return false; 
    }    
}

void Pokemon:: setPokedex(int index){
    int counter = 0;
    for(int i = 0; i<pokedex.size();i++){
        if(pokedex[i] == index){
            counter++;
        }
    }
    if(counter == 0){
    pokedex.push_back(index);
    }
}

void Pokemon:: getPokedex(){
    for(int i = 0; i<pokedex.size(); i++){
        cout << i << getPokeName(pokedex[i])<< " HP: " << stat.getHP(pokedex[i]) << ", A: " << stat.getAttack(pokedex[i]) << ", D: " << stat.getDefense(pokedex[i]) << ", S: " << stat.getSpeed(pokedex[i]) << endl;
    }
}

int Pokemon:: getPokedexSize(){
    return pokedex.size();
}

int Pokemon:: getsinglepokedexindex(int index){
    return pokedex.at(index);
}

int Pokemon:: getPokeParty0thPoke(){
    return pokeParty[0];
}

int Pokemon:: getPokeParty1stPoke(){
    return pokeParty[1];
}

int Pokemon:: getPokeParty2ndPoke(){
    return pokeParty[2];
}

int Pokemon:: getPokeParty3rdPoke(){
    return pokeParty[3];
}

int Pokemon:: getPokeParty4thPoke(){
    return pokeParty[4];
}

int Pokemon:: getPokeParty5thPoke(){
    return pokeParty[5];
}

int Pokemon:: getcounters(){
    return counters;
}

void Pokemon:: replaceAndMoveRandomPoke(int pokeBeingReplaced){
    srand(time(NULL));
    int counterb = 0;
    int counter = 0;
    int num = rand()%151;
    randomPokesChosen[pokeBeingReplaced] = num;
    while(counterb == 0){
        int index1 = rand()%25;
        int index2 = rand()%16;
        for(int j = 0;j<20;j++){
            if(j!= pokeBeingReplaced){
                if(index1 == randomPokeLocationIndex1[j] && index2 == randomPokeLocationIndex2[j]){
                    counter++;
                }
            }    
        }    
        if(maps.canItLandHere(index1, index2) == 1 && counter == 0){
            randomPokeLocationIndex1[pokeBeingReplaced] = index1;
            randomPokeLocationIndex2[pokeBeingReplaced] = index2;
            counterb++;
        }
        counter  = 0;
    }
}

void Pokemon:: newpokelocation(int index){
    int count  = 0;
    int counter = 0;
    srand(time(NULL));
    while(count == 0){
        int index1 = rand()%25;
        int index2 = rand()%16;
        for(int j = 0;j<20;j++){
            if(j!= index){
                if(index1 == randomPokeLocationIndex1[j] && index2 == randomPokeLocationIndex2[j]){
                    counter++;
               }
            }    
        }    
        if(maps.canItLandHere(index1, index2) == 1 && counter == 0){
            randomPokeLocationIndex1[index] = index1;
            randomPokeLocationIndex2[index] = index2;
            count++;
        }
        counter = 0;
    }
}

int Pokemon:: getrandompokechosen(int index){
    return randomPokesChosen[index];
}

void Pokemon:: moverandomPoke(){
    srand(time(NULL));
    for(int i = 0; i<20;i++){
        int num = rand()%2;
        if(num == 0){ // move index1
            int juul = rand()%2;
            if(juul == 0){// move up one
                if(maps.canItLandHere(randomPokeLocationIndex1[i] - 1, randomPokeLocationIndex2[i])==1){
                    randomPokeLocationIndex1[i]--;
                }
                else{
                    i--;
                }
            }
            if(juul == 1){// move down 1
                if(maps.canItLandHere(randomPokeLocationIndex1[i] + 1, randomPokeLocationIndex2[i])==1){
                    randomPokeLocationIndex1[i]++;
                }
                else{
                    i--;
                }
                
            }
        }
        if(num == 1){// move index2
            int vape= rand()%2;
            if(vape == 0){//move left
                if(maps.canItLandHere(randomPokeLocationIndex1[i], randomPokeLocationIndex2[i]-1) ==1){
                    randomPokeLocationIndex2[i]--;
                }
                else{
                    i--;
                }
            }
            if(vape == 1){// move right
                if(maps.canItLandHere(randomPokeLocationIndex1[i], randomPokeLocationIndex2[i]+1) == 1){
                    randomPokeLocationIndex2[i]++;
                }
                else{
                    i--;
                }
            }
        }
    }
}

bool Pokemon:: wannafightbro(int PI1, int PI2){
    int j = 0;
    for(int i = 0; i<20; i++){
        if(randomPokeLocationIndex1[i] == PI1 || PI1 -1 == randomPokeLocationIndex1[i] || PI1 - 2 == randomPokeLocationIndex1[i] || PI1+1 == randomPokeLocationIndex1[i] || PI1 + 2 == randomPokeLocationIndex1[i]){
            if(randomPokeLocationIndex2[i] == PI2 || PI2 -1 == randomPokeLocationIndex2[i] || PI2 - 2 == randomPokeLocationIndex2[i] || PI2+1 == randomPokeLocationIndex2[i] || PI2 + 2 == randomPokeLocationIndex2[i]){
                j++;
                wannafightpoke = i; // storing index of first poke within range
                return true;
                break;
            }
        }
    }
    if(j == 0){
        return false;
    }
}

int Pokemon:: getwannafightpokeindex(){
    return randomPokesChosen[wannafightpoke];
}

string Pokemon:: getwannafightpokename(){
    return getPokeName(randomPokesChosen[wannafightpoke]);
}


  void Pokemon:: setPokeParty0thPoke(int index){
      pokeParty[0] = index;
  }
  void Pokemon:: setPokeParty1stPoke(int index){
      pokeParty[1] = index;
  }
  void Pokemon:: setPokeParty2ndPoke(int index){
      pokeParty[2] = index;
  }
  void Pokemon:: setPokeParty3rdPoke(int index){
      pokeParty[3] = index;
  }
  void Pokemon:: setPokeParty4thPoke(int index){
      pokeParty[4] = index;
  }
  void Pokemon:: setPokeParty5thPoke(int index){
      pokeParty[5] = index;
  } 
  
  
  int Pokemon:: unluckyPokeNum(){
      return unluckypoke;
  }
  
  int Pokemon:: wannafightpokenum(){
      return wannafightpoke;
  }
  
  void Pokemon:: setTypeCount(int index){
      string type1 = pokeType1[index];
      string type2 = pokeType2[index];
      int counter = 0;
      for(int i = 0;i<types.size();i++){
          if(type1 == types[i]){
              counter++;
          }
      }
      if(counter == 0){
          types.push_back(type1);
          typeCount++;
      }
      counter = 0;
      for(int j = 0;j<types.size();j++){
          if(type2 == types[j]){
              counter++;
          }
      }
      if(counter == 0){
          types.push_back(type2);
          typeCount++;
      }
  }
  
  int Pokemon:: getTypeCount(){
      return typeCount;
  }

int main(){
Pokemon pokes;
srand(time(NULL));
pokes.randomPokesChooser();
pokes.setRandomPoke1stLocation();
for(int i = 0;i<151;i++){
pokes.setTypeCount(i);
if(pokes.getTypeCount()==8){
    cout << i << endl;
    break;
}
}
//cout << pokes.getrandompokechosen(1) << endl << pokes.getrandomPokelocationindex1(1) << endl << pokes.getrandomPokeLocationindex2(1) << endl;
//pokes.replaceAndMoveRandomPoke(1);
//cout << pokes.getrandompokechosen(1) << endl << pokes.getrandomPokelocationindex1(1) << endl << pokes.getrandomPokeLocationindex2(1) << endl;

//for(int i = 0;i<20;i++){
  //  cout << pokes.getrandompokechosen(3) << endl;
    //pokes.replaceRandomPoke(3);
    //cout << pokes.getrandompokechosen(3) << endl;
    //cout << i << endl;
    
//}    

//for(int i = 0; i<7; i++){
//cout << pokes.setPokeParty(i) << endl;
//}
/*cout << pokes.getrandomPokelocationindex1(17)<< endl;
for(int i = 0; i<20;i++){
cout << pokes.getrandomPokelocationindex1(i) <<" this is index1 of " << i <<  endl;
cout << pokes.getrandomPokeLocationindex2(i) << " this is index2 of "<< i << endl;
}
cout << pokes.tryluck(15, 5) << endl;
cout << pokes.getunluckypoke();*/
}