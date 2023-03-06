#include <iostream>
#include "Rectangle.h"


int main(){
    Point p1;
    p1.x = 0;
    p1.y = 0;

    Point p2;
    p2.x = 3;
    p2.y =3;

    Rectangle R1(p1,p2);
    p1 =  R1.get_p1();
    p2 = R1.get_p2();
    std::cout << p1.x << ','<<p1.y <<std::endl;
    std::cout << p2.x << ','<<p2.y <<std::endl;
    std::cout << R1.GetWidth() << "width, now height:"<<R1.GetHeight()<<std::endl;
    Point p3;
    p1.x = 2;
    p1.y = 2;
    Point p4;
    p1.x = 5;
    p1.y = 5;

    Rectangle R2(p3,p4);
    std::cout << R1.Overlaps(R2)<<std::endl;
    std::cout <<"area: "<<R1.CalculateArea()<<std::endl;
    R1.Expand();
    p1 =  R1.get_p1();
    p2 = R1.get_p2();
    std::cout << p1.x << ','<<p1.y <<std::endl;
    std::cout << p2.x << ','<<p2.y <<std::endl;
    R1.Shrink();
    R1.Shrink();
    R1.Shrink();
    p1 =  R1.get_p1();    
    p2 = R1.get_p2();
    std::cout << p1.x << ','<<p1.y <<std::endl;
    std::cout << p2.x << ','<<p2.y <<std::endl;    
}