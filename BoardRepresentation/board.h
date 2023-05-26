#ifndef BOARD_H
#define BOARD_H

#include "pieces.h"
#include <bitset>

enum Type{
	PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

class Bitboard {
	private:
		constexpr static int N = 8; // N x N board 
		std::bitset< N * N> squares;

	public:
		void setPiece(int square, Type type){
			squares.set(square, type);
		}

}; //end of board class
   
#endif
