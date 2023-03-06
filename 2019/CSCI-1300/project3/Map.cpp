#include <iostream>
#include <fstream>
#include <cmath>
#include "Map.h"
#include "split.cpp"
using namespace std;

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

int Map:: getPlayerIndex1(){
    return playerIndex1;
}

int Map:: getPlayerIndex2(){
    return playerIndex2;
}

void Map:: getPlayerLocation(){
    string oldmap= map[playerIndex1][playerIndex2];
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
        cout <<  map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< endl;  
        cout <<  map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1+1][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1+2][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , "<< map[playerIndex1+3][playerIndex2+4]<< endl;     

    }
    if(playerIndex2 == 1 && playerIndex1>=3 && playerIndex1<=21){
        cout <<   map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< endl;  
        cout <<   map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1+1][playerIndex2+4]<< " , "<< map[playerIndex1+1][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1+2][playerIndex2+4]<< " , "<< map[playerIndex1+2][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , "<< map[playerIndex1+3][playerIndex2+4]<< " , "<< map[playerIndex1+3][playerIndex2+5]<< endl;     
        
    }
    if(playerIndex2 == 0 && playerIndex1>=3 && playerIndex1<=21){
        cout <<    map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< " , "<< map[playerIndex1-2][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< " , "<< map[playerIndex1-1][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< " , " << map[playerIndex1][playerIndex2+6] << endl;  
        cout <<    map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1=1][playerIndex2+4]<< " , "<< map[playerIndex1+1][playerIndex2+5]<< " , "<< map[playerIndex1+1][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1+2][playerIndex2+4]<< " , "<< map[playerIndex1+2][playerIndex2+5]<< " , "<< map[playerIndex1+2][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , "<< map[playerIndex1+3][playerIndex2+4]<< " , "<< map[playerIndex1+3][playerIndex2+5]<< " , "<< map[playerIndex1+3][playerIndex2+6]<< endl;     
        
    }
    if(playerIndex2 == 13 && playerIndex1>=3 && playerIndex1<=21){
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< endl;     
        cout <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< endl;     
        
    }
    if(playerIndex2 == 14 && playerIndex1>=3 && playerIndex1<=21){
        cout <<  map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< endl;     
        
    }
    if(playerIndex2 == 15 && playerIndex1>=3 && playerIndex1<=21){
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-6]<< " , " << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-6]<< " , " << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< endl;     
        cout <<map[playerIndex1][playerIndex2-6]<< " , " << map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-6]<< " , " << map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-6]<< " , " << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-6]<< " , " << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< endl;     
        
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 2){
        cout << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , " << map[playerIndex1-2][playerIndex2+4]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , " << map[playerIndex1-1][playerIndex2+4]<< endl;     
        cout << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< endl;     
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 1){
        cout << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , " << map[playerIndex1-2][playerIndex2+4]<< " , " << map[playerIndex1-2][playerIndex2+5]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , " << map[playerIndex1-1][playerIndex2+4]<< " , " << map[playerIndex1-1][playerIndex2+5]<< endl;     
        cout << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< " , " << map[playerIndex1][playerIndex2+5]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< " , " << map[playerIndex1+1][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< " , " << map[playerIndex1+2][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< " , " << map[playerIndex1+3][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< " , " << map[playerIndex1+4][playerIndex2+5]<< endl;     
        
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 0){
        cout << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , " << map[playerIndex1-2][playerIndex2+4]<< " , " << map[playerIndex1-2][playerIndex2+5]<< " , " << map[playerIndex1-2][playerIndex2+6]<< endl;     
        cout << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , " << map[playerIndex1-1][playerIndex2+4]<< " , " << map[playerIndex1-1][playerIndex2+5]<< " , " << map[playerIndex1-1][playerIndex2+6]<< endl;     
        cout << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< " , " << map[playerIndex1][playerIndex2+5]<< " , " << map[playerIndex1][playerIndex2+6]<< endl;  
        cout << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< " , " << map[playerIndex1+1][playerIndex2+5]<< " , " << map[playerIndex1+1][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< " , " << map[playerIndex1+2][playerIndex2+5]<< " , " << map[playerIndex1+2][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< " , " << map[playerIndex1+3][playerIndex2+5]<< " , " << map[playerIndex1+3][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< " , " << map[playerIndex1+4][playerIndex2+5]<< " , " << map[playerIndex1+4][playerIndex2+6]<< endl;           
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 2){
        cout << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , " << map[playerIndex1-1][playerIndex2+4]<< endl;     
        cout << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< endl;           
        cout << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< " , " << map[playerIndex1+5][playerIndex2+4]<< endl;           
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 1){
        cout << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , " << map[playerIndex1-1][playerIndex2+4]<< " , " << map[playerIndex1-1][playerIndex2+5]<< endl;     
        cout << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< " , " << map[playerIndex1][playerIndex2+5]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< " , " << map[playerIndex1+1][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< " , " << map[playerIndex1+2][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< " , " << map[playerIndex1+3][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< " , " << map[playerIndex1+4][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< " , " << map[playerIndex1+5][playerIndex2+4]<< " , " << map[playerIndex1+5][playerIndex2+5]<< endl;     
        
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 0){
        cout << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , " << map[playerIndex1-1][playerIndex2+4]<< " , " << map[playerIndex1-1][playerIndex2+5]<< " , " << map[playerIndex1-1][playerIndex2+6]<< endl;     
        cout << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< " , " << map[playerIndex1][playerIndex2+5]<< " , " << map[playerIndex1][playerIndex2+6]<< endl;  
        cout << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< " , " << map[playerIndex1+1][playerIndex2+5]<< " , " << map[playerIndex1+1][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< " , " << map[playerIndex1+2][playerIndex2+5]<< " , " << map[playerIndex1+2][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< " , " << map[playerIndex1+3][playerIndex2+5]<< " , " << map[playerIndex1+3][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< " , " << map[playerIndex1+4][playerIndex2+5]<< " , " << map[playerIndex1+4][playerIndex2+6]<< endl;           
        cout << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< " , " << map[playerIndex1+5][playerIndex2+4]<< " , " << map[playerIndex1+5][playerIndex2+5]<< " , " << map[playerIndex1+5][playerIndex2+6]<< endl;           
        
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 2){
        cout << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< endl;           
        cout << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< " , " << map[playerIndex1+5][playerIndex2+4]<< endl;           
        cout << map[playerIndex1+6][playerIndex2-2]<< " , " << map[playerIndex1+6][playerIndex2-1]<< " , " << map[playerIndex1+6][playerIndex2]<< " , " << map[playerIndex1+6][playerIndex2+1]<< " , " << map[playerIndex1+6][playerIndex2+2]<< " , " << map[playerIndex1+6][playerIndex2+3]<< " , " << map[playerIndex1+6][playerIndex2+4]<< endl;           
        
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 1){
        cout << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< " , " << map[playerIndex1][playerIndex2+5]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< " , " << map[playerIndex1+1][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< " , " << map[playerIndex1+2][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< " , " << map[playerIndex1+3][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< " , " << map[playerIndex1+4][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< " , " << map[playerIndex1+5][playerIndex2+4]<< " , " << map[playerIndex1+5][playerIndex2+5]<< endl;     
        cout << map[playerIndex1+6][playerIndex2-1]<< " , " << map[playerIndex1+6][playerIndex2]<< " , " << map[playerIndex1+6][playerIndex2+1]<< " , " << map[playerIndex1+6][playerIndex2+2]<< " , " << map[playerIndex1+6][playerIndex2+3]<< " , " << map[playerIndex1+6][playerIndex2+4]<< " , " << map[playerIndex1+6][playerIndex2+5]<< endl;     

    }
    if(playerIndex1 == 0 && playerIndex2 == 0){
        cout << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , " << map[playerIndex1][playerIndex2+4]<< " , " << map[playerIndex1][playerIndex2+5]<< " , " << map[playerIndex1][playerIndex2+6]<< endl;  
        cout << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , " << map[playerIndex1+1][playerIndex2+4]<< " , " << map[playerIndex1+1][playerIndex2+5]<< " , " << map[playerIndex1+1][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , " << map[playerIndex1+2][playerIndex2+4]<< " , " << map[playerIndex1+2][playerIndex2+5]<< " , " << map[playerIndex1+2][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< " , " << map[playerIndex1+3][playerIndex2+3]<< " , " << map[playerIndex1+3][playerIndex2+4]<< " , " << map[playerIndex1+3][playerIndex2+5]<< " , " << map[playerIndex1+3][playerIndex2+6]<< endl;     
        cout << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< " , " << map[playerIndex1+4][playerIndex2+3]<< " , " << map[playerIndex1+4][playerIndex2+4]<< " , " << map[playerIndex1+4][playerIndex2+5]<< " , " << map[playerIndex1+4][playerIndex2+6]<< endl;           
        cout << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< " , " << map[playerIndex1+5][playerIndex2+3]<< " , " << map[playerIndex1+5][playerIndex2+4]<< " , " << map[playerIndex1+5][playerIndex2+5]<< " , " << map[playerIndex1+5][playerIndex2+6]<< endl;           
        cout << map[playerIndex1+6][playerIndex2]<< " , " << map[playerIndex1+6][playerIndex2+1]<< " , " << map[playerIndex1+6][playerIndex2+2]<< " , " << map[playerIndex1+6][playerIndex2+3]<< " , " << map[playerIndex1+6][playerIndex2+4]<< " , " << map[playerIndex1+6][playerIndex2+5]<< " , " << map[playerIndex1+6][playerIndex2+6]<< endl;           
        
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 13){
        cout << map[playerIndex1-2][playerIndex2-4]<< " , " << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-4]<< " , " << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-4]<< " , " << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-4]<< " , " << map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-4]<< " , " << map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< endl;     
        
        
    }
    if(playerIndex1 == 2 && playerIndex2 == 14){
        cout << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-5]<< " , " <<map[playerIndex1+4][playerIndex2-4]<< " , " <<map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< endl;     
        
       
    }
    if(playerIndex1 == 2 && playerIndex2 == 15){
        cout << map[playerIndex1-2][playerIndex2-6]<< " , " << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-6]<< " , " << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< endl;     
        cout <<map[playerIndex1][playerIndex2-6]<< " , " << map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-6]<< " , " << map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-6]<< " , " << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-6]<< " , " << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-6]<< " , " << map[playerIndex1+4][playerIndex2-5]<< " , " <<map[playerIndex1+4][playerIndex2-4]<< " , " <<map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< endl;     
        
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 15){
        cout << map[playerIndex1-1][playerIndex2-6]<< " , " << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< endl;     
        cout <<map[playerIndex1][playerIndex2-6]<< " , " << map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-6]<< " , " << map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-6]<< " , " << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-6]<< " , " << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-6]<< " , " << map[playerIndex1+4][playerIndex2-5]<< " , " <<map[playerIndex1+4][playerIndex2-4]<< " , " <<map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-6]<< " , " << map[playerIndex1+5][playerIndex2-5]<< " , " <<map[playerIndex1+5][playerIndex2-4]<< " , " <<map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< endl;     
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 14){
        cout << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-5]<< " , " <<map[playerIndex1+4][playerIndex2-4]<< " , " <<map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-5]<< " , " <<map[playerIndex1+5][playerIndex2-4]<< " , " <<map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< endl;     
        
    }
    if(playerIndex1 == 1 && playerIndex2 == 13){
        cout << map[playerIndex1-1][playerIndex2-4]<< " , " << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-4]<< " , " << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-4]<< " , " << map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-4]<< " , " << map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-4]<< " , " << map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< endl;     
        
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 15){
        cout <<map[playerIndex1][playerIndex2-6]<< " , " << map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-6]<< " , " << map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-6]<< " , " << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-6]<< " , " << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-6]<< " , " << map[playerIndex1+4][playerIndex2-5]<< " , " <<map[playerIndex1+4][playerIndex2-4]<< " , " <<map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-6]<< " , " << map[playerIndex1+5][playerIndex2-5]<< " , " <<map[playerIndex1+5][playerIndex2-4]<< " , " <<map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< endl;     
        cout << map[playerIndex1+6][playerIndex2-6]<< " , " << map[playerIndex1+6][playerIndex2-5]<< " , " <<map[playerIndex1+6][playerIndex2-4]<< " , " <<map[playerIndex1+6][playerIndex2-3]<< " , " << map[playerIndex1+6][playerIndex2-2]<< " , " << map[playerIndex1+6][playerIndex2-1]<< " , " << map[playerIndex1+6][playerIndex2]<< endl;     
        
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 14){
        cout <<map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-5]<< " , " <<map[playerIndex1+3][playerIndex2-4]<< " , " <<map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-5]<< " , " <<map[playerIndex1+4][playerIndex2-4]<< " , " <<map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-5]<< " , " <<map[playerIndex1+5][playerIndex2-4]<< " , " <<map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+6][playerIndex2-5]<< " , " <<map[playerIndex1+6][playerIndex2-4]<< " , " <<map[playerIndex1+6][playerIndex2-3]<< " , " << map[playerIndex1+6][playerIndex2-2]<< " , " << map[playerIndex1+6][playerIndex2-1]<< " , " << map[playerIndex1+6][playerIndex2]<< " , " << map[playerIndex1+6][playerIndex2+1]<< endl;     
        
    }
    if(playerIndex1 == 0 && playerIndex2 == 13){
        cout << map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-4]<< " , " << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+3][playerIndex2-4]<< " , " << map[playerIndex1+3][playerIndex2-3]<< " , " << map[playerIndex1+3][playerIndex2-2]<< " , " << map[playerIndex1+3][playerIndex2-1]<< " , " << map[playerIndex1+3][playerIndex2]<< " , " << map[playerIndex1+3][playerIndex2+1]<< " , " << map[playerIndex1+3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+4][playerIndex2-4]<< " , " << map[playerIndex1+4][playerIndex2-3]<< " , " << map[playerIndex1+4][playerIndex2-2]<< " , " << map[playerIndex1+4][playerIndex2-1]<< " , " << map[playerIndex1+4][playerIndex2]<< " , " << map[playerIndex1+4][playerIndex2+1]<< " , " << map[playerIndex1+4][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+5][playerIndex2-4]<< " , " << map[playerIndex1+5][playerIndex2-3]<< " , " << map[playerIndex1+5][playerIndex2-2]<< " , " << map[playerIndex1+5][playerIndex2-1]<< " , " << map[playerIndex1+5][playerIndex2]<< " , " << map[playerIndex1+5][playerIndex2+1]<< " , " << map[playerIndex1+5][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+6][playerIndex2-4]<< " , " << map[playerIndex1+6][playerIndex2-3]<< " , " << map[playerIndex1+6][playerIndex2-2]<< " , " << map[playerIndex1+6][playerIndex2-1]<< " , " << map[playerIndex1+6][playerIndex2]<< " , " << map[playerIndex1+6][playerIndex2+1]<< " , " << map[playerIndex1+6][playerIndex2+2]<< endl;     
        
        
    }
    if(playerIndex1 == 22 && playerIndex2 == 2){
        cout <<  map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< endl;  
        cout <<  map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1+1][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1+2][playerIndex2+4]<< endl;     

        
    }
    if(playerIndex1 == 22 && playerIndex2 == 1){
        cout <<   map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< " , "<< map[playerIndex1-4][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< endl;  
        cout <<   map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1+1][playerIndex2+4]<< " , "<< map[playerIndex1+1][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1+2][playerIndex2+4]<< " , "<< map[playerIndex1+2][playerIndex2+5]<< endl;     

    }
    if(playerIndex1 == 22 && playerIndex2 == 0){
        cout <<    map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< " , "<< map[playerIndex1-4][playerIndex2+5]<< " , "<< map[playerIndex1-4][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< " , "<< map[playerIndex1-2][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< " , "<< map[playerIndex1-1][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< map[playerIndex1][playerIndex2+6] << endl;  
        cout <<    map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1=1][playerIndex2+4]<< " , "<< map[playerIndex1+1][playerIndex2+5]<< " , "<< map[playerIndex1+1][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< " , " << map[playerIndex1+2][playerIndex2+3]<< " , "<< map[playerIndex1+2][playerIndex2+4]<< " , "<< map[playerIndex1+2][playerIndex2+5]<< " , "<< map[playerIndex1+2][playerIndex2+6]<< endl;     

    }
    if(playerIndex1 == 23 && playerIndex2 == 2){
        cout <<  map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< " , "<< map[playerIndex1-5][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< endl;  
        cout <<  map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1+1][playerIndex2+4]<< endl;     

    }
    if(playerIndex1 == 23 && playerIndex2 == 1){
        cout <<   map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< " , "<< map[playerIndex1-5][playerIndex2+4]<< " , "<< map[playerIndex1-5][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< " , "<< map[playerIndex1-4][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< endl;  
        cout <<   map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1+1][playerIndex2+4]<< " , "<< map[playerIndex1+1][playerIndex2+5]<< endl;     

    }
    if(playerIndex1 == 23 && playerIndex2 == 0){
        cout <<    map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< " , "<< map[playerIndex1-5][playerIndex2+4]<< " , "<< map[playerIndex1-5][playerIndex2+5]<< " , "<< map[playerIndex1-5][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< " , "<< map[playerIndex1-4][playerIndex2+5]<< " , "<< map[playerIndex1-4][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< " , "<< map[playerIndex1-2][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< " , "<< map[playerIndex1-1][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< map[playerIndex1][playerIndex2+6] << endl;  
        cout <<    map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< " , " << map[playerIndex1+1][playerIndex2+3]<< " , "<< map[playerIndex1=1][playerIndex2+4]<< " , "<< map[playerIndex1+1][playerIndex2+5]<< " , "<< map[playerIndex1+1][playerIndex2+6]<< endl;     

        
    }
    if(playerIndex1 == 24 && playerIndex2 == 2){
        cout <<  map[playerIndex1-6][playerIndex2-2]<< " , " << map[playerIndex1-6][playerIndex2-1]<< " , " << map[playerIndex1-6][playerIndex2]<< " , " << map[playerIndex1-6][playerIndex2+1]<< " , " << map[playerIndex1-6][playerIndex2+2]<< " , " << map[playerIndex1-6][playerIndex2+3]<< " , "<< map[playerIndex1-6][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< " , "<< map[playerIndex1-5][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;     
        cout <<  map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< endl;  

        
    }
    if(playerIndex1 == 24 && playerIndex2 == 1){
        cout <<   map[playerIndex1-6][playerIndex2-1]<< " , " << map[playerIndex1-6][playerIndex2]<< " , " << map[playerIndex1-6][playerIndex2+1]<< " , " << map[playerIndex1-6][playerIndex2+2]<< " , " << map[playerIndex1-6][playerIndex2+3]<< " , "<< map[playerIndex1-6][playerIndex2+4]<< " , "<< map[playerIndex1-6][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< " , "<< map[playerIndex1-5][playerIndex2+4]<< " , "<< map[playerIndex1-5][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< " , "<< map[playerIndex1-4][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< endl;     
        cout <<   map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< endl;  

    }
    if(playerIndex1 == 24 && playerIndex2 == 0){
        cout <<    map[playerIndex1-6][playerIndex2]<< " , " << map[playerIndex1-6][playerIndex2+1]<< " , " << map[playerIndex1-6][playerIndex2+2]<< " , " << map[playerIndex1-6][playerIndex2+3]<< " , "<< map[playerIndex1-6][playerIndex2+4]<< " , "<< map[playerIndex1-6][playerIndex2+5]<< " , "<< map[playerIndex1-6][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< " , " << map[playerIndex1-5][playerIndex2+3]<< " , "<< map[playerIndex1-5][playerIndex2+4]<< " , "<< map[playerIndex1-5][playerIndex2+5]<< " , "<< map[playerIndex1-5][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< " , " << map[playerIndex1-4][playerIndex2+3]<< " , "<< map[playerIndex1-4][playerIndex2+4]<< " , "<< map[playerIndex1-4][playerIndex2+5]<< " , "<< map[playerIndex1-4][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< " , " << map[playerIndex1-3][playerIndex2+3]<< " , "<< map[playerIndex1-3][playerIndex2+4]<< " , "<< map[playerIndex1-3][playerIndex2+5]<< " , "<< map[playerIndex1-3][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< " , " << map[playerIndex1-2][playerIndex2+3]<< " , "<< map[playerIndex1-2][playerIndex2+4]<< " , "<< map[playerIndex1-2][playerIndex2+5]<< " , "<< map[playerIndex1-2][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< " , " << map[playerIndex1-1][playerIndex2+3]<< " , "<< map[playerIndex1-1][playerIndex2+4]<< " , "<< map[playerIndex1-1][playerIndex2+5]<< " , "<< map[playerIndex1-1][playerIndex2+6]<< endl;     
        cout <<    map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< " , " << map[playerIndex1][playerIndex2+3]<< " , "<< map[playerIndex1][playerIndex2+4]<< " , "<< map[playerIndex1][playerIndex2+5]<< map[playerIndex1][playerIndex2+6] << endl;  

    }
    if(playerIndex1 == 22 && playerIndex2 == 13){
        cout << map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-4]<< " , " << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-4]<< " , " << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-4]<< " , " << map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< " , " << map[playerIndex1+2][playerIndex2+2]<< endl;     

    }
    if(playerIndex1 == 22 && playerIndex2 == 14){
        cout <<  map[playerIndex1-4][playerIndex2-5]<< " , " <<map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< endl;     
        cout <<  map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< " , " << map[playerIndex1+2][playerIndex2+1]<< endl;     

    }
    if(playerIndex1 == 22 && playerIndex2 == 15){
        cout << map[playerIndex1-4][playerIndex2-6]<< " , " << map[playerIndex1-4][playerIndex2-5]<< " , " <<map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-6]<< " , " << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-6]<< " , " << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< endl;     
        cout <<map[playerIndex1][playerIndex2-6]<< " , " << map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-6]<< " , " << map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< endl;     
        cout << map[playerIndex1+2][playerIndex2-6]<< " , " << map[playerIndex1+2][playerIndex2-5]<< " , " <<map[playerIndex1+2][playerIndex2-4]<< " , " <<map[playerIndex1+2][playerIndex2-3]<< " , " << map[playerIndex1+2][playerIndex2-2]<< " , " << map[playerIndex1+2][playerIndex2-1]<< " , " << map[playerIndex1+2][playerIndex2]<< endl;     

    }
    if(playerIndex1 == 23 && playerIndex2 == 15){
        cout << map[playerIndex1-5][playerIndex2-6]<< " , " << map[playerIndex1-5][playerIndex2-5]<< " , " <<map[playerIndex1-5][playerIndex2-4]<< " , " << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< endl;     
        cout << map[playerIndex1-4][playerIndex2-6]<< " , " << map[playerIndex1-4][playerIndex2-5]<< " , " <<map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-6]<< " , " << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-6]<< " , " << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< endl;     
        cout <<map[playerIndex1][playerIndex2-6]<< " , " << map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-6]<< " , " << map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< endl;     

    }
    if(playerIndex1 == 23 && playerIndex2 == 14){
        cout <<  map[playerIndex1-5][playerIndex2-5]<< " , " <<map[playerIndex1-5][playerIndex2-4]<< " , " << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< endl;     
        cout <<  map[playerIndex1-4][playerIndex2-5]<< " , " <<map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< endl;     
        cout <<  map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  
        cout <<map[playerIndex1+1][playerIndex2-5]<< " , " <<map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< endl;     

    }
    if(playerIndex1 == 23 && playerIndex2 == 13){
        cout << map[playerIndex1-5][playerIndex2-4]<< " , " << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-4]<< " , " << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-4]<< " , " << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  
        cout << map[playerIndex1+1][playerIndex2-4]<< " , " << map[playerIndex1+1][playerIndex2-3]<< " , " << map[playerIndex1+1][playerIndex2-2]<< " , " << map[playerIndex1+1][playerIndex2-1]<< " , " << map[playerIndex1+1][playerIndex2]<< " , " << map[playerIndex1+1][playerIndex2+1]<< " , " << map[playerIndex1+1][playerIndex2+2]<< endl;     

    }
    if(playerIndex1 == 24 && playerIndex2 == 15){
        cout << map[playerIndex1-6][playerIndex2-6]<< " , " << map[playerIndex1-6][playerIndex2-5]<< " , " <<map[playerIndex1-6][playerIndex2-4]<< " , " << map[playerIndex1-6][playerIndex2-3]<< " , " << map[playerIndex1-6][playerIndex2-2]<< " , " << map[playerIndex1-6][playerIndex2-1]<< " , " << map[playerIndex1-6][playerIndex2]<< endl;     
        cout << map[playerIndex1-5][playerIndex2-6]<< " , " << map[playerIndex1-5][playerIndex2-5]<< " , " <<map[playerIndex1-5][playerIndex2-4]<< " , " << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< endl;     
        cout << map[playerIndex1-4][playerIndex2-6]<< " , " << map[playerIndex1-4][playerIndex2-5]<< " , " <<map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-6]<< " , " << map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-6]<< " , " << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-6]<< " , " << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< endl;     
        cout <<map[playerIndex1][playerIndex2-6]<< " , " << map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< endl;  

    }
    if(playerIndex1 == 24 && playerIndex2 == 14){
        cout <<  map[playerIndex1-6][playerIndex2-5]<< " , " <<map[playerIndex1-6][playerIndex2-4]<< " , " << map[playerIndex1-6][playerIndex2-3]<< " , " << map[playerIndex1-6][playerIndex2-2]<< " , " << map[playerIndex1-6][playerIndex2-1]<< " , " << map[playerIndex1-6][playerIndex2]<< " , " << map[playerIndex1-6][playerIndex2+1]<< endl;     
        cout <<  map[playerIndex1-5][playerIndex2-5]<< " , " <<map[playerIndex1-5][playerIndex2-4]<< " , " << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< endl;     
        cout <<  map[playerIndex1-4][playerIndex2-5]<< " , " <<map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< endl;     
        cout <<  map[playerIndex1-3][playerIndex2-5]<< " , " <<map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-5]<< " , " <<map[playerIndex1-2][playerIndex2-4]<< " , " <<map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-5]<< " , " <<map[playerIndex1-1][playerIndex2-4]<< " , " <<map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< endl;     
        cout <<map[playerIndex1][playerIndex2-5]<< " , " <<map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< endl;  

    }
    if(playerIndex1 == 24 && playerIndex2 == 13){
        cout << map[playerIndex1-6][playerIndex2-4]<< " , " << map[playerIndex1-6][playerIndex2-3]<< " , " << map[playerIndex1-6][playerIndex2-2]<< " , " << map[playerIndex1-6][playerIndex2-1]<< " , " << map[playerIndex1-6][playerIndex2]<< " , " << map[playerIndex1-6][playerIndex2+1]<< " , " << map[playerIndex1-6][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-5][playerIndex2-4]<< " , " << map[playerIndex1-5][playerIndex2-3]<< " , " << map[playerIndex1-5][playerIndex2-2]<< " , " << map[playerIndex1-5][playerIndex2-1]<< " , " << map[playerIndex1-5][playerIndex2]<< " , " << map[playerIndex1-5][playerIndex2+1]<< " , " << map[playerIndex1-5][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-4][playerIndex2-4]<< " , " << map[playerIndex1-4][playerIndex2-3]<< " , " << map[playerIndex1-4][playerIndex2-2]<< " , " << map[playerIndex1-4][playerIndex2-1]<< " , " << map[playerIndex1-4][playerIndex2]<< " , " << map[playerIndex1-4][playerIndex2+1]<< " , " << map[playerIndex1-4][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-3][playerIndex2-4]<< " , " << map[playerIndex1-3][playerIndex2-3]<< " , " << map[playerIndex1-3][playerIndex2-2]<< " , " << map[playerIndex1-3][playerIndex2-1]<< " , " << map[playerIndex1-3][playerIndex2]<< " , " << map[playerIndex1-3][playerIndex2+1]<< " , " << map[playerIndex1-3][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-2][playerIndex2-4]<< " , " << map[playerIndex1-2][playerIndex2-3]<< " , " << map[playerIndex1-2][playerIndex2-2]<< " , " << map[playerIndex1-2][playerIndex2-1]<< " , " << map[playerIndex1-2][playerIndex2]<< " , " << map[playerIndex1-2][playerIndex2+1]<< " , " << map[playerIndex1-2][playerIndex2+2]<< endl;     
        cout << map[playerIndex1-1][playerIndex2-4]<< " , " << map[playerIndex1-1][playerIndex2-3]<< " , " << map[playerIndex1-1][playerIndex2-2]<< " , " << map[playerIndex1-1][playerIndex2-1]<< " , " << map[playerIndex1-1][playerIndex2]<< " , " << map[playerIndex1-1][playerIndex2+1]<< " , " << map[playerIndex1-1][playerIndex2+2]<< endl;     
        cout << map[playerIndex1][playerIndex2-4]<< " , " << map[playerIndex1][playerIndex2-3]<< " , " << map[playerIndex1][playerIndex2-2]<< " , " << map[playerIndex1][playerIndex2-1]<< " , " << map[playerIndex1][playerIndex2]<< " , " << map[playerIndex1][playerIndex2+1]<< " , " << map[playerIndex1][playerIndex2+2]<< endl;  

    }
    
    map[playerIndex1][playerIndex2] = oldmap;

}// this is my function that handles printing out the 7x7 map at each turn 

void Map:: setPlayerLocation(int direction ){// this function will move the player based on an input of 1-4 which in the game will be NSEW
    if(direction == 1){
        playerIndex1--;
    }
    if(direction == 2){
        playerIndex1++;
    }
    if(direction == 3){
        playerIndex2++;
    }
    if(direction == 4){
        playerIndex2--;
    }
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

bool Map:: canP1moveHere(int index1, int index2){
    if(index1<0 || index1>24 || index2 <0 || index2 >15){
        return false;
    }
    if(map[index1][index2] == "w"){
        return false;
    }
    else{
        return true;
    }
    
}

void Map:: sendtoPokeCenter(int index1, int index2){
    int count = 0;
    for(int i = 0;i<16;i++){
        if(map[index1][i] == "C"){
            playerIndex2 = i;
            count++;
            break;
        }
    } 
    if(count == 0){
        for(int j = 0; j<25;j++){
            if(map[j][index2]== "C"){
                playerIndex1 = j;
                count++;
                break;
            }
        }
    }
    if(count == 0){
        for(int k = index1; k<25; k++){
            for(int b = 0;b<16;b++){
                if(map[k][b] == "C"){
                    playerIndex1 = k;
                    playerIndex2 = b;
                    count++;
                    break;
                }
            }
            if(count>0){
                break;
            }
        }
    }
    if(count == 0){
        for(int t = 0; t<index1;t++){
            for(int h = 0; h<16; t++){
                if(map[t][h] == "C"){
                    count++;
                    playerIndex1 = t;
                    playerIndex2 = h;
                    break;
                }
            }
            if(count>0){
                break;
            }
        }
    }
    
}

