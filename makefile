# Langton's Ant
# Author:      Jamie Mott
# Date : April 4, 2019
# Description : This is the makefile for Langton's Ant


# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -std=c++0x

# File variables
OBJS = Main.o MainMenu.o Validation.o GameBoard.o Ant.o
SRCS = Main.cpp MainMenu.cpp Validation.cpp GameBoard.cpp Ant.cpp
HEADERS = MainMenu.hpp Validation.hpp GameBoard.hpp Ant.hpp

langton: $(OBJS)
	$(CXX) $(CXXFLAGS) -o langton $(OBJS)

Main.o: Main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c Main.cpp

MainMenu.o: MainMenu.cpp MainMenu.hpp
	$(CXX) $(CXXFLAGS) -c MainMenu.cpp

Validation.o: Validation.cpp Validation.hpp
	$(CXX) $(CXXFLAGS) -c Validation.cpp

GameBoard.o: GameBoard.cpp GameBoard.hpp
	$(CXX) $(CXXFLAGS) -c GameBoard.cpp

Ant.o: Ant.cpp Ant.hpp GameBoard.hpp
	$(CXX) $(CXXFLAGS) -c Ant.cpp

clean:
	rm *.o langton