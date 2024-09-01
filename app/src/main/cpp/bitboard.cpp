#include "../headers/bitboard.h"
using namespace SimpleChess;

    U64 getBit(U64 board, int index){
        return (board & ( 1ULL << index ));
    }
    // non-void setter in case we want a copy of the newly set bit
   U64 setBit(U64 board, int index){
        return (board |= ( 1ULL << index ));
    }

    U64 getKingMoves(U64 board){
        return 0;
    }
    U64 getWhitePawnMoves(U64 board){
        return 0;
    }
    U64 getBlackPawnMoves(U64 board){
        return 0;

    }
    U64 getKnightMoves(U64 board){
        return 0;

    }
    U64 getBishopMoves(U64 board){
        return 0;

    }
    U64 getRookMoves(U64 board){
        return 0;

    }
    U64 getQueenMoves(U64 board){
        return 0;

    }
