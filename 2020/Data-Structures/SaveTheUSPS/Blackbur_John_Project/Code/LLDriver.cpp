#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>//timing library
#include "LinkedList.hpp"
using namespace std;
using namespace std::chrono;//use this for timing

int main(int argc, char* const argv[]){
    int data[40000];// read in data file to this array
    LL L1;//class object
    float insert[400];//time recorded in microseconds
    float search[400];// time for searches
    string line,first;
    int counter = 0;
    ifstream infile(argv[1]);
    if(infile.is_open()!= true){
        cout << "Failed to open the file." << endl;
        return 0;
    }
    while(infile.good()){//read into array is good
        getline(infile,first,',');
        data[counter] = stof(first);
        counter++;
    }
    infile.close();
    //just read in the file into the array now going to time the inserts and searches
    
    int loopCount = 0;//keep count of what iteration its on
    int insertIndex = 0;// use this to insert the right numbers into the LL
    while(loopCount<400){//run this loop 400 times to search and insert all the entries
        loopCount++;
        
        
        
        auto start = high_resolution_clock::now();//start timing the insertions
        for(int j = insertIndex;j<insertIndex+100;j++){
            L1.insert(data[j]);//100 inserts
        }
        auto finish = high_resolution_clock::now();//stop timing inserts
        auto duration = duration_cast<microseconds>(finish - start); //recording the time in microseconds
        insert[loopCount] = duration.count()/100;//inserting the time taken to do the inserts into insert array
        
        
        
        int randIndex[100];
        for(int k = 0;k<100;k++){//generate random number based on number of inserts done
            randIndex[k] = rand()%(insertIndex+100);
        }


        auto start2 = high_resolution_clock::now();//start search timing
        for(int l = 0;l<100;l++){//perform 100 searches
            L1.search(data[randIndex[l]]);
        }
        auto finish2 = high_resolution_clock::now();//stop timing search
        auto duration2 = duration_cast<microseconds>(finish2 - start2); //recording the time in microseconds
        search[loopCount] = duration2.count()/100;//input avg time into search array;


        insertIndex = insertIndex+100;
    }   



    //now output time data from search and insert arrays into external file
    //search and insert arrays are being filled correctly and time taken is working right
    ofstream Ofile(argv[2]);
    Ofile<<"Insert Data in microseconds: " <<endl;
    for(int t = 0;t<400;t++){
        Ofile<<insert[t]<< ",";
        if(t%20 == 0&& t!=0){//breaking the data into lines of 20 in output file
            Ofile<<endl;
        }
    }
    Ofile<<endl<<"Search Data in microseconds:"<<endl;
    for(int t = 0;t<400;t++){
        Ofile<<search[t]<< ",";
        if(t%20 == 0 && t!=0){
            Ofile<<endl;
        }        
    }    
    Ofile<<endl<<"end of test"<<endl;
    Ofile.close();
}