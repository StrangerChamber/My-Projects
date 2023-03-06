#include <iostream>
#include <vector>
#ifndef BOARD_H
#define BOARD_H




/*
This class is where most of the work gets done
This class stores the board as a string array
it keeps track of where my player is and where each enemy is
This class also determines what moves are legal as to not cause seg faults
It also keeps track of if the player has won or lost yet
*/

class Board {
public:
	Board();
	int get_row() const {return row; }  
	int get_col() const {return col; }  
    void getMoves();
    void print_board();
    bool isGameOver();
    bool isitLegal(int move);
    void movePlayer(int move);
    void didYouWin();
    void moveEnemy();
    void checkIfDead();

private:
	std::string arr_[4][4];
	int row;
    int col;
    int over = 0;
    int e1Row;
    int e2Row;
    int e1Col;
    int e2Col;
    int turnCount = 0;
}; 

#endif 