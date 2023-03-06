#include "Point.h"
#include <iostream> // inlcuded for wrong user input message
#include <cmath> //included so I can use sqrt function

//Jack Blackburn

Point:: Point(int x){//constructor setting point to origin and dimensions based on input
    for(int n = 0;n<x; n++){
        points.push_back(0);
    }
}

Point:: Point(std::vector <int> n){ // second constructor in which user inputs all the points and size by way of a vector
    for( int x = 0; x<n.size();x++){
        points.push_back(n[x]);
    }
}

int Point:: getDimensions(){ // returns size of the vector which is also the amount of dimensions for the point
    return points.size();
}

float Point:: getPoint(int index){ // getter function that gets point at given index
    return points[index];
}


void Point::setPoint(int index, int value){//setter for given index and given value
    points[index] = value;
}


float Point::distance(std::vector<int> input){ // formula for calculating euclidean distance for an x-dimensions point and another point with the same number of dimensions
    if(input.size() == points.size()){
        float total = 0;
        for(int x = 0;x<points.size();x++){
            total += ((points[x]-input[x])*(points[x]-input[x]));
        }
        return sqrt(total);
    }
    else{
        std::cout << "The given input has the incorrect amount of dimensions therefore the distance was not calculated" << std::endl;
        return 0;
    }
}

void Point::translate(int distance){ // shifts each coordinate by given distance
    for(int x = 0;x<points.size();x++){
        points[x] += distance;
    }
}