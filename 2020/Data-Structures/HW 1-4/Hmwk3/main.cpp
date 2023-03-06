/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>

void displayMenu();  // declaration for main's helper-function

int main(int argc, char* argv[])
{
    // TODO: COMPLETE THIS DRIVER PROGRAM
    CountryNetwork CountryNet;
    int input = 0;
    string newCountry, Country, message;
    // TODO
    while(input!= 5){
        displayMenu();
        cin >> input;
        if(input == 1){
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();
        }
        if(input == 2){
            CountryNet.printPath();
        }
        if(input == 3){
            cout << "Enter name of the country to receive the message: " << endl;
            cin >> Country;
            cout << "Enter the message to send: " << endl;
            cin.ignore();
            getline(cin,message);
            cout << endl;
            CountryNet.transmitMsg(Country, message);
        }
        if(input == 4){
            cout << "Enter a new country name: " << endl;
            cin>> newCountry;
            cout << "Enter the previous country name (or First): " << endl;
            cin>> Country;
            if(Country != "First"){
                while(CountryNet.searchNetwork(Country) ==  NULL){
                    cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    cin>> Country;
                }
            }
            Country[0] = toupper(Country[0]);
            CountryNet.insertCountry(CountryNet.searchNetwork(Country), newCountry);
            CountryNet.printPath();
        }
        if(input == 5){
            cout << "Quitting..." << endl;
        }

    }

    cout << "Goodbye!"<< endl;
    return 0;
}



/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
