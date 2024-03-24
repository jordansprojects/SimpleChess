#ifndef CHESSPARSER_H
#define CHESSPARSER_H
#include "types.h"
#include "string"
#include "../BoardRep/movegen.h"
namespace ChessParser{


int getIndex(char file, int rank ){
    return (file - 'a')  + ( (rank -1 ) * 8 );
}

/*
@param 
*/
int convert(std::string move){
    for(long unsigned int i = 0 ; i < move.length(); i++){
    }
    return 0;
}

}


#endif