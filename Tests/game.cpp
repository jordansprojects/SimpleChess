/* **********************************************************************
 * game.cpp - tester class for chess game functionality
 */

#include "../BoardRep/bitboard.h"
#include "../UI/CLI.h"
#include <iostream>
using namespace std;


void parseMove(string move){


}

int main(){

	ChessBoard board;
	bool gameOn = true;
	string moveStr;
	while( gameOn ){

	cout << "Make your move : ";

	getline(cin, moveStr);
	if ( moveStr == "resign"){
		gameOn = false;
	}
	

	}

	cout << "Thank you for playing <3\n";


  return 0;

}
