#ifndef BITBOARD_H
#define BITBOARD_H
#include <string>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * useful references:
 * https://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html
 *
 * */ 

typedef unsigned long long U64; /* unsigned 64 bit integer */ 


enum Team{
	WHITE,
	BLACK,
	BLUE, /* support for chess beyond 2 teams!  */
	GREEN,
	PINK,
	ORANGE
};

enum Pieces {
	EMPTY,
	PAWN,
	KNIGHT,
	ROOK,
	BISHOP,
	QUEEN,
	KING
};


/* ************************************************
 * Returns desired unicode character for each piece and color
 * @param  team ( Only black and white are supported ) 
 * @param  piece
 * ************************************************************/
std::string getUnicode(int team, int piece ){
	switch(piece){
		case KING:
			return (team == WHITE)? "/U+2654" : "/U+265A";
			break;
		case QUEEN:
			break;
		case ROOK:
			break;
		case BISHOP:
			break;
		case KNIGHT:
			break;
		case PAWN:
			break;


	}

}


/* Indicies of squares on the board
 * this may seem like overkill, but it is 
 * convenient to refer to an index as its chess coordinate 
 * */
enum Squares{
		A1, B1, C1, D1, E1, F1, G1, H1,
		A2, B2, C2, D2, E2, F2, G2, H2,
		A3, B3, C3, D3, E3, F3, G3, H3,
		A4, B4, C4, D4, E4, F4, G4, H4,
		A5, B5, C5, D5, E5, F5, G5, H5,
		A6, B6, C6, D6, E6, F6, G6, H6,
		A7, B7, C7, D7, E7, F7, G7, H7,
		A8, B8, C8, D8, E8, F8, G8, H8 };

/* Starting Positions */



class MoveGeneration {
	private:
		U64 whitePawns;
	public:
		void generateRookMoves();
		void generateBishopMoves();
		void generateKnightMoves();
		void generateQueenMoves();
		void generatePawnMoves();

	protected:
		int square;
		Team team;
}; // end of Piece class
#endif


