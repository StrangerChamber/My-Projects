#include <iostream>
#include <math.h>
using namespace std;

// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: f19 – Lucas Haynes
// Project 1 - Problem 3


int num;
double agility;                                // setting all of my globally scoped variables 
double strength;
double speed;

int main(){
while(num<=4){                                             // originating my first loop that will keep the outputting until the input is 4 or more  
	cout<<"Select a numerical option:"<<endl;              // setting the unchanging original table
	cout<<"=== menu ==="<<endl;
	cout<<"1. Fox"<<endl;
	cout<<"2. Bunny"<<endl;
	cout<<"3. Sloth"<<endl;
	cout<<"4. Quit"<< endl;

cin >> num ;                                // the input that will decide everything
while (num<=4){                            // my nested while loop for getting the hirescore
if (num == 4){                             // first condition to kill the loop if the input is 4
	num++;
}
else if (num == 3){                      // if statement to get the hire score for sloths
	cout << "Enter Strength:" << endl;
	cin >> strength;
	cout << "Enter Speed:" << endl;
	cin >> speed;
		double hireScore = 2.16 * strength + 3.24 * speed;
	cout << "Hire Score: " << hireScore << endl;
	break;
	
}

else if (num == 2){                       // if statement for bunnies
		cout << "Enter Agility:" << endl;
	cin >> agility;
	cout << "Enter Speed:" << endl;
	cin >> speed;
		double hireScore =  1.8 * agility + 3.24 * speed;
	cout << "Hire Score: " << hireScore << endl;
	break;

}

else if ( num == 1){                  // final if statement for foxes

	cout << "Enter Agility:" << endl;
	cin >> agility;
	cout << "Enter Strength:" << endl;
	cin >> strength;
		double hireScore =  1.8 * agility + 2.16 * strength;
	cout << "Hire Score: " << hireScore << endl;
	
	break;
}
}
}
}