#include "stdafx.h"
#include "Board.h"
#include "iostream"
using namespace std;

//Pre:makes sure board is empty
//Post:the proceeds to puting the checker pieces
Board::Board()
{
	reset();
	maxJumps = 0;
	currentJump = 0;
	firstRedPieceCol = -1;
	firstRedPieceRow = -1;

}

//pre: collects checker( x,y)
//post: makes sure it fits on the board
void Board::reset()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			board[row][col] = '0';
		}
	}

}

//pre:addes ckecker to the board
//post:will add echeker to the bored if it meets requirements
void Board::addChecker(char who, int row, int col)
{
	if (who == Red && firstRedPieceRow == -1 && firstRedPieceCol == -1)
	{
		firstRedPieceCol = col;
		firstRedPieceRow = row;
	}
	board[row][col] = who;
}

//pre:calculates number of jumps 
//psot:totals number of jumps
int Board::numJumps(int row, int col)
{
	if (board[row][col] == Red)
	{
		currentJump = 0;
		addChecker('0', row, col);
		tryToJump(row, col);
		addChecker(Red, row, col);
	}
	return maxJumps;
}
//Pre:will print the board
//Post: makes sure that the board is an 8X8
void Board::print()
{
	cout << "---------------------------" << endl;
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << board[i][j] << "   ";
		}
		cout << endl;
	}
	{

	}
	cout << "---------------------------" << endl;

}
//Pre:will get the first red piece (x)
//Post: will finds its x cooridnate
int Board::getFirstRedPieceRow()
{

	return firstRedPieceRow;
}
//Pre: will get the first red piece (y)
//Post: will finds its y coordinate 
int Board::getFirstRedPieceCol()
{
	return firstRedPieceRow;
}

//Pre:looks and finds out if it can jump certian peices
//Post:jumps the correct peiecs and not its own. make sure it can make legal jump
int Board::tryToJump(int row, int col)
{
	if (jumpNorthEast(row, col))
	{
		currentJump++;
		addChecker('0', row + 1, col + 1);
		tryToJump(row + 2, col + 2);
		if (currentJump > maxJumps)
		{
			maxJumps = currentJump;
		}
		addChecker(Black, row + 1, col + 1);
		currentJump--;
	}
	if (jumpSouthEast(row, col))
	{
		currentJump++;
		addChecker('0', row - 1, col + 1);
		tryToJump(row - 2, col + 2);
		if (currentJump > maxJumps)
		{
			maxJumps = currentJump;
		}
		addChecker(Black, row - 1, col + 1);
		currentJump--;
	}
	if (jumpSouthWest(row, col))
	{
		currentJump++;
		addChecker('0', row - 1, col - 1);
		tryToJump(row - 2, col - 2);
		if (currentJump > maxJumps)
		{
			maxJumps = currentJump;
		}
		addChecker(Black, row - 1, col - 1);
		currentJump--;
	}
	if (jumpNorthWest(row, col))
	{
		currentJump++;
		addChecker('0', row + 1, col - 1);
		tryToJump(row + 2, col - 2);
		if (currentJump > maxJumps)
		{
			maxJumps = currentJump;
		}
		addChecker(Black, row + 1, col - 1);
		currentJump--;
	}
	return 0;
}
//Pre:if it will try to jump legally northeast
//Post:it will jump northeast if met requiremnets
bool Board::jumpNorthEast(int row, int col)
{
	return (row <= 5 && col <= 5 && board[row + 1][col + 1] == Black && board[row + 2][col + 2] == '0');
}
//Pre:it will try to jump legally northwest
//Post:it iwll jump northwest if met requirments
bool Board::jumpNorthWest(int row, int col)
{
	return (row <= 5 && col >= 2 && board[row + 1][col - 1] == Black && board[row + 2][col - 2] == '0');
}
//Pre:will try to jump southeast legally
//Post:it willl jump over if southeast meets requirements
bool Board::jumpSouthEast(int row, int col)
{
	return (row >= 2 && col <= 5 && board[row - 1][col + 1] == Black && board[row - 2][col + 2] == '0');

}
//Pre: will try jump southwest legally
//Post:will jump southwest if met requiremnets
bool Board::jumpSouthWest(int row, int col)
{
	return (row >= 2 && col >= 2 && board[row - 1][col - 1] == Black && board[row - 2][col - 2] == '0');
}
