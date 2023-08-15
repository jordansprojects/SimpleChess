/* **********************************************************************
 * game.cpp - a tester class for piece and board objects
 */

#include "../BoardRep/bitboard.h"
#include "../UI/CLI.h"
#include <iostream>
using namespace std;

int main(){

	ChessBoard board;
	bool gameOn = true;
	string move; 
	while( gameOn ){
	cout << "Make your move : ";
	getline(cin, move);
	if ( move == "resign"){
		gameOn = false;
	}
	
	}


  return 0;

}
