#ifndef CLI_H
#define CLI_H
#include "../BoardRep/bitboard.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <bitset>
#include <iomanip>
/*********************************
 * Simple Console UI
 *********************************/

/* unicode symbols for chess pieces and pawns */
std::string whitePawnUnicode = "\u2659";
std::string blackPawnUnicode = "\u265F";
std::string whiteKnightUnicode = "\u2658";
std::string blackKnightUnicode = "\u265E";
std::string whiteBishopUnicode = "\u2657";
std::string blackBishopUnicode = "\u265D";
std::string whiteRookUnicode = "\u2656";
std::string blackRookUnicode = "\u265C";
std::string whiteQueenUnicode= "\u2655";
std::string blackQueenUnicode =  "\u265B";
std::string whiteKingUnicode = "♔" ;
std::string blackKingUnicode =  "\u265A" ;

// space per piece
std::string SPACE = "	";

/* ************************************************************
 * Returns desired unicode value for each piece and color
 * @param  team ( Only black and white are supported ) 
 * @param  piece
 * ************************************************************/
static std::string getUnicode(int team, int piece ){
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
 *  This function is sort of deprecated - since it made more sense
 * to print each unicode character directly
 * ************************************************************/
static std::string getSymbol(int team, int piece){
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
			throw std::runtime_error("CLI.h: invalid piece  or team value provided.\n");
	}

	return c;

}
/****
 * Checks all boards and prints the corresponding unicode symbol based on
 * whether or not a particular bit in a particular bitboard has been set
 *  @param board : ChessBoard object that contains all bitboards
 *  @param i : index to check
 */
void printPieceBasedOnBitboardsIndex(ChessBoard board,int i){
					if( std::bitset<64>(board.getWhitePawns())[i]){
						std::cout <<  SPACE<< whitePawnUnicode ;
					}else if(std::bitset<64>(board.getWhiteKnights())[i]) {
						std::cout << SPACE<<  whiteKnightUnicode ;
					}else if(std::bitset<64>(board.getWhiteBishops())[i]) {
						std::cout <<  SPACE<<  whiteBishopUnicode ;
					}else if(std::bitset<64>(board.getWhiteRooks())[i]) {
						std::cout << SPACE<< whiteRookUnicode ;
					}else if(std::bitset<64>(board.getWhiteQueens())[i]) {
						std::cout << SPACE<<  whiteQueenUnicode ;
					}else if(std::bitset<64>(board.getWhiteKings())[i]) {
						std::cout <<  SPACE<<  whiteKingUnicode ;
					}else if(std::bitset<64>(board.getBlackPawns())[i]){
						std::cout << SPACE<< blackPawnUnicode ;
					}else if(std::bitset<64>(board.getBlackKnights())[i]) {
						std::cout <<  SPACE<< blackKnightUnicode ;
					}else if(std::bitset<64>(board.getBlackBishops())[i]) {
						std::cout <<  SPACE<<  blackBishopUnicode ;
					}else if(std::bitset<64>(board.getBlackRooks())[i]) {
						std::cout <<  SPACE<<  blackRookUnicode ;
					}else if (std::bitset<64>(board.getBlackQueens())[i]) {
						std::cout <<  SPACE<<  blackQueenUnicode ;
					}else if(std::bitset<64>(board.getBlackKings())[i]) {
						std::cout <<  SPACE<<  blackKingUnicode ;
					}
					else{
						std::cout <<  SPACE << "_";
					}
}

/*
 * Prints the board to the console.
 */
void printBoard(ChessBoard board, int playerView){
	std::string whitePawnUnicode = "\u2659";
	std::string fileStr = "\u0061\u0062\u0063\u0064\u0065\u0066\u0067\u0068";
	std::string rankStr = "12345678";


	if (playerView == WHITE){
		reverse(rankStr.begin(), rankStr.end());
		for( int i = 0; i < 8 ; i++){
			// print the rank at the beginning of each row
			std::cout <<std::right <<SPACE<< rankStr[i] << std::left;
			/* we go in reverse bitset order for white.
			 * the board is printed in reverse order, and each individual
			 * row is reversed as well - otherwise the board does
			 * not appear properly rotated 180 degrees */
			for(int j = (63 - i * 8) - 7 ; j < (64 - i * 8) ; j++ ){
				printPieceBasedOnBitboardsIndex(board,j);
			}
			std::cout << std::endl;
		}
	}else if (playerView == BLACK){
		reverse(fileStr.begin(), fileStr.end());
		int startOfRow = 7;
		for( int i = 0 ; i  < 8; i++){
					// print the rank at the beginning of each row
					std::cout <<std::right << SPACE << rankStr[i] << std::left;
					for(int j = startOfRow; j > startOfRow - 8; j-- ){
						printPieceBasedOnBitboardsIndex(board,j);
					}
					startOfRow+=8;
					std::cout << std::endl;
				}
	}
	// now print the file string
	std::cout <<  SPACE;

	for(size_t i =0 ; i < fileStr.length(); i++)
		std::cout<<  SPACE<< fileStr[i];
	std::cout<<std::right << std::endl;
	
}

#endif
