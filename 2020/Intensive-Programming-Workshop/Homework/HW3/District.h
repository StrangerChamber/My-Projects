#include <iostream>
using namespace std;
#include <vector>
#ifndef DISTRICT_H
#define DISTRICT_H

class District{
    public:
        District();
        int getID();
        int getVoterAmount();
        std::vector<int> getPartyCounts();//num of people in the district
        int getSize();
        void setPartyCount(int partyNum, int newsize);
        int partyCount(int partyNum);//num of people in each party
        bool operator <(const District& D) const //this is neccessary for adding district to my map in electoral map 
    {
        return ID < D.ID;
    }
    private:
        int dSize;
        static int ID;
        std::vector<int> constituents;
        int amountOfVoters;
};

#endif


enum class Party{//party types
    None,
    Dem,
    Rep,
    Lib,
};