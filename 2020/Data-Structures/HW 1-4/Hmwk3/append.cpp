#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool append(string* &str_arr, string s, int &numEntries, int &arraySize){
    int counter = 0;
    if(numEntries == arraySize -1){
        arraySize = arraySize * 2;
        string *ptr = new string[arraySize];
        for(int i = 0; i< arraySize/2; i++){
            ptr[i] = str_arr[i];
        }
        delete[] str_arr;
        str_arr = ptr;
        counter++;
    }
    str_arr[numEntries] = s;    
    numEntries++;
    if(counter == 0){
        return false;
    }
    else{
        return true;
    }

}

int main(int argc, char* const argv[]){

}