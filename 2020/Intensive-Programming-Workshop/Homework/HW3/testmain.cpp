#include "ElectoralMap.cpp"
#include <iostream>
#include "Election.cpp"
#include "TextUI.cpp"
using namespace std;


//I was using this file to test member functions 


//find a place to put this 
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
   os << "[";
   for (int i = 0; i < v.size(); ++i) {
      os << v[i].name;
      if (i != v.size() - 1)
         os << ", ";
   }
   os << "]\n";
   return os;
}



int main(){
            srand((unsigned int)time(NULL));
         Election election;
         Candidate c1;
         c1.name = "biden";
         c1.party = Party::Dem;
         election.addCandidate(c1);
         Candidate c2;
         c2.name = "trump";
         c2.party = Party::Rep;
         election.addCandidate(c2);

         Candidate c3;
         c3.name = "libby";
         c3.party = Party::Lib;
         election.addCandidate(c3);
        ElectoralMap onlymaps = ElectoralMap::getInstance();
        cout<<"District 1:"<<endl;
        cout <<"Square miles: "<<onlymaps.districtSize(1) <<endl;
        cout << "Democrat count: " << onlymaps.districtPartySize(1,1) << " Republican Count:" << onlymaps.districtPartySize(2,1)<<" Libertarian Count: " <<onlymaps.districtPartySize(3,1) << " No party Count: " << onlymaps.districtPartySize(0,1)<<endl;
    
        cout <<endl;
        cout<<"District 2:"<<endl;
        cout <<"Square miles: "<<onlymaps.districtSize(2) <<endl;
        cout << "Democrat count: " << onlymaps.districtPartySize(1,2) << " Republican Count:" << onlymaps.districtPartySize(2,2)<<" Libertarian Count: " <<onlymaps.districtPartySize(3,2) << " No party Count: " << onlymaps.districtPartySize(0,2)<<endl;

        cout <<endl;
        cout<<"District 3:"<<endl;
        cout <<"Square miles: "<<onlymaps.districtSize(3) <<endl;
        cout << "Democrat count: " << onlymaps.districtPartySize(1,3) << " Republican Count:" << onlymaps.districtPartySize(2,3)<<" Libertarian Count: " <<onlymaps.districtPartySize(3,3) << " No party Count: " << onlymaps.districtPartySize(0,3)<<endl;



                int z = 0;
        while(z == 0){//campaigning loop
            cout <<"which candidate would you like to go campaigning?(1 for dem, 2 for rep, 3 for lib, 4 for stop campaigning"<<endl;
            int canChoice;
            cin>>canChoice;
            if(canChoice == 4){
                break;
            }
            cout << "which district would you like to campaign in?enter num of the district"<<endl;
            int DChoice;
            cin>>DChoice;
            //find num of constits with each party
            vector<int> update = election.campaign(canChoice, onlymaps.districtSize(DChoice),DChoice, onlymaps.districtPartySize(1,DChoice),onlymaps.districtPartySize(2,DChoice),onlymaps.districtPartySize(3,DChoice),onlymaps.districtPartySize(0,DChoice));
            //update electoral map district voter count
            onlymaps.setDistrictPartySize(DChoice,0, update[0]);//update no party
            onlymaps.setDistrictPartySize(DChoice,1, update[1]);//update dem party
            onlymaps.setDistrictPartySize(DChoice,2, update[2]);//update rep party
            onlymaps.setDistrictPartySize(DChoice,3, update[3]);//update lib party
            cout <<"here are the new voter counts in each district"<< endl;
            cout <<endl;
            cout<<"District 1:"<<endl;
            cout <<"Square miles: "<<onlymaps.districtSize(1) <<endl;
            cout << "Democrat count: " << onlymaps.districtPartySize(1,1) << " Republican Count:" << onlymaps.districtPartySize(2,1)<<" Libertarian Count: " <<onlymaps.districtPartySize(3,1) << " No party Count: " << onlymaps.districtPartySize(0,1)<<endl;
        
            cout <<endl;
            cout<<"District 2:"<<endl;
            cout <<"Square miles: "<<onlymaps.districtSize(2) <<endl;
            cout << "Democrat count: " << onlymaps.districtPartySize(1,2) << " Republican Count:" << onlymaps.districtPartySize(2,2)<<" Libertarian Count: " <<onlymaps.districtPartySize(3,2) << " No party Count: " << onlymaps.districtPartySize(0,2)<<endl;

            cout <<endl;
            cout<<"District 3:"<<endl;
            cout <<"Square miles: "<<onlymaps.districtSize(3) <<endl;
            cout << "Democrat count: " << onlymaps.districtPartySize(1,3) << " Republican Count:" << onlymaps.districtPartySize(2,3)<<" Libertarian Count: " <<onlymaps.districtPartySize(3,3) << " No party Count: " << onlymaps.districtPartySize(0,3)<<endl;
        }
            //now that campaigning is done its time to call a vote
            // tally votes depending on type of election chosen
            //winner announced :)
            //restart loop
            election.CountVotes(1,onlymaps.districtPartySize(1,1),onlymaps.districtPartySize(2,1),onlymaps.districtPartySize(3,1),onlymaps.districtPartySize(0,1));
            election.CountVotes(1,onlymaps.districtPartySize(1,2),onlymaps.districtPartySize(2,2),onlymaps.districtPartySize(3,2),onlymaps.districtPartySize(0,2));
            election.CountVotes(1,onlymaps.districtPartySize(1,3),onlymaps.districtPartySize(2,3),onlymaps.districtPartySize(3,3),onlymaps.districtPartySize(0,3));
            election.winner();


        


}