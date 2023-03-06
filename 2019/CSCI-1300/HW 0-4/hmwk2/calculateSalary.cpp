#include <iostream>
#include <math.h> 
using namespace std;


int calculateSalary(int rainDays, int coldDays, int sunnyDays){
 
  
   int rainMoney= rainDays * 50 ;
    int coldMoney= coldDays * 40;
    int sunnyMoney= sunnyDays * 80;
    int salary = sunnyMoney + rainMoney + coldMoney;
return salary;
}
int main(){
    
}