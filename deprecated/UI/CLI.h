#ifndef CLI_H
#define CLI_H
#include "../BoardRep/bitboard.h"
#include"CLITypes.h"

#include <iostream>
#include <sstream>
#include <algorithm> // for reverse()
#include <stdexcept>
#include <bitset>
#include <iomanip>

// TODO:  change this to not be a class but instead a namespace including free functions

class ConsoleUI {
private:
	bool parseMove(std::string);

public:
	/****
	 * Checks all boards and prints the corresponding unicode symbol based on
	 * whether or not a particular bit in a particular bitboard has been set
	 *
	 *  @param board : ChessBoard object that contains all bitboards
	 *  @param i : index to check
	 */
	void printPieceBasedOnBitboardsIndex(ChessBoard board,int i){
		// change this entirely or account for empty spots in location map
			std:: cout << symbols[board.locationMap[i]];

	}

	static std::string getSymbol(int team, int piece){
		if (team == BLACK ){
			piece += WKING;
		}
		std::cout << symbols[piece];
		return "";
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
					//std::cout << SPACE << '\n';
					std::cout<< SPACE ;
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
							std::cout<< SPACE ;
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
	

	bool parseMove(std::string move, ChessBoard cb){
		// pawn move
		std::transform(move.begin(), move.end(), move.begin(), [](unsigned char c) { return std::tolower(c); });
		if(move.length() == 2){
			if (move[0] < 'a' || move[0] > 'h' || move[1] < '1' || move[1] > '8'){
				std::cout << "Invalid move.\n";
				return false;
			}else{
				// pawn move

			}
		}else if (move.length() == 3 ){

			if(move[1] < 'a' || move[1] > 'h'){
				std::cout << "Invalid move\n";
				return false;
			}
			if(move[2] < '1' || move[2] > '8'){
				return false;
			}

		}else{
			std::cout << "Invalid move.\n";
			return false;
		}

		switch(move[0]){
			case 'r': case 'R': // rook move
				break;
			case 'q': case'Q':  // queen move
				break;
			case 'b': case 'B':// bishop move
				break;
			case 'n': case 'N': // knight move
				break;
			case 'k': case 'K': // king move
				break;
			
			default:
				std::cout << "Invalid move\n";
				return false ;
			}

		return true;
	}








	/*************************************************************
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

		// this math works for producing the correct unicode number, but there is more
		// complexity to actually producing the correct encoded data .
		// that remains a TODO in this project.

		if ( team == WHITE){
			ss <<  (2654 +  ( (piece - KING) *-1 ));

		}else if (team == BLACK){
			ss << 265 << char('A' + ( (piece - KING) *-1 ));
		}

		return ss.str();
	}


}; //end of ConsoleUI class
#endif
