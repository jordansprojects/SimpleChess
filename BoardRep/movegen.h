#ifndef MOVEGEN_H
#include "bitmanip.h"

U64 minRank = 0, maxRank = 0, noMin10 = 0, noPlus10 = 0,
noMin15 = 0, noPlus15 = 0 , noMin6 = 0, noPlus6= 0;

void initBoundaries(){
     //TO-DO assess these and minimize unnecessary iterations
    BitFuncs::iterateOverRank(minRank, A1, BitFuncs::setBit);
    BitFuncs::iterateOverRank(maxRank, A8, BitFuncs::setBit);

    BitFuncs::iterateOverRank(noPlus15, A7, BitFuncs::setBit);
    BitFuncs::iterateOverRank(noMin15, A2, BitFuncs::setBit);

    BitFuncs::iterateOverFile(noPlus6, B1, BitFuncs::setBit);
    BitFuncs::iterateOverFile(noPlus6, A1, BitFuncs::setBit);

    BitFuncs::iterateOverFile(noMin10, B1, BitFuncs::setBit);
    
    BitFuncs::iterateOverFile(noPlus10,G1, BitFuncs::setBit);
    BitFuncs::iterateOverFile(noPlus10,H1, BitFuncs::setBit);

    noMin10 |= noPlus6;
    noPlus15 |= maxRank;
    noMin15  |= minRank;

    noMin6 = noPlus10;

}

U64 generateKnightMoves(U64 board, int index, U64 same =0){
    U64 knight = BitFuncs::getBit(board,index);
    U64 moves = 0; 
    if( (knight | maxRank) != maxRank){
        if ( (knight | noPlus10) != noPlus10){
            BitFuncs::setBit(moves, index + 10); 
        }
        if ( (knight | noPlus6) != noPlus6){
                BitFuncs::setBit(moves, index + 6);
        }
         if ( (knight | noPlus15) != noPlus15){
            BitFuncs::setBit(moves, index + 15);
            BitFuncs::setBit(moves, index + 17);
        }
    } if( (knight | minRank) !=  minRank){

         if ( (knight | noMin6) != noMin6){
                BitFuncs::setBit(moves, index - 6);
        }

        if ( (knight | noMin10) != noMin10){
                BitFuncs::setBit(moves, index - 10);
        }
        if ( (knight | noMin15) != noMin15){
            BitFuncs::setBit(moves, index - 15);
            BitFuncs::setBit(moves, index - 17);
        }
    }
    moves = ( moves ^ (moves & same) ); // optional prevention of moving ontop of pieces on same team
    return moves;
}


#endif
