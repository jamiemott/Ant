/******************************************************************************
** Description : This is the main function for the Langton's Ant project. The
** main function takes user input to determine if the user will play the game
** and, if so, asks for the needed information to set up the board (rows, columns,
** number of steps, starting position (random option available)). It then runs
** the simulation and prints out the board for each step.
*****************************************************************************/


#include "MainMenu.hpp"
#include "Validation.hpp"
#include "GameBoard.hpp"
#include "Ant.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	cout << "Welcome to Langton's Ant." << endl;
	cout << "------------------------------------------------" << endl;

	int choice = mainMenu("Start Langton's Ant Simulation", "Quit");

	//Loops while the user continues to opt to play
	while (choice == 1)
	{
		cout << "Please enter the following information to set up the game:" << endl;
		cout << "Please select a number of rows from 2 to 150: ";
		
		int gridRows = inputValidate(2, 150);

		cout << "Please select a number of columns from 2 to 150: ";
		
		int gridCols = inputValidate(2, 150);

		cout << "Please select a number of steps from 1 to 25000: ";
		
		int antSteps = inputValidate(1, 25000);

		cout << "Would you like to select the ant's starting location or should it be random?" << endl;
		
		int randomStart = mainMenu("Pick the ant's starting position", "Make it random!");
		int rowStart = 0;
		int colStart = 0;

		//User chooses the starting row and column
		if (randomStart == 1)
		{
			cout << "Please select a row from 0 to " << gridRows - 1 << ": ";
			
			rowStart = inputValidate(0, gridRows-1);
			
			cout << "Please select a column from 0 to " << gridCols - 1 << ": ";
			
			colStart = inputValidate(0, gridCols-1);
		}

		//Randomly selects a position within the game board
		else
		{
			unsigned seed = time(0);
			srand(seed);
			rowStart = rand() % gridRows; //don't add 1 so that modulo keeps it within array notation
			colStart = rand() % gridCols;
		}

		cout << "Ok, we will be playing today with a " << gridRows << " by " << gridCols << " game board." << endl;
		cout << "The ant will start at location " << rowStart << " " << colStart << "." << endl;
		cout << "The ant will take " << antSteps << " steps.  Let's watch the ant walk!" << endl;
		cout << "----------------------------------------------------" << endl;

		/*Dynamically creates the 2D matrix. Source code is based on:
		learncpp.com/cpp-tutorial/6-14-pointers-to-pointers*/
		char **antBoard = new char*[gridRows];
		for (int i = 0; i < gridRows; ++i)
		{
			antBoard[i] = new char[gridCols];
		}

		/*Creates a pointer to the board in order to interact.  
		Must be defined before Ant so ant can link to the board when it is constructed*/
		GameBoard *ptrAntBoard = new GameBoard(antBoard, gridRows, gridCols);

		//Initializes the ant. Uses a pointer to the game board along with the start position.
		Ant antMan(ptrAntBoard, rowStart, colStart);
		
		//Loop to locate ant, move ant and print screen
		for (int i = 0; i <= antSteps; i++)
		{
			int currentRow = antMan.getAntRow();
			int currentCol = antMan.getAntCol();

			antMan.moveAnt(currentRow, currentCol);

			if (i == 0) //To designate starting board before steps
			{
				cout << "Starting Board:" << endl;
			}

			else
			{
				cout << "Step: " << i << endl;
			}

			//Printing the board with the ant.
			for (int i = 0; i < gridRows; i++)
			{
				for (int j = 0; j < gridCols; j++)
				{
					if (i == currentRow && j == currentCol) //ant
					{
						cout << '*';
					}

					else
					{
						cout << ptrAntBoard->tokenColor(i, j);//tokens
					}
				}

				cout << endl;
			}
			cout << endl;
		}

		/*Process to delete the dynamically created 2D array. Source code is based on:
		learncpp.com/cpp-tutorial/6-14-pointers-to-pointers*/
		for (int i = 0; i < gridRows; ++i)
		{
			delete[] antBoard[i];
		}
		delete[] antBoard;

		delete ptrAntBoard;


		cout << "The simulation has ended. Would you like to play again?" << endl;
		
		choice = mainMenu("Play again", "Quit");
	}

	cout << "Thanks for playing!" << endl;

	return 0;
}