#ifndef BITBOARD_H 
#define BITBOARD_H
#include <vector>
#include <stack>
#include <string>
#include "defaults.h"
namespace SimpleChess{

	U64 getBit(U64 board, int index);
	U64 setBit(U64 board, int index); // non-void setter in case we want a copy of the newly set bit
	U64 popBit(U64 board);
	U64 setBits(U64 board, std::vector<int> &indicies);

	std::vector<U64> getKingMoves(U64 board);
	std::vector<U64> getWhitePawnMoves(U64 board);
	std::vector<U64> getBlackPawnMoves(U64 board);
	std::vector<U64> getKnightMoves(U64 board);
	std::vector<U64>getBishopMoves(U64 board);
	std::vector<U64> getRookMoves(U64 board);
	std::vector<U64> getQueenMoves(U64 board);

	// Convert bitboard to string
	std::string toString(U64 board, std::string symbol);

	class Bitboard{
	std::vector<std::stack<U64>> boardStates;

	};

}
#endif
