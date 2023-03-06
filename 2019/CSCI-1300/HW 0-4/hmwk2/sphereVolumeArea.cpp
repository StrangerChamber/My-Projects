#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    double volume;
    double surfaceArea;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    surfaceArea = 4.0 * M_PI * pow(radius,2);
    cout << "volume: " << volume << endl << "surface area: " << surfaceArea << endl;
    //your code goes here

} 