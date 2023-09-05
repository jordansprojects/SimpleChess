/* **********************************************************************
 * game.cpp - tester class for chess game functionality
 ***********************************************************************/

#include "../BoardRep/bitboard.h"
#include "../UI/CLI.h"
#include <iostream>
#include <algorithm>
using namespace std;

/*
 *  parses move string.
 *
 *  @return false if  move selection failed
 *
 */
bool parseMove(string move){
	// pawn move
	std::transform(move.begin(), move.end(), move.begin(), [](unsigned char c) { return std::tolower(c); });
	if(move.length() == 2){
		if (move[0] < 'a' || move[0] > 'h' || move[1] < '1' || move[1] > '8'){
			cout << "Invalid move.\n";
			return false;
		}else{
			// pawn move

		}
	}else if (move.length() == 3 ){
		switch(move[0]){
		case 'r': // rook move
			break;
		case 'q': // queen move//
			break;
		case 'b': // bishop move
			break;
		case 'n': // knight move
			break;
		case 'k': // king move
			break;
		default:
			cout << "Invalid move\n";
			return false ;
		}
		if(move[1] < '1' || move[1] > '8'){
			cout << "Invalid move\n";
			return false;
		}

	}else{
		cout << "Invalid move.\n";
		return false;
	}

	return true;
}

int main(){
	ChessBoard board;
	int who = WHITE;
	bool gameOn = true;
	string moveStr;
	while( gameOn ){

	cout << "Player " << who <<" :  Make your move : ";
	getline(cin, moveStr);

	if ( moveStr == "resign"){
		gameOn = false;
	}
	if (parseMove(moveStr)){
		who = (who == WHITE)? BLACK: WHITE;
	}

	} // end of game loop

	cout << "Thank you for playing <3\n";


  return 0;

}
