#include "../headers/bitboard.h"
#include <cmath>

namespace SimpleChess{

    U64 getBit(U64 board, int index){
        return ( board & ( 1ULL << index ));
    }

    U64 setBit(U64 board, int index){ // non-void setter in case we want a copy of the newly set bit
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

    /* @brief Calculates knight moves
     * @param board The bitboard containing knight bits
     * @return vector of possible moves for each bit
     */
    std::vector<U64> getKnightMoves(U64 board){
        std::vector<U64> moveMaps;
        while(board != 0){
            U64 map = 0;
            U64 lsb = board & -board;
            int index = board & (0- board);
            board = popBit(board, index);
            // TO-DO : Look into parallel prefix way of doing this : https://www.chessprogramming.org/Parallel_Prefix_Algorithms
            // These probably need to be double checked when Im not so tired : https://www.chessprogramming.org/Knight_Pattern
            map |= ((lsb >> noNoWe) & (!H_FILE));
            map |= ((lsb >> noEaEa) & (!(A_FILE & B_FILE)));
            map |= ((lsb >> noNoEa) & (!A_FILE));
            map |= (lsb >> noWeWe) & (!H_FILE & !G_FILE) ;
            map |= ((lsb << soEaEa) & (!(A_FILE & B_FILE)));
            map |= ((lsb << soSoEa) & (!A_FILE)) ;
            map |= (lsb << soSoWe) & (!H_FILE);
            map |= ((lsb << soWeWe) & (!H_FILE & !G_FILE));
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


