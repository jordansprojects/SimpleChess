#ifndef CHESSPARSER_H
#define CHESSPARSER_H
#include "types.h"
#include "string"
#include "../BoardRep/movegen.h"
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
@param 
    Parser that can interpret token in algebriac, long algebriac,
    reversible algebriac, descriptive, and smith notation  

    If performance becomes an issue, it may be better to have different parsers
    that can be configured (Ex user wants to use long algebriac) but if it is 
    fairly inexpensive to support all - that will be the plan
*/
int convert(std::string moveToken){
    switch(moveToken.length()){
        case 2: // pawn move in algebriac notation
        break;
        case 3: // piece move in algebriac notation
        break;
        case 4:
        break;

    }

    return 0;
}

}


#endif