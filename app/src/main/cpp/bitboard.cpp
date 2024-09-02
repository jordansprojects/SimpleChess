#include "../headers/bitboard.h"
using namespace SimpleChess;

    U64 getBit(U64 board, int index){
        return ( board & ( 1ULL << index ));
    }
    // non-void setter in case we want a copy of the newly set bit
   U64 setBit(U64 board, int index){
        return  ( board |= ( 1ULL << index ));
    }

    U64 popBit(U64 board, int index ){
        return ( ( board & ( 1ULL << index ) ) ? board ^= (1ULL << index): 0);
    }

    // accepts knight bitboard and returns array of 
    // movement maps for each knight
    U64* Bitboard::getKnightMoves(U64 board){
        while(board != 0){
            U64 map = 0;
            // TO-DO : Remove popped bit from board
            U64 lsb = board & -board;
            // TO-DO:  Detect over/underflow and don't add it to the map
            map |= (lsb >> noNoWe );
            map |= (lsb >> noEaEa);
            map |= (lsb >> noNoEa);
            map |= (lsb >> noWeWe);
            map |= (lsb << soEaEa);
            map |= (lsb << soSoEa);
            map |= (lsb << soSoWe);
            map |= (lsb << soWeWe);
        }
        return nullptr;

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
    U64 Bitboard::getBishopMoves(U64 board){
        return 0;

    }
    U64 Bitboard::getRookMoves(U64 board){
        return 0;

    }
    U64 Bitboard::getQueenMoves(U64 board){
        return 0;
    }
