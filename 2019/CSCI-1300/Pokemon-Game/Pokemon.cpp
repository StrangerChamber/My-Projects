#include <iostream>
#include <cmath>
#include <fstream>
#include<time.h>
#include <vector>
using namespace std;
#include "Pokemon.h"


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

int Pokemon:: unluckyPokeNum(){
      return unluckypoke;
}

int Pokemon:: wannafightpokenum(){
      return wannafightpoke;
}

int Pokemon:: getPokedexSize(){
    return pokedex.size();
}

int Pokemon:: getsinglepokedexindex(int index){
    return pokedex.at(index);
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

void Pokemon:: removePokefromDex(int index){
    int position = 1000000;
    for(int i = 0;i<pokedex.size();i++){
        if(pokedex[i]==index){
              position = i;
        }
    }
    if(position!= 1000000){
        pokedex.erase(pokedex.begin() + position);
    }
  }
  
void Pokemon:: lowercounters(){
    counters--;
}  

void Pokemon:: resetcounters(){
    counters = 0;
}
