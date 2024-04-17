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
@param string moveToken: 
@param ChessBoard board:
@param int team:
    Parser that can interpret token in algebriac, long algebriac,
    reversible algebriac, descriptive, and smith notation  

    If performance becomes an issue, it may be better to have different parsers
    that can be configured (Ex user wants to use long algebriac) but if it is 
    fairly inexpensive to support all - that will be the plan

@ return true if move is valid, false if it is not 
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
                moves = generateKnightMoves(board,getIndex(moveToken[1], moveToken[2]), team);
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