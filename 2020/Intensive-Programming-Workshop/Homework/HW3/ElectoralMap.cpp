#include "ElectoralMap.h"


ElectoralMap::ElectoralMap(){
        District d1;
        AllDistricts.insert(std::pair<int,District>(1,d1) );
        District d2;
        AllDistricts.insert(std::pair<int,District>(2,d2) );      
        District d3;
        AllDistricts.insert(std::pair<int,District>(3,d3) );
}


const int ElectoralMap:: numDistricts = 3;

int ElectoralMap:: districtSize(int id){
    return AllDistricts[id].getSize();
}
    

int ElectoralMap::districtPartySize(int partyNum, int districtID){
    return AllDistricts[districtID].partyCount(partyNum);
}

std::map<int, class District> ElectoralMap::getAllDistricts(){
    return AllDistricts;
}

void ElectoralMap::setDistrictPartySize(int districtID, int partyNum, int newSize){
    AllDistricts[districtID].setPartyCount(partyNum, newSize);
}