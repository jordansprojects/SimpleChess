#################################################
# Makefile for SimpleChess Testing Suite
#################################################

CC = g++
CFLAGS = -Wall -pedantic -Werror -Ofast -std=c++1z
LIB = -lm
LDFLAGS = -L.
PROG =  gameCLI bitboardTest CLITest # target executables
SRCS = Tests/game.cpp Tests/bitboardTest.cpp UI/CLI.h BoardRep/bitboard.h 
OBJ = $(SRCS:.cpp=.o) # object files for the target
DEPS = $(SRCS:.cpp=.d) 


#Default Target
all: $(PROG)

gameCLI: Tests/game.o BoardRep/bitboard.o
	$(CC) $(CFLAGS) -o gameCLI Tests/game.o $(LDFLAGS) $(LIB)

bitboardTest: Tests/bitboardTest.o BoardRep/bitboard.o
	$(CC) $(CFLAGS) -o bitboardTest Tests/bitboardTest.o $(LDFLAGS) $(LIB)

CLITest: Tests/CLITest.o UI/CLI.o
	$(CC) $(CFLAGS) -o CLITest Tests/CLITest.o $(LDFLAGS) $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.h.o:
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -f *.o $(PROG)
	
