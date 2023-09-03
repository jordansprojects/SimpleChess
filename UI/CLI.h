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

const int SETWUNICODE = 7;
const int SETWGENERAL = 3;

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
					if( board.getWhitePawnsAsBitset()[i]){
						std::cout << std::setw(SETWUNICODE)<< whitePawnUnicode ;
					}else if(board.getWhiteKnightsAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< whiteKnightUnicode ;
					}else if(board.getWhiteBishopsAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< whiteBishopUnicode ;
					}else if(board.getWhiteRooksAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< whiteRookUnicode ;
					}else if(board.getWhiteQueensAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< whiteQueenUnicode ;
					}else if(board.getWhiteKingsAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< whiteKingUnicode ;
					}else if( board.getBlackPawnsAsBitset()[i]){
						std::cout << std::setw(SETWUNICODE)<< blackPawnUnicode ;
					}else if(board.getBlackKnightsAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< blackKnightUnicode ;
					}else if(board.getBlackBishopsAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< blackBishopUnicode ;
					}else if(board.getBlackRooksAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< blackRookUnicode ;
					}else if(board.getBlackQueensAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< blackQueenUnicode ;
					}else if(board.getBlackKingsAsBitset()[i]) {
						std::cout << std::setw(SETWUNICODE)<< blackKingUnicode ;
					}
					else{
						std::cout <<std::setw(SETWGENERAL) << "_";
					}
}
/*
 * Prints the board to the console.
 */
void printBoard(ChessBoard board, int playerView){
	std::string whitePawnUnicode = "\u2659";
	std::string fileStr = "abcdefgh";
	std::string rankStr = "12345678";


	if (playerView == WHITE){
		reverse(rankStr.begin(), rankStr.end()); //reverse rankStr
		for( int i = 0; i < 8 ; i++){
			// print the rank at the beginning of each row
			std::cout <<std::right <<std::setw(SETWGENERAL)  << rankStr[i] << std::left;
			for(int j = 63 - (i*8); j > 63 - ( (i*8) + 8) ; j--){ /* we go in reverse bitset order for white */
				printPieceBasedOnBitboardsIndex(board,j);
			}
			std::cout << std::endl;
		}
	}else if (playerView == BLACK){
		//reverse the fileStr for black
		reverse(fileStr.begin(), fileStr.end());
		for( int i = 0; i < 8 ; i++){
					// print the rank at the beginning of each row
					std::cout <<std::right <<std::setw(SETWGENERAL)  << rankStr[i] << std::left;
					for(int j = (i*8); j < ( (i*8) + 8) ; j++){ /* we go in reverse bitset order for white */
						printPieceBasedOnBitboardsIndex(board,j);
					}
					std::cout << std::endl;
				}
	}
	// now print the file string
	std::cout << std::right << "  ";
	for(size_t i =0 ; i < fileStr.length(); i++)
		std::cout<< std::setw(SETWGENERAL)<< fileStr[i];
	std::cout<<std::endl;
	
}

#endif
