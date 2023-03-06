//John Blackburn JOBL2177 
//9-18-2020
#include <iostream> 
#include "Board.cpp"
#include "player.cpp"
#include "maze.cpp"

/* NOTE ABOUT MY WORK

For this project I kind of 
dismantled the classes that were already 
made and took the game my own direction
It seemed to me it was unecessarily complicated with the classes
and enum and struct. So, I made it much simpler
and loaded most of my methods into my Board class. The 
player and maze classes were hardly used for my game.
I also ditched the enum so I didn't have to constantly 
translate it into strings. I understand if I get points 
taken for not using the given classes and methods. I was in a rush at the end
so I made it simpler for myself so I could spend less time debugging and more
time implementing the rules of the game. I believe I 
was able to recreate the game with the same rules and that
it'll work the same way just fine. 
*/


int main(){
    Maze m;//instantiate maze 
    m.welcome();//only time I use that class
   
    Board b1;//heavy hitter class
   
    std::cout << "please enter your first name:" << std::endl;
    std::string name;
    std::cin>>name;
    Player p1(name, true);//only use of player class
   
    std::cout << "A new maze has been created for you. You move through the maze by inputting the direction you would like to go at each turn" << std::endl;
    std::cout <<"are you sure you want to play?? Enter Y for yes enter N for no." << std::endl;
    std::string yn;
    
    int x = 0;
    while(x == 0){// loop making sure player is ready to start the game
        std::cin>> yn;
        if (yn == "y" || yn == "Y"){
            std::cout << "welcome to my maze, let us begin. Please beware you can only make a total of 7 moves to defeat my maze" << std::endl;
            x++;
        }
        else if(yn =="n"||yn=="N"){
            std::cout <<"we all know our limits. Goodbye!" <<std::endl;
            return 0;
        }
        else{
            std::cout <<"invalid input please enter y or n" << std::endl;
        }
    }
    
    while(b1.isGameOver() == false){// this is the game play loop it keeps looping until the game is over
        b1.getMoves();//get available moves and print them above current board
        
        b1.print_board();//prints the current state of the board
        
        int move;
        std::cout << "Which way would you like to move(or enter 5 to quit)" << std::endl;
        std::cin>>move; //input choice of move
        if(move == 5){// quit sequence in case of unsolvable maze
            return 0;
        }

        int count = 0;
        while(count == 0){//loop to ensure user input an appropriate move
            if(b1.isitLegal(move) == true){
                count++;
            }
            else{
                std::cout << "Please enter a valid move" << std::endl;
                std::cin>>move;
            }
        }

        b1.movePlayer(move);// actually moving player and updating board

        b1.moveEnemy();// move 2 enemies once player has moved

        b1.checkIfDead();// checks if an enemy moved onto players current spot

        b1.didYouWin(); // checks if you won or lost and breaks loop if so
        //if you didn't win or lose on the current turn you repeat the loop until you win or lose or quit  
    }

}