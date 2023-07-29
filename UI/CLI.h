#ifndef CLI_H
#define CLI_H

/*********************************
 * Simple Console UI 
 *
 *
 *********************************/

/* ************************************************
 * Returns desired unicode character for each piece and color
 * @param  team ( Only black and white are supported ) 
 * @param  piece
 * ************************************************************/

std::string getUnicode(int team, int piece ){

	// TODO: FINISH THIS.
	// normally I would not leave a function this simple unfished,
	// but i am going to a 5K w/ my buddy and want to push changes
	// ASAP <3 
	/* this will be optimized to use simple arithmetic to retrieve
	 * the proper unicode synbol. */
	int maxIndex = 6;
	std::string prefix = "265";
	int startWhite = 4;
	int startBlack = 'A';
	
	/*
	if ( team == WHITE){
	
	}else if (team == BLACK){
	
	
	}else{
		throw "Attempt to retrieve unicode for invalid team enum. Only black and white is supported at this time.\n";
	
	}
	*/
	
	switch(piece){
		case KING:
			return (team == WHITE)? "\u2654" : "\u265A";
			break;
		case QUEEN:
			return (team == WHITE)? "\u2655": "\u265B";
			break;
		case ROOK:
			return (team == WHITE)? "\u2656": "\u265C";
			break;
		case BISHOP:
			break;
		case KNIGHT:
			break;
		case PAWN:
			break;
	}

}

#endif
