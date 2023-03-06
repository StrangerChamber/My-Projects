#include <iostream>
#ifndef ELECTION_H
#define ELECTION_H

struct Candidate{//candidate struct
    int id;
    std::string name;
    Party party;
    int VotesAccumulated = 0;//how i counted the votes
};

class Election{
    public:
    //Election();
    void Reset();//reset candidates vector
    void addCandidate(Candidate c); // this works 
    void winner();//annouces winner
    std::vector<int> campaign(int canNum, int districtNum, int dnum, int demcount, int repcount, int libcount, int nopcount);//campaign simulation work
    void GetDistrictsFromMap(std::map<int,class District> d);
    std::vector<Candidate> getCandidates(); // this works
    void CountVotes(int district,int demCount, int repCount, int libCount, int NopCount);//tally votes and give candidates votes according to logic in write up
    private:
    std::vector<Candidate> candidates;// stores candidates registered 
    std::map<int,class District> districtInfo;

};


#endif

class RepresentativeElection: public Election{
    public:

    private:

};


