#include "../UI/CLI.h"
#include "../BoardRep/bitboard.h"
#include <iomanip>
#include <string>
#include <functional>//

using namespace std;
//
void printBanner(string bannerStr, int spacing);
template < class T >
void runTestOnAllPieces(std::function<T(int,int)>);
int main(){
	ChessBoard board;
	const int SPACING = 55;

	/* test 1 */
	printBanner("Testing Unicode Value Generation", SPACING);
	runTestOnAllPieces<string>(&getUnicode);

	/* test 2 */
	printBanner("Testing Unicode Symbol Printing", SPACING);
	cout<< setw(SPACING+7) << " (Console must support unicode symbols)\n";
	cout<< setw(SPACING+7) << " (Guidance to be supplied in near future)\n";
	runTestOnAllPieces<string>(getSymbol);



	/** test3  **/
	printBanner("Testing the printing of the default board from White's perspective", SPACING+20);
	printBoard(board,WHITE);

	/** test 4**/
	printBanner("Testing the printing of the default board from Black's perspective", SPACING+20);
	printBoard(board,BLACK);

	cout << "\n\n";

return 0;
}

/**************************************************
 * Tester Helper functions
 * **************************************************/
/* passing functions as param is a c++11 feature */
template <class T>
void runTestOnAllPieces(function <T (int, int)> testFunc){
	int spacing = 10;
	std::string teamStrings [] = {"white", "black"};
	for ( int team = WHITE ; team <=BLACK; team++){
		cout<< "\nPrinting for team " << teamStrings[team] << ":";//
		for ( int piece = EMPTY; piece <= KING; piece++){
			cout<< setw(spacing) << testFunc(team, piece);
		} 
	}
	cout << '\n';
	
}
void printBanner(std::string bannerStr, int spacing){
	string bar = "------------------------------------------------------------------";
	cout<< '\n' << setw(spacing)<<bar << '\n' << 
	setw(spacing) << bannerStr <<"\n"	
	<< setw(spacing) << bar << '\n';
	
}



