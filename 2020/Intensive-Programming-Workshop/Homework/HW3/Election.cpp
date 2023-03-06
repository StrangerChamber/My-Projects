#include "Election.h"





void Election::addCandidate(Candidate c){
    candidates.push_back(c);
}

std::vector<Candidate> Election::getCandidates(){
    return candidates;
}

void  Election::GetDistrictsFromMap(std::map<int,class District> d){
    districtInfo = d;
    return;
}


std::vector<int> Election::campaign(int canNum, int dSize, int DNum, int demcount, int repcount, int libcount, int nopcont){//this one's gonna be a doozy
    int canPartyNum = canNum; //1 for dem, 2 for rep, 3 for lib
    int districtSquareMiles = dSize;
    int districtNumber = DNum ;
    int DemConstits = demcount;
    int RepConstits = repcount;
    int LibConstits = libcount;
    int NoPConstits = nopcont;
    int CandidatePartyConstitCount;
    int ConstitsNotInCPOrNoP;
    int MajorityPartyNotCP;
    int MajorityPartyNum;
    if(canPartyNum == 1){
        CandidatePartyConstitCount = DemConstits;  
        ConstitsNotInCPOrNoP = RepConstits + LibConstits;
        if(RepConstits>=LibConstits){
            MajorityPartyNotCP = RepConstits;
            MajorityPartyNum = 2;
        }else{
            MajorityPartyNotCP = LibConstits;
            MajorityPartyNum = 3;
        }
    }
    if(canPartyNum == 2){
        CandidatePartyConstitCount = RepConstits;
        ConstitsNotInCPOrNoP = DemConstits + LibConstits;
        if(DemConstits>=LibConstits){
            MajorityPartyNotCP = DemConstits;
            MajorityPartyNum = 1;
        }else{
            MajorityPartyNotCP = LibConstits;
            MajorityPartyNum = 3;
        }

    }
    if(canPartyNum == 3){
        CandidatePartyConstitCount = LibConstits;
        ConstitsNotInCPOrNoP = RepConstits + DemConstits;
        if(RepConstits>=DemConstits){
            MajorityPartyNotCP = RepConstits;
            MajorityPartyNum = 2;
        }else{
            MajorityPartyNotCP = DemConstits;
            MajorityPartyNum = 1;
        }
    }
    //have all info needed to do probability 
    float PSuccess = (((CandidatePartyConstitCount+1)*2)/ConstitsNotInCPOrNoP)*(((CandidatePartyConstitCount+1)*2)/districtSquareMiles);
    float PExtraSuccess = PSuccess*.1;
    float randNum = float(rand()%10); //not sure what to make this my initial thought is to do 100 but then it would only update the voter count once in a blue moon the highest num possible is 64.5 from psuccess 
    //now to see what case we invoked
    if(randNum>PExtraSuccess && randNum<=PSuccess){//scenario one
        if(NoPConstits>0){
            NoPConstits--;
            CandidatePartyConstitCount++;
        }
    }
    if(randNum<=PExtraSuccess && randNum<=PSuccess){//scenario two and three
        MajorityPartyNotCP--;
        CandidatePartyConstitCount++;
        if(NoPConstits>0){
            NoPConstits--;
            CandidatePartyConstitCount++;
        }
    }
    if(canPartyNum == 1){
        DemConstits = CandidatePartyConstitCount;
        if(MajorityPartyNum == 2){
            RepConstits = MajorityPartyNotCP;
        }else{
            LibConstits = MajorityPartyNotCP;
        }
    }
    if(canPartyNum == 2){
        RepConstits = CandidatePartyConstitCount;
        if(MajorityPartyNum == 1){
            DemConstits = MajorityPartyNotCP;
        }else{
            LibConstits = MajorityPartyNotCP;
        }
    }
    if(canPartyNum == 3){
        LibConstits = CandidatePartyConstitCount;
        if(MajorityPartyNum == 2){
            RepConstits = MajorityPartyNotCP;
        }else{
            DemConstits = MajorityPartyNotCP;
        }
    }
    std::vector<int> constitList;
    constitList.push_back(NoPConstits);
    constitList.push_back(DemConstits);
    constitList.push_back(RepConstits);    
    constitList.push_back(LibConstits);
    return constitList;
}




void Election::CountVotes(int districtID, int demCount, int repCount, int libCount, int NopCount){
    int count = 0;
    if(demCount>repCount){
        if(demCount>libCount){
            count = 1;
        }else{
            count = 3;
        }

    }else{
        if(repCount>libCount){
            count = 2;
        }else{
            count =3;
        }
    }    
    for(int i  = 0; i<candidates.size();i++){
        if(candidates[i].party == Party::Dem){
            candidates[i].VotesAccumulated += demCount;
            demCount = 0;
            if(count == 1){
                candidates[i].VotesAccumulated += NopCount;
                NopCount = 0;
            }
        }
        if(candidates[i].party == Party::Rep){
            candidates[i].VotesAccumulated += repCount;
            repCount = 0;
            if(count == 2){
                candidates[i].VotesAccumulated += NopCount;
                NopCount = 0;
            }

        }
        if(candidates[i].party == Party::Lib){
            candidates[i].VotesAccumulated += libCount;
            libCount = 0;
            if(count == 3){
                candidates[i].VotesAccumulated += NopCount;
                NopCount = 0;
            }
        }
    }
    if(demCount!=0 || repCount!=0 || libCount!=0){//not everyone has voted yet
        int votesLeft = demCount+repCount+libCount+NopCount;
        candidates[0].VotesAccumulated += votesLeft;
    }
    return;
}

void Election::winner(){
    Candidate winner;
    for(int i = 0;i<candidates.size();i++){
        if(i == 0){
            winner = candidates[i];
        }
        if(winner.VotesAccumulated<candidates[i].VotesAccumulated){
            winner = candidates[i];
        }
    }
    std::cout<<"The long anticipated winner or the election is.............."<<endl<<endl<<winner.name<<" with a total of "<<winner.VotesAccumulated<<" votes"<<endl;
}



void Election::Reset(){
    candidates.clear();
    return;
}