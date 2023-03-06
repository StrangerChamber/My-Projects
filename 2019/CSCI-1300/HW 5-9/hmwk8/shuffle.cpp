#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 8 - Problem 1


// algorithm
// take in two vectors of type int
// create a 3rd vector to store the alternating list
// determine whether the size of the input vectors are equal or not
// if equal fill the new vector with alternating values from the input vectors starting with the first input vector then return the filled vector
// if either input vector is empty return an empty vector
// if one input vector has less values input into it fill the new vector alternating starting with the larger one until you reach the size of the smaller vector then fill the new vector with the rest of the values from the larger vector
// return the new vector

vector<int> shuffle(vector<int> v1, vector<int> v2){
    vector<int> v3; // creating a new vector to store my alternating values
    if(v1.size()== 0 && v2.size() == 0){ // if either input vector is empty return an empty vector
        return v3;
    }
    if(v1.size() == v2.size()){ // if they're equal in size fill the new vector alternating starting with v1
        for (int i = 0; i< v1.size(); i++){
            v3.push_back(v1[i]);
            v3.push_back(v2[i]);
        }
        return v3;
    }
    if (v1.size()<v2.size()){ // if one is smaller than the other alternate starting with the larger one up until the smaller ones size
        for(int i = 0; i<v1.size(); i++){
            v3.push_back(v2[i]);
            v3.push_back(v1[i]);
        }
        for (int j = v1.size();j<v2.size();j++){ // fill the new vector with the rest of the values from the larger vector
            v3.push_back(v2[j]);
        }
        return v3;
    }
    if(v2.size()<v1.size()){ // same as above just if the second vector is smaller 
        for(int i = 0; i< v2.size();i++){
            v3.push_back(v1[i]);
            v3.push_back(v2[i]);
        }
        for(int j = v2.size(); j<v1.size(); j++){
            v3.push_back(v1[j]);
        }
        return v3; // return whatever is stored in my new vector
    }
}



int main(){
    
}