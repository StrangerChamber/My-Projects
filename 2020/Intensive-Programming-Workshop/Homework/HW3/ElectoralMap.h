#include "District.cpp"
#include <iostream>
#include <map>
#include <vector>
#ifndef ELECTORALMAP_H
#define ELECTORALMAP_H


class ElectoralMap{
    public:
    static ElectoralMap& getInstance(){
        static ElectoralMap instance;        
        return instance;
    };
    int districtSize(int id);
    int districtPartySize(int partyNum, int districtID);
    void setDistrictPartySize(int districtID, int partyNum, int newSize);
    std::map<int, class District> getAllDistricts();
    private:
    ElectoralMap();
    static const int numDistricts;
    std::map<int, class District> AllDistricts;
};



#endif