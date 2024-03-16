#ifndef BITMANIP_H
#define BITMANIP_H
#include <functional>
typedef unsigned long long U64; 

namespace BitFuncs{

U64 getBit(U64 board, int index ){
	return (board & (1ULL << index));
}
void  setBit(U64 & board, int index ){
	(board |= (1ULL << index));
}
U64 setAndGetBit(U64 board, int index ){
	return (board |= (1ULL << index));
}
U64 popBit(U64 board, int index){
	return (getBit(board,index) ? board ^= (1ULL << index): 0);

}

void iterateOverBits (U64 board, std::function <void (U64)> func){
			U64 word =  board;
			while(word != 0){
				auto lsb = word & -word;
				func(lsb);
				word^=lsb;
			}
		}
void iterateOverBits (U64 board, std::function <U64 (U64)> func){
			U64 word =  board;
			while(word != 0){
				auto lsb = word & -word;
				func(lsb);
				word^=lsb;
			}
		}
void iterateOverFile(U64 & board, int file, std::function <void (U64&, int)> func){

    int fileInd = file;
    for(int i = 0; i < 8 ; i++){
        func(board, fileInd);
        fileInd += 8;   
    }
}

void iterateOverRank(U64 & board, int rank, std::function <void (U64&, int)> func ){
    for(int i = rank; i < (rank + 8); i++){
        func(board, i);
    }
}

void printBitsNicely(U64 board){
		for ( int i = 0 ; i < 64 ; i++){
			if(i != 0 && i % 8 == 0) std::cout<<'\n';
			if (BitFuncs::getBit(board, i)){
				std::cout << " 1 ";
			}else{
				std::cout << " . ";
			}
			
		}
		std:: cout << '\n';
}

void printBitsNicely(U64 board, int perspectivePiece){
		for ( int i = 0 ; i < 64 ; i++){
			if(i != 0 && i % 8 == 0) std::cout<<'\n';
			if (getBit(board, i)){
				std::cout << " 1 ";
			}else if (i == perspectivePiece){
                std::cout<< " * ";
            }else{
				std::cout << " . ";
			}
			
		}
		std:: cout << '\n';
}

}


#endif