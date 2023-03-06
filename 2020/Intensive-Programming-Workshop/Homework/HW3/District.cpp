#include "District.h"
#include <stdlib.h>
#include <time.h> 


int District::ID = 0;

District::District(){//constructor creates random amount of constits, their parties, and size of district
    ID++;
    int constits = rand()%10;//amount of consituents
    amountOfVoters = constits;
    int size = rand()%25+5;//rand etween 5 and 29
    dSize = size;
    for(int i = 0; i<constits;i++){
        int parti = rand()%4;
        if(parti == 0){//none
            constituents.push_back(0);
        }
        if(parti == 1){//dem
            constituents.push_back(1);
        }
        if(parti == 2){//rep
            constituents.push_back(2);
        }
        if(parti == 3){//lib
            constituents.push_back(3);
        }
    }
}


int District::getID(){
    return ID;
}


std::vector<int> District::getPartyCounts(){
    return constituents;
}


int District::getSize(){
    return dSize;
}


int District::partyCount(int partyNum){
    int count = 0;
    if(partyNum == 0){//no party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 0){
                count++;
            }
        }
    }
    if(partyNum == 1){//dem party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 1){
                count++;
            }
        }
    }
    if(partyNum == 2){//rep party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 2){
                count++;
            }
        }
    }
    if(partyNum == 3){//lib party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 3){
                count++;
            }
        }
    }
    return count;
}

int District::getVoterAmount(){
    return amountOfVoters;
}


void District::setPartyCount(int partyNum, int newSize){
    int count = 0;
    if(partyNum == 0){//no party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 0){
                count++;
            }
        }
    }
    if(partyNum == 1){//dem party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 1){
                count++;
            }
        }
    }
    if(partyNum == 2){//rep party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 2){
                count++;
            }
        }
    }
    if(partyNum == 3){//lib party
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == 3){
                count++;
            }
        }
    }
    if(count == newSize){
        return;
    }
    if(count<newSize){//need to add some
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] != partyNum){
                constituents[i] = partyNum;
                count++;
            }
            if(count == newSize){
                return;
            }
        }
    }
    if(count>newSize){
        for(int i = 0;i<constituents.size();i++){
            if(constituents[i] == partyNum){
                if(partyNum != 3){
                    constituents[i] = 3;
                }else{
                    constituents[i] = partyNum+1;
                }    
                count--;
            }
            if(count == newSize){
                return;
            }
        }

    }
}