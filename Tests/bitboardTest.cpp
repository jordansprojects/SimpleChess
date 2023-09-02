/* bitboardTest.cpp - tests bitboard accuracy */

#include "../BoardRep/bitboard.h"
#include <assert.h>
int main(){

	/* desired outcomes are determined by using Layout 2  on this website :  https://gekomad.github.io/Cinnamon/BitboardCalculator/ */
	/* Using theses types of hard-coded constants for testing and not the bitboard code itself may seem inefficient and a bit redundant, 
	 * but it is a useful way for us  to ensure the logic of the bitboard is consistent and that we are understanding its construction
	 * properly. */ 
	const U64 WHITEPAWNS = 65280ULL;
	const U64 BLACKPAWNS = 71776119061217280ULL;

	const U64 WHITEKNIGHTS = 66ULL;
	const U64 BLACKKNIGHTS = 4755801206503243776ULL;

	const U64 WHITEBISHOPS = 36ULL;
	const U64 BLACKBISHOPS =  2594073385365405696ULL;

	const U64 WHITEROOKS = 129ULL;
	const U64 BLACKROOKS =  9295429630892703744ULL;

	const U64 WHITEQUEENS = 8ULL;
	const U64 BLACKQUEENS = 576460752303423488ULL;

	const U64 WHITEKINGS = 16ULL;
	const U64 BLACKKINGS= 1152921504606846976ULL;

	/* verify constants */


	// create chessboard
	ChessBoard board;
	// check if bitboard values are valid upon initialization
	std::cout << "Test 1 ) checking if initial pawn bitboards are correct...\n";
	assert (WHITEPAWNS == board.getWhitePawns());
	assert (BLACKPAWNS == board.getBlackPawns());

	std::cout << "Test 2 ) checking if initial knight bitboards are correct...\n";
	assert (WHITEKNIGHTS == board.getWhiteKnights());
	assert (BLACKKNIGHTS == board.getBlackKnights());

	std::cout << "Test 3 ) checking if initial bishop bitboards are correct...\n";
	assert (WHITEBISHOPS == board.getWhiteBishops());
	assert (BLACKBISHOPS == board.getBlackBishops());

	std::cout << "Test 4 ) checking if initial rook bitboards are correct...\n";
	assert (WHITEROOKS == board.getWhiteRooks());
	assert (BLACKROOKS == board.getBlackRooks());

	std::cout << "Test 5 ) checking if initial queen bitboards are correct... \n";
	assert (WHITEQUEENS == board.getWhiteQueens());
	assert (BLACKQUEENS == board.getBlackQueens());

	std::cout << "Test 6 ) checking if initial king bitboards are correct... \n";
	assert (WHITEKINGS == board.getWhiteKings());
	assert (BLACKKINGS == board.getBlackKings());



	std::cout << "Passed All tests succesfuly!\n";


}
