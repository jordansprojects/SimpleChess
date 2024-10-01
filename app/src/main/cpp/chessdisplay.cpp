#include "../headers/chessdisplay.h"
/*
 * @brief Creates bitboard string to match updated bitboard states
 * @param boards vector of bitboards in the order <determine order specification here>
 * @return The string representing the chessboard
 */
std::string createChessboard(std::vector<U64> boards){
    std::string boardStr(64, '_');
    for(int i = 0 ; i < boards.size(); i++){
        U64 currentBoard = boards[i];
        int lsb = currentBoard & 1;
        // modify
        popBit(currentBoard, lsb);


    }
    return boardStr;

}

/*
 * @brief Modifies bitboard string to match updated bitboard states
 * @param impactedBoards vector of bitboards that have changed
 * @return The new string representing the chessboard
 */
std::string updateChessboard(std::string board, std::vector<U64> impactedBoards){

}

