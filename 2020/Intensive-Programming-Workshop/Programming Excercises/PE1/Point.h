#ifndef Point_H
#define Point_H

class Point{ // defining my class "point" here with appropriate header guard above
    public:
    Point();  // contructor to set point to origin
    Point(float x1, float y1); // constructor to set point to user input
    float getX(); // get x function
    float getY(); // get y function
    void setX(float x1); // setter for x
    void setY(float y1); // setter for y
    float distance(float x1, float y1); // distance formula calculator
    void translate(int distance); // shifts point by given distance
    private:
    float x; //stores x value for my point
    float y; // stores y for the point

};

#endif

