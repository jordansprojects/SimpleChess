// defaultboards.h - Made the most sense to define these if most games will start this way
#ifndef DEFAULTS_H
#define DEFAULTS_H

namespace SimpleChess{
typedef unsigned long long U64;

// LERF - Little Endian Rank-file mapping
enum Squares{
    A1, B1, C1, D1, E1, F1, G1, H1,  // 00 01 02 03 04 05 06 07
    A2, B2, C2, D2, E2, F2, G2, H2,  // 08 09 10 11 12 13 14 15
    A3, B3, C3, D3, E3, F3, G3, H3,  // 16 17 18 19 20 21 22 23
    A4, B4, C4, D4, E4, F4, G4, H4,  // 24 25 26 27 28 29 30 31
    A5, B5, C5, D5, E5, F5, G5, H5,  // 32 33 34 35 36 37 38 39
    A6, B6, C6, D6, E6, F6, G6, H6,  // 40 41 42 43 44 45 46 47
    A7, B7, C7, D7, E7, F7, G7, H7,  // 48 49 50 51 52 53 54 55
    A8, B8, C8, D8, E8, F8, G8, H8 };// 56 57 58 59 60 61 62 63

    constexpr U64 A_FILE = 0x0101010101010101;
    constexpr U64 H_FILE = 0x8080808080808080;
    constexpr U64 RANK_1 = 0x00000000000000FF;
    constexpr U64 RANK_8 = 0xFF00000000000000;
    constexpr U64 A1_H8_DIAGONAL =0x8040201008040201;

    // Right shifts (+)
    constexpr int noWe = 7, nort = 8, noEa = 9, east = 1,
    noNoWe = 15, noNoEa=17, noWeWe=6, noEaEa=10;

    // Left shifts (-)
    constexpr int west = 1, soWe = 9, south = 8, soEa = 7,
    soSoWe = 17, soSoEa = 15, soEaEa = 6, soWeWe = 10;

    constexpr U64  WHITE_KNIGHTS_DEFAULT = 0 | ( 1ULL << B1 ) | ( 1ULL << G1 );
    constexpr U64  WHITE_BISHOPS_DEFAULT = 0 | ( 1ULL << F1 ) | ( 1ULL << C1 );
    constexpr U64  WHITE_ROOKS_DEFAULT   = 0 | ( 1ULL << H1 ) | ( 1ULL << A1 );
    constexpr U64  WHITE_QUEEN_DEFAULT   = 0 | ( 1ULL << D1 );
    constexpr U64  WHITE_KING_DEFAULT    = 0 | ( 1ULL << E1 );

    constexpr U64  BLACK_KNIGHTS_DEFAULT = 0 | ( 1ULL << B8 ) | ( 1ULL << G8 );
    constexpr U64  BLACK_BISHOPS_DEFAULT = 0 | ( 1ULL << F8 ) | ( 1ULL << C8 );
    constexpr U64  BLACK_ROOKS_DEFAULT   = 0 | ( 1ULL << H8 ) | ( 1ULL << A8 );
    constexpr U64  BLACK_QUEEN_DEFAULT   = 0 | ( 1ULL << D8 );
    constexpr U64  BLACK_KING_DEFAULT    = 0 | ( 1ULL << E8 );

};
#endif
