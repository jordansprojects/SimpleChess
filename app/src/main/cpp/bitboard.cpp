#include "../headers/bitboard.h"
using namespace SimpleChess;

    U64 getBit(U64 board, int index){
        return ( board & ( 1ULL << index ));
    }
    // non-void setter in case we want a copy of the newly set bit
   U64 setBit(U64 board, int index){
        return  ( board |= ( 1ULL << index ));
    }

    U64 Bitboard::getKingMoves(U64 board){
        return 0;
    }
    U64 Bitboard::getWhitePawnMoves(U64 board){
        return 0;
    }
    U64 Bitboard::getBlackPawnMoves(U64 board){
        return 0;

    }
    U64 Bitboard::getKnightMoves(U64 board){
        return 0;

    }
    U64 Bitboard::getBishopMoves(U64 board){
        return 0;

    }
    U64 Bitboard::getRookMoves(U64 board){
        return 0;

    }
    U64 Bitboard::getQueenMoves(U64 board){
        return 0;

    }
