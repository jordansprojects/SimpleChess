#ifndef CLI_H
#define CLI_H
#include "../BoardRep/bitboard.h"
#include <iostream>
#include <sstream>
/*********************************
 * Simple Console UI 
 *********************************/

/* ************************************************************
 * Returns desired unicode value for each piece and color
 * @param  team ( Only black and white are supported ) 
 * @param  piece
 * ************************************************************/
std::string getUnicode(int team, int piece ){
	std::stringstream ss;
	if ( piece < EMPTY || piece > KING){
		throw "CLI.h: Invalid piece Index provided. Must be value between 1 - 6 inclusive.\n"; 
	}

	if (piece == EMPTY ){
		return "_";
	}

	/* this math works for producing the correct unicode number, but there is more
	 * complexity to actually producing the correct encoded data . 
	 * that remains a TODO in this project. */
	
	if ( team == WHITE){
		ss <<  (2654 +  ( (piece - KING) *-1 ));
	
	}else if (team == BLACK){
		ss << 265 << char('A' + ( (piece - KING) *-1 ));  
	}

	return ss.str();
}

/* ************************************************************
 * Returns desired unicode character for each piece and color
 * @param  team ( Only black and white are supported )
 * @param  piece
 * ************************************************************/
std::string getSymbol(int team, int piece){
	std::string c;
	switch(piece){
		case EMPTY:
			c=  '_';
			break;
		case KING:
			 c = (team == WHITE)? "♔" : "\u265A" ;
			 break;
		case QUEEN:
			c =  (team == WHITE)? "\u2655": "\u265B";
			break;
		case ROOK:
			c =  (team == WHITE)? "\u2656"  : "\u265C";
			break;
		case BISHOP:
			c =  (team == WHITE)? "\u2657": "\u265D";
			break;
		case KNIGHT:
			c = (team == WHITE)? "\u2658": "\u265E";
			break;
		case PAWN:
			c=  (team == WHITE)? "\u2659": "\u265F";
			break;
		default:
			throw "CLI.h: invalid piece  or team value provided.\n"; 
	}

	return c;

}


void printBoard(ChessBoard board){
	

}

#endif
