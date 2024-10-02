#include "../headers/chessdisplay.h"
#include <bit>
/*
 * @brief Creates bitboard string to match updated bitboard states
 * @param boards vector of bitboards in the order <determine order specification here>
 * @return The string representing the chessboard
 */
std::string createChessboard(std::vector<U64> boards){
    std::string boardStr(64, '_');
    for(int i = 0 ; i < boards.size(); i++){
        U64 currentBoard = boards[i];
        while (currentBoard != 0){
            int bitIndex = std::countr_zero(currentBoard);
            boardStr[index] = UNICODE_PIECES[i];
            currentBoard  = popBit(currentBoard, bitIndex);
        }
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

