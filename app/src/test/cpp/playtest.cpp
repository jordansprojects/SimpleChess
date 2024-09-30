#include "../../main/headers/bitboard.h"
#include "../../main/headers/unicodepieces.h"
#include <iostream>
using namespace std;
int main(){
    // TODO: init bitboard based on default constants
    bool isGameOn = true;
    bool isPlayerTwosTurn = false;
    string move;

    while(isGameOn){
        printf("Player %d's turn : ", (isPlayerTwosTurn + 1));
        getline(cin, move);
        if ( move == "resign"){
            isGameOn = false;
        }
        else if (true){ // TODO update condition to check if move is valid
            isPlayerTwosTurn = !isPlayerTwosTurn;
        }else{
            cout << "Invalid move. Try again.";
        }
    }
    cout << "Thank you for playing. \n";

}
