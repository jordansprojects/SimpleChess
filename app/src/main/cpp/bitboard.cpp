#include "../headers/bitboard.h"
#include <cmath>

namespace SimpleChess{

    U64 getBit(U64 board, int index){
        return ( board & ( 1ULL << index ));
    }
    // non-void setter in case we want a copy of the newly set bit
   U64 setBit(U64 board, int index){
        return  ( board |= ( 1ULL << index ));
    }

    U64 setBits(U64 board, std::vector<int> &indicies){
        for (long unsigned int i = 0; i < indicies.size() ; i++){
            board |= ( 1ULL << indicies[i] );
        }
        return board;
    }

    U64 popBit(U64 board, int index ){
        return ( ( board & ( 1ULL << index ) ) ? board ^= (1ULL << index): 0);
    }

    // accepts knight bitboard and returns array of 
    // movement maps for each knight
    std::vector<U64> getKnightMoves(U64 board){
        std::vector<U64> moveMaps;
        while(board != 0){
            U64 map = 0;
            U64 lsb = board & -board;
            int index = board & (0- board);
            board = popBit(board, index);
            // TO-DO:  Detect over/underflow and don't add it to the map
            // TO-DO : Look into parallel prefix way of doing this : https://www.chessprogramming.org/Parallel_Prefix_Algorithms
            map |= (lsb >> noNoWe );
            map |= (lsb >> noEaEa);
            map |= (lsb >> noNoEa);
            map |= (lsb >> noWeWe);
            map |= (lsb << soEaEa);
            map |= (lsb << soSoEa);
            map |= (lsb << soSoWe);
            map |= (lsb << soWeWe);
            moveMaps.emplace_back(map);
        }
        return moveMaps;
    }

    std::vector<U64> getKingMoves(U64 board){
        std::vector<U64> moveMaps;
        return moveMaps;
    }
    std::vector<U64> getWhitePawnMoves(U64 board){
        std::vector<U64> moveMaps;
        return moveMaps;
    }
    std::vector<U64> getBlackPawnMoves(U64 board){
        std::vector<U64> moveMaps;
        return moveMaps;

    }
    std::vector<U64> getBishopMoves(U64 board){
        std::vector<U64> moveMaps;
        return moveMaps;

    }
    std::vector<U64> getRookMoves(U64 board){
        std::vector<U64> moveMaps;
        return moveMaps;

    }
    std::vector<U64> getQueenMoves(U64 board){
        std::vector<U64> moveMaps;
        return moveMaps;
    }

    std::string toString(U64 board, std::string symbol){
        std::string boardStr = "";
        for(int i = 0; i < 64; i++){
            boardStr += (getBit(board,i) > 0 )? symbol : "_";
        }
        return boardStr;
    }
}


