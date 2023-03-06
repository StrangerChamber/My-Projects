#include <iostream>
#include <math.h>
using namespace std;



int chessBoard(char letter, int number){
     if (letter == 'a' && number%2!= 0){
        cout << "black";
        
    }
   else if (letter == 'a' && number%2==0){
        cout<< "white";
    }
    else if ( letter == 'b' && number%2!= 0){
        cout << "white";
    }
    else if ( letter == 'b' && number%2==0){
        cout << "black";
    }
    else if (letter == 'c' && number%2!= 0){
        cout << "black";
    }
    else if (letter == 'c' && number%2== 0){
         cout << "white";
    }
    else if (letter =='d' && number%2!= 0){
         cout << "white";
    }
    else if (letter =='d' && number%2== 0){
        cout << "black";
    }
    else if (letter == 'e' && number%2!=0){
        cout << "black";
    }
    else if(letter == 'e' && number%2==0){
        cout << "white";
    }
    else if (letter == 'f' && number%2!=0){
        cout << "white";
    }
    else if (letter == 'f' && number%2==0){
        cout << "black";
    }
    else if (letter == 'g' && number%2!=0){
        cout << "black";
    }
    else if (letter == 'g' && number%2==0){
        cout << "white";
    }
    else if (letter == 'h' && number%2!=0){
        cout << "white";
    }
     else if (letter == 'h' && number%2==0){
        cout << "black";
     }
     else if (number>=8){
         cout << "Chessboard squares can only have letters between a-h and numbers between 1-8.";
     }
    else{
        cout<< "Chessboard squares can only have letters between a-h and numbers between 1-8.";
    }
}

int main(){
   chessBoard('a',6);
    
}