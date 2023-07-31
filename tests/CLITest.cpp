#include "../UI/CLI.h"

int main(){
	std::cout << " ---- testing every unicode character -----" ;	
	for ( int team = WHITE ; team <=BLACK; team++){
		std::cout << "Printing for team #" << team << '\n';
		for ( int piece = EMPTY; piece <= KING; piece++){
			std::cout<< getUnicode(team, piece);
			std::cout<< " ";
		} 
		
	}

}
