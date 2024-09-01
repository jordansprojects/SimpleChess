#ifndef BITBOARD_H 
#define BITBOARD_H
namespace SimpleChess{
	typedef unsigned long long U64;

	enum Squares{
		A1, B1, C1, D1, E1, F1, G1, H1,  // 00 01 02 03 04 05 06 07
		A2, B2, C2, D2, E2, F2, G2, H2,  // 08 09 10 11 12 13 14 15
		A3, B3, C3, D3, E3, F3, G3, H3,  // 16 17 18 19 20 21 22 23
		A4, B4, C4, D4, E4, F4, G4, H4,  // 24 25 26 27 28 29 30 31
		A5, B5, C5, D5, E5, F5, G5, H5,  // 32 33 34 35 36 37 38 39
		A6, B6, C6, D6, E6, F6, G6, H6,  // 40 41 42 43 44 45 46 47
		A7, B7, C7, D7, E7, F7, G7, H7,  // 48 49 50 51 52 53 54 55
		A8, B8, C8, D8, E8, F8, G8, H8 };// 56 57 58 59 60 61 62 63	

	constexpr int northWe = 7, nort = 8, noEa = 9,
		  west = -1, east = 1, soWe = -9, 
		  south = -8, soEa = -7, noNoWe = 15,
		  noNoEa=17, noWeWe=6, soWeWe=-10,
		  soSoWe=-17, soSoEa=-15, soEaEa=-6,
		  noEaEa=10;

	U64 getBit(U64 board, int index);
	U64 setBit(U64 board, int index); // non-void setter in case we want a copy of the newly set bit

	U64 getKingMoves(U64 board);
	U64 getWhitePawnMoves(U64 board);
	U64 getBlackPawnMoves(U64 board);
	U64 getKnightMoves(U64 board);
	U64 getBishopMoves(U64 board);
	U64 getRookMoves(U64 board);
	U64 getQueenMoves(U64 board);


}
#endif
