#include "GameBoard.hpp"
#include <iostream>


/*The constructor takes a pointer to a pointer to a char in order to interact
with the dynamically created 2D array in the main function.  It also takes in the 
total rows and columns selected by the user.  It calls the setBoardColor function
to initialize all the board tokens to white.*/
GameBoard::GameBoard(char **board, int a, int b)
{
	gameBoard = board;
	rows = a;
	cols = b;
	setBoardColor(rows, cols);
}

//Initializes the "color" of the board tokens using the total rows and columns
void GameBoard::setBoardColor(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			gameBoard[i][j] = 'W'; //sets tokens to white
		}
	}
}

//Returns the token color of the location passed in the parameters
char GameBoard::tokenColor(int r, int c)
{
	char tokenColor = gameBoard[r][c];

	return tokenColor;
}

//Switches the input token's colors between black and white when called
void GameBoard::changeTokenColor(int r, int c)
{
	char currentColor = tokenColor(r, c);

	if (currentColor == 'W')
	{
		gameBoard[r][c] = 'B'; //change white to black
	}

	if (currentColor == 'B')
	{
		gameBoard[r][c] = 'W'; //change black to white
	}
}

/*Takes in the ant's orientation, current row and column and checks to see if the
ant's current position is at the edge of the board.*/
bool GameBoard::checkBoarder(int dir, int r, int c)
{
	if (dir == 1 && r == 0) //Facing north and at top of board
	{
		return true; //at edge
	}

	if (dir == 2 && c == cols -1) //Facing east and at side of board
	{
		return true; //at edge
	}

	if (dir == 3 && r == rows -1) //Facing south and at bottom of board
	{
		return true; //at edge
	}

	if (dir == 1 && c == 0) //Facing west and at side of board
	{
		return true; //at edge
	}

	else
	{
		return false; //able to move forward
	}
}
	