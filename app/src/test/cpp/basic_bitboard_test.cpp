#include "../../main/headers/bitboard.h"
#include <gtest/gtest.h>
#include "../../main/headers/unicodepieces.h"
using namespace SimpleChess;

    TEST(KnightMoves, BasicAssertions){
        std::vector<int> startingPositions  = {B1, G1, B8, G8};
        std::vector<int> validLocationsFromG1 = {
            F6, H6, E7 // From G1
        };

        U64 expectedLocations = setBits(0, validLocationsFromG1);
        U64 invalidLocations = !expectedLocations;

        U64 knights = setBits(0 , startingPositions);
        ASSERT_GT(knights,0) << toString(knights, blackKnightUnicode);
        std::vector<U64> moves = getKnightMoves(knights);
        ASSERT_GT(moves.size(),0);


    }
