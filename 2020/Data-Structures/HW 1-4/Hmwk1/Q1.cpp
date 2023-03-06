#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int insertIntoSortedArray(float myArray[],int numEntries, float newValue){
    int index = 0;
    for(int i = 0; i<=numEntries;i++){
        if(myArray[i]<=newValue){
            index = i;
            break;
        }
        else{
            if(i == numEntries){
                index = numEntries-1;
            }
        }
    }
    for(int j = numEntries;j>index;j--){
        myArray[j] = myArray[j-1];
    }
    myArray[index] = newValue;
    
        numEntries++;
        return numEntries;
}

int main(int argc, char* const argv[]){
    float dummy[100];
    string line, first;
    int numPutIn = 1;
    ifstream infile;
    infile.open(argv[1]);
    if(infile.is_open()!= true){
        cout << "Failed to open the file." << endl;
    }
    else{
        while(getline(infile,line)){
            stringstream s(line);
            getline(s, first);
            insertIntoSortedArray(dummy, numPutIn, stof(first));
            numPutIn++;
            for(int i = 0; i<numPutIn-1; i++){
                cout << dummy[i];
                if(i!=numPutIn-2){
                    cout<< ",";
                }
            }
            cout << endl;
        }
    }
}