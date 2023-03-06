#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
using namespace std;
#include "Trainers.h"


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
        int num1 = rand()%151;
        trainer1pokes.push_back(num1);
    }
    int much = rand()%6+1;
    for(int i = 0;i<much;i++){
        int num2 = rand()%151;
        trainer2pokes.push_back(num2);
    }
    int mucho = rand()%6+1;
    for(int i = 0;i<mucho;i++){
        int num3 = rand()%151;
        trainer3pokes.push_back(num3);
    }
    int gracias = rand()%6+1;
    for(int i = 0;i<gracias;i++){
        int num4 = rand()%151;
        trainer4pokes.push_back(num4);
    } 
    for(int i = 0;i<gracias;i++){
        int num5 = rand()%151;
        trainer5pokes.push_back(num5);
    }     
    for(int i = 0;i<mucho;i++){
        int num6 = rand()%151;
        trainer6pokes.push_back(num6);
    }   
    for(int i = 0;i<num;i++){
        int num7 = rand()%151;
        trainer7pokes.push_back(num7);
    }     
    for(int i = 0;i<much;i++){
        int num8 = rand()%151;
        trainer8pokes.push_back(num8);
    }     
    int love = rand()%6+1;
    for(int i = 0;i<love;i++){
        int num9 = rand()%151;
        trainer9pokes.push_back(num9);
    }     
    for(int i = 0;i<love;i++){
        int num10 = rand()%151;
        trainer10pokes.push_back(num10);
    }   
    int crazy = rand()%6+1;
    for(int i = 0;i<crazy;i++){
        int num11 = rand()%151;
        trainer11pokes.push_back(num11);
    }     
    for(int i = 0;i<crazy;i++){
        int num12 = rand()%151;
        trainer12pokes.push_back(num12);
    }     
    for(int i = 0;i<much;i++){
        int num13 = rand()%151;
        trainer13pokes.push_back(num13);
    }     
    for(int i = 0;i<love;i++){
        int num14 = rand()%151;
        trainer14pokes.push_back(num14);
    }     
    for(int i = 0;i<crazy;i++){
        int num15 = rand()%151;
        trainer15pokes.push_back(num15);
    }     
}

int Trainers:: getTrainer1Pokesindex(int index){// use this to plug into another function needing an index to print poke name and stats
    return trainer1pokes.at(index);
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



