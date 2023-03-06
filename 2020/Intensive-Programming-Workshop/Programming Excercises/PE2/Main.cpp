#include <iostream>
#include "Point.cpp"

// Jack Blackburn

int main(){

    /*
    I instantiate 3 points, 2 of them with equal amount of dimensions

    Then I print the Point coordinates and amount of dimensions

    Then I calculate then print the distances between them 
    for the ones that do not have the same number of dimensions I print that the distance can not be calculated
    
    Then I shift the points and print the new values and distances


    */
    Point p1(4);
    std::vector <int> rex = {1,2,3,4};
    Point p2(rex);
    std::vector <int> tex = {11,12,13,14,15};
    Point p3(tex);
    std::cout << "point 1:" << p1.getPoint(0) << ','<< p1.getPoint(1) << ',' << p1.getPoint(2) << ',' << p1.getPoint(3) << std::endl;
    std::cout << "Point 1 dimensions:" << p1.getDimensions() << std::endl;
    std::cout << "point 2:" << p2.getPoint(0) << ','<< p2.getPoint(1) << ',' << p2.getPoint(2) << ',' << p2.getPoint(3) << std::endl;
    std::cout << "Point 2 dimensions:" << p2.getDimensions() << std::endl;    
    std::cout << "point 3:" << p3.getPoint(0) << ','<< p3.getPoint(1) << ',' << p3.getPoint(2) << ',' << p3.getPoint(3) << ',' << p3.getPoint(4) <<std::endl;
    std::cout << "Point 3 dimensions:" << p3.getDimensions() << std::endl;


    std::cout << "Distance from point 1 to point 2: " << p1.distance(p2.points) << std::endl;// dsitances between them
    std::cout << "Distance from point 1 to point 3: " << p1.distance(p3.points) << std::endl;
    std::cout << "Distance from point 2 to point 3: " << p3.distance(p2.points) << std::endl;
    p2.setPoint(0, 19);
    p1.translate(4);
    p2.translate(2);
    p3.translate(1);

    std::cout << "point 1:" << p1.getPoint(0) << ','<< p1.getPoint(1) << ',' << p1.getPoint(2) << ',' << p1.getPoint(3) << std::endl;
    std::cout << "Point 1 dimensions:" << p1.getDimensions() << std::endl;
    std::cout << "point 2:" << p2.getPoint(0) << ','<< p2.getPoint(1) << ',' << p2.getPoint(2) << ',' << p2.getPoint(3) << std::endl;
    std::cout << "Point 2 dimensions:" << p2.getDimensions() << std::endl;    
    std::cout << "point 3:" << p3.getPoint(0) << ','<< p3.getPoint(1) << ',' << p3.getPoint(2) << ',' << p3.getPoint(3) << ',' << p3.getPoint(4) <<std::endl;
    std::cout << "Point 3 dimensions:" << p3.getDimensions() << std::endl;

    std::cout << "Distance from point 1 to point 2: " << p1.distance(rex) << std::endl;// dsitances between them
    std::cout << "Distance from point 1 to point 3: " << p1.distance(tex) << std::endl;
    std::cout << "Distance from point 2 to point 3: " << p3.distance(rex) << std::endl;

    
    return 0;
}