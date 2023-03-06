#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
// CS1300 Fall 2019
// Author: Jack Blackburn
// Recitation: Lucas Hayne
// Homework 8 - Problem 3 and 4

class Player
{
  private: // private variables
  string name;  // variable for player name
  double points; // variable for player points
  public: // public member functions
  Player(); // constructor
  Player(string, double); // parameterized constructor
  string getName(); // get name
  double getPoints(); // get points
  void setName(string); // set name
  void setPoints(double); // set points
  
};

//algorithm
// set points equal to 0
// set name to an empty string
Player:: Player(){ // constructor setting name to an empty string and points to 0
    points = 0;
    name = "";
}
// algorithm
// input string and double
// set string equal to name
// double equal to points
Player:: Player(string newName, double newPoints){   // parameterized constructor setting name and points to whatever is input
    name = newName;
    points = newPoints;
}
//algorithm
// return name
string Player:: getName(){ // getting the name of the player
    return name;
}
// algorithm
// return points
double Player:: getPoints(){ // getting the player points
    return points;
}
//algorithm
// input string
// set that string equal to the player name
void Player::setName(string newName){ // setting the name to whats input
    name = newName;
}


// algorithm
// input a double
// that input value now equal to points
void Player:: setPoints(double newPoints){ // setting points to the input value
    points = newPoints;
}


int split(string str, char c, string array[], int sizes){
    if (str.length()== 0){
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i<str.length(); i++){
        if (str[i]==c){
            if (word.length() == 0) {
                continue;
            }
            array[j++]= word;
            word = "";
        }
        else {
            word = word + str[i];
        }
        
    }
    return j;
}  /// this is my split function that I am recycling from awhile ago



class Team
{
    private:// private variables
    string teamName; // string for team name
    vector<Player> players; // vector object of type player
    public: // public member functions
    Team();// constructor
    Team(string);// parameterized constructor
    int getNumPlayers();// get number of players
    string getTeamName(); // get team name
    void setTeamName(string); // set team name
    void readRoster(string); // read the roster of players and points
    string getPlayerName(int i); // get player name
    double getPlayerPoints(int i); // get player points
    
};


// algorithm
// set teamname to an empty string
// set players to an empty vector
Team:: Team(){// constructor
    teamName = "";
    vector<Player> players;
}

//algorithm
// input string
// set string to team name
Team:: Team(string newTeamName){ // parameterized constructor
    teamName = newTeamName;
}

//algorithm
//input string
// set string to teamname
void Team:: setTeamName(string newName){ // setting my team name
    teamName = newName;
}


// algorithm
// input file name
// open the file
// read file line by line
// split the file into names and points through an array
// store the names and points into a vector
void Team:: readRoster(string fileName){ // reading the player name and their points and storing them into a vector
    ifstream datafile(fileName); // opening file
    if(datafile.is_open()) // if the file opens
    {
        string arr[2]; // array to split the names and points into two values
        string line = "";
        string name = "";
        double ratings = 0;
        while(getline(datafile, line)){ // reading the file line by line
            Player people; // declaring an object from the player class
            split(line, ',', arr, 2); // calling the split function to split my file
            name = arr[0]; // name is stored into the 0th index in the array
            people.setName(name); // setting the name with my players object
            ratings = stod(arr[1]); // the ratings are in the 1st index of my dummy array
            people.setPoints(ratings);// using the players object to set the points
            players.push_back(people); // filling the players vector using my player object
            name = ""; // reset name for next line
            ratings = 0; // reset ratings 
        }
    }
}

// algorithm
// input an int
// if the input value is larger than the player vector or less that 0 size return an "ERROR"
// otherwise return the name of the player at that index
string Team:: getPlayerName(int i){ // getting player name at a certain index
    if (i>=players.size()|| i<0){ // if given an invalid index value
        return "ERROR";
    }
    return players[i].getName(); // returning the player name at the given index
}

// algorithm
// input an integer
// if the integer is larger that the player vector size or less than 0 return -1
// otherwise return the points at the given index
double Team:: getPlayerPoints(int i){ // getting the players point at the input index
    if(i>=players.size()|| i<0){ // invalid index
        return -1;
    }
    return players[i].getPoints(); // returning the players points at the input index
}

// algorithm
// return the size of the players vector
int Team:: getNumPlayers(){ // getting the number of players stored in the vector
    return players.size();
}

// algorithm
// returning the team name
string Team:: getTeamName(){ // getting the team name
    return teamName;
}


int main(){
    // checking readRoster gets the right number of players (getNumPlayers)
Team team4("Seg Faultline");
cout << team4.getTeamName() << endl;
team4.readRoster("roster1.txt");
int n4 = team4.getNumPlayers();
cout << n4 << endl;

// checking default constructor
Team team1;
cout << team1.getTeamName() << endl;
cout << team1.getNumPlayers() << endl;

// checking teamName setter
Team team2;
team2.setTeamName("Llamas Pajamas");
cout << team2.getTeamName() << endl;
cout << team2.getNumPlayers() << endl;

// checking parameterized constructor
Team team3("Seg Faultline");
cout << team3.getTeamName() << endl;
cout << team3.getNumPlayers() << endl;

// checking readRoster gets the right number of players (getNumPlayers)
Team team5("Thats so Ravenclaw");
cout << team5.getTeamName() << endl;
team5.readRoster("roster1.txt");
int n5 = team5.getNumPlayers();
for (int i = 0; i < n5; i++) {
    cout << team5.getPlayerName(i) << " ";
    cout << team5.getPlayerPoints(i) << endl;
}

// checking getter player name functions
Team team6("Llamas Pajamas");
cout << team6.getTeamName() << endl;
team6.readRoster("roster1.txt");
cout << team6.getPlayerName(-1) << endl;
cout << team6.getPlayerName(4) << endl;
cout << team6.getPlayerName(5) << endl;

// checking getter player points functions
Team team7("Llamas Pajamas");
cout << team7.getTeamName() << endl;
team7.readRoster("roster1.txt");
cout << team7.getPlayerPoints(-1) << endl;
cout << team7.getPlayerPoints(4) << endl;
cout << team7.getPlayerPoints(5) << endl;
}