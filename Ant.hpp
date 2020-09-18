/******************************************************************************
** Description : This is the class specification for Ant. An ant object represents
** an ant that moves around a game board. The class has a constructor that takes 
** a pointer to a GameBoard at the starting location to initialize an Ant object.
** It also has methods for getting the ant's row and column, turning the ant
** according to the rules of Langton's Ant, and moving the ant.
*****************************************************************************/


#ifndef ANT_HPP
#define ANT_HPP

#include "GameBoard.hpp"


class Ant
{
private:
	int orientation; //1 = North, 2 = East, 3 = South, 4 = West
	int row;
	int col;
	GameBoard *board;

public:
	Ant(GameBoard*, int, int); //pointer to board plus starting row/column to create ant
	int getAntRow(); 
	int getAntCol();
	void turnAnt(int, int);
	void moveAnt(int, int);
};
#endif
