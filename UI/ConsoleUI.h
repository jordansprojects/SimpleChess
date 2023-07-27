#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

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
	switch(piece){
		case KING:
			return (team == WHITE)? "/U+2654" : "/U+265A";
			break;
		case QUEEN:
			break;
		case ROOK:
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
