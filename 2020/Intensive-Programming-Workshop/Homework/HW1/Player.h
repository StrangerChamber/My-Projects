#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

struct Position {
	int row;
	int col;


	bool operator==(const Position &other) {
		return row == other.row && col == other.col;
	}
};


class Player { // the only way I used this class was to have the player enter their name in the beginning of each game
public:

	Player(const std::string name, const bool is_human);  // constructor

	std::string get_name() const {return name_; }  // inline member function
	int get_points() const {return points_; }  // inline member function
	int get_row() const {return pos_.row; }  // inline member function
	int get_col() const {return pos_.col; }  // inline member function
	bool is_human() const {return is_human_; }  // inline member function


	void SetPosition(int row, int col);//set position 


private:
	std::string name_;//store name
	int points_;
	Position pos_;
	bool is_human_;



}; 

#endif  
