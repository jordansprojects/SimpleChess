#ifndef PIECES_H
#define PIECES_H

enum Team
{
	WHITE,
	BLACK,
	BLUE, /* support for chess beyond 2 teams!  */
	GREEN,
	PINK,
	ORANGE
};

enum Pieces
{
	PAWN,
	KNIGHT,
	ROOK,
	BISHOP,
	QUEEN,
	KING
};

#include <vector>
/****************************************************
 * Abstract class to represent objects on the board
 ****************************************************/
class Piece
{
public:
	virtual void move() = 0;
	virtual void generateMoves() = 0;
	void generateRookMoves();
	void generateBishopMoves();
	void generateKnightMoves();

protected:
	int square;
	Team team;
}; // end of Piece class
#endif
