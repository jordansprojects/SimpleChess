#ifndef CHESSPARSER_H
#define CHESSPARSER_H
#include "types.h"
#include "string"
#include "../BoardRep/movegen.h"
#include "bitboard.h"
namespace ChessParser{

/*
    Converts chess coordinates to to bit index
    @param : char representing the file (column)
    @param : int representing  the rank (row) 
*/
int getIndex(char file, int rank ){
    return (file - 'a')  + ( (rank -1 ) * 8 );
}

/*
    Converts chess coordinates to to bit index
    @param : char representing the file (column)
    @param : char representing  the rank (row) 
*/
int getIndex(char file, char rank ){
    return getIndex(file, (rank - '0'));
}

/*
@param string moveToken:token in algebriac notation 
@param ChessBoard board:
@param int team
@return true if move is valid, false if it is not 
*/
bool parse(std::string moveToken, ChessBoard board, int team){
    U64 moves;
    char piece;
    U64 selected;
    switch(moveToken.length()){
        case 2: // pawn move in algebriac notation
        break;
        case 3: // piece move in algebriac notation
            piece = moveToken[0];
            if(piece == 'k' || piece == 'K'){
                // TODO: update this to call the method diferently.
		// moves = generateKnightMoves(board,getIndex(moveToken[1], moveToken[2]), team);
		selected = (team  == WHITE )? board.getWhiteKnights() : board.getBlackKnights();
            }
        break;
        case 4:
        break;

    }

    return 0;
}

}


#endif
