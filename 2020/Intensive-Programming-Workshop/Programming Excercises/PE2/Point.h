#ifndef Point_H
#define Point_H
#include <vector>

//Jack Blackburn

class Point{ // defining my class "point" here with appropriate header guard above
    public:
    Point(int n);  // contructor to set point to origin with n dimensions

    Point(std::vector <int> n); // constructor to set point to user input

    float getPoint(int index); // get point function gives value at the dimension input
    
    int getDimensions(); // returns the amount of dimensions 

    void setPoint(int index, int value); // setter for index given 
    
    float distance(std::vector <int> rex); // distance formula calculator for each dimensions
    
    void translate(int distance); // shifts points by given distance
    
    std::vector<int> points; // decided to make the vector public so I can directly compare the vector of one object to another
};

#endif

