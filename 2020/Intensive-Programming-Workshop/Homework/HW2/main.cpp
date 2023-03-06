#include <iostream>
using namespace std;
#include <vector>
#include "Counter.hpp"


int main(){
    Counter<int> c;
    vector<int> v1 (5,1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(3);
    for(int i = 0;i<v1.size();i++){
        cout << v1[i] << ",";
    }
    cout <<endl;
    Counter<int> c2(v1);
    vector<int> v2 = c2.MostCommon(3);
    cout << "should be 1 2" << endl;
    cout << v2[0] <<" " << v2[1] << v2[2]<<endl;

}