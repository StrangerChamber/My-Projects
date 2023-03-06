#include <iostream>

void createBoard(std::string board[3][3]){
    for(int o =0;o<3;o++){
        for(int i = 0;i<3;i++){
            board[o][i] = " ! ";
        }
    }    
}

void displayBoard(std::string board[3][3]){
    for(int o =0;o<3;o++){
        for(int i = 0;i<3;i++){
            std::cout << board[o][i];
        }
        std::cout << std::endl;
    }
}

void getXPlayerChoice(std::string board[3][3]){
    std::cout<<"enter the index of the spot you would like to place an X on one coordinate at a time starting with the x then y" << std::endl;
    int x;
    int y;
    std::cin>>x;
    std::cin>>y;
    board[x][y] = " X ";
}

void getOPlayerChoice(std::string board[3][3]){
    std::cout<<"enter the index of the spot you would like to place an X on one coordinate at a time starting with the x then y" << std::endl;
    int x;
    int y;
    std::cin>>x;
    std::cin>>y;
    board[x][y] = " O ";
}

int main(){
    std::string board[3][3];
    createBoard(board);
    //displayBoard(board);
    int r = 0;
    while(r < 5){//game play loop
        getXPlayerChoice(board);
        displayBoard(board);
        getOPlayerChoice(board);
        displayBoard(board);
        r++;
    }
    std::cout <<"game over max number of moves has been reached. good bye"<< std::endl; 
}