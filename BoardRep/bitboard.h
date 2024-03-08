#ifndef BITBOARD_H
#define BITBOARD_H
#include <string>
#include <unordered_map> /* keep track of moves for a particular position */
#include <vector>
#include <iostream> /* for quick debug */
#include<bitset>
#include <functional>
#include "types.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * useful resources:
 * https://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html
 * https://gekomad.github.io/Cinnamon/BitboardCalculator/   ( we use Layout # 2  )
 * Chess Programming on YouTube
 *
 * */ 

typedef unsigned long long U64; /* unsigned 64 bit integer */ 

// bit manipulation macros : https://www.youtube.com/watch?v=wPr210gVeHI
#define getBit(bitboard, index) (bitboard & (1ULL << index))
#define setBit(bitboard, index) (bitboard |= (1ULL << index))
#define popBit(bitboard, index) (getBit(bitboard,index) ? bitboard ^= (1ULL << index): 0)


/* This is a standard chess board that assumes an 8x8 board and a black team
 * and a white team
 * */
class ChessBoard{

	private:
		/* bitboards for each type of piece */
		/* note the support for multiple kings of one color - in case some silly varient has it */ 
		U64 whitePawns, whiteKnights  ,whiteBishops , whiteRooks, whiteQueens,  whiteKings,
	    	blackPawns, blackKnights, blackBishops,  blackRooks, blackQueens, blackKings, empty;

		std::unordered_map< U64*, std::vector<U64*>> moves = {{}};
		std::unordered_map< int, int> locationMap = {}; // maps index of board to piece on the board

		const int RANK_UNIT = 8; // one step to the next file (AKA row or horizontal line) is 8 bits
		const int FILE_UNIT = 1; // one step to the next rank (AKA column or vertical line) is 1 bit

		typedef U64 (*PiececentricFunctions)(int index, U64 board);

		void setLocMap(int index, int piece ){
			locationMap[index] = piece;
		}



	public:
		friend class ConsoleUI;
		ChessBoard(){
			initBoards();
		}

		/* set up the initial bitboard states */
		/* NOTE: I could have used std::bitset::set() for setting
		 * bits on teh bitboard instead; but this works too.
		 */
		void initBoards(){
			/* set bitboards to zero*/
			whitePawns = blackPawns = whiteKnights = blackKnights = whiteBishops
			   = blackBishops = whiteRooks = blackRooks = whiteQueens = blackQueens = whiteKings = blackKings = empty = 0;

			/* set up pawn bitboards */
			for ( int i = A2; i <= H2; i++){
				setBit(whitePawns,i);
				setLocMap(i, WPAWN);
				setBit(blackPawns, (i + 40) ) ;
				setLocMap(i + 40, BPAWN);
			}

			setBit(setBit(whiteKnights, B1), G1);
			setLocMap(B1 , WKNIGHT);
			setLocMap(G1 , WKNIGHT);

			setBit(setBit(blackKnights, B8), G8);
			setLocMap(B8 , BKNIGHT);
			setLocMap(G8 , BKNIGHT);
			

			setBit(setBit(whiteBishops, C1), F1);
			setLocMap(C1 , WBISHOP);
			setLocMap(F1 , WBISHOP);

			setBit(setBit(blackBishops, C8), F8);
			setLocMap(C8 , BBISHOP);
			setLocMap(F8 , BBISHOP);


			setBit(setBit(whiteRooks, A1), H1);
			setLocMap(A1 , WROOK);
			setLocMap(H1 , WROOK);

			setBit(setBit(blackRooks, A8), H8);
			setLocMap(A8 , BROOK);
			setLocMap(H8 , BROOK);

			setBit(whiteQueens, D1);
			setLocMap(D1 , WQUEEN);
			setBit(blackQueens, D8);
			setLocMap(D8 , BQUEEN);


			setBit(whiteKings, E1);
			setLocMap(E1 , WKING);
			setBit(blackKings, E8);
			setLocMap(E8 , BKING);
			
			empty = ~(whitePawns & blackPawns & whiteKnights & blackKnights & whiteBishops & blackBishops &
					whiteRooks & blackRooks & whiteQueens & blackQueens & whiteKings & blackKings);

		}

		/* bitboard getters */
		U64 getWhitePawns(){
			return whitePawns;
		}

		U64 getBlackPawns(){
			return blackPawns;
		}

		U64 getWhiteKnights(){
			return whiteKnights;
		}

		U64 getBlackKnights(){
			return blackKnights;
		}

		U64 getWhiteBishops(){
			return whiteBishops;
		}

		U64 getBlackBishops(){
			return blackBishops;
		}
		
		U64 getWhiteRooks(){
			return whiteRooks;
		}

		U64 getBlackRooks(){
			return blackRooks;
		}

		U64 getWhiteQueens(){
			return whiteQueens;
		}

		U64 getBlackQueens(){
			return blackQueens;
		}

		U64 getWhiteKings(){
			return whiteKings;
		}

		U64 getBlackKings(){
			return blackKings;
		}

		U64 getEmpty(){
			return empty;
		}
		std::vector<U64> getWhite(){
			return {whitePawns, whiteKnights, whiteBishops, whiteRooks,whiteQueens,whiteKings};
		}

		std::vector<U64> getBlack(){
			return {blackPawns, blackKnights, blackBishops, blackRooks, blackQueens,blackKings};
		}

		bool isAtTop(int index ){
			return (index < A2 );
		}

		bool isAtBottom(int index){
			return (index > H7);
		}

		bool isOnWestCorner(int index){
			return (index % 8 == 0);
		}

		void iterateOverBits (U64 board, std::function <void (U64)> testFunc){
			// iterates over bitboard
			std::cout<< "you passed in board\n";
			U64 word =  board;
			while(word != 0){
				auto lsb = word & -word;
				testFunc(lsb);
				word^=lsb;

			}

		}
};

#endif


