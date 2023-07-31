#ifndef CLI_H
#define CLI_H
#include "../BoardRep/bitboard.h"
#include <iostream>
#include <sstream>
/*********************************
 * Simple Console UI 
 *
 *
 *********************************/

/* ************************************************
 * Returns desired unicode character for each piece and color
 * @param  team ( Only black and white are supported ) 
 * @param  piece
 * ************************************************************/



char getUnicode(int team, int piece ){
	std::stringstream ss;
	int minIndex = EMPTY;
	int maxIndex = KING;
	if ( piece < minIndex || piece > maxIndex){
		throw "CLI.h: Invalid piece Index provided. Must be value between 1 - 6 inclusive.\n"; 
	}


	switch(piece){
		case EMPTY:
			return '_';
		case KING:
			return (team == WHITE)? '\u2654' : '\u265A' ;
		case QUEEN:
			return (team == WHITE)? 0x2655: 0x265B;
		case ROOK:
			return (team == WHITE)? 0x2656  : 0x265C;
		case BISHOP:
			return (team == WHITE)? 0x2657: 0x265D;
		case KNIGHT:
			return (team == WHITE)? 0x2658: 0x265E;
		case PAWN:
			return (team == WHITE)? 0x2659: 0x265F;
		default:
			throw "CLI.h: invalid piece  or team value provided.\n";
	}

}

#endif
