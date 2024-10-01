
#ifndef UNICODEPIECES__H
#define UNICODEPIECES__H
#include <string>
#include <vector>

	/* unicode symbols for chess pieces and pawns */
	const std::string whitePawnUnicode = "\u2659";
	const std::string blackPawnUnicode = "\u265F";
	const std::string whiteKnightUnicode = "\u2658";
	const std::string blackKnightUnicode = "\u265E";
	const std::string whiteBishopUnicode = "\u2657";
	const std::string blackBishopUnicode = "\u265D";
	const std::string  whiteRookUnicode = "\u2656";
	const std::string  blackRookUnicode = "\u265C";
	const std::string  whiteQueenUnicode= "\u2655";
	const std::string  blackQueenUnicode =  "\u265B";
	const std::string whiteKingUnicode = "♔" ;
	const std::string  blackKingUnicode =  "\u265A" ;

	const std::vector<std::string> whiteUnicodePieces = {whitePawnUnicode, whiteKnightUnicode,whiteBishopUnicode,whiteRookUnicode,whiteQueenUnicode,whiteKingUnicode};

	const std::vector<std::string> blackUnicodePieces = {blackPawnUnicode, blackKnightUnicode,blackBishopUnicode,blackRookUnicode,blackQueenUnicode,blackKingUnicode};


#endif

