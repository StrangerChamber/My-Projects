#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Park{
    string parkname;
    string state;
    int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length){
    parks[length].parkname = parkname;
    parks[length].state = state;
    parks[length].area = area;
    length++;
}

void printList(const Park parks[], int length){
    for(int i = 0; i< length;i++){
        cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl;
    }
}


int main(int argc, char* const argv[]){
    ifstream infile;
    Park park[100];
    int counter = 0;
    string line, first, second, third;
    infile.open(argv[1]);
    while(getline(infile,line)){
        stringstream s(line);
        getline(s, first, ',');
        getline(s, second, ',');
        getline(s, third, ',');
        addPark(park, first, second, stoi(third), counter);
        counter++;
    }
    printList(park, counter); 
    ofstream outFile;
    outFile.open(argv[2]);
    for(int i = 0; i<counter; i++){
        if(park[i].area>= stoi(argv[3]) && park[i].area<= stoi(argv[4])){
            outFile << park[i].parkname << ',' << park[i].state<<',' << park[i].area <<endl;
        }
    }
    outFile.close();

}
