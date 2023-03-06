#include <iostream>
#include "Point.cpp"


int main(){
    Point P1; //first instance of my class aka point 1
    Point P2(5,10); // second instance
    Point P3(12,4); // third instance
    std::cout << "Point 1 Coordinates: (" << P1.getX() << ',' << P1.getY() << ')' << std::endl; //declaring where the points are 
    std::cout << "Point 2 Coordinates: (" << P2.getX() << ',' << P2.getY() << ')' << std::endl;
    std::cout << "Point 3 Coordinates: (" << P3.getX() << ',' << P3.getY() << ')' << std::endl;

    std::cout << "Distance from point 1 to point 2: " << P1.distance(P2.getX(), P2.getY()) << std::endl;// dsitances between them
    std::cout << "Distance from point 1 to point 3: " << P1.distance(P3.getX(), P3.getY()) << std::endl;
    std::cout << "Distance from point 2 to point 3: " << P3.distance(P2.getX(), P2.getY()) << std::endl;

    P1.translate(10); // moving point1 positive 10 places
    
    std::cout << "Point 1 Coordinates: (" << P1.getX() << ',' << P1.getY() << ')' << std::endl;// stating new point location
    std::cout << "Point 2 Coordinates: (" << P2.getX() << ',' << P2.getY() << ')' << std::endl;
    std::cout << "Point 3 Coordinates: (" << P3.getX() << ',' << P3.getY() << ')' << std::endl;
    
    std::cout << "Distance from point 1 to point 2: " << P1.distance(P2.getX(), P2.getY()) << std::endl;// new distance
    std::cout << "Distance from point 1 to point 3: " << P1.distance(P3.getX(), P3.getY()) << std::endl;
    std::cout << "Distance from point 2 to point 3: " << P3.distance(P2.getX(), P2.getY()) << std::endl;
    
    P1.translate(-5); // moving same point negative 5 places
    
    std::cout << "Point 1 Coordinates: (" << P1.getX() << ',' << P1.getY() << ')' << std::endl; // new location
    std::cout << "Point 2 Coordinates: (" << P2.getX() << ',' << P2.getY() << ')' << std::endl;
    std::cout << "Point 3 Coordinates: (" << P3.getX() << ',' << P3.getY() << ')' << std::endl;
    
    std::cout << "Distance from point 1 to point 2: " << P1.distance(P2.getX(), P2.getY()) << std::endl;// new distances
    std::cout << "Distance from point 1 to point 3: " << P1.distance(P3.getX(), P3.getY()) << std::endl;
    std::cout << "Distance from point 2 to point 3: " << P3.distance(P2.getX(), P2.getY()) << std::endl;
    
    return 0;
}