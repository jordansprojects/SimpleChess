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

/****************************************************
 *
 ****************************************************/
class Queen : Piece
{
};

/****************************************************
 *
 ****************************************************/
class Knight : Piece
{
};

/****************************************************
 *
 ****************************************************/
class Rook : Piece
{
};

/****************************************************
 *
 ****************************************************/

class Bishop : Piece
{
};

/****************************************************
 *
 * I understand a pawn is not technically "a piece" :-)
 ****************************************************/
class Pawn : Piece
{
};

/****************************************************
 *
 ****************************************************/
class King : Piece
{
};
#endif
