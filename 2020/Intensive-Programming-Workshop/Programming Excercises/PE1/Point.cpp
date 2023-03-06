#include "Point.h"
#include <cmath> //included so I can use sqrt function

Point:: Point(){//constructor
    x = 0;
    y = 0;
}

Point:: Point(float x1, float y1){ // second constructor
    x = x1;
    y = y1;
}

float Point:: getX(){ // getter 1
    return x;
}

float Point:: getY(){ //getter 2
    return y;
}

void Point::setX(float x1){//setter 1
    x = x1;
}

void Point:: setY(float y1){//setter 2
    y = y1;
}

float Point::distance(float x1, float y1){ // formula for calculating distance and then returning given value
    return sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)));
}

void Point::translate(int distance){ // shifts each coordinate by given distance
    x += distance;
    y += distance;
}