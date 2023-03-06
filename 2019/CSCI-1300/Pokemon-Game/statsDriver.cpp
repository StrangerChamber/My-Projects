#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


class Stats{
  private:
  int HP[151];  // health of pokemon
  int attack[151]; // strength of attacks
  int defense[151]; // resistance against attacks
  int max[151];    // max value of the attack and defense values
  int speed[151]; // speed of poke 

  public:
  Stats();
  int getHP(int);
  void setHP(int);
  int getAttack(int);
  void setAttack(int);
  int getDefense(int);
  void setDefense(int);
  int getMax(int);
  int getSpeed(int);
  void setSpeed(int);
};


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
            attack[i] = stoi(arr[3]);
            defense[i] = stoi(arr[4]);
            speed[i] = stoi(arr[5]);
            max[i] = stoi(arr[6]);
            i++;
        }
        
    }
}

int Stats:: getHP(int index){
    return HP[index];
}

void Stats:: setHP(int index){
    int NewHP = HP[index] * 1.02;
    if(NewHP!= 102){
        NewHP = NewHP +1;
    }    
    HP[index] = NewHP;
    
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


int main(){
    Stats stat;
    //for(int i = 0; i<151; i++){
      //  cout << stat.getHP(i) << " , " << stat.getAttack(i) << " , " << stat.getDefense(i) << " , " << stat.getSpeed(i) << " , " << stat.getMax(i) << endl; 
    //}
    
    cout << stat.getAttack(150) << endl;
    stat.setAttack(150);
    cout << stat.getAttack(150)<< endl;
}