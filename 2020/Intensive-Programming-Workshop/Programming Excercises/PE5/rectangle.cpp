#include <iostream>
#include "Rectangle.h"
//Jack Blackburn
//constructor works fine
// get width and height work too
//overlaps does not work correctly
//calc area works fine too
//expand works good
//shrink allows you to send a rectangle into negative space with it should not do
Rectangle::Rectangle(Point p1, Point p2){
    p1_.x = p1.x;
    p1_.y = p1.y;
    p2_.x = p2.x;
    p2_.y = p2.y; 
}

int Rectangle::GetWidth(){
    return p2_.x - p1_.x;
}

int Rectangle::GetHeight(){
    return p2_.y - p1_.y;
}


bool Rectangle::Overlaps(Rectangle& other){
    Point p = other.get_p1();
    Point pp = other.get_p2();
    if(((p.x >= p1_.x && p.x <= p2_.x)&&(p.y>=p1_.y && p.y<= p2_.y))||((pp.x >= p1_.x && pp.x <= p2_.x)&&(pp.y>=p1_.y && pp.y<= p2_.y))){
        return true;
    }
    return false;
}

int Rectangle::CalculateArea(){
    return (p2_.x - p1_.x)*(p2_.y - p1_.y);
}

void Rectangle::Expand(){
    p1_.x -= 1;
    p1_.y -= 1;
    p2_.x += 1;
    p2_.y += 1;
}

void Rectangle::Shrink(){
    if(p1_.x+1>p2_.x-1 || p1_.y+1>p2_.y-1){
        return;
    }
    p1_.x += 1;
    p1_.y += 1;
    p2_.x -= 1;
    p2_.y -= 1;
}