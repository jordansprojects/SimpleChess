#ifndef BITBOARD_H
#define BITBOARD_H
#include <string>
#include <unordered_map> /* keep track of moves for a particular position */
#include <vector>
#include <iostream> /* for quick debug */
#include<bitset>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * useful resources:
 * https://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html
 * https://gekomad.github.io/Cinnamon/BitboardCalculator/   ( we use Layout # 2  )
 *
 * */ 

typedef unsigned long long U64; /* unsigned 64 bit integer */ 


enum Team{
	WHITE,
	BLACK,
};

enum Pieces {
	EMPTY, 		// 0 
	PAWN, 		// 1
	KNIGHT,		// 2
	BISHOP,		// 3 
	ROOK,		// 4 
	QUEEN,		// 5
	KING		// 6
};

/******************************************************************
 * Indexes of squares on the board
 * this may seem like overkill, but it is 
 * convenient to refer to an index as its chess coordinate 
 * Note that this view is the perspective of the black player
 ******************************************************************/
enum Squares{
		A1, B1, C1, D1, E1, F1, G1, H1,  // 00 01 02 03 04 05 06 07
		A2, B2, C2, D2, E2, F2, G2, H2,  // 08 09 10 11 12 13 14 15
		A3, B3, C3, D3, E3, F3, G3, H3,  // 16 17 18 19 20 21 22 23
		A4, B4, C4, D4, E4, F4, G4, H4,  // 24 25 26 27 28 29 30 31
		A5, B5, C5, D5, E5, F5, G5, H5,  // 32 33 34 35 36 37 38 39
		A6, B6, C6, D6, E6, F6, G6, H6,  // 40 41 42 43 44 45 46 47
		A7, B7, C7, D7, E7, F7, G7, H7,  // 48 49 50 51 52 53 54 55
		A8, B8, C8, D8, E8, F8, G8, H8 };// 56 57 58 59 60 61 62 63


/* This is a standard chess board that assumes an 8x8 board and a black team
 * and a white team
 * */
class ChessBoard{
	private:
		/* bitboards for each type of piece */
		/* note the support for multiple kings of one color - in case some silly varient has it */ 
		U64 whitePawns, whiteKnights  ,whiteBishops , whiteRooks, whiteQueens,  whiteKings,
	    	blackPawns, blackKnights, blackBishops,  blackRooks, blackQueens, blackKings, empty;
		std::bitset<64> whitePawnsBitset, whiteKnightsBitset,whiteBishopsBitset , whiteRooksBitset,
		whiteQueensBitset,  whiteKingsBitset,blackPawnsBitset, blackKnightsBitset, blackBishopsBitset,
		blackRooksBitset, blackQueensBitset, blackKingsBitset, emptyBitset;
		std::unordered_map< U64*, std::vector<U64*>> moves = {};

		const int RANK_UNIT = 8; // one step to the next file (AKA row or horizontal line) is 8 bits
		const int FILE_UNIT = 1; // one step to the next rank (AKA column or vertical line) is 1 bit

		/* setKthBit - sets the Kth bit to 1.
		 * Does so by shifting 1 k times  and then perform bitwise OR operation with the number  
		 * param k: the bit to be set
		 * param n: the current decimal value of the bitboard
		 * Reference: https://www.geeksforgeeks.org/set-k-th-bit-given-number*/
		U64 setKthBit(U64 n, int k){
			return ( ( 1ULL <<  k ) | n );
		}




	public:
		ChessBoard(){
			std::cout << "bitboard is init\n";
			initBoards();
		}
		/* move generation code */
		void generateRookMoves();
		void generateBishopMoves();
		void generateKnightMoves();
		void generateQueenMoves();
		void generatePawnMoves();

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
				whitePawns = setKthBit( whitePawns, i );
				/* 40 is the index distance between the white and black pawns */
				blackPawns = setKthBit(blackPawns, i + 40 ) ;
			}
			whitePawnsBitset =  std::bitset<64>(whitePawns);
			blackPawnsBitset =  std::bitset<64>(blackPawns);

			/* set up other bitboards manually 
			 * we can make nested calls for boards with two pieces of each type*/
			whiteKnights = setKthBit(setKthBit(whiteKnights, B1), G1);
			blackKnights = setKthBit(setKthBit(blackKnights, B8), G8);
			
			whiteKnightsBitset =  std::bitset<64>(whiteKnights);
			blackKnightsBitset =  std::bitset<64>(blackKnights);


			whiteBishops = setKthBit(setKthBit(whiteBishops, C1), F1);
			blackBishops = setKthBit(setKthBit(blackBishops, C8), F8);
			whiteBishopsBitset =  std::bitset<64>(whiteBishops);
			blackBishopsBitset =  std::bitset<64>(blackBishops);

			whiteRooks = setKthBit(setKthBit(whiteRooks, A1), H1);
			blackRooks = setKthBit(setKthBit(blackRooks, A8), H8);
			whiteRooksBitset =  std::bitset<64>(whiteRooks);
			blackRooksBitset =  std::bitset<64>(blackRooks);

			whiteQueens = setKthBit(whiteQueens, D1);
			blackQueens = setKthBit(blackQueens, D8);
			whiteQueensBitset =  std::bitset<64>(whiteQueens);
			blackQueensBitset =  std::bitset<64>(blackQueens);

			whiteKings = setKthBit(whiteKings, E1);
			blackKings = setKthBit(blackKings, E8);
			whiteKingsBitset =  std::bitset<64>(whiteKings);
			blackKingsBitset =  std::bitset<64>(blackKings);
			
			empty = ~(whitePawns & blackPawns & whiteKnights & blackKnights & whiteBishops & blackBishops &
					whiteRooks & blackRooks & whiteQueens & blackQueens & whiteKings & blackKings);

			emptyBitset =  std::bitset<64>(empty);
		}


		/* move generation methods */

		/**************************
		 * generates moves for white pawns
		 * @param bits : the bitset of the desired piece type
		 * @param vector to store moves from a particular position
		 */
		void populateWhitePawnMoves(U64 bits, std::vector<U64*>&v){
			U64 forwardSteps = (bits >> RANK_UNIT xor empty); // move to the next rank
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


		std::vector<U64> getWhite(){
			return {whitePawns, whiteKnights, whiteBishops, whiteRooks,whiteQueens,whiteKings};
		}

		std::vector<U64> getBlack(){
			return {blackPawns, blackKnights, blackBishops, blackRooks, blackQueens,blackKings};
		}

		/* bitboard bitset getters */
		std::bitset<64> getWhitePawnsAsBitset(){
					return whitePawnsBitset;
				}

		std::bitset<64> getBlackPawnsAsBitset(){
				return blackPawnsBitset;
				}

		std::bitset<64> getWhiteKnightsAsBitset(){
					return whiteKnightsBitset;
				}

		std::bitset<64> getBlackKnightsAsBitset(){
					return blackKnightsBitset;
				}

		std::bitset<64> getWhiteBishopsAsBitset(){
					return whiteBishopsBitset;
				}

		std::bitset<64> getBlackBishopsAsBitset(){
					return blackBishopsBitset;
				}

		std::bitset<64> getWhiteRooksAsBitset(){
					return whiteRooksBitset;
				}

		std::bitset<64> getBlackRooksAsBitset(){
					return blackRooksBitset;
				}

		std::bitset<64> getWhiteQueensAsBitset(){
					return whiteQueensBitset;
				}

		std::bitset<64> getBlackQueensAsBitset(){
					return blackQueensBitset;
				}

		std::bitset<64> getWhiteKingsAsBitset(){
					return whiteKingsBitset;
				}

		std::bitset<64> getBlackKingsAsBitset(){
					return blackKingsBitset;
				}
	

};

#endif


