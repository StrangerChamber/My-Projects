#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#include <string>
#include <vector>

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
  bool isItaG(int, int);

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

class Trainers{
    private:
    string trainerName[15];
    int trainergymindex1[15];
    int trainergymindex2[15];
    string trainerGym;
    vector<int> trainer1pokes; // storing up to 6 poke indexes
    vector<int> trainer2pokes;
    vector<int> trainer3pokes;
    vector<int> trainer4pokes;
    vector<int> trainer5pokes;
    vector<int> trainer6pokes;
    vector<int> trainer7pokes;
    vector<int> trainer8pokes;
    vector<int> trainer9pokes;
    vector<int> trainer10pokes;
    vector<int> trainer11pokes;
    vector<int> trainer12pokes;
    vector<int> trainer13pokes;
    vector<int> trainer14pokes;
    vector<int> trainer15pokes;
    public:
    Trainers();
    int getTrainer1Pokesindex(int);
    int getTrainer2Pokesindex(int);
    int getTrainer3Pokesindex(int);
    int getTrainer4Pokesindex(int);
    int getTrainer5Pokesindex(int);
    int getTrainer6Pokesindex(int);
    int getTrainer7Pokesindex(int);
    int getTrainer8Pokesindex(int);
    int getTrainer9Pokesindex(int);
    int getTrainer10Pokesindex(int);
    int getTrainer11Pokesindex(int);
    int getTrainer12Pokesindex(int);
    int getTrainer13Pokesindex(int);
    int getTrainer14Pokesindex(int);
    int getTrainer15Pokesindex(int);
    void setTrainerPokes();
    string getTrainerName(int);
    void setTrainerName(string, int);
    int getTrainerGymindex1(int);
    int getTrainerGymindex2(int);
    void setTrainerGym();
    int getT1partysize();
    int getT2partysize();
    int getT3partysize();
    int getT4partysize();
    int getT5partysize();
    int getT6partysize();
    int getT7partysize();
    int getT8partysize();
    int getT9partysize();
    int getT10partysize();
    int getT11partysize();
    int getT12partysize();
    int getT13partysize();
    int getT14partysize();
    int getT15partysize();

};

Trainers:: Trainers(){
    trainerGym ="";
    ifstream inFile;
    inFile.open("trainers.txt");
    int i = 0;
    string line = "";
    while(getline(inFile,line)){
        trainerName[i]= line;
        i++;
    }
}


string Trainers:: getTrainerName(int index){
    return trainerName[index];
}


int Trainers:: getTrainerGymindex1(int index1){
    return trainergymindex1[index1];
}
int Trainers:: getTrainerGymindex2(int index2){
    return trainergymindex2[index2];
}

void Trainers:: setTrainerGym(){
    trainergymindex1[0] = 1;
    trainergymindex2[0] = 7;
    trainergymindex1[1] = 1;
    trainergymindex2[1] = 14;
    trainergymindex1[2] = 3;
    trainergymindex2[2] = 2;
    trainergymindex1[3] = 4;
    trainergymindex2[3] = 11;
    trainergymindex1[4] = 7;
    trainergymindex2[4] = 15;
    trainergymindex1[5] = 8;
    trainergymindex2[5] = 1;
    trainergymindex1[6] = 10;
    trainergymindex2[6] = 8;
    trainergymindex1[7] = 11;// test from here
    trainergymindex2[7] = 11;
    trainergymindex1[8] = 12;
    trainergymindex2[8] = 15;
    trainergymindex1[9] = 13;
    trainergymindex2[9] = 2;
    trainergymindex1[10] = 17;
    trainergymindex2[10] = 1;
    trainergymindex1[11] = 19;
    trainergymindex2[11] = 8;
    trainergymindex1[12] = 21;
    trainergymindex2[12] = 12;
    trainergymindex1[13] = 22;
    trainergymindex2[13] = 6;
    trainergymindex1[14] = 23;
    trainergymindex2[14] = 1;
    
}

void Trainers:: setTrainerName(string newName, int index){
    trainerName[index] = newName;
}

void Trainers:: setTrainerPokes(){
    srand(time(NULL));
    int num = rand()%6+1;
    for(int i = 0;i<num;i++){
        int num1 = rand()%151+1;
        trainer1pokes.push_back(num1);
    }
    int much = rand()%6+1;
    for(int i = 0;i<much;i++){
        int num2 = rand()%151+1;
        trainer2pokes.push_back(num2);
    }
    int mucho = rand()%6+1;
    for(int i = 0;i<mucho;i++){
        int num3 = rand()%151+1;
        trainer3pokes.push_back(num3);
    }
    int gracias = rand()%6+1;
    for(int i = 0;i<gracias;i++){
        int num4 = rand()%151+1;
        trainer4pokes.push_back(num4);
    } 
    for(int i = 0;i<gracias;i++){
        int num5 = rand()%151+1;
        trainer5pokes.push_back(num5);
    }     
    for(int i = 0;i<mucho;i++){
        int num6 = rand()%151+1;
        trainer6pokes.push_back(num6);
    }   
    for(int i = 0;i<num;i++){
        int num7 = rand()%151+1;
        trainer7pokes.push_back(num7);
    }     
    for(int i = 0;i<much;i++){
        int num8 = rand()%151+1;
        trainer8pokes.push_back(num8);
    }     
    int love = rand()%6+1;
    for(int i = 0;i<love;i++){
        int num9 = rand()%151+1;
        trainer9pokes.push_back(num9);
    }     
    for(int i = 0;i<love;i++){
        int num10 = rand()%151+1;
        trainer10pokes.push_back(num10);
    }   
    int crazy = rand()%6+1;
    for(int i = 0;i<crazy;i++){
        int num11 = rand()%151+1;
        trainer11pokes.push_back(num11);
    }     
    for(int i = 0;i<crazy;i++){
        int num12 = rand()%151+1;
        trainer12pokes.push_back(num12);
    }     
    for(int i = 0;i<much;i++){
        int num13 = rand()%151+1;
        trainer13pokes.push_back(num13);
    }     
    for(int i = 0;i<love;i++){
        int num14 = rand()%151+1;
        trainer14pokes.push_back(num14);
    }     
    for(int i = 0;i<crazy;i++){
        int num15 = rand()%151+1;
        trainer15pokes.push_back(num15);
    }     
}

int Trainers:: getTrainer1Pokesindex(int index){// use this to plug into another function needing an index to print poke name and stats
    return trainer1pokes.at(index);
}

int Trainers:: getT1partysize(){
    return trainer1pokes.size();
}

int Trainers:: getT2partysize(){
    return trainer2pokes.size();
}

int Trainers:: getT3partysize(){
    return trainer3pokes.size();
}

int Trainers:: getT4partysize(){
    return trainer4pokes.size();
}

int Trainers:: getT5partysize(){
    return trainer5pokes.size();
}

int Trainers:: getT6partysize(){
    return trainer6pokes.size();
}

int Trainers:: getT7partysize(){
    return trainer7pokes.size();
}

int Trainers:: getT8partysize(){
    return trainer8pokes.size();
}

int Trainers:: getT9partysize(){
    return trainer9pokes.size();
}

int Trainers:: getT10partysize(){
    return trainer10pokes.size();
}

int Trainers:: getT11partysize(){
    return trainer11pokes.size();
}

int Trainers:: getT12partysize(){
    return trainer12pokes.size();
}

int Trainers:: getT13partysize(){
    return trainer13pokes.size();
}

int Trainers:: getT14partysize(){
    return trainer14pokes.size();
}

int Trainers:: getT15partysize(){
    return trainer15pokes.size();
}

int Trainers:: getTrainer2Pokesindex(int index){
    return trainer2pokes.at(index);
}

int Trainers:: getTrainer3Pokesindex(int index){
    return trainer3pokes.at(index);
}

int Trainers:: getTrainer4Pokesindex(int index){
    return trainer4pokes.at(index);
}

int Trainers:: getTrainer5Pokesindex(int index){
    return trainer5pokes.at(index);
}

int Trainers:: getTrainer6Pokesindex(int index){
    return trainer6pokes.at(index);
}

int Trainers:: getTrainer7Pokesindex(int index){
    return trainer7pokes.at(index);
}

int Trainers:: getTrainer8Pokesindex(int index){
    return trainer8pokes.at(index);
}

int Trainers:: getTrainer9Pokesindex(int index){
    return trainer9pokes.at(index);
}

int Trainers:: getTrainer10Pokesindex(int index){
    return trainer10pokes.at(index);
}

int Trainers:: getTrainer11Pokesindex(int index){
    return trainer11pokes.at(index);
}

int Trainers:: getTrainer12Pokesindex(int index){
    return trainer12pokes.at(index);
}

int Trainers:: getTrainer13Pokesindex(int index){
    return trainer13pokes.at(index);
}

int Trainers:: getTrainer14Pokesindex(int index){
    return trainer14pokes.at(index);
}

int Trainers:: getTrainer15Pokesindex(int index){
    return trainer15pokes.at(index);
}

int main(){
    Trainers train;
    Map maps;
train.setTrainerPokes();
train.setTrainerGym();
//cout << train.getTrainerName(9);
cout << "name good" << endl;
cout << train.getT10partysize() << endl;
for(int i = 0; i<train.getT10partysize();i++){
cout << train.getTrainer10Pokesindex(i) << endl;
}
for(int i = 0;i<train.getT10partysize();i++){
cout << i << endl;

train.getTrainer10Pokesindex(i);
}
cout << "We made it" << endl;
    //for(int i = 0; i<15;i++){
    //cout << train.getTrainerGymindex1(i) << endl;
    //cout << train.getTrainerGymindex2(i) << endl;
    //}
}