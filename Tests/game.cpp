/* **********************************************************************
 * game.cpp - tester class for chess game functionality
 ***********************************************************************/

#include "../BoardRep/bitboard.h"
#include "../UI/CLI.h"
#include <iostream>
using namespace std;

int main(){
	ChessBoard board;
	int who = WHITE;
	bool gameOn = true;
	string moveStr;
	while( gameOn ){
		printBoard(board,who);
		cout << "Player " << who <<" :  Make your move : ";
		getline(cin, moveStr);

		if ( moveStr == "resign"){
			gameOn = false;
		}
		else if (parseMove(moveStr, board)){
			who = (who == WHITE)? BLACK: WHITE;
		}
	} // end of game loop
	cout << "Thank you for playing <3\n";

  return 0;

}
