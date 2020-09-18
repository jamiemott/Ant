#include "Ant.hpp"
#include "GameBoard.hpp"
#include <iostream>

/*Initializes the ant object by taking a pointer to the GameBoard it will be
interacting with and the starting row and column of the ant. 
NOTE: 1 = north, 2 = east, 3 = south, 4 = west */
Ant::Ant(GameBoard *gameBoard, int r, int c)
{
	board = gameBoard;
	row = r;
	col = c;
	orientation = 1; //Initialize with ant facing north
}


//Returns the current row of the ant
int Ant::getAntRow()
{
	return row;
}

//Returns the current column of the ant
int Ant::getAntCol()
{
	return col;
}

/*Turns the ant 90 degrees to the right if the board token is white ('W')
or turns the ant 90 degrees to the left if the board token is black ('B').
If the ant is at the boarder and cannot move forward, this continues to
turn the ant in the direction dictated by the token color until it can move.*/
void Ant::turnAnt(int r, int c)
{
	if (board->tokenColor(r, c) == 'W')
	{
		if (orientation < 4)
		{
			orientation += 1;
		}

		else
		{
			orientation = 1;
		}
	}

	if (board->tokenColor(r, c) == 'B')
	{
		if (orientation > 1)
		{
			orientation -= 1; 
		}

		else
		{
			orientation = 4;
		}
	}
}


/*This function handles the movement of the ant around the board.  It starts
by turning the ant based on the color of the token.  It then checks if the ant is
at the boarder and continues to turn the ant if necessary.  Then the token is
changed to the opposite color and the ant is moved forward.*/
void Ant::moveAnt(int r, int c)
{
	turnAnt(r, c);
	
	//Loop to keep Ant on the board.  Turns until it can move forward
	while (board->checkBoarder(orientation, r, c) == true)
	{
		turnAnt(r, c);
	}

	board->changeTokenColor(r, c);

	if (orientation == 1) //North
	{
		row -= 1; //Move up 1 row
	}

	if (orientation == 2) //East
	{
		col += 1; //Move right 1 column
	}

	if (orientation == 3)//South
	{
		row += 1; //Move down 1 row
	}

	if (orientation == 4) //West
	{
		col -= 1; //Move left 1 column
	}
}
