#include "ElectoralMap.cpp"
#include <iostream>
#include "Election.cpp"
#include "TextUI.cpp"
using namespace std;

//Jack Blackburn
//Quick Note: I chose to take the L on the representative election vote count
//I ran out of time and have other things due so I built out everything except for that
//Overall I think this simulator works pretty well and I had some fun building it 
//even though testing is always a pain
// nice idea for a HW 


// using this to print out my candidate names
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
    TextUI dialog;
    Election election;
    ElectoralMap onlymaps = ElectoralMap::getInstance(); //instantiate map outside simulation loop so it only instantiates once
    int x = 0;
    int electionChoice = 4;
    char choice;
    string name;
    while (x == 0){//simulation loop this will keep doing simultions until the user chooses to quit
        //first things first the user must choose what type of election they desire
        int candidateID = 0;
        dialog.electionType();
        int y = 0;
        while(y == 0){ //this loop ensures a correct input choice
            cin>>electionChoice;
            if(electionChoice == 0){ //direct choice
                cout<<"you have chosen the direct election path. POWER TO THE PEOPLE"<<endl;
                break;
            }
            if(electionChoice == 1){//rep choice
                cout << "you have chosen the representative election path. POWER TO THE DISTRICTS"<<endl;
                break;
            }
            if(electionChoice == 2){//quit choice
                cout << "you have chosen to quit"<<endl;
                x=1;
                break;
            }
            else{
                cout << "please enter a valid option 0-2" << endl;
            }
        }    
        if(x == 1){//this only goes in if user chose to quit above and should kill the simulation loop
            break;
        }
        //now to register candidates
        //dems first
        dialog.DemReg();
        cin>>choice;
        if(choice == 'y'){//addcandidate
            dialog.name();
            cin>>name;
            Candidate c1;
            c1.id = candidateID;
            candidateID++;
            c1.name = name;
            c1.party = Party::Dem;
            election.addCandidate(c1);
        }
        choice = ' ';
        name = "";
        dialog.RepReg();//register a republican
        cin>>choice;
        if(choice == 'y'){//addcandidate
            dialog.name();
            cin>>name;
            Candidate c2;
            c2.id = candidateID;
            candidateID++;
            c2.name = name;
            c2.party = Party::Rep;
            election.addCandidate(c2);
        }
        choice = ' ';
        name = "";
        dialog.LibReg();//register a libertarian
        cin>>choice;
        if(choice == 'y'){//addcandidate
            dialog.name();
            cin>>name;
            Candidate c3;
            c3.id = candidateID;
            candidateID++;
            c3.name = name;
            c3.party = Party::Lib;
            election.addCandidate(c3);
        }
        //now for campaigning
        cout << "you have succesfully registered " <<candidateID<< " candidates:"<<endl;
        cout << election.getCandidates()<<endl;
        dialog.campaign();
        //print each of the 3 districts with size and amount of voters in each party
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

        //now for the actual campaigning
        //testing that stuff right above this was a pain in the ***
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
        dialog.ElectionTime();
        //now that campaigning is done its time to call a vote
        // tally votes depending on type of election chosen
        //winner announced :)
        //restart loop
        if(electionChoice == 0){//direct election voting 
            election.CountVotes(1,onlymaps.districtPartySize(1,1),onlymaps.districtPartySize(2,1),onlymaps.districtPartySize(3,1),onlymaps.districtPartySize(0,1));
            election.CountVotes(1,onlymaps.districtPartySize(1,2),onlymaps.districtPartySize(2,2),onlymaps.districtPartySize(3,2),onlymaps.districtPartySize(0,2));
            election.CountVotes(1,onlymaps.districtPartySize(1,3),onlymaps.districtPartySize(2,3),onlymaps.districtPartySize(3,3),onlymaps.districtPartySize(0,3));
            election.winner();
        }    
        if(electionChoice == 1){//this would be the rep style but I ran out of time so for now it just does the same thing as above
            cout <<"above you chose to do a representative election so now the votes will be counted in the selected style"<<endl;
            election.CountVotes(1,onlymaps.districtPartySize(1,1),onlymaps.districtPartySize(2,1),onlymaps.districtPartySize(3,1),onlymaps.districtPartySize(0,1));
            election.CountVotes(1,onlymaps.districtPartySize(1,2),onlymaps.districtPartySize(2,2),onlymaps.districtPartySize(3,2),onlymaps.districtPartySize(0,2));
            election.CountVotes(1,onlymaps.districtPartySize(1,3),onlymaps.districtPartySize(2,3),onlymaps.districtPartySize(3,3),onlymaps.districtPartySize(0,3));
            election.winner();

        }
    election.Reset();//clears candidates so restart works correctly
    }
    cout << "You have left the simulation loop and chosen to quit. Goodbye" << endl;
}

