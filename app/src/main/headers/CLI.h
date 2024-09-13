//TO-DO : Store these in a better way

#ifndef CLI_TYPES_H
#define CLI_TYPES_H
#include <string>
#include <string_view> // for an immutable string
#include <vector>
	/* unicode symbols for chess pieces and pawns */
	static constexpr std::string_view whitePawnUnicode = "\u2659";
	static constexpr std::string_view blackPawnUnicode = "\u265F";
	static constexpr std::string_view whiteKnightUnicode = "\u2658";
	static constexpr std::string_view blackKnightUnicode = "\u265E";
	static constexpr std::string_view whiteBishopUnicode = "\u2657";
	static constexpr std::string_view blackBishopUnicode = "\u265D";
	static constexpr std::string_view whiteRookUnicode = "\u2656";
	static constexpr std::string_view blackRookUnicode = "\u265C";
	static constexpr std::string_view whiteQueenUnicode= "\u2655";
	static constexpr std::string_view blackQueenUnicode =  "\u265B";
	static constexpr std::string_view whiteKingUnicode = "♔" ;
	static constexpr std::string_view blackKingUnicode =  "\u265A" ;
	static constexpr std::string_view emptyUnicode =  ".";


	std::vector<std::string_view> symbols = { emptyUnicode, whitePawnUnicode, whiteKnightUnicode, whiteBishopUnicode,
	 whiteRookUnicode, whiteQueenUnicode, whiteKingUnicode,blackPawnUnicode , blackKnightUnicode,
	 blackBishopUnicode, blackRookUnicode, blackQueenUnicode , blackKingUnicode};
	// space per piece
	static constexpr std::string_view SPACE = " ";
#endif
