#include "../BoardRep/chessParser.h"

#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

int main(){
    std::cout << "Testing ChessParser:: getIndex(ch, int ) \n";
    vector<int> bitIndicies;
    // populate vector of coordinates to compare against
    for(int i = 0; i < 64; i ++){
        bitIndicies.push_back(i);
    }
    string files = "abcdefgh";
    int i = 0;
    for (int rank = 1; rank <= 8; rank++){
        for(char file : files) {
            printf("confirming that %c%d == %d \n", file, rank, bitIndicies[i]);
            assert(ChessParser::getIndex(file, rank) == bitIndicies[i]);
            i++;
        }    
    }


    cout << "String to index converston pasts passed\n";

    


}