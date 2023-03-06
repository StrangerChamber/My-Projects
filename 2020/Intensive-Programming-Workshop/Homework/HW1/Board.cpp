#include "Board.h"
#include <stdlib.h> 


Board:: Board(){//constructor initializing a new board for each game
    for(int i = 0;i<4;i++){ //intializing everything as empty
        for(int j = 0;j<4;j++){
            arr_[i][j] = "G";
        }
    }   
    srand(time(NULL));// this makes sure the board is different each game
    row = 0;
    col = 0; 
    arr_[0][0] = "P"; //set top left to player
    arr_[3][3] = "E"; // bottom right to exit
    for(int i = 0;i<4;i++){ //random placement of walls 
        for(int j = 0;j<4;j++){
            if(i==0 && j==0){
                j++;
            }
            if(i == 3 && j == 3){
                break;
            }
            int rand = std::rand()%5 +1;
            if(rand == 1){
                arr_[i][j] = 'W';
            }
        }
    }
    for(int h = 0;h<4;h++){ //random placement of treasure 
        for(int k = 0;k<4;k++){
            if(arr_[h][k] == "W" || arr_[h][k] == "E" || arr_[h][k] == "P"){

            }
            else{
                int rand = std::rand()%10 +1;
                if(rand == 1){
                    arr_[h][k] = "T";
                }
            }
        }
    }
    // now for placement of two enemies
    arr_[2][3] = "B";
    e1Row = 2;
    e1Col = 3;
    arr_[1][3] = "B";
    e2Row = 1;
    e2Col = 3;
}

void Board::print_board(){//this function prints the board as is
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            std::cout << arr_[i][j]<< "  ";
        }
        std::cout << std::endl;
    }
}

bool Board:: isGameOver(){// this function will end the game if certain conditions are met
    if(row == 3 && col == 3){
        return true;
    }
    else{
        return false;
    }
}


//here this functions 
//determines which moves are legal for the player

void Board::getMoves(){
    if(row-1>=0 && arr_[row-1][col]!="W"){
        std::cout<<"You can move up. Enter 1 for up"<<std::endl;
    }
    if(row+1<4&& arr_[row+1][col]!="W"){
        std::cout<<"You can move down. Enter 2 for down"<<std::endl;
    }
    if(col-1>=0 && arr_[row][col-1]!="W"){
        std::cout<<"You can move left. Enter 3 for left"<<std::endl;
    }
    if(col+1<4 && arr_[row][col+1]!="W"){
        std::cout<<"You can move right. Enter 4 for right"<<std::endl;
    }
}


// this function determines 
//if the user move input can be executed
bool Board:: isitLegal(int move){
    switch(move){
        case 1: 
            if(row-1>=0 && arr_[row-1][col]!="W"){
                return true;
            }
            return false;
        case 2:
            if(row+1<4 && arr_[row+1][col]!="W"){
                return true;
            }    
            return false;
        case 3:
            if(col-1>=0 && arr_[row][col-1]!="W"){
                return true;
            }    
            return false;
        case 4:
            if(col+1<4 && arr_[row][col+1]!="W"){
                return true;
            }    
            return false;
        default:
            return false;    
    }

}


//this function updates the board according to the player input

void Board::movePlayer(int move){
    if(move == 1){
        if(arr_[row-1][col] == "T"){
            std::cout << "you landed on treasure, congrats you get 100 points!"<<std::endl; 
        }       
        if(arr_[row-1][col] == "B"){
            std::cout << "You landed on an enemy. Game over!!!" << std::endl;
            over = 1;
            return;
        }
        arr_[row-1][col] = "P";
        arr_[row][col] = "G";
        row = row-1;
    }
    if(move == 2){
        if(arr_[row+1][col] == "T"){
            std::cout << "you landed on treasure, congrats you get 100 points!"<<std::endl; 
        } 
        if(arr_[row+1][col] == "B"){
            std::cout << "You landed on an enemy. Game over!!!" << std::endl;
            over = 1;
            return;
        }                 
        arr_[row+1][col] = "P";
        arr_[row][col] = "G";
        row = row+1;
    }
    if(move == 3){
        if(arr_[row][col-1] == "T"){
            std::cout << "you landed on treasure, congrats you get 100 points!"<<std::endl; 
        }          
        if(arr_[row][col-1] == "B"){
            std::cout << "You landed on an enemy. Game over!!!" << std::endl;
            over = 1;
            return;
        }        
        arr_[row][col-1] = "P";
        arr_[row][col] = "G";
        col = col-1;
    }
    if(move ==4){
        if(arr_[row][col+1] == "T"){
            std::cout << "you landed on treasure, congrats you get 100 points!"<<std::endl; 
        }         
        if(arr_[row][col+1] == "B"){
            std::cout << "You landed on an enemy. Game over!!!" << std::endl;
            over = 1;
            return;
        }         
        arr_[row][col+1] = "P";
        arr_[row][col] = "G";
        col = col+1;
    }
    turnCount++;
}


//check at the end of each turn
// makes sure if you were supposed to have lost or won
// the program tells you that
void Board::didYouWin(){
    if(arr_[3][3] == "P"){
        std::cout<<"YOU WON CONGRATS YOU BEAT MY MAZE!!!! GOODBYE!" << std::endl;
        return;
    }
    if(over == 1){
        std::cout<<"better luck next time" << std::endl;
        row = 3;
        col = 3;
        return;
    }
    if(turnCount >= 7){
        std::cout<<"Oh no you went over the amount of turns you can take so you lose. GAME OVER!" << std::endl;
        row = 3;
        col = 3;
    }
}

//after the player moves
//this function moves the two enemies randomly
// this function makes it so that they don't always move
// every turn 
void Board::moveEnemy(){
    srand(time(NULL));
    int randy = rand()%5;    
            if(randy == 0 && e1Row-1>=0  && arr_[e1Row-1][e1Col]!="E"){
                arr_[e1Row-1][e1Col] = "B";
                arr_[e1Row][e1Col] = "G";
                e1Row -= 1;
            }
           if(randy == 1 && e1Row+1<4 && arr_[e1Row+1][e1Col]!="E"){
                arr_[e1Row+1][e1Col] = "B";
                arr_[e1Row][e1Col] = "G";
                e1Row +=1;
            }    
            if(randy == 2 && e1Col-1>=0 && arr_[e1Row][e1Col-1]!="E"){
                arr_[e1Row][e1Col-1] = "B";
                arr_[e1Row][e1Col] = "G";
                e1Col -=1;
            }    
            if(randy == 3 && e1Col+1<4 && arr_[e1Row][e1Col+1]!="E"){
                arr_[e1Row][e1Col+1] = "B";
                arr_[e1Row][e1Col] = "G";
                e1Col +=1;
            }     

        int rand0 = rand()%5;    

            if(rand0 == 0 && e2Row-1>=0 && arr_[e2Row-1][e2Col]!="E"){
                arr_[e2Row-1][e2Col] = "B";
                arr_[e2Row][e2Col] = "G";
                e2Row -= 1;
            }
            if(rand0 == 1 && e2Row+1<4 && arr_[e2Row+1][e2Col]!="E"){
                arr_[e2Row+1][e2Col] = "B";
                arr_[e2Row][e2Col] = "G";
                e2Row +=1;
            }    
            if(rand0 == 2 && e2Col-1>=0 &&  arr_[e2Row][e2Col-1]!="E"){
                arr_[e2Row][e2Col-1] = "B";
                arr_[e2Row][e2Col] = "G";
                e2Col -=1;
            }    
            if(rand0 == 3 && e2Col+1<4  && arr_[e2Row][e2Col+1]!="E"){
                arr_[e2Row][e2Col+1] = "B";
                arr_[e2Row][e2Col] = "G";
                e2Col +=1;
            }     

}

//this function checks to make sure an enemy 
//didn't land on you after your move

void Board::checkIfDead(){ 
    if((row == e1Row && col == e1Col) || (row == e2Row && col == e2Col)){
        over = 1;
        std::cout <<"OH NO an enemy jumped on you. Game Over!!!!" <<std::endl;
    }
}