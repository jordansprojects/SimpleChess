#ifndef CHESSDISPLAY_H
#define CHESSDISPLAY_H
#include "unicodepieces.h"
#include "bitboard.h"

/*
 * @brief Creates bitboard string to match updated bitboard states
 * @param boards vector of bitboards in the order <determine order specification here>
 * @return The string representing the chessboard
 */
std::string createChessboard(std::vector<SimpleChess::U64> boards);

/*
 * @brief Modifies bitboard string to match updated bitboard states
 * @param impactedBoards vector of bitboards that have changed
 * @return The new string representing the chessboard
 */
std::string updateChessboard(std::string board, std::vector<SimpleChess::U64> impactedBoards);


#endif
