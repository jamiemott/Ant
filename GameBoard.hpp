#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP


class GameBoard
{
private:
	char **gameBoard;
	int rows;
	int cols;

public:
	GameBoard(char**, int, int);
	void setBoardColor(int, int);
	char tokenColor(int, int);
	void changeTokenColor(int, int);
	bool checkBoarder(int, int, int);
};
#endif