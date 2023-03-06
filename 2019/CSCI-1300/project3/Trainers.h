#ifndef TRAINERS_H
#define TRAINERS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

#endif