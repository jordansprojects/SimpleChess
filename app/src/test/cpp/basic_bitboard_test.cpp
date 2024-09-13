#include "../../main/headers/bitboard.h"
#include <gtest/gtest.h>

using namespace SimpleChess;
    TEST(KnightMoves, BasicAssertions){
        std::vector<int> startingPositions  = {B1, G1, B8, G8};
        U64 knights = setBits(0 , startingPositions);
        ASSERT_GT(knights,0);

    }
