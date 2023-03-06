#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "BST.hpp"
using namespace std;
using namespace std::chrono;


int main(int argc, char* const argv[]){
    int data[40000];// reading data for file into this array
    Tree T1;//class object
    float insert[400];//time recorded in microseconds
    float search[400];
    string line,first;
    int counter = 0;
    
    
    
    ifstream infile(argv[1]);
    if(infile.is_open()!= true){
        cout << "Failed to open the file." << endl;
        return 0;
    }
    while(infile.good()){//read into array is good
        getline(infile,first,',');
        data[counter] = stoi(first);
        counter++;
    }
    infile.close();

    //data has been read into the array now it's time to time the searches and inserts


    int loopCount = 0;//keep count of what iteration its on
    int insertIndex = 0;// use this to insert the right numbers into the LL
    
    
    while(loopCount<400){//run this loop 400 times to search and insert all the entries
        loopCount++;
        
        
        auto start = high_resolution_clock::now();//start timing the insertions
        for(int j = insertIndex;j<insertIndex+100;j++){
            T1.insert(data[j]);//insert 100 times
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
            T1.search(data[randIndex[l]]);
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
        if(t%50 == 0&& t!=0){//output data in lines of 50
            Ofile<<endl;
        }
    }
    Ofile<<endl<<"Search Data in microseconds:"<<endl;
    for(int t = 0;t<400;t++){
        Ofile<<search[t]<< ",";
        if(t%50 == 0 && t!=0){//lines of 50
            Ofile<<endl;
        }        
    }    
    Ofile<<endl<<"end of test"<<endl;
    Ofile.close();
}    
